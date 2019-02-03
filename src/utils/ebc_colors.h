#pragma once

#include <iostream>

#include <math.h>

#include "db/malt.h"

class DruidUtils {
 public:
  /**
   * Computes the EBC thanks to the Morey formula.
   * @param final_volume Volume in litre within the fermentor
   */
  static float to_ebc(const QList<DruidMalt> &malts,
                      const float &final_volume) {
    float ebc;

    for (const auto &malt : malts) {
      ebc += malt.ebc() * malt.weight() / 1000.;
    }

    ebc = 2.9396 * pow(4.23 * ebc / final_volume, 0.6859);

    return static_cast<float>(static_cast<int>(ebc * 10.)) / 10.;
  }

  static QColor to_color(const float ebc) {
    // srm = 0.508 * ebc
    const float srm =
        static_cast<float>(static_cast<int>(ebc * 0.508 * 10.)) / 10.;
    QColor color;

    std::cout << srm << std::endl;
    std::cout << (srm == 8.9) << std::endl;

    std::cout << std::abs(srm - 8.9) << std::endl;

    if (srm == 0.1f) {
      color.setRgb(250, 250, 210);
    } else if (srm == 0.2f) {
      color.setRgb(250, 250, 204);
    } else if (srm == 0.3f) {
      color.setRgb(250, 250, 199);
    } else if (srm == 0.4f) {
      color.setRgb(250, 250, 193);
    } else if (srm == 0.5f) {
      color.setRgb(250, 250, 188);
    } else if (srm == 0.6f) {
      color.setRgb(250, 250, 182);
    } else if (srm == 0.7f) {
      color.setRgb(250, 250, 177);
    } else if (srm == 0.8f) {
      color.setRgb(250, 250, 171);
    } else if (srm == 0.9f) {
      color.setRgb(250, 250, 166);
    } else if (srm == 1.0f) {
      color.setRgb(250, 250, 160);
    } else if (srm == 1.1f) {
      color.setRgb(250, 250, 155);
    } else if (srm == 1.2f) {
      color.setRgb(250, 250, 149);
    } else if (srm == 1.3f) {
      color.setRgb(250, 250, 144);
    } else if (srm == 1.4f) {
      color.setRgb(250, 250, 138);
    } else if (srm == 1.5f) {
      color.setRgb(250, 250, 133);
    } else if (srm == 1.6f) {
      color.setRgb(250, 250, 127);
    } else if (srm == 1.7f) {
      color.setRgb(250, 250, 122);
    } else if (srm == 1.8f) {
      color.setRgb(250, 250, 116);
    } else if (srm == 1.9f) {
      color.setRgb(250, 250, 111);
    } else if (srm == 2.0f) {
      color.setRgb(250, 250, 105);
    } else if (srm == 2.1f) {
      color.setRgb(250, 250, 100);
    } else if (srm == 2.2f) {
      color.setRgb(250, 250, 94);
    } else if (srm == 2.3f) {
      color.setRgb(250, 250, 89);
    } else if (srm == 2.4f) {
      color.setRgb(250, 250, 83);
    } else if (srm == 2.5f) {
      color.setRgb(250, 250, 78);
    } else if (srm == 2.6f) {
      color.setRgb(249, 250, 72);
    } else if (srm == 2.7f) {
      color.setRgb(248, 249, 67);
    } else if (srm == 2.8f) {
      color.setRgb(247, 248, 61);
    } else if (srm == 2.9f) {
      color.setRgb(246, 247, 56);
    } else if (srm == 3.0f) {
      color.setRgb(245, 246, 50);
    } else if (srm == 3.1f) {
      color.setRgb(244, 245, 45);
    } else if (srm == 3.2f) {
      color.setRgb(243, 244, 45);
    } else if (srm == 3.3f) {
      color.setRgb(242, 242, 45);
    } else if (srm == 3.4f) {
      color.setRgb(241, 240, 46);
    } else if (srm == 3.5f) {
      color.setRgb(240, 238, 46);
    } else if (srm == 3.6f) {
      color.setRgb(239, 236, 46);
    } else if (srm == 3.7f) {
      color.setRgb(238, 234, 46);
    } else if (srm == 3.8f) {
      color.setRgb(237, 232, 47);
    } else if (srm == 3.9f) {
      color.setRgb(236, 230, 47);
    } else if (srm == 4.0f) {
      color.setRgb(235, 228, 47);
    } else if (srm == 4.1f) {
      color.setRgb(234, 226, 47);
    } else if (srm == 4.2f) {
      color.setRgb(233, 224, 48);
    } else if (srm == 4.3f) {
      color.setRgb(232, 222, 48);
    } else if (srm == 4.4f) {
      color.setRgb(231, 220, 48);
    } else if (srm == 4.5f) {
      color.setRgb(230, 218, 48);
    } else if (srm == 4.6f) {
      color.setRgb(229, 216, 49);
    } else if (srm == 4.7f) {
      color.setRgb(228, 214, 49);
    } else if (srm == 4.8f) {
      color.setRgb(227, 212, 49);
    } else if (srm == 4.9f) {
      color.setRgb(226, 210, 49);
    } else if (srm == 5.0f) {
      color.setRgb(225, 208, 50);
    } else if (srm == 5.1f) {
      color.setRgb(224, 206, 50);
    } else if (srm == 5.2f) {
      color.setRgb(223, 204, 50);
    } else if (srm == 5.3f) {
      color.setRgb(222, 202, 50);
    } else if (srm == 5.4f) {
      color.setRgb(221, 200, 51);
    } else if (srm == 5.5f) {
      color.setRgb(220, 198, 51);
    } else if (srm == 5.6f) {
      color.setRgb(219, 196, 51);
    } else if (srm == 5.7f) {
      color.setRgb(218, 194, 51);
    } else if (srm == 5.8f) {
      color.setRgb(217, 192, 52);
    } else if (srm == 5.9f) {
      color.setRgb(216, 190, 52);
    } else if (srm == 6.0f) {
      color.setRgb(215, 188, 52);
    } else if (srm == 6.1f) {
      color.setRgb(214, 186, 52);
    } else if (srm == 6.2f) {
      color.setRgb(213, 184, 53);
    } else if (srm == 6.3f) {
      color.setRgb(212, 182, 53);
    } else if (srm == 6.4f) {
      color.setRgb(211, 180, 53);
    } else if (srm == 6.5f) {
      color.setRgb(210, 178, 53);
    } else if (srm == 6.6f) {
      color.setRgb(209, 176, 54);
    } else if (srm == 6.7f) {
      color.setRgb(208, 174, 54);
    } else if (srm == 6.8f) {
      color.setRgb(207, 172, 54);
    } else if (srm == 6.9f) {
      color.setRgb(206, 170, 54);
    } else if (srm == 7.0f) {
      color.setRgb(205, 168, 55);
    } else if (srm == 7.1f) {
      color.setRgb(204, 166, 55);
    } else if (srm == 7.2f) {
      color.setRgb(203, 164, 55);
    } else if (srm == 7.3f) {
      color.setRgb(202, 162, 55);
    } else if (srm == 7.4f) {
      color.setRgb(201, 160, 56);
    } else if (srm == 7.5f) {
      color.setRgb(200, 158, 56);
    } else if (srm == 7.6f) {
      color.setRgb(200, 156, 56);
    } else if (srm == 7.7f) {
      color.setRgb(199, 154, 56);
    } else if (srm == 7.8f) {
      color.setRgb(199, 152, 56);
    } else if (srm == 7.9f) {
      color.setRgb(198, 150, 56);
    } else if (srm == 8.0f) {
      color.setRgb(198, 148, 56);
    } else if (srm == 8.1f) {
      color.setRgb(197, 146, 56);
    } else if (srm == 8.2f) {
      color.setRgb(197, 144, 56);
    } else if (srm == 8.3f) {
      color.setRgb(196, 142, 56);
    } else if (srm == 8.4f) {
      color.setRgb(196, 141, 56);
    } else if (srm == 8.5f) {
      color.setRgb(195, 140, 56);
    } else if (srm == 8.6f) {
      color.setRgb(195, 139, 56);
    } else if (srm == 8.7f) {
      color.setRgb(194, 139, 56);
    } else if (srm == 8.8f) {
      color.setRgb(194, 138, 56);
    } else if (srm == 8.9f) {
      color.setRgb(193, 137, 56);
    } else if (srm == 9.0f) {
      color.setRgb(193, 136, 56);
    } else if (srm == 9.1f) {
      color.setRgb(192, 136, 56);
    } else if (srm == 9.2f) {
      color.setRgb(192, 135, 56);
    } else if (srm == 9.3f) {
      color.setRgb(192, 134, 56);
    } else if (srm == 9.4f) {
      color.setRgb(192, 133, 56);
    } else if (srm == 9.5f) {
      color.setRgb(192, 133, 56);
    } else if (srm == 9.6f) {
      color.setRgb(192, 132, 56);
    } else if (srm == 9.7f) {
      color.setRgb(192, 131, 56);
    } else if (srm == 9.8f) {
      color.setRgb(192, 130, 56);
    } else if (srm == 9.9f) {
      color.setRgb(192, 130, 56);
    } else if (srm == 10.0f) {
      color.setRgb(192, 129, 56);
    } else if (srm == 10.1f) {
      color.setRgb(192, 128, 56);
    } else if (srm == 10.2f) {
      color.setRgb(192, 127, 56);
    } else if (srm == 10.3f) {
      color.setRgb(192, 127, 56);
    } else if (srm == 10.4f) {
      color.setRgb(192, 126, 56);
    } else if (srm == 10.5f) {
      color.setRgb(192, 125, 56);
    } else if (srm == 10.6f) {
      color.setRgb(192, 124, 56);
    } else if (srm == 10.7f) {
      color.setRgb(192, 124, 56);
    } else if (srm == 10.8f) {
      color.setRgb(192, 123, 56);
    } else if (srm == 10.9f) {
      color.setRgb(192, 122, 56);
    } else if (srm == 11.0f) {
      color.setRgb(192, 121, 56);
    } else if (srm == 11.1f) {
      color.setRgb(192, 121, 56);
    } else if (srm == 11.2f) {
      color.setRgb(192, 120, 56);
    } else if (srm == 11.3f) {
      color.setRgb(192, 119, 56);
    } else if (srm == 11.4f) {
      color.setRgb(192, 118, 56);
    } else if (srm == 11.5f) {
      color.setRgb(192, 118, 56);
    } else if (srm == 11.6f) {
      color.setRgb(192, 117, 56);
    } else if (srm == 11.7f) {
      color.setRgb(192, 116, 56);
    } else if (srm == 11.8f) {
      color.setRgb(192, 115, 56);
    } else if (srm == 11.9f) {
      color.setRgb(192, 115, 56);
    } else if (srm == 12.0f) {
      color.setRgb(192, 114, 56);
    } else if (srm == 12.1f) {
      color.setRgb(192, 113, 56);
    } else if (srm == 12.2f) {
      color.setRgb(192, 112, 56);
    } else if (srm == 12.3f) {
      color.setRgb(192, 112, 56);
    } else if (srm == 12.4f) {
      color.setRgb(192, 111, 56);
    } else if (srm == 12.5f) {
      color.setRgb(192, 110, 56);
    } else if (srm == 12.6f) {
      color.setRgb(192, 109, 56);
    } else if (srm == 12.7f) {
      color.setRgb(192, 109, 56);
    } else if (srm == 12.8f) {
      color.setRgb(192, 108, 56);
    } else if (srm == 12.9f) {
      color.setRgb(191, 107, 56);
    } else if (srm == 13.0f) {
      color.setRgb(190, 106, 56);
    } else if (srm == 13.1f) {
      color.setRgb(189, 106, 56);
    } else if (srm == 13.2f) {
      color.setRgb(188, 105, 56);
    } else if (srm == 13.3f) {
      color.setRgb(187, 104, 56);
    } else if (srm == 13.4f) {
      color.setRgb(186, 103, 56);
    } else if (srm == 13.5f) {
      color.setRgb(185, 103, 56);
    } else if (srm == 13.6f) {
      color.setRgb(184, 102, 56);
    } else if (srm == 13.7f) {
      color.setRgb(183, 101, 56);
    } else if (srm == 13.8f) {
      color.setRgb(182, 100, 56);
    } else if (srm == 13.9f) {
      color.setRgb(181, 100, 56);
    } else if (srm == 14.0f) {
      color.setRgb(180, 99, 56);
    } else if (srm == 14.1f) {
      color.setRgb(179, 98, 56);
    } else if (srm == 14.2f) {
      color.setRgb(178, 97, 56);
    } else if (srm == 14.3f) {
      color.setRgb(177, 97, 56);
    } else if (srm == 14.4f) {
      color.setRgb(175, 96, 55);
    } else if (srm == 14.5f) {
      color.setRgb(174, 95, 55);
    } else if (srm == 14.6f) {
      color.setRgb(172, 94, 55);
    } else if (srm == 14.7f) {
      color.setRgb(171, 94, 55);
    } else if (srm == 14.8f) {
      color.setRgb(169, 93, 54);
    } else if (srm == 14.9f) {
      color.setRgb(168, 92, 54);
    } else if (srm == 15.0f) {
      color.setRgb(167, 91, 54);
    } else if (srm == 15.1f) {
      color.setRgb(165, 91, 54);
    } else if (srm == 15.2f) {
      color.setRgb(164, 90, 53);
    } else if (srm == 15.3f) {
      color.setRgb(162, 89, 53);
    } else if (srm == 15.4f) {
      color.setRgb(161, 88, 53);
    } else if (srm == 15.5f) {
      color.setRgb(159, 88, 53);
    } else if (srm == 15.6f) {
      color.setRgb(158, 87, 52);
    } else if (srm == 15.7f) {
      color.setRgb(157, 86, 52);
    } else if (srm == 15.8f) {
      color.setRgb(155, 85, 52);
    } else if (srm == 15.9f) {
      color.setRgb(154, 85, 52);
    } else if (srm == 16.0f) {
      color.setRgb(152, 84, 51);
    } else if (srm == 16.1f) {
      color.setRgb(151, 83, 51);
    } else if (srm == 16.2f) {
      color.setRgb(149, 82, 51);
    } else if (srm == 16.3f) {
      color.setRgb(148, 82, 51);
    } else if (srm == 16.4f) {
      color.setRgb(147, 81, 50);
    } else if (srm == 16.5f) {
      color.setRgb(145, 80, 50);
    } else if (srm == 16.6f) {
      color.setRgb(144, 79, 50);
    } else if (srm == 16.7f) {
      color.setRgb(142, 78, 50);
    } else if (srm == 16.8f) {
      color.setRgb(141, 77, 49);
    } else if (srm == 16.9f) {
      color.setRgb(139, 76, 49);
    } else if (srm == 17.0f) {
      color.setRgb(138, 75, 48);
    } else if (srm == 17.1f) {
      color.setRgb(137, 75, 47);
    } else if (srm == 17.2f) {
      color.setRgb(135, 74, 47);
    } else if (srm == 17.3f) {
      color.setRgb(134, 73, 46);
    } else if (srm == 17.4f) {
      color.setRgb(132, 72, 45);
    } else if (srm == 17.5f) {
      color.setRgb(131, 72, 45);
    } else if (srm == 17.6f) {
      color.setRgb(129, 71, 44);
    } else if (srm == 17.7f) {
      color.setRgb(128, 70, 43);
    } else if (srm == 17.8f) {
      color.setRgb(127, 69, 43);
    } else if (srm == 17.9f) {
      color.setRgb(125, 69, 42);
    } else if (srm == 18.0f) {
      color.setRgb(124, 68, 41);
    } else if (srm == 18.1f) {
      color.setRgb(122, 67, 41);
    } else if (srm == 18.2f) {
      color.setRgb(121, 66, 40);
    } else if (srm == 18.3f) {
      color.setRgb(119, 66, 39);
    } else if (srm == 18.4f) {
      color.setRgb(118, 65, 39);
    } else if (srm == 18.5f) {
      color.setRgb(117, 64, 38);
    } else if (srm == 18.6f) {
      color.setRgb(115, 63, 37);
    } else if (srm == 18.7f) {
      color.setRgb(114, 63, 37);
    } else if (srm == 18.8f) {
      color.setRgb(112, 62, 36);
    } else if (srm == 18.9f) {
      color.setRgb(111, 61, 35);
    } else if (srm == 19.0f) {
      color.setRgb(109, 60, 34);
    } else if (srm == 19.1f) {
      color.setRgb(108, 60, 33);
    } else if (srm == 19.2f) {
      color.setRgb(107, 59, 32);
    } else if (srm == 19.3f) {
      color.setRgb(105, 58, 31);
    } else if (srm == 19.4f) {
      color.setRgb(104, 57, 29);
    } else if (srm == 19.5f) {
      color.setRgb(102, 57, 28);
    } else if (srm == 19.6f) {
      color.setRgb(101, 56, 27);
    } else if (srm == 19.7f) {
      color.setRgb(99, 55, 26);
    } else if (srm == 19.8f) {
      color.setRgb(98, 54, 25);
    } else if (srm == 19.9f) {
      color.setRgb(97, 54, 24);
    } else if (srm == 20.0f) {
      color.setRgb(95, 53, 23);
    } else if (srm == 20.1f) {
      color.setRgb(94, 52, 21);
    } else if (srm == 20.2f) {
      color.setRgb(92, 51, 20);
    } else if (srm == 20.3f) {
      color.setRgb(91, 51, 19);
    } else if (srm == 20.4f) {
      color.setRgb(89, 50, 18);
    } else if (srm == 20.5f) {
      color.setRgb(88, 49, 17);
    } else if (srm == 20.6f) {
      color.setRgb(87, 48, 16);
    } else if (srm == 20.7f) {
      color.setRgb(85, 48, 15);
    } else if (srm == 20.8f) {
      color.setRgb(84, 47, 13);
    } else if (srm == 20.9f) {
      color.setRgb(82, 46, 12);
    } else if (srm == 21.0f) {
      color.setRgb(81, 45, 11);
    } else if (srm == 21.1f) {
      color.setRgb(79, 45, 10);
    } else if (srm == 21.2f) {
      color.setRgb(78, 44, 9);
    } else if (srm == 21.3f) {
      color.setRgb(77, 43, 8);
    } else if (srm == 21.4f) {
      color.setRgb(75, 42, 9);
    } else if (srm == 21.5f) {
      color.setRgb(74, 42, 9);
    } else if (srm == 21.6f) {
      color.setRgb(72, 41, 10);
    } else if (srm == 21.7f) {
      color.setRgb(71, 40, 10);
    } else if (srm == 21.8f) {
      color.setRgb(69, 39, 11);
    } else if (srm == 21.9f) {
      color.setRgb(68, 39, 11);
    } else if (srm == 22.0f) {
      color.setRgb(67, 38, 12);
    } else if (srm == 22.1f) {
      color.setRgb(65, 37, 12);
    } else if (srm == 22.2f) {
      color.setRgb(64, 36, 13);
    } else if (srm == 22.3f) {
      color.setRgb(62, 36, 13);
    } else if (srm == 22.4f) {
      color.setRgb(61, 35, 14);
    } else if (srm == 22.5f) {
      color.setRgb(59, 34, 14);
    } else if (srm == 22.6f) {
      color.setRgb(58, 33, 15);
    } else if (srm == 22.7f) {
      color.setRgb(57, 33, 15);
    } else if (srm == 22.8f) {
      color.setRgb(55, 32, 16);
    } else if (srm == 22.9f) {
      color.setRgb(54, 31, 16);
    } else if (srm == 23.0f) {
      color.setRgb(52, 30, 17);
    } else if (srm == 23.1f) {
      color.setRgb(51, 30, 17);
    } else if (srm == 23.2f) {
      color.setRgb(49, 29, 18);
    } else if (srm == 23.3f) {
      color.setRgb(48, 28, 18);
    } else if (srm == 23.4f) {
      color.setRgb(47, 27, 19);
    } else if (srm == 23.5f) {
      color.setRgb(45, 27, 19);
    } else if (srm == 23.6f) {
      color.setRgb(44, 26, 20);
    } else if (srm == 23.7f) {
      color.setRgb(42, 25, 20);
    } else if (srm == 23.8f) {
      color.setRgb(41, 24, 21);
    } else if (srm == 23.9f) {
      color.setRgb(39, 24, 21);
    } else if (srm == 24.0f) {
      color.setRgb(38, 23, 22);
    } else if (srm == 24.1f) {
      color.setRgb(37, 22, 21);
    } else if (srm == 24.2f) {
      color.setRgb(37, 22, 21);
    } else if (srm == 24.3f) {
      color.setRgb(36, 22, 21);
    } else if (srm == 24.4f) {
      color.setRgb(36, 21, 20);
    } else if (srm == 24.5f) {
      color.setRgb(35, 21, 20);
    } else if (srm == 24.6f) {
      color.setRgb(35, 21, 20);
    } else if (srm == 24.7f) {
      color.setRgb(34, 20, 19);
    } else if (srm == 24.8f) {
      color.setRgb(34, 20, 19);
    } else if (srm == 24.9f) {
      color.setRgb(33, 20, 19);
    } else if (srm == 25.0f) {
      color.setRgb(33, 19, 18);
    } else if (srm == 25.1f) {
      color.setRgb(32, 19, 18);
    } else if (srm == 25.2f) {
      color.setRgb(32, 19, 18);
    } else if (srm == 25.3f) {
      color.setRgb(31, 18, 17);
    } else if (srm == 25.4f) {
      color.setRgb(31, 18, 17);
    } else if (srm == 25.5f) {
      color.setRgb(30, 18, 17);
    } else if (srm == 25.6f) {
      color.setRgb(30, 17, 16);
    } else if (srm == 25.7f) {
      color.setRgb(29, 17, 16);
    } else if (srm == 25.8f) {
      color.setRgb(29, 17, 16);
    } else if (srm == 25.9f) {
      color.setRgb(28, 16, 15);
    } else if (srm == 26.0f) {
      color.setRgb(28, 16, 15);
    } else if (srm == 26.1f) {
      color.setRgb(27, 16, 15);
    } else if (srm == 26.2f) {
      color.setRgb(27, 15, 14);
    } else if (srm == 26.3f) {
      color.setRgb(26, 15, 14);
    } else if (srm == 26.4f) {
      color.setRgb(26, 15, 14);
    } else if (srm == 26.5f) {
      color.setRgb(25, 14, 13);
    } else if (srm == 26.6f) {
      color.setRgb(25, 14, 13);
    } else if (srm == 26.7f) {
      color.setRgb(24, 14, 13);
    } else if (srm == 26.8f) {
      color.setRgb(24, 13, 12);
    } else if (srm == 26.9f) {
      color.setRgb(23, 13, 12);
    } else if (srm == 27.0f) {
      color.setRgb(23, 13, 12);
    } else if (srm == 27.1f) {
      color.setRgb(22, 12, 11);
    } else if (srm == 27.2f) {
      color.setRgb(22, 12, 11);
    } else if (srm == 27.3f) {
      color.setRgb(21, 12, 11);
    } else if (srm == 27.4f) {
      color.setRgb(21, 11, 10);
    } else if (srm == 27.5f) {
      color.setRgb(20, 11, 10);
    } else if (srm == 27.6f) {
      color.setRgb(20, 11, 10);
    } else if (srm == 27.7f) {
      color.setRgb(19, 10, 9);
    } else if (srm == 27.8f) {
      color.setRgb(19, 10, 9);
    } else if (srm == 27.9f) {
      color.setRgb(18, 10, 9);
    } else if (srm == 28.0f) {
      color.setRgb(18, 9, 8);
    } else if (srm == 28.1f) {
      color.setRgb(17, 9, 8);
    } else if (srm == 28.2f) {
      color.setRgb(17, 9, 8);
    } else if (srm == 28.3f) {
      color.setRgb(16, 8, 7);
    } else if (srm == 28.4f) {
      color.setRgb(16, 8, 7);
    } else if (srm == 28.5f) {
      color.setRgb(15, 8, 7);
    } else if (srm == 28.6f) {
      color.setRgb(15, 7, 6);
    } else if (srm == 28.7f) {
      color.setRgb(14, 7, 6);
    } else if (srm == 28.8f) {
      color.setRgb(14, 7, 6);
    } else if (srm == 28.9f) {
      color.setRgb(13, 6, 5);
    } else if (srm == 29.0f) {
      color.setRgb(13, 6, 5);
    } else if (srm == 29.1f) {
      color.setRgb(12, 6, 5);
    } else if (srm == 29.2f) {
      color.setRgb(12, 5, 4);
    } else if (srm == 29.3f) {
      color.setRgb(11, 5, 4);
    } else if (srm == 29.4f) {
      color.setRgb(11, 5, 4);
    } else if (srm == 29.5f) {
      color.setRgb(10, 4, 3);
    } else if (srm == 29.6f) {
      color.setRgb(10, 4, 3);
    } else if (srm == 29.7f) {
      color.setRgb(9, 4, 3);
    } else if (srm == 29.8f) {
      color.setRgb(9, 3, 2);
    } else if (srm == 29.9f) {
      color.setRgb(8, 3, 2);
    } else if (srm == 30.0f) {
      color.setRgb(8, 3, 2);
    }

    return color;
  }
};
