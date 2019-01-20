#include <QApplication>
#include <QFile>
#include <QTextStream>

#include <window.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

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
