/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mre parameters
***/
// MAE% = 0.94 %
// MAE = 77 
// WCE% = 3.77 %
// WCE = 309 
// WCRE% = 100.00 %
// EP% = 95.37 %
// MRE% = 15.13 %
// MSE = 9467 
// PDK45_PWR = 0.062 mW
// PDK45_AREA = 174.6 um2
// PDK45_DELAY = 0.76 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t mul8x5u_3LT(const uint64_t A,const uint64_t B)
{
   uint64_t dout_26, dout_27, dout_28, dout_61, dout_62, dout_68, dout_69, dout_70, dout_98, dout_99, dout_100, dout_101, dout_102, dout_103, dout_104, dout_105, dout_106, dout_107, dout_112, dout_113, dout_114, dout_115, dout_133, dout_134, dout_138, dout_139, dout_140, dout_141, dout_142, dout_143, dout_144, dout_145, dout_146, dout_147, dout_148, dout_149, dout_150, dout_151, dout_152, dout_156, dout_157, dout_158, dout_159, dout_160, dout_173, dout_174, dout_178, dout_179, dout_180, dout_181, dout_182, dout_183, dout_184, dout_185, dout_186, dout_187, dout_188, dout_189, dout_190, dout_191, dout_192, dout_193, dout_194, dout_195, dout_196, dout_197;
   uint64_t O;

   dout_26=((B >> 0)&1)&((A >> 7)&1);
   dout_27=((A >> 6)&1)&((B >> 1)&1);
   dout_28=((A >> 7)&1)&((B >> 1)&1);
   dout_61=dout_26&((B >> 1)&1);
   dout_62=dout_26^dout_28;
   dout_68=((A >> 5)&1)&((B >> 2)&1);
   dout_69=((A >> 6)&1)&((B >> 2)&1);
   dout_70=((A >> 7)&1)&((B >> 2)&1);
   dout_98=dout_62^dout_69;
   dout_99=dout_62&dout_69;
   dout_100=dout_98&dout_68;
   dout_101=dout_98^dout_68;
   dout_102=dout_99|dout_100;
   dout_103=dout_61^dout_70;
   dout_104=dout_61&((B >> 2)&1);
   dout_105=((A >> 7)&1)&dout_102;
   dout_106=dout_103^dout_102;
   dout_107=dout_104|dout_105;
   dout_112=((A >> 4)&1)&((B >> 3)&1);
   dout_113=((A >> 5)&1)&((B >> 3)&1);
   dout_114=((A >> 6)&1)&((B >> 3)&1);
   dout_115=((A >> 7)&1)&((B >> 3)&1);
   dout_133=dout_27|dout_112;
   dout_134=dout_27&dout_112;
   dout_138=dout_101^dout_113;
   dout_139=dout_101&dout_113;
   dout_140=dout_138&dout_134;
   dout_141=dout_138^dout_134;
   dout_142=dout_139|dout_140;
   dout_143=dout_106^dout_114;
   dout_144=dout_106&dout_114;
   dout_145=dout_143&dout_142;
   dout_146=dout_143^dout_142;
   dout_147=dout_144|dout_145;
   dout_148=dout_107^dout_115;
   dout_149=dout_107&((B >> 3)&1);
   dout_150=dout_115&dout_147;
   dout_151=dout_148^dout_147;
   dout_152=dout_149|dout_150;
   dout_156=((A >> 3)&1)&((B >> 4)&1);
   dout_157=((A >> 4)&1)&((B >> 4)&1);
   dout_158=((A >> 5)&1)&((B >> 4)&1);
   dout_159=((A >> 6)&1)&((B >> 4)&1);
   dout_160=((A >> 7)&1)&((B >> 4)&1);
   dout_173=dout_133|dout_156;
   dout_174=dout_133&dout_156;
   dout_178=dout_141^dout_157;
   dout_179=dout_141&dout_157;
   dout_180=dout_178&dout_174;
   dout_181=dout_178^dout_174;
   dout_182=dout_179|dout_180;
   dout_183=dout_146^dout_158;
   dout_184=dout_146&dout_158;
   dout_185=dout_183&dout_182;
   dout_186=dout_183^dout_182;
   dout_187=dout_184|dout_185;
   dout_188=dout_151^dout_159;
   dout_189=dout_151&dout_159;
   dout_190=dout_188&dout_187;
   dout_191=dout_188^dout_187;
   dout_192=dout_189|dout_190;
   dout_193=dout_152^dout_160;
   dout_194=dout_152&((B >> 4)&1);
   dout_195=((A >> 7)&1)&dout_192;
   dout_196=dout_193^dout_192;
   dout_197=dout_194|dout_195;

   O = 0;
   O |= (dout_152&1) << 0;
   O |= (dout_61&1) << 1;
   O |= (dout_70&1) << 2;
   O |= (dout_27&1) << 3;
   O |= (dout_105&1) << 4;
   O |= (dout_160&1) << 5;
   O |= (dout_173&1) << 6;
   O |= (dout_173&1) << 7;
   O |= (dout_181&1) << 8;
   O |= (dout_186&1) << 9;
   O |= (dout_191&1) << 10;
   O |= (dout_196&1) << 11;
   O |= (dout_197&1) << 12;
   return O;
}
