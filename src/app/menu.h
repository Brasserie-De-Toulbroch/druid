#include <QWidget>
#include <QPushButton>

class DruidMenu : public QWidget
{
    public:
        DruidMenu();

    private:
        QPushButton *_load;
        QPushButton *_save;
        QPushButton *_edit;
};
