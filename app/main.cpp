#include "main_window.h"
#include <QApplication>
#include <QFontDatabase>
#include <QStyle>
#include <QScreen>
#include <QDesktopWidget>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/PublicSans-VariableFont_wght.ttf");
    QFontDatabase::addApplicationFont(":/PublicSans-Italic-VariableFont_wght.ttf");
    QFontDatabase::addApplicationFont(":/Bauhaus-93.ttf");

    QFile style_file(":/stylesheet.qss");
    style_file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(style_file.readAll());
    app.setStyleSheet(style_sheet);

    MainWindow main_window;
    main_window.setWindowTitle("Hrai-Space");
    main_window.resize(1547, 1000);

    main_window.show();
    return app.exec();
}
