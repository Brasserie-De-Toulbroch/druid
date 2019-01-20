#pragma once

#include <QWidget>
#include <QTimer>

#include "ui_central_widget.h"

class DruidCentralWidget: public QWidget, public Ui::DruidCentralWidget
{
    Q_OBJECT

    public:
        DruidCentralWidget();

    private:
        void time_start();
        void time_stop();
        void time_update();

        static QString msecs_to_string( int millisecondes );

        QTimer _timer;
        bool _timer_stop = false;
};
