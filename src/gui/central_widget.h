#pragma once

#include <QTabWidget>

#include "ui_central_widget.h"

class DruidCentralWidget: public QWidget, public Ui::DruidCentralWidget
{
    Q_OBJECT

    public:
        DruidCentralWidget();
};
