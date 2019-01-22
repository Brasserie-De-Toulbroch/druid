#pragma once

#include <QGroupBox>

#include "ui_volume.h"

class DruidVolume: public QGroupBox, public Ui::DruidVolume
{
    Q_OBJECT

    public:
        struct Tun
        {
            float diameter;
            float height;
        };

        DruidVolume();

    private:
        void compute_sterilizer();
        void compute_boiler();
        void compute_fermentor();
        float volume_in_l( const Tun &tun, float height_from_top ) const;

        Tun _sterilizer;
        Tun _boiler;
        Tun _fermentor;
};
