/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and wce parameters
***/
// MAE% = 9.00 %
// MAE = 737 
// WCE% = 31.31 %
// WCE = 2565 
// WCRE% = 712.50 %
// EP% = 96.45 %
// MRE% = 70.86 %
// MSE = 911969 
// PDK45_PWR = 0.00089 mW
// PDK45_AREA = 7.0 um2
// PDK45_DELAY = 0.04 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t mul8x5u_18L(const uint64_t A /* 8-bit unsigned operand */, const uint64_t B /* 5-bit unsigned operand */)
{
   uint64_t dout_48, dout_52, dout_168;
   uint64_t O;

   dout_48=((A >> 6)&1)&((B >> 2)&1);
   dout_52=((A >> 7)&1)&((B >> 4)&1);
   dout_168=((B >> 3)&1)&((A >> 5)&1);

   O = 0;
   O |= (0&1) << 0;
   O |= (0&1) << 1;
   O |= (0&1) << 2;
   O |= (dout_52&1) << 3;
   O |= (0&1) << 4;
   O |= (dout_48&1) << 5;
   O |= (0&1) << 6;
   O |= (0&1) << 7;
   O |= (0&1) << 8;
   O |= (0&1) << 9;
   O |= (dout_168&1) << 10;
   O |= (dout_48&1) << 11;
   O |= (dout_52&1) << 12;
   return O;
}
