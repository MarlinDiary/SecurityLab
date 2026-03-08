#include <stddef.h>

typedef unsigned int (*noise_bank_fn)(unsigned int);

#define DECLARE_NOISE_FN(ID, MUL, ADD, XOR) \
unsigned int notebook_pro_noise_##ID(unsigned int value) \
{ \
    unsigned int mixed; \
    mixed = value ^ (unsigned int)(ID + 0x41u); \
    mixed = (mixed * MUL##u) + ADD##u; \
    mixed ^= XOR##u; \
    mixed = (mixed << 1) | (mixed >> 31); \
    return mixed; \
}

DECLARE_NOISE_FN(0, 33, 11, 0x40)
DECLARE_NOISE_FN(1, 35, 18, 0x43)
DECLARE_NOISE_FN(2, 37, 25, 0x46)
DECLARE_NOISE_FN(3, 39, 32, 0x49)
DECLARE_NOISE_FN(4, 41, 39, 0x4C)
DECLARE_NOISE_FN(5, 43, 46, 0x4F)
DECLARE_NOISE_FN(6, 45, 53, 0x52)
DECLARE_NOISE_FN(7, 47, 60, 0x55)
DECLARE_NOISE_FN(8, 49, 67, 0x58)
DECLARE_NOISE_FN(9, 51, 74, 0x5B)
DECLARE_NOISE_FN(10, 53, 81, 0x5E)
DECLARE_NOISE_FN(11, 55, 88, 0x61)
DECLARE_NOISE_FN(12, 57, 95, 0x64)
DECLARE_NOISE_FN(13, 59, 102, 0x67)
DECLARE_NOISE_FN(14, 61, 109, 0x6A)
DECLARE_NOISE_FN(15, 63, 116, 0x6D)
DECLARE_NOISE_FN(16, 65, 123, 0x70)
DECLARE_NOISE_FN(17, 33, 130, 0x73)
DECLARE_NOISE_FN(18, 35, 137, 0x76)
DECLARE_NOISE_FN(19, 37, 144, 0x79)
DECLARE_NOISE_FN(20, 39, 151, 0x7C)
DECLARE_NOISE_FN(21, 41, 158, 0x7F)
DECLARE_NOISE_FN(22, 43, 165, 0x82)
DECLARE_NOISE_FN(23, 45, 172, 0x85)
DECLARE_NOISE_FN(24, 47, 179, 0x88)
DECLARE_NOISE_FN(25, 49, 186, 0x8B)
DECLARE_NOISE_FN(26, 51, 193, 0x8E)
DECLARE_NOISE_FN(27, 53, 200, 0x91)
DECLARE_NOISE_FN(28, 55, 207, 0x94)
DECLARE_NOISE_FN(29, 57, 214, 0x97)
DECLARE_NOISE_FN(30, 59, 221, 0x9A)
DECLARE_NOISE_FN(31, 61, 228, 0x9D)
DECLARE_NOISE_FN(32, 63, 235, 0xA0)
DECLARE_NOISE_FN(33, 65, 242, 0xA3)
DECLARE_NOISE_FN(34, 33, 249, 0xA6)
DECLARE_NOISE_FN(35, 35, 256, 0xA9)
DECLARE_NOISE_FN(36, 37, 263, 0xAC)
DECLARE_NOISE_FN(37, 39, 270, 0xAF)
DECLARE_NOISE_FN(38, 41, 277, 0xB2)
DECLARE_NOISE_FN(39, 43, 284, 0xB5)
DECLARE_NOISE_FN(40, 45, 291, 0xB8)
DECLARE_NOISE_FN(41, 47, 298, 0xBB)
DECLARE_NOISE_FN(42, 49, 305, 0xBE)
DECLARE_NOISE_FN(43, 51, 312, 0xC1)
DECLARE_NOISE_FN(44, 53, 319, 0xC4)
DECLARE_NOISE_FN(45, 55, 326, 0xC7)
DECLARE_NOISE_FN(46, 57, 333, 0xCA)
DECLARE_NOISE_FN(47, 59, 340, 0xCD)
DECLARE_NOISE_FN(48, 61, 347, 0xD0)
DECLARE_NOISE_FN(49, 63, 354, 0xD3)
DECLARE_NOISE_FN(50, 65, 361, 0xD6)
DECLARE_NOISE_FN(51, 33, 368, 0xD9)
DECLARE_NOISE_FN(52, 35, 375, 0xDC)
DECLARE_NOISE_FN(53, 37, 382, 0xDF)
DECLARE_NOISE_FN(54, 39, 389, 0xE2)
DECLARE_NOISE_FN(55, 41, 396, 0xE5)
DECLARE_NOISE_FN(56, 43, 403, 0xE8)
DECLARE_NOISE_FN(57, 45, 410, 0xEB)
DECLARE_NOISE_FN(58, 47, 417, 0xEE)
DECLARE_NOISE_FN(59, 49, 424, 0xF1)
DECLARE_NOISE_FN(60, 51, 431, 0xF4)
DECLARE_NOISE_FN(61, 53, 438, 0xF7)
DECLARE_NOISE_FN(62, 55, 445, 0xFA)
DECLARE_NOISE_FN(63, 57, 452, 0xFD)
DECLARE_NOISE_FN(64, 59, 459, 0x100)
DECLARE_NOISE_FN(65, 61, 466, 0x103)
DECLARE_NOISE_FN(66, 63, 473, 0x106)
DECLARE_NOISE_FN(67, 65, 480, 0x109)
DECLARE_NOISE_FN(68, 33, 487, 0x10C)
DECLARE_NOISE_FN(69, 35, 494, 0x10F)
DECLARE_NOISE_FN(70, 37, 501, 0x112)
DECLARE_NOISE_FN(71, 39, 508, 0x115)
DECLARE_NOISE_FN(72, 41, 515, 0x118)
DECLARE_NOISE_FN(73, 43, 522, 0x11B)
DECLARE_NOISE_FN(74, 45, 529, 0x11E)
DECLARE_NOISE_FN(75, 47, 536, 0x121)
DECLARE_NOISE_FN(76, 49, 543, 0x124)
DECLARE_NOISE_FN(77, 51, 550, 0x127)
DECLARE_NOISE_FN(78, 53, 557, 0x12A)
DECLARE_NOISE_FN(79, 55, 564, 0x12D)
DECLARE_NOISE_FN(80, 57, 571, 0x130)
DECLARE_NOISE_FN(81, 59, 578, 0x133)
DECLARE_NOISE_FN(82, 61, 585, 0x136)
DECLARE_NOISE_FN(83, 63, 592, 0x139)
DECLARE_NOISE_FN(84, 65, 599, 0x13C)
DECLARE_NOISE_FN(85, 33, 606, 0x13F)
DECLARE_NOISE_FN(86, 35, 613, 0x142)
DECLARE_NOISE_FN(87, 37, 620, 0x145)
DECLARE_NOISE_FN(88, 39, 627, 0x148)
DECLARE_NOISE_FN(89, 41, 634, 0x14B)
DECLARE_NOISE_FN(90, 43, 641, 0x14E)
DECLARE_NOISE_FN(91, 45, 648, 0x151)
DECLARE_NOISE_FN(92, 47, 655, 0x154)
DECLARE_NOISE_FN(93, 49, 662, 0x157)
DECLARE_NOISE_FN(94, 51, 669, 0x15A)
DECLARE_NOISE_FN(95, 53, 676, 0x15D)
DECLARE_NOISE_FN(96, 55, 683, 0x160)
DECLARE_NOISE_FN(97, 57, 690, 0x163)
DECLARE_NOISE_FN(98, 59, 697, 0x166)
DECLARE_NOISE_FN(99, 61, 704, 0x169)
DECLARE_NOISE_FN(100, 63, 711, 0x16C)
DECLARE_NOISE_FN(101, 65, 718, 0x16F)
DECLARE_NOISE_FN(102, 33, 725, 0x172)
DECLARE_NOISE_FN(103, 35, 732, 0x175)
DECLARE_NOISE_FN(104, 37, 739, 0x178)
DECLARE_NOISE_FN(105, 39, 746, 0x17B)
DECLARE_NOISE_FN(106, 41, 753, 0x17E)
DECLARE_NOISE_FN(107, 43, 760, 0x181)
DECLARE_NOISE_FN(108, 45, 767, 0x184)
DECLARE_NOISE_FN(109, 47, 774, 0x187)
DECLARE_NOISE_FN(110, 49, 781, 0x18A)
DECLARE_NOISE_FN(111, 51, 788, 0x18D)
DECLARE_NOISE_FN(112, 53, 795, 0x190)
DECLARE_NOISE_FN(113, 55, 802, 0x193)
DECLARE_NOISE_FN(114, 57, 809, 0x196)
DECLARE_NOISE_FN(115, 59, 816, 0x199)
DECLARE_NOISE_FN(116, 61, 823, 0x19C)
DECLARE_NOISE_FN(117, 63, 830, 0x19F)
DECLARE_NOISE_FN(118, 65, 837, 0x1A2)
DECLARE_NOISE_FN(119, 33, 844, 0x1A5)
DECLARE_NOISE_FN(120, 35, 851, 0x1A8)
DECLARE_NOISE_FN(121, 37, 858, 0x1AB)
DECLARE_NOISE_FN(122, 39, 865, 0x1AE)
DECLARE_NOISE_FN(123, 41, 872, 0x1B1)
DECLARE_NOISE_FN(124, 43, 879, 0x1B4)
DECLARE_NOISE_FN(125, 45, 886, 0x1B7)
DECLARE_NOISE_FN(126, 47, 893, 0x1BA)
DECLARE_NOISE_FN(127, 49, 900, 0x1BD)
DECLARE_NOISE_FN(128, 51, 907, 0x1C0)
DECLARE_NOISE_FN(129, 53, 914, 0x1C3)
DECLARE_NOISE_FN(130, 55, 921, 0x1C6)
DECLARE_NOISE_FN(131, 57, 928, 0x1C9)
DECLARE_NOISE_FN(132, 59, 935, 0x1CC)
DECLARE_NOISE_FN(133, 61, 942, 0x1CF)
DECLARE_NOISE_FN(134, 63, 949, 0x1D2)
DECLARE_NOISE_FN(135, 65, 956, 0x1D5)
DECLARE_NOISE_FN(136, 33, 963, 0x1D8)
DECLARE_NOISE_FN(137, 35, 970, 0x1DB)
DECLARE_NOISE_FN(138, 37, 977, 0x1DE)
DECLARE_NOISE_FN(139, 39, 984, 0x1E1)
DECLARE_NOISE_FN(140, 41, 991, 0x1E4)
DECLARE_NOISE_FN(141, 43, 998, 0x1E7)
DECLARE_NOISE_FN(142, 45, 1005, 0x1EA)
DECLARE_NOISE_FN(143, 47, 1012, 0x1ED)
DECLARE_NOISE_FN(144, 49, 1019, 0x1F0)
DECLARE_NOISE_FN(145, 51, 1026, 0x1F3)
DECLARE_NOISE_FN(146, 53, 1033, 0x1F6)
DECLARE_NOISE_FN(147, 55, 1040, 0x1F9)
DECLARE_NOISE_FN(148, 57, 1047, 0x1FC)
DECLARE_NOISE_FN(149, 59, 1054, 0x1FF)
DECLARE_NOISE_FN(150, 61, 1061, 0x202)
DECLARE_NOISE_FN(151, 63, 1068, 0x205)
DECLARE_NOISE_FN(152, 65, 1075, 0x208)
DECLARE_NOISE_FN(153, 33, 1082, 0x20B)
DECLARE_NOISE_FN(154, 35, 1089, 0x20E)
DECLARE_NOISE_FN(155, 37, 1096, 0x211)
DECLARE_NOISE_FN(156, 39, 1103, 0x214)
DECLARE_NOISE_FN(157, 41, 1110, 0x217)
DECLARE_NOISE_FN(158, 43, 1117, 0x21A)
DECLARE_NOISE_FN(159, 45, 1124, 0x21D)
DECLARE_NOISE_FN(160, 47, 1131, 0x220)
DECLARE_NOISE_FN(161, 49, 1138, 0x223)
DECLARE_NOISE_FN(162, 51, 1145, 0x226)
DECLARE_NOISE_FN(163, 53, 1152, 0x229)
DECLARE_NOISE_FN(164, 55, 1159, 0x22C)
DECLARE_NOISE_FN(165, 57, 1166, 0x22F)
DECLARE_NOISE_FN(166, 59, 1173, 0x232)
DECLARE_NOISE_FN(167, 61, 1180, 0x235)
DECLARE_NOISE_FN(168, 63, 1187, 0x238)
DECLARE_NOISE_FN(169, 65, 1194, 0x23B)
DECLARE_NOISE_FN(170, 33, 1201, 0x23E)
DECLARE_NOISE_FN(171, 35, 1208, 0x241)
DECLARE_NOISE_FN(172, 37, 1215, 0x244)
DECLARE_NOISE_FN(173, 39, 1222, 0x247)
DECLARE_NOISE_FN(174, 41, 1229, 0x24A)
DECLARE_NOISE_FN(175, 43, 1236, 0x24D)
DECLARE_NOISE_FN(176, 45, 1243, 0x250)
DECLARE_NOISE_FN(177, 47, 1250, 0x253)
DECLARE_NOISE_FN(178, 49, 1257, 0x256)
DECLARE_NOISE_FN(179, 51, 1264, 0x259)
DECLARE_NOISE_FN(180, 53, 1271, 0x25C)
DECLARE_NOISE_FN(181, 55, 1278, 0x25F)
DECLARE_NOISE_FN(182, 57, 1285, 0x262)
DECLARE_NOISE_FN(183, 59, 1292, 0x265)
DECLARE_NOISE_FN(184, 61, 1299, 0x268)
DECLARE_NOISE_FN(185, 63, 1306, 0x26B)
DECLARE_NOISE_FN(186, 65, 1313, 0x26E)
DECLARE_NOISE_FN(187, 33, 1320, 0x271)
DECLARE_NOISE_FN(188, 35, 1327, 0x274)
DECLARE_NOISE_FN(189, 37, 1334, 0x277)
DECLARE_NOISE_FN(190, 39, 1341, 0x27A)
DECLARE_NOISE_FN(191, 41, 1348, 0x27D)
DECLARE_NOISE_FN(192, 43, 1355, 0x280)
DECLARE_NOISE_FN(193, 45, 1362, 0x283)
DECLARE_NOISE_FN(194, 47, 1369, 0x286)
DECLARE_NOISE_FN(195, 49, 1376, 0x289)
DECLARE_NOISE_FN(196, 51, 1383, 0x28C)
DECLARE_NOISE_FN(197, 53, 1390, 0x28F)
DECLARE_NOISE_FN(198, 55, 1397, 0x292)
DECLARE_NOISE_FN(199, 57, 1404, 0x295)
DECLARE_NOISE_FN(200, 59, 1411, 0x298)
DECLARE_NOISE_FN(201, 61, 1418, 0x29B)
DECLARE_NOISE_FN(202, 63, 1425, 0x29E)
DECLARE_NOISE_FN(203, 65, 1432, 0x2A1)
DECLARE_NOISE_FN(204, 33, 1439, 0x2A4)
DECLARE_NOISE_FN(205, 35, 1446, 0x2A7)
DECLARE_NOISE_FN(206, 37, 1453, 0x2AA)
DECLARE_NOISE_FN(207, 39, 1460, 0x2AD)
DECLARE_NOISE_FN(208, 41, 1467, 0x2B0)
DECLARE_NOISE_FN(209, 43, 1474, 0x2B3)
DECLARE_NOISE_FN(210, 45, 1481, 0x2B6)
DECLARE_NOISE_FN(211, 47, 1488, 0x2B9)
DECLARE_NOISE_FN(212, 49, 1495, 0x2BC)
DECLARE_NOISE_FN(213, 51, 1502, 0x2BF)
DECLARE_NOISE_FN(214, 53, 1509, 0x2C2)
DECLARE_NOISE_FN(215, 55, 1516, 0x2C5)
DECLARE_NOISE_FN(216, 57, 1523, 0x2C8)
DECLARE_NOISE_FN(217, 59, 1530, 0x2CB)
DECLARE_NOISE_FN(218, 61, 1537, 0x2CE)
DECLARE_NOISE_FN(219, 63, 1544, 0x2D1)
DECLARE_NOISE_FN(220, 65, 1551, 0x2D4)
DECLARE_NOISE_FN(221, 33, 1558, 0x2D7)
DECLARE_NOISE_FN(222, 35, 1565, 0x2DA)
DECLARE_NOISE_FN(223, 37, 1572, 0x2DD)
DECLARE_NOISE_FN(224, 39, 1579, 0x2E0)
DECLARE_NOISE_FN(225, 41, 1586, 0x2E3)
DECLARE_NOISE_FN(226, 43, 1593, 0x2E6)
DECLARE_NOISE_FN(227, 45, 1600, 0x2E9)
DECLARE_NOISE_FN(228, 47, 1607, 0x2EC)
DECLARE_NOISE_FN(229, 49, 1614, 0x2EF)
DECLARE_NOISE_FN(230, 51, 1621, 0x2F2)
DECLARE_NOISE_FN(231, 53, 1628, 0x2F5)
DECLARE_NOISE_FN(232, 55, 1635, 0x2F8)
DECLARE_NOISE_FN(233, 57, 1642, 0x2FB)
DECLARE_NOISE_FN(234, 59, 1649, 0x2FE)
DECLARE_NOISE_FN(235, 61, 1656, 0x301)
DECLARE_NOISE_FN(236, 63, 1663, 0x304)
DECLARE_NOISE_FN(237, 65, 1670, 0x307)
DECLARE_NOISE_FN(238, 33, 1677, 0x30A)
DECLARE_NOISE_FN(239, 35, 1684, 0x30D)
DECLARE_NOISE_FN(240, 37, 1691, 0x310)
DECLARE_NOISE_FN(241, 39, 1698, 0x313)
DECLARE_NOISE_FN(242, 41, 1705, 0x316)
DECLARE_NOISE_FN(243, 43, 1712, 0x319)
DECLARE_NOISE_FN(244, 45, 1719, 0x31C)
DECLARE_NOISE_FN(245, 47, 1726, 0x31F)
DECLARE_NOISE_FN(246, 49, 1733, 0x322)
DECLARE_NOISE_FN(247, 51, 1740, 0x325)
DECLARE_NOISE_FN(248, 53, 1747, 0x328)
DECLARE_NOISE_FN(249, 55, 1754, 0x32B)
DECLARE_NOISE_FN(250, 57, 1761, 0x32E)
DECLARE_NOISE_FN(251, 59, 1768, 0x331)
DECLARE_NOISE_FN(252, 61, 1775, 0x334)
DECLARE_NOISE_FN(253, 63, 1782, 0x337)
DECLARE_NOISE_FN(254, 65, 1789, 0x33A)
DECLARE_NOISE_FN(255, 33, 1796, 0x33D)

volatile const noise_bank_fn notebook_pro_noise_bank[] = {
    notebook_pro_noise_0,
    notebook_pro_noise_1,
    notebook_pro_noise_2,
    notebook_pro_noise_3,
    notebook_pro_noise_4,
    notebook_pro_noise_5,
    notebook_pro_noise_6,
    notebook_pro_noise_7,
    notebook_pro_noise_8,
    notebook_pro_noise_9,
    notebook_pro_noise_10,
    notebook_pro_noise_11,
    notebook_pro_noise_12,
    notebook_pro_noise_13,
    notebook_pro_noise_14,
    notebook_pro_noise_15,
    notebook_pro_noise_16,
    notebook_pro_noise_17,
    notebook_pro_noise_18,
    notebook_pro_noise_19,
    notebook_pro_noise_20,
    notebook_pro_noise_21,
    notebook_pro_noise_22,
    notebook_pro_noise_23,
    notebook_pro_noise_24,
    notebook_pro_noise_25,
    notebook_pro_noise_26,
    notebook_pro_noise_27,
    notebook_pro_noise_28,
    notebook_pro_noise_29,
    notebook_pro_noise_30,
    notebook_pro_noise_31,
    notebook_pro_noise_32,
    notebook_pro_noise_33,
    notebook_pro_noise_34,
    notebook_pro_noise_35,
    notebook_pro_noise_36,
    notebook_pro_noise_37,
    notebook_pro_noise_38,
    notebook_pro_noise_39,
    notebook_pro_noise_40,
    notebook_pro_noise_41,
    notebook_pro_noise_42,
    notebook_pro_noise_43,
    notebook_pro_noise_44,
    notebook_pro_noise_45,
    notebook_pro_noise_46,
    notebook_pro_noise_47,
    notebook_pro_noise_48,
    notebook_pro_noise_49,
    notebook_pro_noise_50,
    notebook_pro_noise_51,
    notebook_pro_noise_52,
    notebook_pro_noise_53,
    notebook_pro_noise_54,
    notebook_pro_noise_55,
    notebook_pro_noise_56,
    notebook_pro_noise_57,
    notebook_pro_noise_58,
    notebook_pro_noise_59,
    notebook_pro_noise_60,
    notebook_pro_noise_61,
    notebook_pro_noise_62,
    notebook_pro_noise_63,
    notebook_pro_noise_64,
    notebook_pro_noise_65,
    notebook_pro_noise_66,
    notebook_pro_noise_67,
    notebook_pro_noise_68,
    notebook_pro_noise_69,
    notebook_pro_noise_70,
    notebook_pro_noise_71,
    notebook_pro_noise_72,
    notebook_pro_noise_73,
    notebook_pro_noise_74,
    notebook_pro_noise_75,
    notebook_pro_noise_76,
    notebook_pro_noise_77,
    notebook_pro_noise_78,
    notebook_pro_noise_79,
    notebook_pro_noise_80,
    notebook_pro_noise_81,
    notebook_pro_noise_82,
    notebook_pro_noise_83,
    notebook_pro_noise_84,
    notebook_pro_noise_85,
    notebook_pro_noise_86,
    notebook_pro_noise_87,
    notebook_pro_noise_88,
    notebook_pro_noise_89,
    notebook_pro_noise_90,
    notebook_pro_noise_91,
    notebook_pro_noise_92,
    notebook_pro_noise_93,
    notebook_pro_noise_94,
    notebook_pro_noise_95,
    notebook_pro_noise_96,
    notebook_pro_noise_97,
    notebook_pro_noise_98,
    notebook_pro_noise_99,
    notebook_pro_noise_100,
    notebook_pro_noise_101,
    notebook_pro_noise_102,
    notebook_pro_noise_103,
    notebook_pro_noise_104,
    notebook_pro_noise_105,
    notebook_pro_noise_106,
    notebook_pro_noise_107,
    notebook_pro_noise_108,
    notebook_pro_noise_109,
    notebook_pro_noise_110,
    notebook_pro_noise_111,
    notebook_pro_noise_112,
    notebook_pro_noise_113,
    notebook_pro_noise_114,
    notebook_pro_noise_115,
    notebook_pro_noise_116,
    notebook_pro_noise_117,
    notebook_pro_noise_118,
    notebook_pro_noise_119,
    notebook_pro_noise_120,
    notebook_pro_noise_121,
    notebook_pro_noise_122,
    notebook_pro_noise_123,
    notebook_pro_noise_124,
    notebook_pro_noise_125,
    notebook_pro_noise_126,
    notebook_pro_noise_127,
    notebook_pro_noise_128,
    notebook_pro_noise_129,
    notebook_pro_noise_130,
    notebook_pro_noise_131,
    notebook_pro_noise_132,
    notebook_pro_noise_133,
    notebook_pro_noise_134,
    notebook_pro_noise_135,
    notebook_pro_noise_136,
    notebook_pro_noise_137,
    notebook_pro_noise_138,
    notebook_pro_noise_139,
    notebook_pro_noise_140,
    notebook_pro_noise_141,
    notebook_pro_noise_142,
    notebook_pro_noise_143,
    notebook_pro_noise_144,
    notebook_pro_noise_145,
    notebook_pro_noise_146,
    notebook_pro_noise_147,
    notebook_pro_noise_148,
    notebook_pro_noise_149,
    notebook_pro_noise_150,
    notebook_pro_noise_151,
    notebook_pro_noise_152,
    notebook_pro_noise_153,
    notebook_pro_noise_154,
    notebook_pro_noise_155,
    notebook_pro_noise_156,
    notebook_pro_noise_157,
    notebook_pro_noise_158,
    notebook_pro_noise_159,
    notebook_pro_noise_160,
    notebook_pro_noise_161,
    notebook_pro_noise_162,
    notebook_pro_noise_163,
    notebook_pro_noise_164,
    notebook_pro_noise_165,
    notebook_pro_noise_166,
    notebook_pro_noise_167,
    notebook_pro_noise_168,
    notebook_pro_noise_169,
    notebook_pro_noise_170,
    notebook_pro_noise_171,
    notebook_pro_noise_172,
    notebook_pro_noise_173,
    notebook_pro_noise_174,
    notebook_pro_noise_175,
    notebook_pro_noise_176,
    notebook_pro_noise_177,
    notebook_pro_noise_178,
    notebook_pro_noise_179,
    notebook_pro_noise_180,
    notebook_pro_noise_181,
    notebook_pro_noise_182,
    notebook_pro_noise_183,
    notebook_pro_noise_184,
    notebook_pro_noise_185,
    notebook_pro_noise_186,
    notebook_pro_noise_187,
    notebook_pro_noise_188,
    notebook_pro_noise_189,
    notebook_pro_noise_190,
    notebook_pro_noise_191,
    notebook_pro_noise_192,
    notebook_pro_noise_193,
    notebook_pro_noise_194,
    notebook_pro_noise_195,
    notebook_pro_noise_196,
    notebook_pro_noise_197,
    notebook_pro_noise_198,
    notebook_pro_noise_199,
    notebook_pro_noise_200,
    notebook_pro_noise_201,
    notebook_pro_noise_202,
    notebook_pro_noise_203,
    notebook_pro_noise_204,
    notebook_pro_noise_205,
    notebook_pro_noise_206,
    notebook_pro_noise_207,
    notebook_pro_noise_208,
    notebook_pro_noise_209,
    notebook_pro_noise_210,
    notebook_pro_noise_211,
    notebook_pro_noise_212,
    notebook_pro_noise_213,
    notebook_pro_noise_214,
    notebook_pro_noise_215,
    notebook_pro_noise_216,
    notebook_pro_noise_217,
    notebook_pro_noise_218,
    notebook_pro_noise_219,
    notebook_pro_noise_220,
    notebook_pro_noise_221,
    notebook_pro_noise_222,
    notebook_pro_noise_223,
    notebook_pro_noise_224,
    notebook_pro_noise_225,
    notebook_pro_noise_226,
    notebook_pro_noise_227,
    notebook_pro_noise_228,
    notebook_pro_noise_229,
    notebook_pro_noise_230,
    notebook_pro_noise_231,
    notebook_pro_noise_232,
    notebook_pro_noise_233,
    notebook_pro_noise_234,
    notebook_pro_noise_235,
    notebook_pro_noise_236,
    notebook_pro_noise_237,
    notebook_pro_noise_238,
    notebook_pro_noise_239,
    notebook_pro_noise_240,
    notebook_pro_noise_241,
    notebook_pro_noise_242,
    notebook_pro_noise_243,
    notebook_pro_noise_244,
    notebook_pro_noise_245,
    notebook_pro_noise_246,
    notebook_pro_noise_247,
    notebook_pro_noise_248,
    notebook_pro_noise_249,
    notebook_pro_noise_250,
    notebook_pro_noise_251,
    notebook_pro_noise_252,
    notebook_pro_noise_253,
    notebook_pro_noise_254,
    notebook_pro_noise_255
};

const unsigned int notebook_pro_noise_bank_count =
    (unsigned int)(sizeof(notebook_pro_noise_bank) / sizeof(notebook_pro_noise_bank[0]));
