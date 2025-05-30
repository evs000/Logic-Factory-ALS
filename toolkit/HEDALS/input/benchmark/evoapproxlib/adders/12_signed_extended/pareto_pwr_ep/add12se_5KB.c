/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and ep parameters
***/
// MAE% = 0.02 %
// MAE = 0.8 
// WCE% = 0.049 %
// WCE = 2.0 
// WCRE% = 200.00 %
// EP% = 62.50 %
// MRE% = 0.28 %
// MSE = 1.0 
// PDK45_PWR = 0.048 mW
// PDK45_AREA = 97.1 um2
// PDK45_DELAY = 0.87 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t add12se_5KB(const uint64_t B,const uint64_t A)
{
   uint64_t dout_25, dout_27, dout_31, dout_32, dout_33, dout_34, dout_35, dout_36, dout_37, dout_38, dout_39, dout_40, dout_41, dout_42, dout_43, dout_44, dout_45, dout_46, dout_47, dout_48, dout_49, dout_50, dout_51, dout_52, dout_53, dout_54, dout_55, dout_56, dout_57, dout_58, dout_59, dout_60, dout_61, dout_62, dout_63, dout_64, dout_65, dout_66, dout_67, dout_68, dout_69, dout_70, dout_71, dout_72, dout_73, dout_74, dout_75, dout_76, dout_77, dout_78, dout_79, dout_80, dout_81, dout_82;
   uint64_t O;

   dout_25=(((A >> 1)&1)&((B >> 0)&1))^0xFFFFFFFFFFFFFFFFU;
   dout_27=((A >> 1)&1)&((B >> 0)&1);
   dout_31=((A >> 2)&1)^((B >> 2)&1);
   dout_32=((A >> 2)&1)&((B >> 2)&1);
   dout_33=dout_31&dout_27;
   dout_34=dout_31^dout_27;
   dout_35=dout_32|dout_33;
   dout_36=((A >> 3)&1)^((B >> 3)&1);
   dout_37=((A >> 3)&1)&((B >> 3)&1);
   dout_38=dout_36&dout_35;
   dout_39=dout_36^dout_35;
   dout_40=dout_37|dout_38;
   dout_41=((A >> 4)&1)^((B >> 4)&1);
   dout_42=((A >> 4)&1)&((B >> 4)&1);
   dout_43=dout_41&dout_40;
   dout_44=dout_41^dout_40;
   dout_45=dout_42|dout_43;
   dout_46=((A >> 5)&1)^((B >> 5)&1);
   dout_47=((A >> 5)&1)&((B >> 5)&1);
   dout_48=dout_46&dout_45;
   dout_49=dout_46^dout_45;
   dout_50=dout_47|dout_48;
   dout_51=((A >> 6)&1)^((B >> 6)&1);
   dout_52=((A >> 6)&1)&((B >> 6)&1);
   dout_53=dout_51&dout_50;
   dout_54=dout_51^dout_50;
   dout_55=dout_52|dout_53;
   dout_56=((A >> 7)&1)^((B >> 7)&1);
   dout_57=((A >> 7)&1)&((B >> 7)&1);
   dout_58=dout_56&dout_55;
   dout_59=dout_56^dout_55;
   dout_60=dout_57|dout_58;
   dout_61=((A >> 8)&1)^((B >> 8)&1);
   dout_62=((A >> 8)&1)&((B >> 8)&1);
   dout_63=dout_61&dout_60;
   dout_64=dout_61^dout_60;
   dout_65=dout_62|dout_63;
   dout_66=((A >> 9)&1)^((B >> 9)&1);
   dout_67=((A >> 9)&1)&((B >> 9)&1);
   dout_68=dout_66&dout_65;
   dout_69=dout_66^dout_65;
   dout_70=dout_67|dout_68;
   dout_71=((A >> 10)&1)^((B >> 10)&1);
   dout_72=((A >> 10)&1)&((B >> 10)&1);
   dout_73=dout_71&dout_70;
   dout_74=dout_71^dout_70;
   dout_75=dout_72|dout_73;
   dout_76=((A >> 11)&1)^((B >> 11)&1);
   dout_77=((A >> 11)&1)&((B >> 11)&1);
   dout_78=dout_76&dout_75;
   dout_79=dout_76^dout_75;
   dout_80=dout_77|dout_78;
   dout_81=((A >> 11)&1)^((B >> 11)&1);
   dout_82=dout_81^dout_80;

   O = 0;
   O |= (((B >> 1)&1)&1) << 0;
   O |= (dout_25&1) << 1;
   O |= (dout_34&1) << 2;
   O |= (dout_39&1) << 3;
   O |= (dout_44&1) << 4;
   O |= (dout_49&1) << 5;
   O |= (dout_54&1) << 6;
   O |= (dout_59&1) << 7;
   O |= (dout_64&1) << 8;
   O |= (dout_69&1) << 9;
   O |= (dout_74&1) << 10;
   O |= (dout_79&1) << 11;
   O |= (dout_82&1) << 12;
   return O;
}
