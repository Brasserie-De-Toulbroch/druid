#pragma once

#include <QMainWindow>

#include <central_widget.h>

class DruidWindow : public QMainWindow
{
    Q_OBJECT

    public:
        DruidWindow();

    private:
        DruidCentralWidget _central_widget;
};
