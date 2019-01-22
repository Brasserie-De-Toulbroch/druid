#pragma once

#include <QGroupBox>
#include <QTimer>

#include "ui_timer.h"

class DruidTimer: public QGroupBox, public Ui::DruidTimer
{
    Q_OBJECT

    public:
        DruidTimer();

    private:
        void time_start();
        void time_stop();
        void time_update();

        static QString msecs_to_string( int millisecondes );

        QTimer _timer;
        bool _timer_stop = false;
};
