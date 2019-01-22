#pragma once

#include <QWidget>
#include <QPushButton>

class DruidMenu : public QWidget
{
    Q_OBJECT

    public:
        DruidMenu();

    signals:
        void save();

    private:
        void setupUi();

        QPushButton *_load;
        QPushButton *_save;
        QPushButton *_edit;
};
