#pragma once

#include <math.h>

#include "db/malt.h"

/**
 * Computes the EBC thanks to the Morey formula.
 * @param final_volume Volume in litre within the fermentor
 */
float to_ebc(const QList<DruidMalt> &malts, const float &final_volume) {
  float ebc;

  for (const auto &malt : malts) {
    ebc += malt.ebc() * malt.weight();
  }

  ebc = 2.9396 * pow(4.23 * ebc / final_volume, 0.6859);

  return ebc;
}

QColor to_color(const float ebc) {
  const float ebc_rounded =
      static_cast<float>(static_cast<int>(ebc * 10.)) / 10.;
  QColor color;

  if (ebc_rounded == 0.1) {
    color.setRgb(250, 250, 210);
  } else if (ebc_rounded == 0.2) {
    color.setRgb(250, 250, 204);
  } else if (ebc_rounded == 0.3) {
    color.setRgb(250, 250, 199);
  } else if (ebc_rounded == 0.4) {
    color.setRgb(250, 250, 193);
  } else if (ebc_rounded == 0.5) {
    color.setRgb(250, 250, 188);
  } else if (ebc_rounded == 0.6) {
    color.setRgb(250, 250, 182);
  } else if (ebc_rounded == 0.7) {
    color.setRgb(250, 250, 177);
  } else if (ebc_rounded == 0.8) {
    color.setRgb(250, 250, 171);
  } else if (ebc_rounded == 0.9) {
    color.setRgb(250, 250, 166);
  } else if (ebc_rounded == 1) {
    color.setRgb(250, 250, 160);
  } else if (ebc_rounded == 1.1) {
    color.setRgb(250, 250, 155);
  } else if (ebc_rounded == 1.2) {
    color.setRgb(250, 250, 149);
  } else if (ebc_rounded == 1.3) {
    color.setRgb(250, 250, 144);
  } else if (ebc_rounded == 1.4) {
    color.setRgb(250, 250, 138);
  } else if (ebc_rounded == 1.5) {
    color.setRgb(250, 250, 133);
  } else if (ebc_rounded == 1.6) {
    color.setRgb(250, 250, 127);
  } else if (ebc_rounded == 1.7) {
    color.setRgb(250, 250, 122);
  } else if (ebc_rounded == 1.8) {
    color.setRgb(250, 250, 116);
  } else if (ebc_rounded == 1.9) {
    color.setRgb(250, 250, 111);
  } else if (ebc_rounded == 2) {
    color.setRgb(250, 250, 105);
  } else if (ebc_rounded == 2.1) {
    color.setRgb(250, 250, 100);
  } else if (ebc_rounded == 2.2) {
    color.setRgb(250, 250, 94);
  } else if (ebc_rounded == 2.3) {
    color.setRgb(250, 250, 89);
  } else if (ebc_rounded == 2.4) {
    color.setRgb(250, 250, 83);
  } else if (ebc_rounded == 2.5) {
    color.setRgb(250, 250, 78);
  } else if (ebc_rounded == 2.6) {
    color.setRgb(249, 250, 72);
  } else if (ebc_rounded == 2.7) {
    color.setRgb(248, 249, 67);
  } else if (ebc_rounded == 2.8) {
    color.setRgb(247, 248, 61);
  } else if (ebc_rounded == 2.9) {
    color.setRgb(246, 247, 56);
  } else if (ebc_rounded == 3) {
    color.setRgb(245, 246, 50);
  } else if (ebc_rounded == 3.1) {
    color.setRgb(244, 245, 45);
  } else if (ebc_rounded == 3.2) {
    color.setRgb(243, 244, 45);
  } else if (ebc_rounded == 3.3) {
    color.setRgb(242, 242, 45);
  } else if (ebc_rounded == 3.4) {
    color.setRgb(241, 240, 46);
  } else if (ebc_rounded == 3.5) {
    color.setRgb(240, 238, 46);
  } else if (ebc_rounded == 3.6) {
    color.setRgb(239, 236, 46);
  } else if (ebc_rounded == 3.7) {
    color.setRgb(238, 234, 46);
  } else if (ebc_rounded == 3.8) {
    color.setRgb(237, 232, 47);
  } else if (ebc_rounded == 3.9) {
    color.setRgb(236, 230, 47);
  } else if (ebc_rounded == 4) {
    color.setRgb(235, 228, 47);
  } else if (ebc_rounded == 4.1) {
    color.setRgb(234, 226, 47);
  } else if (ebc_rounded == 4.2) {
    color.setRgb(233, 224, 48);
  } else if (ebc_rounded == 4.3) {
    color.setRgb(232, 222, 48);
  } else if (ebc_rounded == 4.4) {
    color.setRgb(231, 220, 48);
  } else if (ebc_rounded == 4.5) {
    color.setRgb(230, 218, 48);
  } else if (ebc_rounded == 4.6) {
    color.setRgb(229, 216, 49);
  } else if (ebc_rounded == 4.7) {
    color.setRgb(228, 214, 49);
  } else if (ebc_rounded == 4.8) {
    color.setRgb(227, 212, 49);
  } else if (ebc_rounded == 4.9) {
    color.setRgb(226, 210, 49);
  } else if (ebc_rounded == 5) {
    color.setRgb(225, 208, 50);
  } else if (ebc_rounded == 5.1) {
    color.setRgb(224, 206, 50);
  } else if (ebc_rounded == 5.2) {
    color.setRgb(223, 204, 50);
  } else if (ebc_rounded == 5.3) {
    color.setRgb(222, 202, 50);
  } else if (ebc_rounded == 5.4) {
    color.setRgb(221, 200, 51);
  } else if (ebc_rounded == 5.5) {
    color.setRgb(220, 198, 51);
  } else if (ebc_rounded == 5.6) {
    color.setRgb(219, 196, 51);
  } else if (ebc_rounded == 5.7) {
    color.setRgb(218, 194, 51);
  } else if (ebc_rounded == 5.8) {
    color.setRgb(217, 192, 52);
  } else if (ebc_rounded == 5.9) {
    color.setRgb(216, 190, 52);
  } else if (ebc_rounded == 6) {
    color.setRgb(215, 188, 52);
  } else if (ebc_rounded == 6.1) {
    color.setRgb(214, 186, 52);
  } else if (ebc_rounded == 6.2) {
    color.setRgb(213, 184, 53);
  } else if (ebc_rounded == 6.3) {
    color.setRgb(212, 182, 53);
  } else if (ebc_rounded == 6.4) {
    color.setRgb(211, 180, 53);
  } else if (ebc_rounded == 6.5) {
    color.setRgb(210, 178, 53);
  } else if (ebc_rounded == 6.6) {
    color.setRgb(209, 176, 54);
  } else if (ebc_rounded == 6.7) {
    color.setRgb(208, 174, 54);
  } else if (ebc_rounded == 6.8) {
    color.setRgb(207, 172, 54);
  } else if (ebc_rounded == 6.9) {
    color.setRgb(206, 170, 54);
  } else if (ebc_rounded == 7) {
    color.setRgb(205, 168, 55);
  } else if (ebc_rounded == 7.1) {
    color.setRgb(204, 166, 55);
  } else if (ebc_rounded == 7.2) {
    color.setRgb(203, 164, 55);
  } else if (ebc_rounded == 7.3) {
    color.setRgb(202, 162, 55);
  } else if (ebc_rounded == 7.4) {
    color.setRgb(201, 160, 56);
  } else if (ebc_rounded == 7.5) {
    color.setRgb(200, 158, 56);
  } else if (ebc_rounded == 7.6) {
    color.setRgb(200, 156, 56);
  } else if (ebc_rounded == 7.7) {
    color.setRgb(199, 154, 56);
  } else if (ebc_rounded == 7.8) {
    color.setRgb(199, 152, 56);
  } else if (ebc_rounded == 7.9) {
    color.setRgb(198, 150, 56);
  } else if (ebc_rounded == 8) {
    color.setRgb(198, 148, 56);
  } else if (ebc_rounded == 8.1) {
    color.setRgb(197, 146, 56);
  } else if (ebc_rounded == 8.2) {
    color.setRgb(197, 144, 56);
  } else if (ebc_rounded == 8.3) {
    color.setRgb(196, 142, 56);
  } else if (ebc_rounded == 8.4) {
    color.setRgb(196, 141, 56);
  } else if (ebc_rounded == 8.5) {
    color.setRgb(195, 140, 56);
  } else if (ebc_rounded == 8.6) {
    color.setRgb(195, 139, 56);
  } else if (ebc_rounded == 8.7) {
    color.setRgb(194, 139, 56);
  } else if (ebc_rounded == 8.8) {
    color.setRgb(194, 138, 56);
  } else if (ebc_rounded == 8.9) {
    color.setRgb(193, 137, 56);
  } else if (ebc_rounded == 9) {
    color.setRgb(193, 136, 56);
  } else if (ebc_rounded == 9.1) {
    color.setRgb(192, 136, 56);
  } else if (ebc_rounded == 9.2) {
    color.setRgb(192, 135, 56);
  } else if (ebc_rounded == 9.3) {
    color.setRgb(192, 134, 56);
  } else if (ebc_rounded == 9.4) {
    color.setRgb(192, 133, 56);
  } else if (ebc_rounded == 9.5) {
    color.setRgb(192, 133, 56);
  } else if (ebc_rounded == 9.6) {
    color.setRgb(192, 132, 56);
  } else if (ebc_rounded == 9.7) {
    color.setRgb(192, 131, 56);
  } else if (ebc_rounded == 9.8) {
    color.setRgb(192, 130, 56);
  } else if (ebc_rounded == 9.9) {
    color.setRgb(192, 130, 56);
  } else if (ebc_rounded == 10) {
    color.setRgb(192, 129, 56);
  } else if (ebc_rounded == 10.1) {
    color.setRgb(192, 128, 56);
  } else if (ebc_rounded == 10.2) {
    color.setRgb(192, 127, 56);
  } else if (ebc_rounded == 10.3) {
    color.setRgb(192, 127, 56);
  } else if (ebc_rounded == 10.4) {
    color.setRgb(192, 126, 56);
  } else if (ebc_rounded == 10.5) {
    color.setRgb(192, 125, 56);
  } else if (ebc_rounded == 10.6) {
    color.setRgb(192, 124, 56);
  } else if (ebc_rounded == 10.7) {
    color.setRgb(192, 124, 56);
  } else if (ebc_rounded == 10.8) {
    color.setRgb(192, 123, 56);
  } else if (ebc_rounded == 10.9) {
    color.setRgb(192, 122, 56);
  } else if (ebc_rounded == 11) {
    color.setRgb(192, 121, 56);
  } else if (ebc_rounded == 11.1) {
    color.setRgb(192, 121, 56);
  } else if (ebc_rounded == 11.2) {
    color.setRgb(192, 120, 56);
  } else if (ebc_rounded == 11.3) {
    color.setRgb(192, 119, 56);
  } else if (ebc_rounded == 11.4) {
    color.setRgb(192, 118, 56);
  } else if (ebc_rounded == 11.5) {
    color.setRgb(192, 118, 56);
  } else if (ebc_rounded == 11.6) {
    color.setRgb(192, 117, 56);
  } else if (ebc_rounded == 11.7) {
    color.setRgb(192, 116, 56);
  } else if (ebc_rounded == 11.8) {
    color.setRgb(192, 115, 56);
  } else if (ebc_rounded == 11.9) {
    color.setRgb(192, 115, 56);
  } else if (ebc_rounded == 12) {
    color.setRgb(192, 114, 56);
  } else if (ebc_rounded == 12.1) {
    color.setRgb(192, 113, 56);
  } else if (ebc_rounded == 12.2) {
    color.setRgb(192, 112, 56);
  } else if (ebc_rounded == 12.3) {
    color.setRgb(192, 112, 56);
  } else if (ebc_rounded == 12.4) {
    color.setRgb(192, 111, 56);
  } else if (ebc_rounded == 12.5) {
    color.setRgb(192, 110, 56);
  } else if (ebc_rounded == 12.6) {
    color.setRgb(192, 109, 56);
  } else if (ebc_rounded == 12.7) {
    color.setRgb(192, 109, 56);
  } else if (ebc_rounded == 12.8) {
    color.setRgb(192, 108, 56);
  } else if (ebc_rounded == 12.9) {
    color.setRgb(191, 107, 56);
  } else if (ebc_rounded == 13) {
    color.setRgb(190, 106, 56);
  } else if (ebc_rounded == 13.1) {
    color.setRgb(189, 106, 56);
  } else if (ebc_rounded == 13.2) {
    color.setRgb(188, 105, 56);
  } else if (ebc_rounded == 13.3) {
    color.setRgb(187, 104, 56);
  } else if (ebc_rounded == 13.4) {
    color.setRgb(186, 103, 56);
  } else if (ebc_rounded == 13.5) {
    color.setRgb(185, 103, 56);
  } else if (ebc_rounded == 13.6) {
    color.setRgb(184, 102, 56);
  } else if (ebc_rounded == 13.7) {
    color.setRgb(183, 101, 56);
  } else if (ebc_rounded == 13.8) {
    color.setRgb(182, 100, 56);
  } else if (ebc_rounded == 13.9) {
    color.setRgb(181, 100, 56);
  } else if (ebc_rounded == 14) {
    color.setRgb(180, 99, 56);
  } else if (ebc_rounded == 14.1) {
    color.setRgb(179, 98, 56);
  } else if (ebc_rounded == 14.2) {
    color.setRgb(178, 97, 56);
  } else if (ebc_rounded == 14.3) {
    color.setRgb(177, 97, 56);
  } else if (ebc_rounded == 14.4) {
    color.setRgb(175, 96, 55);
  } else if (ebc_rounded == 14.5) {
    color.setRgb(174, 95, 55);
  } else if (ebc_rounded == 14.6) {
    color.setRgb(172, 94, 55);
  } else if (ebc_rounded == 14.7) {
    color.setRgb(171, 94, 55);
  } else if (ebc_rounded == 14.8) {
    color.setRgb(169, 93, 54);
  } else if (ebc_rounded == 14.9) {
    color.setRgb(168, 92, 54);
  } else if (ebc_rounded == 15) {
    color.setRgb(167, 91, 54);
  } else if (ebc_rounded == 15.1) {
    color.setRgb(165, 91, 54);
  } else if (ebc_rounded == 15.2) {
    color.setRgb(164, 90, 53);
  } else if (ebc_rounded == 15.3) {
    color.setRgb(162, 89, 53);
  } else if (ebc_rounded == 15.4) {
    color.setRgb(161, 88, 53);
  } else if (ebc_rounded == 15.5) {
    color.setRgb(159, 88, 53);
  } else if (ebc_rounded == 15.6) {
    color.setRgb(158, 87, 52);
  } else if (ebc_rounded == 15.7) {
    color.setRgb(157, 86, 52);
  } else if (ebc_rounded == 15.8) {
    color.setRgb(155, 85, 52);
  } else if (ebc_rounded == 15.9) {
    color.setRgb(154, 85, 52);
  } else if (ebc_rounded == 16) {
    color.setRgb(152, 84, 51);
  } else if (ebc_rounded == 16.1) {
    color.setRgb(151, 83, 51);
  } else if (ebc_rounded == 16.2) {
    color.setRgb(149, 82, 51);
  } else if (ebc_rounded == 16.3) {
    color.setRgb(148, 82, 51);
  } else if (ebc_rounded == 16.4) {
    color.setRgb(147, 81, 50);
  } else if (ebc_rounded == 16.5) {
    color.setRgb(145, 80, 50);
  } else if (ebc_rounded == 16.6) {
    color.setRgb(144, 79, 50);
  } else if (ebc_rounded == 16.7) {
    color.setRgb(142, 78, 50);
  } else if (ebc_rounded == 16.8) {
    color.setRgb(141, 77, 49);
  } else if (ebc_rounded == 16.9) {
    color.setRgb(139, 76, 49);
  } else if (ebc_rounded == 17) {
    color.setRgb(138, 75, 48);
  } else if (ebc_rounded == 17.1) {
    color.setRgb(137, 75, 47);
  } else if (ebc_rounded == 17.2) {
    color.setRgb(135, 74, 47);
  } else if (ebc_rounded == 17.3) {
    color.setRgb(134, 73, 46);
  } else if (ebc_rounded == 17.4) {
    color.setRgb(132, 72, 45);
  } else if (ebc_rounded == 17.5) {
    color.setRgb(131, 72, 45);
  } else if (ebc_rounded == 17.6) {
    color.setRgb(129, 71, 44);
  } else if (ebc_rounded == 17.7) {
    color.setRgb(128, 70, 43);
  } else if (ebc_rounded == 17.8) {
    color.setRgb(127, 69, 43);
  } else if (ebc_rounded == 17.9) {
    color.setRgb(125, 69, 42);
  } else if (ebc_rounded == 18) {
    color.setRgb(124, 68, 41);
  } else if (ebc_rounded == 18.1) {
    color.setRgb(122, 67, 41);
  } else if (ebc_rounded == 18.2) {
    color.setRgb(121, 66, 40);
  } else if (ebc_rounded == 18.3) {
    color.setRgb(119, 66, 39);
  } else if (ebc_rounded == 18.4) {
    color.setRgb(118, 65, 39);
  } else if (ebc_rounded == 18.5) {
    color.setRgb(117, 64, 38);
  } else if (ebc_rounded == 18.6) {
    color.setRgb(115, 63, 37);
  } else if (ebc_rounded == 18.7) {
    color.setRgb(114, 63, 37);
  } else if (ebc_rounded == 18.8) {
    color.setRgb(112, 62, 36);
  } else if (ebc_rounded == 18.9) {
    color.setRgb(111, 61, 35);
  } else if (ebc_rounded == 19) {
    color.setRgb(109, 60, 34);
  } else if (ebc_rounded == 19.1) {
    color.setRgb(108, 60, 33);
  } else if (ebc_rounded == 19.2) {
    color.setRgb(107, 59, 32);
  } else if (ebc_rounded == 19.3) {
    color.setRgb(105, 58, 31);
  } else if (ebc_rounded == 19.4) {
    color.setRgb(104, 57, 29);
  } else if (ebc_rounded == 19.5) {
    color.setRgb(102, 57, 28);
  } else if (ebc_rounded == 19.6) {
    color.setRgb(101, 56, 27);
  } else if (ebc_rounded == 19.7) {
    color.setRgb(99, 55, 26);
  } else if (ebc_rounded == 19.8) {
    color.setRgb(98, 54, 25);
  } else if (ebc_rounded == 19.9) {
    color.setRgb(97, 54, 24);
  } else if (ebc_rounded == 20) {
    color.setRgb(95, 53, 23);
  } else if (ebc_rounded == 20.1) {
    color.setRgb(94, 52, 21);
  } else if (ebc_rounded == 20.2) {
    color.setRgb(92, 51, 20);
  } else if (ebc_rounded == 20.3) {
    color.setRgb(91, 51, 19);
  } else if (ebc_rounded == 20.4) {
    color.setRgb(89, 50, 18);
  } else if (ebc_rounded == 20.5) {
    color.setRgb(88, 49, 17);
  } else if (ebc_rounded == 20.6) {
    color.setRgb(87, 48, 16);
  } else if (ebc_rounded == 20.7) {
    color.setRgb(85, 48, 15);
  } else if (ebc_rounded == 20.8) {
    color.setRgb(84, 47, 13);
  } else if (ebc_rounded == 20.9) {
    color.setRgb(82, 46, 12);
  } else if (ebc_rounded == 21) {
    color.setRgb(81, 45, 11);
  } else if (ebc_rounded == 21.1) {
    color.setRgb(79, 45, 10);
  } else if (ebc_rounded == 21.2) {
    color.setRgb(78, 44, 9);
  } else if (ebc_rounded == 21.3) {
    color.setRgb(77, 43, 8);
  } else if (ebc_rounded == 21.4) {
    color.setRgb(75, 42, 9);
  } else if (ebc_rounded == 21.5) {
    color.setRgb(74, 42, 9);
  } else if (ebc_rounded == 21.6) {
    color.setRgb(72, 41, 10);
  } else if (ebc_rounded == 21.7) {
    color.setRgb(71, 40, 10);
  } else if (ebc_rounded == 21.8) {
    color.setRgb(69, 39, 11);
  } else if (ebc_rounded == 21.9) {
    color.setRgb(68, 39, 11);
  } else if (ebc_rounded == 22) {
    color.setRgb(67, 38, 12);
  } else if (ebc_rounded == 22.1) {
    color.setRgb(65, 37, 12);
  } else if (ebc_rounded == 22.2) {
    color.setRgb(64, 36, 13);
  } else if (ebc_rounded == 22.3) {
    color.setRgb(62, 36, 13);
  } else if (ebc_rounded == 22.4) {
    color.setRgb(61, 35, 14);
  } else if (ebc_rounded == 22.5) {
    color.setRgb(59, 34, 14);
  } else if (ebc_rounded == 22.6) {
    color.setRgb(58, 33, 15);
  } else if (ebc_rounded == 22.7) {
    color.setRgb(57, 33, 15);
  } else if (ebc_rounded == 22.8) {
    color.setRgb(55, 32, 16);
  } else if (ebc_rounded == 22.9) {
    color.setRgb(54, 31, 16);
  } else if (ebc_rounded == 23) {
    color.setRgb(52, 30, 17);
  } else if (ebc_rounded == 23.1) {
    color.setRgb(51, 30, 17);
  } else if (ebc_rounded == 23.2) {
    color.setRgb(49, 29, 18);
  } else if (ebc_rounded == 23.3) {
    color.setRgb(48, 28, 18);
  } else if (ebc_rounded == 23.4) {
    color.setRgb(47, 27, 19);
  } else if (ebc_rounded == 23.5) {
    color.setRgb(45, 27, 19);
  } else if (ebc_rounded == 23.6) {
    color.setRgb(44, 26, 20);
  } else if (ebc_rounded == 23.7) {
    color.setRgb(42, 25, 20);
  } else if (ebc_rounded == 23.8) {
    color.setRgb(41, 24, 21);
  } else if (ebc_rounded == 23.9) {
    color.setRgb(39, 24, 21);
  } else if (ebc_rounded == 24) {
    color.setRgb(38, 23, 22);
  } else if (ebc_rounded == 24.1) {
    color.setRgb(37, 22, 21);
  } else if (ebc_rounded == 24.2) {
    color.setRgb(37, 22, 21);
  } else if (ebc_rounded == 24.3) {
    color.setRgb(36, 22, 21);
  } else if (ebc_rounded == 24.4) {
    color.setRgb(36, 21, 20);
  } else if (ebc_rounded == 24.5) {
    color.setRgb(35, 21, 20);
  } else if (ebc_rounded == 24.6) {
    color.setRgb(35, 21, 20);
  } else if (ebc_rounded == 24.7) {
    color.setRgb(34, 20, 19);
  } else if (ebc_rounded == 24.8) {
    color.setRgb(34, 20, 19);
  } else if (ebc_rounded == 24.9) {
    color.setRgb(33, 20, 19);
  } else if (ebc_rounded == 25) {
    color.setRgb(33, 19, 18);
  } else if (ebc_rounded == 25.1) {
    color.setRgb(32, 19, 18);
  } else if (ebc_rounded == 25.2) {
    color.setRgb(32, 19, 18);
  } else if (ebc_rounded == 25.3) {
    color.setRgb(31, 18, 17);
  } else if (ebc_rounded == 25.4) {
    color.setRgb(31, 18, 17);
  } else if (ebc_rounded == 25.5) {
    color.setRgb(30, 18, 17);
  } else if (ebc_rounded == 25.6) {
    color.setRgb(30, 17, 16);
  } else if (ebc_rounded == 25.7) {
    color.setRgb(29, 17, 16);
  } else if (ebc_rounded == 25.8) {
    color.setRgb(29, 17, 16);
  } else if (ebc_rounded == 25.9) {
    color.setRgb(28, 16, 15);
  } else if (ebc_rounded == 26) {
    color.setRgb(28, 16, 15);
  } else if (ebc_rounded == 26.1) {
    color.setRgb(27, 16, 15);
  } else if (ebc_rounded == 26.2) {
    color.setRgb(27, 15, 14);
  } else if (ebc_rounded == 26.3) {
    color.setRgb(26, 15, 14);
  } else if (ebc_rounded == 26.4) {
    color.setRgb(26, 15, 14);
  } else if (ebc_rounded == 26.5) {
    color.setRgb(25, 14, 13);
  } else if (ebc_rounded == 26.6) {
    color.setRgb(25, 14, 13);
  } else if (ebc_rounded == 26.7) {
    color.setRgb(24, 14, 13);
  } else if (ebc_rounded == 26.8) {
    color.setRgb(24, 13, 12);
  } else if (ebc_rounded == 26.9) {
    color.setRgb(23, 13, 12);
  } else if (ebc_rounded == 27) {
    color.setRgb(23, 13, 12);
  } else if (ebc_rounded == 27.1) {
    color.setRgb(22, 12, 11);
  } else if (ebc_rounded == 27.2) {
    color.setRgb(22, 12, 11);
  } else if (ebc_rounded == 27.3) {
    color.setRgb(21, 12, 11);
  } else if (ebc_rounded == 27.4) {
    color.setRgb(21, 11, 10);
  } else if (ebc_rounded == 27.5) {
    color.setRgb(20, 11, 10);
  } else if (ebc_rounded == 27.6) {
    color.setRgb(20, 11, 10);
  } else if (ebc_rounded == 27.7) {
    color.setRgb(19, 10, 9);
  } else if (ebc_rounded == 27.8) {
    color.setRgb(19, 10, 9);
  } else if (ebc_rounded == 27.9) {
    color.setRgb(18, 10, 9);
  } else if (ebc_rounded == 28) {
    color.setRgb(18, 9, 8);
  } else if (ebc_rounded == 28.1) {
    color.setRgb(17, 9, 8);
  } else if (ebc_rounded == 28.2) {
    color.setRgb(17, 9, 8);
  } else if (ebc_rounded == 28.3) {
    color.setRgb(16, 8, 7);
  } else if (ebc_rounded == 28.4) {
    color.setRgb(16, 8, 7);
  } else if (ebc_rounded == 28.5) {
    color.setRgb(15, 8, 7);
  } else if (ebc_rounded == 28.6) {
    color.setRgb(15, 7, 6);
  } else if (ebc_rounded == 28.7) {
    color.setRgb(14, 7, 6);
  } else if (ebc_rounded == 28.8) {
    color.setRgb(14, 7, 6);
  } else if (ebc_rounded == 28.9) {
    color.setRgb(13, 6, 5);
  } else if (ebc_rounded == 29) {
    color.setRgb(13, 6, 5);
  } else if (ebc_rounded == 29.1) {
    color.setRgb(12, 6, 5);
  } else if (ebc_rounded == 29.2) {
    color.setRgb(12, 5, 4);
  } else if (ebc_rounded == 29.3) {
    color.setRgb(11, 5, 4);
  } else if (ebc_rounded == 29.4) {
    color.setRgb(11, 5, 4);
  } else if (ebc_rounded == 29.5) {
    color.setRgb(10, 4, 3);
  } else if (ebc_rounded == 29.6) {
    color.setRgb(10, 4, 3);
  } else if (ebc_rounded == 29.7) {
    color.setRgb(9, 4, 3);
  } else if (ebc_rounded == 29.8) {
    color.setRgb(9, 3, 2);
  } else if (ebc_rounded == 29.9) {
    color.setRgb(8, 3, 2);
  } else if (ebc_rounded == 30) {
    color.setRgb(8, 3, 2);
  }

  return color;
}
