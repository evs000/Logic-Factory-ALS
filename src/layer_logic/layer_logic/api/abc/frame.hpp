#pragma once

#if !defined( ABC_NAMESPACE )
#error ABC_NAMESPACE is not defined (babc). Please define it before including this file!
#endif

namespace ABC_NAMESPACE
{
#if defined( __ccdoc__ )
typedef platform_dependent_type ABC_PTRDIFF_T;
#elif defined( ABC_USE_STDINT_H )
typedef ptrdiff_t ABC_PTRDIFF_T;
#elif defined( LIN64 )
typedef long ABC_PTRDIFF_T;
#elif defined( NT64 )
typedef long long ABC_PTRDIFF_T;
#elif defined( NT ) || defined( LIN ) || defined( WIN32 )
typedef int ABC_PTRDIFF_T;
#else
#error unknown platform
#endif /* defined(PLATFORM) */

/**
 * Unsigned integral type that can contain a pointer.
 * This is an unsigned integral type that is the same size as a pointer.
 * NOTE: This type may be different sizes on different platforms.
 */
#if defined( __ccdoc__ )
typedef platform_dependent_type ABC_PTRUINT_T;
#elif defined( ABC_USE_STDINT_H )
typedef uintptr_t ABC_PTRUINT_T;
#elif defined( LIN64 )
typedef unsigned long ABC_PTRUINT_T;
#elif defined( NT64 )
typedef unsigned long long ABC_PTRUINT_T;
#elif defined( NT ) || defined( LIN ) || defined( WIN32 )
typedef unsigned int ABC_PTRUINT_T;
#else
#error unknown platform
#endif /* defined(PLATFORM) */

/**
 * Signed integral type that can contain a pointer.
 * This is a signed integral type that is the same size as a pointer.
 * NOTE: This type may be different sizes on different platforms.
 */
#if defined( __ccdoc__ )
typedef platform_dependent_type ABC_PTRINT_T;
#elif defined( ABC_USE_STDINT_H )
typedef intptr_t ABC_PTRINT_T;
#elif defined( LIN64 )
typedef long ABC_PTRINT_T;
#elif defined( NT64 )
typedef long long ABC_PTRINT_T;
#elif defined( NT ) || defined( LIN ) || defined( WIN32 )
typedef int ABC_PTRINT_T;
#else
#error unknown platform
#endif /* defined(PLATFORM) */

/**
 * 64-bit signed integral type.
 */
#if defined( __ccdoc__ )
typedef platform_dependent_type ABC_INT64_T;
#elif defined( ABC_USE_STDINT_H )
typedef int64_t ABC_INT64_T;
#elif defined( LIN64 )
typedef long ABC_INT64_T;
#elif defined( NT64 ) || defined( LIN )
typedef long long ABC_INT64_T;
#elif defined( WIN32 ) || defined( NT )
typedef signed __int64 ABC_INT64_T;
#else
#error unknown platform
#endif /* defined(PLATFORM) */

/**
 * 64-bit unsigned integral type.
 */
#if defined( __ccdoc__ )
typedef platform_dependent_type ABC_UINT64_T;
#elif defined( ABC_USE_STDINT_H )
typedef uint64_t ABC_UINT64_T;
#elif defined( LIN64 )
typedef unsigned long ABC_UINT64_T;
#elif defined( NT64 ) || defined( LIN )
typedef unsigned long long ABC_UINT64_T;
#elif defined( WIN32 ) || defined( NT )
typedef unsigned __int64 ABC_UINT64_T;
#else
#error unknown platform
#endif /* defined(PLATFORM) */

#ifdef LIN
#define ABC_CONST( number ) number##ULL
#else // LIN64 and windows
#define ABC_CONST( number ) number
#endif

typedef ABC_UINT64_T word;
typedef ABC_INT64_T iword;

typedef struct Abc_Frame_t_ Abc_Frame_t;
typedef struct Aig_Man_t_ Aig_Man_t;
typedef struct Abc_Ntk_t_ Abc_Ntk_t;
typedef struct Abc_Nam_t_ Abc_Nam_t;
typedef struct Abc_Cex_t_ Abc_Cex_t;

typedef struct Gia_Man_t_ Gia_Man_t;

typedef struct Vec_Ptr_t_ Vec_Ptr_t;
typedef struct Vec_Wec_t_ Vec_Wec_t;
typedef struct Vec_Int_t_ Vec_Int_t;
typedef struct Vec_Str_t_ Vec_Str_t;

typedef struct Mio_LibraryStruct_t_ Mio_Library_t;
typedef struct Mio_GateStruct_t_ Mio_Gate_t;
typedef struct Mio_PinStruct_t_ Mio_Pin_t;
typedef struct Mio_Cell_t_ Mio_Cell_t;
typedef enum
{
  MIO_PHASE_UNKNOWN,
  MIO_PHASE_INV,
  MIO_PHASE_NONINV
} Mio_PinPhase_t;

//////////////////////////////////////////////////////////////////////
/// MAIN FRAME
//////////////////////////////////////////////////////////////////////
void Abc_Start();
void Abc_Stop();

Abc_Ntk_t* Abc_FrameReadNtk( Abc_Frame_t* p );
void Abc_FrameRestart( Abc_Frame_t* p );
int Abc_FrameShowProgress( Abc_Frame_t* p );

void Abc_FrameSetGlobalFrame( Abc_Frame_t* p );
Abc_Frame_t* Abc_FrameGetGlobalFrame();
Abc_Frame_t* Abc_FrameReadGlobalFrame();

void Abc_FrameSetCurrentNetwork( Abc_Frame_t* p, Abc_Ntk_t* pNet );
void Abc_FrameSwapCurrentAndBackup( Abc_Frame_t* p );
void Abc_FrameReplaceCurrentNetwork( Abc_Frame_t* p, Abc_Ntk_t* pNet );
void Abc_FrameUnmapAllNetworks( Abc_Frame_t* p );
void Abc_FrameDeleteAllNetworks( Abc_Frame_t* p );

//////////////////////////////////////////////////////////////////////
/// UTILS
//////////////////////////////////////////////////////////////////////
char* Extra_UtilStrsav( const char* s );

//////////////////////////////////////////////////////////////////////
/// IO
//////////////////////////////////////////////////////////////////////
int IoCommandRead( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadAiger( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadBaf( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadBblif( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadBlif( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadBlifMv( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadBench( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadDsd( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadEdif( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadEqn( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadFins( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadInit( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadPla( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadPlaMo( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadTruth( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadCnf( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadVerilog( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadStatus( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadGig( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadJson( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandReadSF( Abc_Frame_t* pAbc, int argc, char** argv );

int IoCommandWrite( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteHie( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteAiger( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteAigerCex( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteBaf( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteBblif( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteBlif( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteEdgelist( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteBlifMv( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteBench( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteBook( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteCellNet( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteCnf( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteCnf2( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteCex( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteDot( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteEqn( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteGml( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteList( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWritePla( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteVerilog( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteSortCnf( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteTruth( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteTruths( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteStatus( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteSmv( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteJson( Abc_Frame_t* pAbc, int argc, char** argv );
int IoCommandWriteResub( Abc_Frame_t* pAbc, int argc, char** argv );

//////////////////////////////////////////////////////////////////////
/// PASSES
//////////////////////////////////////////////////////////////////////

int Abc_CommandPrintStats( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintExdc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintIo( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintLatch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintFanio( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintMffc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintFactor( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintLevel( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintSupport( Abc_Frame_t* pAbc, int argc, char** argv );
#ifdef ABC_USE_CUDD
int Abc_CommandPrintMint( Abc_Frame_t* pAbc, int argc, char** argv );
#endif
int Abc_CommandPrintSymms( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintUnate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintAuto( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintKMap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintGates( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintSharing( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintXCut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintDsd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintCone( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintMiter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintStatus( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPrintDelay( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandShow( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandShowBdd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandShowCut( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandCollapse( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSatClp( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandStrash( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBalance( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMuxStruct( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMulti( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRenode( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCleanup( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSweep( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFastExtract( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFxch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandEliminate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDisjoint( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSparsify( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandLutpack( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandLutmin( Abc_Frame_t* pAbc, int argc, char** argv );
// int Abc_CommandImfs                   ( Abc_Frame_t * pAbc, int argc, char ** argv );
int Abc_CommandMfs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMfs2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMfs3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMfse( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandLogicPush( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTrace( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandGlitch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSpeedup( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPowerdown( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAddBuffs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMerge( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestDec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestNpn( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestRPO( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestTruth( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRunSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRunEco( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRunGen( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRunTest( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandRewrite( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRefactor( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRestructure( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandResubstitute( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandResubUnate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandResubCore( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandResubCheck( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCascade( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExtract( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandVarMin( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFaultClasses( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExact( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmsStart( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmsStop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmsPs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMajExact( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTwoExact( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandLutExact( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAllExact( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestExact( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMajGen( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandOrchestrate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAIGAugmentation( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandLogic( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandComb( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMiter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMiter2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDemiter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandOrPos( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAndPos( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandZeroPo( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSwapPos( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRemovePo( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDropSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAddPi( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAppend( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPutOnTop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFrames( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDFrames( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBdd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandReorder( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBidec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandOrder( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMuxes( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCubes( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExpand( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSplitSop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExtSeqDcs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandReach( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCone( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandNode( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRange( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCof( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTopmost( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBottommost( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTopAnd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTrim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandShortNames( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMoveNames( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExdcFree( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExdcGet( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExdcSet( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCareSet( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandEspresso( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandGen( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandGenFsm( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCover( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDouble( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandInter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBb2Wb( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandOutdec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandNodeDup( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandWrap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestColor( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTest( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandQuaVar( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandQuaRel( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandQuaReach( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSenseInput( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandNpnLoad( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandNpnSave( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandSendAig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSendStatus( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandBackup( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRestore( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandMinisat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMinisimp( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandIStrash( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandICut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIRewrite( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDRewrite( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDRefactor( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDc2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDChoice( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDrwsat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIRewriteSeq( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIResyn( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandISat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIFraig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDFraig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCSweep( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbSec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSimSec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandMatch( Abc_Frame_t* pAbc, int argc, char** argv );
// int Abc_CommandHaig                   ( Abc_Frame_t * pAbc, int argc, char ** argv );
int Abc_CommandQbf( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandFraig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFraigTrust( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFraigStore( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFraigRestore( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFraigClean( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFraigSweep( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFraigDress( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDumpEquiv( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandRecStart3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRecStop3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRecPs3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRecAdd3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRecDump3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRecMerge3( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandMap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAmap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPhaseMap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandUnmap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAttach( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSuperChoice( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSuperChoiceLut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTimeScale( Abc_Frame_t* pAbc, int argc, char** argv );

// int Abc_CommandFpga                   ( Abc_Frame_t * pAbc, int argc, char ** argv );
// int Abc_CommandFpgaFast               ( Abc_Frame_t * pAbc, int argc, char ** argv );
int Abc_CommandIf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIfif( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandDsdSave( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDsdLoad( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDsdFree( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDsdPs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDsdMatch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDsdMerge( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDsdFilter( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandScut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandInit( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandZero( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandUndc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandOneHot( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPipe( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSeq( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandUnseq( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandRetime( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDRetime( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFlowRetime( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCRetime( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSeqFpga( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSeqMap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSeqSweep( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSeqSweep2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestSeqSweep( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestScorr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandLcorr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSeqCleanup( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCycle( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandXsim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSim3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDarPhase( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSynch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandClockGate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandExtWin( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandInsWin( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSymFun( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPermute( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandUnpermute( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCubeEnum( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPathEnum( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFunEnum( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandCec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDCec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDSec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandXSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSatoko( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Satoko( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sat3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Kissat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandDebug( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandEco( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmc2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmc3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBmcInter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIndcut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandEnlarge( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTempor( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandInduction( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandConstr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandUnfold( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFold( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandUnfold2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandFold2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBm( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBm2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandSaucy( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTestCex( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandPdr( Abc_Frame_t* pAbc, int argc, char** argv );
#ifdef ABC_USE_CUDD
int Abc_CommandReconcile( Abc_Frame_t* pAbc, int argc, char** argv );
#endif
int Abc_CommandCexSave( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCexLoad( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCexCut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCexMerge( Abc_Frame_t* pAbc, int argc, char** argv );
// int Abc_CommandCexMin                 ( Abc_Frame_t * pAbc, int argc, char ** argv );
int Abc_CommandDualRail( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandBlockPo( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandIso( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandTraceStart( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandTraceCheck( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandAbcSave( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbcLoad( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandAbc9Get( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Put( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MoveNames( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Save( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Save2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SaveAig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Load( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Load2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9LoadAig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Read( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReadBlif( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReadCBlif( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReadStg( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReadVer( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9WriteVer( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Write( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9WriteLut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Ps( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PFan( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Pms( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PSig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Status( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MuxProfile( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MuxPos( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MuxStr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MuxDec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PrintTruth( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Unate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Rex2Gia( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9RexWalk( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Show( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SetRegNum( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Strash( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Topand( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Add1Hot( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Cof( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Trim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Dfs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sim2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sim3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MLGen( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MLTest( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Iwls21Test( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReadSim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9WriteSim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PrintSim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GenSim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SimRsb( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Resim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SpecI( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Equiv( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Equiv2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Equiv3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Semi( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Times( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Frames( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Retime( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Enable( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Dc2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Dsd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Bidec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Shrink( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Fx( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Extract( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Balance( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9BalanceLut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Resub( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Reshape( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Syn2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Syn3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Syn4( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Synch2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9False( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Miter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Miter2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Append( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Scl( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Lcorr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Scorr( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Choice( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SatEnum( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Fraig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9CFraig( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Srm( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Srm2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Filter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Reduce( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9EquivMark( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9EquivFilter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Cec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ICec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Verify( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sweep( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Force( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Embed( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sopb( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Dsdb( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Flow( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Flow2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Flow3( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9If( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Iff( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Iiff( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9If2( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Sif( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Jf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Kf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Lf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Mf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Nf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Of( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Pack( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Edge( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SatLut( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9LNetRead( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9LNetSim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9LNetEval( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9LNetOpt( Abc_Frame_t* pAbc, int argc, char** argv );
// #ifndef _WIN32
int Abc_CommandAbc9Ttopt( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Transduction( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9TranStoch( Abc_Frame_t* pAbc, int argc, char** argv );
// #endif
int Abc_CommandAbc9LNetMap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Unmap( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Struct( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Trace( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Speedup( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Era( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Dch( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Rpm( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9BackReach( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Posplit( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Permute( Abc_Frame_t* pAbc, int argc, char** argv );
#ifdef ABC_USE_CUDD
int Abc_CommandAbc9ReachM( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReachP( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReachN( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ReachY( Abc_Frame_t* pAbc, int argc, char** argv );
#endif
int Abc_CommandAbc9Undo( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Mesh( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Iso( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9IsoNpn( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9IsoSt( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Compare( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9RevEng( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Uif( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9CexInfo( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Cycle( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Cone( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Slice( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PoPart( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GroupProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9MultiProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SplitProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SProve( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SplitSat( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Bmc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SBmc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ChainBmc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9BCore( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ICheck( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SatTest( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9FFTest( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Qbf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9QVar( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GenQbf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9HomoQbf( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SatFx( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SatClp( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Inse( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Maxi( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Bmci( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PoXsim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Demiter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Fadds( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ATree( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Polyn( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Acec( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Anorm( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Decla( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Esop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Exorcism( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Mfs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Mfsd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9DeepSyn( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9SatSyn( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9StochSyn( Abc_Frame_t* pAbc, int argc, char** argv );
// int Abc_CommandAbc9PoPart2            ( Abc_Frame_t * pAbc, int argc, char ** argv );
// int Abc_CommandAbc9CexCut             ( Abc_Frame_t * pAbc, int argc, char ** argv );
// int Abc_CommandAbc9CexMerge           ( Abc_Frame_t * pAbc, int argc, char ** argv );
// int Abc_CommandAbc9CexMin             ( Abc_Frame_t * pAbc, int argc, char ** argv );

int Abc_CommandAbc9AbsCreate( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9AbsDerive( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9AbsRefine( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GlaDerive( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GlaRefine( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GlaShrink( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Gla( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Vta( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Vta2Gla( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Gla2Vta( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Fla2Gla( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Gla2Fla( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandAbc9Gen( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Cfs( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9ProdAdd( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9AddFlop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9BMiter( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GenHie( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9PutOnTop( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9BRecover( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9StrEco( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GenCex( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Odc( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9GenRel( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbc9Window( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandAbc9Test( Abc_Frame_t* pAbc, int argc, char** argv );

int Abc_CommandAbcLivenessToSafety( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbcLivenessToSafetySim( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandAbcLivenessToSafetyWithLTL( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandCS_kLiveness( Abc_Frame_t* pAbc, int argc, char** argv );
int Abc_CommandNChooseK( Abc_Frame_t* pAbc, int argc, char** argv );

Aig_Man_t* Abc_NtkToDar( Abc_Ntk_t* pNtk, int fExors, int fRegisters );
Abc_Ntk_t* Abc_NtkFromAigPhase( Aig_Man_t* pMan );

Vec_Ptr_t* Abc_NtkCollectCiNames( Abc_Ntk_t* pNtk );
Vec_Ptr_t* Abc_NtkCollectCoNames( Abc_Ntk_t* pNtk );

//////////////////////////////////////////////////////////////////////
/// STANDARD CELL LIBRARY
//////////////////////////////////////////////////////////////////////
char* Mio_LibraryReadName( Mio_Library_t* pLib );
int Mio_LibraryReadGateNum( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadGates( Mio_Library_t* pLib );
Mio_Gate_t** Mio_LibraryReadGateArray( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadGateById( Mio_Library_t* pLib, int iD );
Mio_Gate_t* Mio_LibraryReadGateByName( Mio_Library_t* pLib, char* pName, char* pOutName );
char* Mio_LibraryReadSopByName( Mio_Library_t* pLib, char* pName );
Mio_Gate_t* Mio_LibraryReadGateByTruth( Mio_Library_t* pLib, word t );
Mio_Gate_t* Mio_LibraryReadConst0( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadConst1( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadNand2( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadAnd2( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadNor2( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadOr2( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadBuf( Mio_Library_t* pLib );
Mio_Gate_t* Mio_LibraryReadInv( Mio_Library_t* pLib );
float Mio_LibraryReadDelayInvRise( Mio_Library_t* pLib );
float Mio_LibraryReadDelayInvFall( Mio_Library_t* pLib );
float Mio_LibraryReadDelayInvMax( Mio_Library_t* pLib );
float Mio_LibraryReadDelayNand2Rise( Mio_Library_t* pLib );
float Mio_LibraryReadDelayNand2Fall( Mio_Library_t* pLib );
float Mio_LibraryReadDelayNand2Max( Mio_Library_t* pLib );
float Mio_LibraryReadDelayAnd2Max( Mio_Library_t* pLib );
float Mio_LibraryReadDelayAigNode( Mio_Library_t* pLib );
float Mio_LibraryReadAreaInv( Mio_Library_t* pLib );
float Mio_LibraryReadAreaBuf( Mio_Library_t* pLib );
float Mio_LibraryReadAreaNand2( Mio_Library_t* pLib );
int Mio_LibraryReadGateNameMax( Mio_Library_t* pLib );
void Mio_LibrarySetName( Mio_Library_t* pLib, char* pName );
char* Mio_GateReadName( Mio_Gate_t* pGate );
char* Mio_GateReadOutName( Mio_Gate_t* pGate );
double Mio_GateReadArea( Mio_Gate_t* pGate );
char* Mio_GateReadForm( Mio_Gate_t* pGate );
Mio_Pin_t* Mio_GateReadPins( Mio_Gate_t* pGate );
Mio_Library_t* Mio_GateReadLib( Mio_Gate_t* pGate );
Mio_Gate_t* Mio_GateReadNext( Mio_Gate_t* pGate );
Mio_Gate_t* Mio_GateReadTwin( Mio_Gate_t* pGate );
int Mio_GateReadPinNum( Mio_Gate_t* pGate );
double Mio_GateReadDelayMax( Mio_Gate_t* pGate );
char* Mio_GateReadSop( Mio_Gate_t* pGate );
Vec_Int_t* Mio_GateReadExpr( Mio_Gate_t* pGate );
word Mio_GateReadTruth( Mio_Gate_t* pGate );
word* Mio_GateReadTruthP( Mio_Gate_t* pGate );
int Mio_GateReadValue( Mio_Gate_t* pGate );
int Mio_GateReadCell( Mio_Gate_t* pGate );
int Mio_GateReadProfile( Mio_Gate_t* pGate );
int Mio_GateReadProfile2( Mio_Gate_t* pGate );
char* Mio_GateReadPinName( Mio_Gate_t* pGate, int iPin );
float Mio_GateReadPinDelay( Mio_Gate_t* pGate, int iPin );
void Mio_GateSetValue( Mio_Gate_t* pGate, int Value );
void Mio_GateSetCell( Mio_Gate_t* pGate, int Cell );
void Mio_GateSetProfile( Mio_Gate_t* pGate, int Prof );
void Mio_GateSetProfile2( Mio_Gate_t* pGate, int Prof );
void Mio_GateIncProfile2( Mio_Gate_t* pGate );
void Mio_GateDecProfile2( Mio_Gate_t* pGate );
void Mio_GateAddToProfile( Mio_Gate_t* pGate, int Prof );
void Mio_GateAddToProfile2( Mio_Gate_t* pGate, int Prof );
int Mio_GateIsInv( Mio_Gate_t* pGate );
char* Mio_PinReadName( Mio_Pin_t* pPin );
Mio_PinPhase_t Mio_PinReadPhase( Mio_Pin_t* pPin );
double Mio_PinReadInputLoad( Mio_Pin_t* pPin );
double Mio_PinReadMaxLoad( Mio_Pin_t* pPin );
double Mio_PinReadDelayBlockRise( Mio_Pin_t* pPin );
double Mio_PinReadDelayFanoutRise( Mio_Pin_t* pPin );
double Mio_PinReadDelayBlockFall( Mio_Pin_t* pPin );
double Mio_PinReadDelayFanoutFall( Mio_Pin_t* pPin );
double Mio_PinReadDelayBlockMax( Mio_Pin_t* pPin );
Mio_Pin_t* Mio_PinReadNext( Mio_Pin_t* pPin );

//////////////////////////////////////////////////////////////////////
/// FPGA
//////////////////////////////////////////////////////////////////////
void Io_WriteVerilogLut( Abc_Ntk_t* pNtk, char* pFileName, int nLutSize, int fFixed, int fNoModules );

//////////////////////////////////////////////////////////////////////
/// stats
//////////////////////////////////////////////////////////////////////
float Abc_NtkGetArea( Abc_Ntk_t* pNtk );

} // namespace ABC_NAMESPACE

namespace hedals{
int hedals_main(int argc, char** argv);
}
namespace resubals{
int app_resub_main(int argc, char** argv);
}
namespace mecals{
int mecals_main(int argc, char** argv);
}
namespace vacsem{
int c2c_main(int argc, char** argvs);
}
int sim_sharp_sat_main(int argc, char** argvs);

namespace alfans{
int main(int argc, char** argv);
}
#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/abc/abc.h"
#include "misc/vec/vec.h"
#include "aig/hop/hop.h"