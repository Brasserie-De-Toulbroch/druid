#include <QApplication>

#include <window.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    DruidWindow window;
    window.show();

    // Druid druid;
    // druid.show();

    // QWidget window;
    // window.setFixedSize(100, 50);

    // QPushButton *button = new QPushButton("Hello World", &window);
    // button->setGeometry(10, 10, 80, 30);

    // window.show();

    return app.exec();
}
