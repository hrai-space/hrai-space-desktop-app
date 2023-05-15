#include <QApplication>
#include <QFontDatabase>
#include <QStyle>
#include <QScreen>
#include <QDesktopWidget>
#include <QFile>
#include <QDebug>
#include <QStyleFactory>

#include "ui/Main_Window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int font_id = QFontDatabase::addApplicationFont(":/OpenSans-VariableFont_wdth,wght.ttf");
    //QFontDatabase::addApplicationFont(":/Bauhaus-93.ttf");

    QFile style_file(":/stylesheet.qss");
    style_file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(style_file.readAll());
    app.setStyleSheet(style_sheet);

    MainWindow main_window;
    main_window.setWindowTitle("Hrai-Space");
    main_window.resize(1280, 1000);
    //main_window.setFixedSize(1547, 1000);
    main_window.show();

    return app.exec();
}
