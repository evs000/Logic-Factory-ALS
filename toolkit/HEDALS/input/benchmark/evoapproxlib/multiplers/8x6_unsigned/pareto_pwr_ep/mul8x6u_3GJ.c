/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and ep parameters
***/
// MAE% = 0.0045 %
// MAE = 0.74 
// WCE% = 0.012 %
// WCE = 2.0 
// WCRE% = 100.00 %
// EP% = 37.11 %
// MRE% = 0.16 %
// MSE = 1.5 
// PDK45_PWR = 0.255 mW
// PDK45_AREA = 493.7 um2
// PDK45_DELAY = 1.58 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t mul8x6u_3GJ(const uint64_t A,const uint64_t B)
{
   uint64_t dout_14, dout_16, dout_17, dout_18, dout_19, dout_20, dout_21, dout_22, dout_23, dout_24, dout_25, dout_26, dout_27, dout_28, dout_29, dout_30, dout_32, dout_33, dout_35, dout_37, dout_38, dout_39, dout_40, dout_41, dout_42, dout_43, dout_44, dout_45, dout_46, dout_47, dout_48, dout_49, dout_50, dout_51, dout_52, dout_53, dout_54, dout_55, dout_56, dout_57, dout_58, dout_59, dout_60, dout_61, dout_62, dout_63, dout_64, dout_65, dout_66, dout_67, dout_68, dout_69, dout_70, dout_71, dout_72, dout_73, dout_74, dout_75, dout_76, dout_77, dout_78, dout_79, dout_80, dout_81, dout_82, dout_83, dout_84, dout_85, dout_86, dout_87, dout_88, dout_89, dout_90, dout_91, dout_92, dout_93, dout_94, dout_95, dout_96, dout_97, dout_98, dout_99, dout_100, dout_101, dout_102, dout_103, dout_104, dout_105, dout_106, dout_107, dout_108, dout_109, dout_110, dout_111, dout_112, dout_113, dout_114, dout_115, dout_116, dout_117, dout_118, dout_119, dout_120, dout_121, dout_122, dout_123, dout_124, dout_125, dout_126, dout_127, dout_128, dout_129, dout_130, dout_131, dout_132, dout_133, dout_134, dout_135, dout_136, dout_137, dout_138, dout_139, dout_140, dout_141, dout_142, dout_143, dout_144, dout_145, dout_146, dout_147, dout_148, dout_149, dout_150, dout_151, dout_152, dout_153, dout_154, dout_155, dout_156, dout_157, dout_158, dout_159, dout_160, dout_161, dout_162, dout_163, dout_164, dout_165, dout_166, dout_167, dout_168, dout_169, dout_170, dout_171, dout_172, dout_173, dout_174, dout_175, dout_176, dout_177, dout_178, dout_179, dout_180, dout_181, dout_182, dout_183, dout_184, dout_185, dout_186, dout_187, dout_188, dout_189, dout_190, dout_191, dout_192, dout_193, dout_194, dout_195, dout_196, dout_197, dout_198, dout_199, dout_200, dout_201, dout_202, dout_203, dout_204, dout_205, dout_206, dout_207, dout_208, dout_209, dout_210, dout_211, dout_212, dout_213, dout_214, dout_215, dout_216, dout_217, dout_218, dout_219, dout_220, dout_221, dout_222, dout_223, dout_224, dout_225, dout_226, dout_227, dout_228, dout_229, dout_230, dout_231, dout_232, dout_233, dout_234, dout_235, dout_236, dout_237, dout_238, dout_239, dout_240, dout_241, dout_242, dout_243;
   uint64_t O;

   dout_14=((A >> 0)&1)&((B >> 0)&1);
   dout_16=((A >> 2)&1)&((B >> 0)&1);
   dout_17=((A >> 3)&1)&((B >> 0)&1);
   dout_18=((A >> 4)&1)&((B >> 0)&1);
   dout_19=((A >> 5)&1)&((B >> 0)&1);
   dout_20=((A >> 6)&1)&((B >> 0)&1);
   dout_21=((A >> 7)&1)&((B >> 0)&1);
   dout_22=((B >> 0)&1)&((B >> 1)&1);
   dout_23=((A >> 1)&1)&((B >> 1)&1);
   dout_24=((A >> 2)&1)&((B >> 1)&1);
   dout_25=((A >> 3)&1)&((B >> 1)&1);
   dout_26=((A >> 4)&1)&((B >> 1)&1);
   dout_27=((A >> 5)&1)&((B >> 1)&1);
   dout_28=((A >> 6)&1)&((B >> 1)&1);
   dout_29=((A >> 7)&1)&((B >> 1)&1);
   dout_30=((A >> 1)&1)&dout_22;
   dout_32=dout_16^dout_23;
   dout_33=((B >> 0)&1)&dout_23;
   dout_35=dout_32^dout_30;
   dout_37=dout_17^dout_24;
   dout_38=dout_17&dout_24;
   dout_39=dout_37&dout_33;
   dout_40=dout_37^dout_33;
   dout_41=dout_38|dout_39;
   dout_42=dout_18^dout_25;
   dout_43=dout_18&dout_25;
   dout_44=dout_42&dout_41;
   dout_45=dout_42^dout_41;
   dout_46=dout_43|dout_44;
   dout_47=dout_19^dout_26;
   dout_48=dout_19&dout_26;
   dout_49=dout_47&dout_46;
   dout_50=dout_47^dout_46;
   dout_51=dout_48|dout_49;
   dout_52=dout_20^dout_27;
   dout_53=dout_20&dout_27;
   dout_54=dout_52&dout_51;
   dout_55=dout_52^dout_51;
   dout_56=dout_53|dout_54;
   dout_57=dout_21^dout_28;
   dout_58=dout_21&dout_28;
   dout_59=dout_57&dout_56;
   dout_60=dout_57^dout_56;
   dout_61=dout_58|dout_59;
   dout_62=dout_61&dout_29;
   dout_63=dout_61^dout_29;
   dout_64=((A >> 0)&1)&((B >> 2)&1);
   dout_65=((A >> 1)&1)&((B >> 2)&1);
   dout_66=((A >> 2)&1)&((B >> 2)&1);
   dout_67=((A >> 3)&1)&((B >> 2)&1);
   dout_68=((A >> 4)&1)&((B >> 2)&1);
   dout_69=((A >> 5)&1)&((B >> 2)&1);
   dout_70=((A >> 6)&1)&((B >> 2)&1);
   dout_71=((A >> 7)&1)&((B >> 2)&1);
   dout_72=dout_35&dout_64;
   dout_73=dout_35^dout_64;
   dout_74=dout_40^dout_65;
   dout_75=dout_40&dout_65;
   dout_76=dout_74&dout_72;
   dout_77=dout_74^dout_72;
   dout_78=dout_75|dout_76;
   dout_79=dout_45^dout_66;
   dout_80=dout_45&dout_66;
   dout_81=dout_79&dout_78;
   dout_82=dout_79^dout_78;
   dout_83=dout_80|dout_81;
   dout_84=dout_50^dout_67;
   dout_85=dout_50&dout_67;
   dout_86=dout_84&dout_83;
   dout_87=dout_84^dout_83;
   dout_88=dout_85|dout_86;
   dout_89=dout_55^dout_68;
   dout_90=dout_55&dout_68;
   dout_91=dout_89&dout_88;
   dout_92=dout_89^dout_88;
   dout_93=dout_90|dout_91;
   dout_94=dout_60^dout_69;
   dout_95=dout_60&dout_69;
   dout_96=dout_94&dout_93;
   dout_97=dout_94^dout_93;
   dout_98=dout_95|dout_96;
   dout_99=dout_63^dout_70;
   dout_100=dout_63&dout_70;
   dout_101=dout_99&dout_98;
   dout_102=dout_99^dout_98;
   dout_103=dout_100|dout_101;
   dout_104=dout_62^dout_71;
   dout_105=dout_62&((B >> 2)&1);
   dout_106=((A >> 7)&1)&dout_103;
   dout_107=dout_104^dout_103;
   dout_108=dout_105|dout_106;
   dout_109=((A >> 0)&1)&((B >> 3)&1);
   dout_110=((A >> 1)&1)&((B >> 3)&1);
   dout_111=((A >> 2)&1)&((B >> 3)&1);
   dout_112=((A >> 3)&1)&((B >> 3)&1);
   dout_113=((A >> 4)&1)&((B >> 3)&1);
   dout_114=((A >> 5)&1)&((B >> 3)&1);
   dout_115=((A >> 6)&1)&((B >> 3)&1);
   dout_116=((A >> 7)&1)&((B >> 3)&1);
   dout_117=dout_77&dout_109;
   dout_118=dout_77^dout_109;
   dout_119=dout_82^dout_110;
   dout_120=dout_82&dout_110;
   dout_121=dout_119&dout_117;
   dout_122=dout_119^dout_117;
   dout_123=dout_120|dout_121;
   dout_124=dout_87^dout_111;
   dout_125=dout_87&dout_111;
   dout_126=dout_124&dout_123;
   dout_127=dout_124^dout_123;
   dout_128=dout_125|dout_126;
   dout_129=dout_92^dout_112;
   dout_130=dout_92&dout_112;
   dout_131=dout_129&dout_128;
   dout_132=dout_129^dout_128;
   dout_133=dout_130|dout_131;
   dout_134=dout_97^dout_113;
   dout_135=dout_97&dout_113;
   dout_136=dout_134&dout_133;
   dout_137=dout_134^dout_133;
   dout_138=dout_135|dout_136;
   dout_139=dout_102^dout_114;
   dout_140=dout_102&dout_114;
   dout_141=dout_139&dout_138;
   dout_142=dout_139^dout_138;
   dout_143=dout_140|dout_141;
   dout_144=dout_107^dout_115;
   dout_145=dout_107&dout_115;
   dout_146=dout_144&dout_143;
   dout_147=dout_144^dout_143;
   dout_148=dout_145|dout_146;
   dout_149=dout_108^dout_116;
   dout_150=dout_108&((B >> 3)&1);
   dout_151=dout_149&dout_148;
   dout_152=dout_149^dout_148;
   dout_153=dout_150|dout_151;
   dout_154=((A >> 0)&1)&((B >> 4)&1);
   dout_155=((A >> 1)&1)&((B >> 4)&1);
   dout_156=((A >> 2)&1)&((B >> 4)&1);
   dout_157=((A >> 3)&1)&((B >> 4)&1);
   dout_158=((A >> 4)&1)&((B >> 4)&1);
   dout_159=((A >> 5)&1)&((B >> 4)&1);
   dout_160=((A >> 6)&1)&((B >> 4)&1);
   dout_161=((A >> 7)&1)&((B >> 4)&1);
   dout_162=dout_122&dout_154;
   dout_163=dout_122^dout_154;
   dout_164=dout_127^dout_155;
   dout_165=dout_127&dout_155;
   dout_166=dout_164&dout_162;
   dout_167=dout_164^dout_162;
   dout_168=dout_165|dout_166;
   dout_169=dout_132^dout_156;
   dout_170=dout_132&dout_156;
   dout_171=dout_169&dout_168;
   dout_172=dout_169^dout_168;
   dout_173=dout_170|dout_171;
   dout_174=dout_137^dout_157;
   dout_175=dout_137&dout_157;
   dout_176=dout_174&dout_173;
   dout_177=dout_174^dout_173;
   dout_178=dout_175|dout_176;
   dout_179=dout_142^dout_158;
   dout_180=dout_142&dout_158;
   dout_181=dout_179&dout_178;
   dout_182=dout_179^dout_178;
   dout_183=dout_180|dout_181;
   dout_184=dout_147^dout_159;
   dout_185=dout_147&dout_159;
   dout_186=dout_184&dout_183;
   dout_187=dout_184^dout_183;
   dout_188=dout_185|dout_186;
   dout_189=dout_152^dout_160;
   dout_190=dout_152&dout_160;
   dout_191=dout_189&dout_188;
   dout_192=dout_189^dout_188;
   dout_193=dout_190|dout_191;
   dout_194=dout_153^dout_161;
   dout_195=dout_153&((B >> 4)&1);
   dout_196=dout_161&dout_193;
   dout_197=dout_194^dout_193;
   dout_198=dout_195|dout_196;
   dout_199=((A >> 0)&1)&((B >> 5)&1);
   dout_200=((A >> 1)&1)&((B >> 5)&1);
   dout_201=((A >> 2)&1)&((B >> 5)&1);
   dout_202=((A >> 3)&1)&((B >> 5)&1);
   dout_203=((A >> 4)&1)&((B >> 5)&1);
   dout_204=((A >> 5)&1)&((B >> 5)&1);
   dout_205=((A >> 6)&1)&((B >> 5)&1);
   dout_206=((A >> 7)&1)&((B >> 5)&1);
   dout_207=dout_167&dout_199;
   dout_208=dout_167^dout_199;
   dout_209=dout_172^dout_200;
   dout_210=dout_172&dout_200;
   dout_211=dout_209&dout_207;
   dout_212=dout_209^dout_207;
   dout_213=dout_210|dout_211;
   dout_214=dout_177^dout_201;
   dout_215=dout_177&dout_201;
   dout_216=dout_214&dout_213;
   dout_217=dout_214^dout_213;
   dout_218=dout_215|dout_216;
   dout_219=dout_182^dout_202;
   dout_220=dout_182&dout_202;
   dout_221=dout_219&dout_218;
   dout_222=dout_219^dout_218;
   dout_223=dout_220|dout_221;
   dout_224=dout_187^dout_203;
   dout_225=dout_187&dout_203;
   dout_226=dout_224&dout_223;
   dout_227=dout_224^dout_223;
   dout_228=dout_225|dout_226;
   dout_229=dout_192^dout_204;
   dout_230=dout_192&dout_204;
   dout_231=dout_229&dout_228;
   dout_232=dout_229^dout_228;
   dout_233=dout_230|dout_231;
   dout_234=dout_197^dout_205;
   dout_235=dout_197&dout_205;
   dout_236=dout_234&dout_233;
   dout_237=dout_234^dout_233;
   dout_238=dout_235|dout_236;
   dout_239=dout_198^dout_206;
   dout_240=dout_198&((B >> 5)&1);
   dout_241=((A >> 7)&1)&dout_238;
   dout_242=dout_239^dout_238;
   dout_243=dout_240|dout_241;

   O = 0;
   O |= (dout_14&1) << 0;
   O |= (dout_207&1) << 1;
   O |= (dout_73&1) << 2;
   O |= (dout_118&1) << 3;
   O |= (dout_163&1) << 4;
   O |= (dout_208&1) << 5;
   O |= (dout_212&1) << 6;
   O |= (dout_217&1) << 7;
   O |= (dout_222&1) << 8;
   O |= (dout_227&1) << 9;
   O |= (dout_232&1) << 10;
   O |= (dout_237&1) << 11;
   O |= (dout_242&1) << 12;
   O |= (dout_243&1) << 13;
   return O;
}
