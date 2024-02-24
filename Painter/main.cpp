#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    settings.setValue("Painter", QDir::toNativeSeparators(QCoreApplication::applicationFilePath()));
    settings.sync();
    MainWindow w;
    w.show();
    return a.exec();
}
