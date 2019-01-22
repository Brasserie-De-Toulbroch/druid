#pragma once

#include <QWidget>

#include "ui_central_widget.h"
#include "timer.h"
#include "volume.h"
#include "notes.h"
#include "menu.h"

class DruidCentralWidget: public QWidget, public Ui::DruidCentralWidget
{
    Q_OBJECT

    public:
        DruidCentralWidget();

    private:
        DruidTimer _timer;
        DruidVolume _volume;
        DruidNotes _notes;
        DruidMenu _menu;
};
