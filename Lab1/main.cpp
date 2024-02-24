#include "spider.h"
#include <QDebug>

#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;                         //создаем переводчик
    translator.load("spider_ru.qm", ".");			//директория - текущая. имя файла  перевода
//    translator.load("spider_ru.qm", "C:\Users\f.zhukov\Documents\QT_VISH\Lab1");
    QApplication ::installTranslator(&translator); 	//применяет переводчик ко всему приложению

    Spider w;

    QString filespec=QString("Spider_");

    filespec += QLocale::system().name();

    w.show();
    return a.exec();
}
