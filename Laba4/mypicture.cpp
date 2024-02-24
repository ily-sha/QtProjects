#include "mypicture.h"
#include <QPainter>
#include <QBoxLayout>

MyPicture::MyPicture(QWidget *parent): QWidget{parent}{
    pixmap = new QPixmap;

    scale = 1;
    QPixmap px("C:/Qt/project/Laba4/photo.jpg");
    px = px.scaled(475, 475, Qt::KeepAspectRatio);
    pixmap = new QPixmap(px);
    qDebug() << pixmap->rect();
}


void MyPicture::paintEvent(QPaintEvent *event){
    QRect rect = pixmap->rect();
    int newWidth = rect.width() * scale;
    int newHeight = rect.height() * scale;
    qDebug() << scale << newWidth << newHeight;
    QPainter painter(this);
    painter.drawPixmap(0, 0, newWidth, newHeight, *pixmap);
    qDebug() << this->rect();
}


void MyPicture::repaintImage(int value){
    qDebug() << value;
    scale = value / 100.0;
    update();
}
