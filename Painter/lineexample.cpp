#include "lineexample.h"
#include "ui_lineexample.h"
#include <QDebug>
#include <QPainter>

LineExample::LineExample(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineExample)
{
    ui->setupUi(this);
}

LineExample::~LineExample()
{
    delete ui;
}


void LineExample::setPen(QPen* pen){
    qDebug() << *pen;
    this->pen = pen;
    update();
}


void LineExample::paintEvent(QPaintEvent *event)
{
     qDebug() << "paintEvent";
    QPainter painter(this);
    painter.setPen(*pen);
    painter.setBackground(QBrush(QColor(Qt::yellow)));
    painter.drawLine(0, 0, geometry().x(), geometry().y());
    qDebug() << geometry();

}
