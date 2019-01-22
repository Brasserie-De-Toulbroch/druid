#pragma once

#include <QGroupBox>

#include "ui_volume.h"

class DruidVolume: public QGroupBox, public Ui::DruidVolume
{
    Q_OBJECT

    public:
        DruidVolume();
};
