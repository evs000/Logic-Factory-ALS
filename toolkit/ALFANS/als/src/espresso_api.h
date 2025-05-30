#pragma once


#include "port.h"
#include "utility.h"
// #include "sparse.h"
// #include "mincov.h"


#define ptime()		util_cpu_time()
#define print_time(t)	util_print_time(t)

#ifdef IBM_WATC
#define void int
#include "short.h"
#endif

#ifdef IBMPC		/* set default options for IBM/PC */
#define NO_INLINE
#define BPI 16
#endif


/* Define host machine characteristics of "unsigned int" */
#ifndef BPI
#define BPI             32              /* # bits per integer */
#endif

#if BPI == 32
#define LOGBPI          5               /* log(BPI)/log(2) */
#else
#define LOGBPI          4               /* log(BPI)/log(2) */
#endif

/* Define the set type */
typedef unsigned int *pset;

/* Define the set family type -- an array of sets */
typedef struct set_family {
    int wsize;                  /* Size of each set in 'ints' */
    int sf_size;                /* User declared set size */
    int capacity;               /* Number of sets allocated */
    int count;                  /* The number of sets in the family */
    int active_count;           /* Number of "active" sets */
    pset data;                  /* Pointer to the set data */
    struct set_family *next;    /* For garbage collection */
} set_family_t, *pset_family;

/* Macros to set and test single elements */
#define WHICH_WORD(element)     (((element) >> LOGBPI) + 1)
#define WHICH_BIT(element)      ((element) & (BPI-1))

/* # of ints needed to allocate a set with "size" elements */
#if BPI == 32
#define SET_SIZE(size)          ((size) <= BPI ? 2 : (WHICH_WORD((size)-1) + 1))
#else
#define SET_SIZE(size)          ((size) <= BPI ? 3 : (WHICH_WORD((size)-1) + 2))
#endif

/*
 *  Three fields are maintained in the first word of the set
 *      LOOP is the index of the last word used for set data
 *      LOOPCOPY is the index of the last word in the set
 *      SIZE is available for general use (e.g., recording # elements in set)
 *      NELEM retrieves the number of elements in the set
 */
#define LOOP(set)               (set[0] & 0x03ff)
#define PUTLOOP(set, i)         (set[0] &= ~0x03ff, set[0] |= (i))
#if BPI == 32
#define LOOPCOPY(set)           LOOP(set)
#define SIZE(set)               (set[0] >> 16)
#define PUTSIZE(set, size)      (set[0] &= 0xffff, set[0] |= ((size) << 16))
#else
#define LOOPCOPY(set)           (LOOP(set) + 1)
#define SIZE(set)               (set[LOOP(set)+1])
#define PUTSIZE(set, size)      ((set[LOOP(set)+1]) = (size))
#endif

#define NELEM(set)		(BPI * LOOP(set))
#define LOOPINIT(size)		((size <= BPI) ? 1 : WHICH_WORD((size)-1))

/*
 *      FLAGS store general information about the set
 */
#define SET(set, flag)          (set[0] |= (flag))
#define RESET(set, flag)        (set[0] &= ~ (flag))
#define TESTP(set, flag)        (set[0] & (flag))

/* Flag definitions are ... */
#define PRIME           0x8000          /* cube is prime */
#define NONESSEN        0x4000          /* cube cannot be essential prime */
#define ACTIVE          0x2000          /* cube is still active */
#define REDUND          0x1000          /* cube is redundant(at this point) */
#define COVERED         0x0800          /* cube has been covered */
#define RELESSEN        0x0400          /* cube is relatively essential */

/* Most efficient way to look at all members of a set family */
#define foreach_set(R, last, p)\
    for(p=R->data,last=p+R->count*R->wsize;p<last;p+=R->wsize)
#define foreach_remaining_set(R, last, pfirst, p)\
    for(p=pfirst+R->wsize,last=R->data+R->count*R->wsize;p<last;p+=R->wsize)
#define foreach_active_set(R, last, p)\
    foreach_set(R,last,p) if (TESTP(p, ACTIVE))

/* Another way that also keeps the index of the current set member in i */
#define foreachi_set(R, i, p)\
    for(p=R->data,i=0;i<R->count;p+=R->wsize,i++)
#define foreachi_active_set(R, i, p)\
    foreachi_set(R,i,p) if (TESTP(p, ACTIVE))

/* Looping over all elements in a set:
 *      foreach_set_element(pset p, int i, unsigned val, int base) {
 *		.
 *		.
 *		.
 *      }
 */
#define foreach_set_element(p, i, val, base) 		\
    for(i = LOOP(p); i > 0; )				\
	for(val = p[i], base = --i << LOGBPI; val != 0; base++, val >>= 1)  \
	    if (val & 1)

/* Return a pointer to a given member of a set family */
#define GETSET(family, index)   ((family)->data + (family)->wsize * (index))

/* Allocate and deallocate sets */
#define set_new(size)	set_clear(ALLOC(unsigned int, SET_SIZE(size)), size)
#define set_full(size)	set_fill(ALLOC(unsigned int, SET_SIZE(size)), size)
#define set_save(r)	set_copy(ALLOC(unsigned int, SET_SIZE(NELEM(r))), r)
#define set_free(r)	FREE(r)

/* Check for set membership, remove set element and insert set element */
#define is_in_set(set, e)       (set[WHICH_WORD(e)] & (1 << WHICH_BIT(e)))
#define set_remove(set, e)      (set[WHICH_WORD(e)] &= ~ (1 << WHICH_BIT(e)))
#define set_insert(set, e)      (set[WHICH_WORD(e)] |= 1 << WHICH_BIT(e))

/* Inline code substitution for those places that REALLY need it on a VAX */
#ifdef NO_INLINE
#define INLINEset_copy(r, a)		(void) set_copy(r,a)
#define INLINEset_clear(r, size)	(void) set_clear(r, size)
#define INLINEset_fill(r, size)		(void) set_fill(r, size)
#define INLINEset_and(r, a, b)		(void) set_and(r, a, b)
#define INLINEset_or(r, a, b)		(void) set_or(r, a, b)
#define INLINEset_diff(r, a, b)		(void) set_diff(r, a, b)
#define INLINEset_ndiff(r, a, b, f)	(void) set_ndiff(r, a, b, f)
#define INLINEset_xor(r, a, b)		(void) set_xor(r, a, b)
#define INLINEset_xnor(r, a, b, f)	(void) set_xnor(r, a, b, f)
#define INLINEset_merge(r, a, b, mask)	(void) set_merge(r, a, b, mask)
#define INLINEsetp_implies(a, b, when_false)	\
    if (! setp_implies(a,b)) when_false
#define INLINEsetp_disjoint(a, b, when_false)	\
    if (! setp_disjoint(a,b)) when_false
#define INLINEsetp_equal(a, b, when_false)	\
    if (! setp_equal(a,b)) when_false

#else

#define INLINEset_copy(r, a)\
    {register int i_=LOOPCOPY(a); do r[i_]=a[i_]; while (--i_>=0);}
#define INLINEset_clear(r, size)\
    {register int i_=LOOPINIT(size); *r=i_; do r[i_] = 0; while (--i_ > 0);}
#define INLINEset_fill(r, size)\
    {register int i_=LOOPINIT(size); *r=i_; \
    r[i_]=((unsigned int)(~0))>>(i_*BPI-size); while(--i_>0) r[i_]=~0;}
#define INLINEset_and(r, a, b)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = a[i_] & b[i_]; while (--i_>0);}
#define INLINEset_or(r, a, b)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = a[i_] | b[i_]; while (--i_>0);}
#define INLINEset_diff(r, a, b)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = a[i_] & ~ b[i_]; while (--i_>0);}
#define INLINEset_ndiff(r, a, b, fullset)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = fullset[i_] & (a[i_] | ~ b[i_]); while (--i_>0);}
#ifdef IBM_WATC
#define INLINEset_xor(r, a, b)		(void) set_xor(r, a, b)
#define INLINEset_xnor(r, a, b, f)	(void) set_xnor(r, a, b, f)
#else
#define INLINEset_xor(r, a, b)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = a[i_] ^ b[i_]; while (--i_>0);}
#define INLINEset_xnor(r, a, b, fullset)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = fullset[i_] & ~ (a[i_] ^ b[i_]); while (--i_>0);}
#endif
#define INLINEset_merge(r, a, b, mask)\
    {register int i_=LOOP(a); PUTLOOP(r,i_);\
    do r[i_] = (a[i_]&mask[i_]) | (b[i_]&~mask[i_]); while (--i_>0);}
#define INLINEsetp_implies(a, b, when_false)\
    {register int i_=LOOP(a); do if (a[i_]&~b[i_]) break; while (--i_>0);\
    if (i_ != 0) when_false;}
#define INLINEsetp_disjoint(a, b, when_false)\
    {register int i_=LOOP(a); do if (a[i_]&b[i_]) break; while (--i_>0);\
    if (i_ != 0) when_false;}
#define INLINEsetp_equal(a, b, when_false)\
    {register int i_=LOOP(a); do if (a[i_]!=b[i_]) break; while (--i_>0);\
    if (i_ != 0) when_false;}

#endif

#if BPI == 32
#define count_ones(v)\
    (bit_count[v & 255] + bit_count[(v >> 8) & 255]\
    + bit_count[(v >> 16) & 255] + bit_count[(v >> 24) & 255])
#else
#define count_ones(v)   (bit_count[v & 255] + bit_count[(v >> 8) & 255])
#endif

/* Table for efficient bit counting */
extern int bit_count[256];
/*----- END OF set.h ----- */

/* Define a boolean type */
#define bool	int
#define FALSE	0
#define TRUE 	1
#define MAYBE	2
#define print_bool(x) ((x) == 0 ? "FALSE" : ((x) == 1 ? "TRUE" : "MAYBE"))

/* Map many cube/cover types/routines into equivalent set types/routines */
#define pcube                   pset
#define new_cube()              set_new(cube.size)
#define free_cube(r)            set_free(r)
#define pcover                  pset_family
#define new_cover(i)            sf_new(i, cube.size)
#define free_cover(r)           sf_free(r)
#define free_cubelist(T)        FREE(T[0]); FREE(T);


/* cost_t describes the cost of a cover */
typedef struct cost_struct {
    int cubes;			/* number of cubes in the cover */
    int in;			/* transistor count, binary-valued variables */
    int out;			/* transistor count, output part */
    int mv;			/* transistor count, multiple-valued vars */
    int total;			/* total number of transistors */
    int primes;			/* number of prime cubes */
} cost_t, *pcost;


/* pair_t describes bit-paired variables */
typedef struct pair_struct {
    int cnt;
    int *var1;
    int *var2;
} pair_t, *ppair;


/* symbolic_list_t describes a single ".symbolic" line */
typedef struct symbolic_list_struct {
    int variable;
    int pos;
    struct symbolic_list_struct *next;
} symbolic_list_t;


/* symbolic_list_t describes a single ".symbolic" line */
typedef struct symbolic_label_struct {
    char *label;
    struct symbolic_label_struct *next;
} symbolic_label_t;


/* symbolic_t describes a linked list of ".symbolic" lines */
typedef struct symbolic_struct {
    symbolic_list_t *symbolic_list;	/* linked list of items */
    int symbolic_list_length;		/* length of symbolic_list list */
    symbolic_label_t *symbolic_label;	/* linked list of new names */
    int symbolic_label_length;		/* length of symbolic_label list */
    struct symbolic_struct *next;
} symbolic_t;


/* PLA_t stores the logical representation of a PLA */
typedef struct {
    pcover F, D, R;		/* on-set, off-set and dc-set */
    char *filename;             /* filename */
    int pla_type;               /* logical PLA format */
    pcube phase;                /* phase to split into on-set and off-set */
    ppair pair;                 /* how to pair variables */
    char **label;		/* labels for the columns */
    symbolic_t *symbolic;	/* allow binary->symbolic mapping */
    symbolic_t *symbolic_output;/* allow symbolic output mapping */
} PLA_t, *pPLA;

#define equal(a,b)      (strcmp(a,b) == 0)

/* This is a hack which I wish I hadn't done, but too painful to change */
#define CUBELISTSIZE(T)         (((pcube *) T[1] - T) - 3)

/* For documentation purposes */
#define IN
#define OUT
#define INOUT

/* The pla_type field describes the input and output format of the PLA */
#define F_type          1
#define D_type          2
#define R_type          4
#define PLEASURE_type   8               /* output format */
#define EQNTOTT_type    16              /* output format algebraic eqns */
#define KISS_type	128		/* output format kiss */
#define CONSTRAINTS_type	256	/* output the constraints (numeric) */
#define SYMBOLIC_CONSTRAINTS_type 512	/* output the constraints (symbolic) */
#define FD_type (F_type | D_type)
#define FR_type (F_type | R_type)
#define DR_type (D_type | R_type)
#define FDR_type (F_type | D_type | R_type)

/* Definitions for the debug variable */
#define COMPL           0x0001
#define ESSEN           0x0002
#define EXPAND          0x0004
#define EXPAND1         0x0008
#define GASP            0x0010
#define IRRED           0x0020
#define REDUCE          0x0040
#define REDUCE1         0x0080
#define SPARSE          0x0100
#define TAUT            0x0200
#define EXACT           0x0400
#define MINCOV          0x0800
#define MINCOV1         0x1000
#define SHARP           0x2000
#define IRRED1		0x4000

#define VERSION\
    "UC Berkeley, Espresso Version #2.3, Release date 01/31/88"

/* Define constants used for recording program statistics */
#define TIME_COUNT      16
#define READ_TIME       0
#define COMPL_TIME      1
#define ONSET_TIME	2
#define ESSEN_TIME      3
#define EXPAND_TIME     4
#define IRRED_TIME      5
#define REDUCE_TIME     6
#define GEXPAND_TIME    7
#define GIRRED_TIME     8
#define GREDUCE_TIME    9
#define PRIMES_TIME     10
#define MINCOV_TIME	11
#define MV_REDUCE_TIME  12
#define RAISE_IN_TIME   13
#define VERIFY_TIME     14
#define WRITE_TIME	15


/* For those who like to think about PLAs, macros to get at inputs/outputs */
#define NUMINPUTS       cube.num_binary_vars
#define NUMOUTPUTS      cube.part_size[cube.num_vars - 1]

#define POSITIVE_PHASE(pos)\
    (is_in_set(PLA->phase, cube.first_part[cube.output]+pos) != 0)

#define INLABEL(var)    PLA->label[cube.first_part[var] + 1]
#define OUTLABEL(pos)   PLA->label[cube.first_part[cube.output] + pos]

#define GETINPUT(c, pos)\
    ((c[WHICH_WORD(2*pos)] >> WHICH_BIT(2*pos)) & 3)
#define GETOUTPUT(c, pos)\
    (is_in_set(c, cube.first_part[cube.output] + pos) != 0)

#define PUTINPUT(c, pos, value)\
    c[WHICH_WORD(2*pos)] = (c[WHICH_WORD(2*pos)] & ~(3 << WHICH_BIT(2*pos)))\
		| (value << WHICH_BIT(2*pos))
#define PUTOUTPUT(c, pos, value)\
    c[WHICH_WORD(pos)] = (c[WHICH_WORD(pos)] & ~(1 << WHICH_BIT(pos)))\
		| (value << WHICH_BIT(pos))

#define TWO     3
#define DASH    3
#define ONE     2
#define ZERO    1


#define EXEC(fct, name, S)\
    {long t=ptime();fct;if(trace)print_trace(S,name,ptime()-t);}
#define EXEC_S(fct, name, S)\
    {long t=ptime();fct;if(summary)print_trace(S,name,ptime()-t);}
#define EXECUTE(fct,i,S,cost)\
    {long t=ptime();fct;totals(t,i,S,&(cost));}

/*
 *    Global Variable Declarations
 */

extern unsigned int debug;              /* debug parameter */
extern bool verbose_debug;              /* -v:  whether to print a lot */
extern char *total_name[TIME_COUNT];    /* basic function names */
extern long total_time[TIME_COUNT];     /* time spent in basic fcts */
extern int total_calls[TIME_COUNT];     /* # calls to each fct */

extern bool echo_comments;		/* turned off by -eat option */
extern bool echo_unknown_commands;	/* always true ?? */
extern bool force_irredundant;          /* -nirr command line option */
extern bool skip_make_sparse;
extern bool kiss;                       /* -kiss command line option */
extern bool pos;                        /* -pos command line option */
extern bool print_solution;             /* -x command line option */
extern bool recompute_onset;            /* -onset command line option */
extern bool remove_essential;           /* -ness command line option */
extern bool single_expand;              /* -fast command line option */
extern bool summary;                    /* -s command line option */
extern bool trace;                      /* -t command line option */
extern bool unwrap_onset;               /* -nunwrap command line option */
extern bool use_random_order;		/* -random command line option */
extern bool use_super_gasp;		/* -strong command line option */
extern char *filename;			/* filename PLA was read from */
extern bool debug_exact_minimization;   /* dumps info for -do exact */


/*
 *  pla_types are the input and output types for reading/writing a PLA
 */
struct pla_types_struct {
    char *key;
    int value;
};


/*
 *  The cube structure is a global structure which contains information
 *  on how a set maps into a cube -- i.e., number of parts per variable,
 *  number of variables, etc.  Also, many fields are pre-computed to
 *  speed up various primitive operations.
 */
#define CUBE_TEMP       10

struct cube_struct {
    int size;                   /* set size of a cube */
    int num_vars;               /* number of variables in a cube */
    int num_binary_vars;        /* number of binary variables */
    int *first_part;            /* first element of each variable */
    int *last_part;             /* first element of each variable */
    int *part_size;             /* number of elements in each variable */
    int *first_word;            /* first word for each variable */
    int *last_word;             /* last word for each variable */
    pset binary_mask;           /* Mask to extract binary variables */
    pset mv_mask;               /* mask to get mv parts */
    pset *var_mask;             /* mask to extract a variable */
    pset *temp;                 /* an array of temporary sets */
    pset fullset;               /* a full cube */
    pset emptyset;              /* an empty cube */
    unsigned int inmask;        /* mask to get odd word of binary part */
    int inword;                 /* which word number for above */
    int *sparse;                /* should this variable be sparse? */
    int num_mv_vars;            /* number of multiple-valued variables */
    int output;                 /* which variable is "output" (-1 if none) */
};

struct cdata_struct {
    int *part_zeros;            /* count of zeros for each element */
    int *var_zeros;             /* count of zeros for each variable */
    int *parts_active;          /* number of "active" parts for each var */
    bool *is_unate;             /* indicates given var is unate */
    int vars_active;            /* number of "active" variables */
    int vars_unate;             /* number of unate variables */
    int best;                   /* best "binate" variable */
};


extern struct pla_types_struct pla_types[];
extern struct cube_struct cube, temp_cube_save;
extern struct cdata_struct cdata, temp_cdata_save;

#ifdef lint
#define DISJOINT 0x5555
#else
#if BPI == 32
#define DISJOINT 0x55555555
#else
#define DISJOINT 0x5555
#endif
#endif

/* function declarations */
extern "C" {
    void getPLA(int, int, char **, int, pPLA *, int);
    pPLA new_PLA();
    void free_PLA(pPLA PLA);
    void fprint_pla(void *fp, pPLA, int);
    void PLA_labels(pPLA PLA);

    pset set_copy(pset, pset);
    pset set_clear(pset, int);

    pcover espresso(pcover ,pcover , pcover);

    void cube_setup();

    pset_family sf_new(int, int);
    pset_family sf_addset(pset_family, pset);
    pset_family sf_join(pset_family, pset_family);
    void sf_cleanup();
    void sf_free(pset_family);

    pset_family d1merge(pset_family, int);
    pcover complement(pcube *);
    pcube * cube1list(pcover);

    void sm_cleanup();
    void setdown_cube();

    void fatal(char * s);

    void print_cube(void *fp, pcube c, char *out_map);
}