#include "widget.h"
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QResizeEvent>

Widget::Widget(QWidget *parent): QWidget(parent) {
    generalCurs = QCursor(Qt::CursorShape::WaitCursor);
    QPixmap pix;
    pix.load("C:/Qt/project/Lab2_/Part1/icon1.ico");
    drawingCurs = QCursor(pix);
}

//1.1
void Widget::mousePressEvent (QMouseEvent * event ){
    if (event->button() == Qt::MouseButton::RightButton){
        int x = event->pos().x();
        int y = event->pos().y();
        QString s = QString("x = %1 y = %2").arg(x).arg(y);
        QPoint p (event->globalPos().x(), event->globalPos().y());
        //          QToolTip::showText(p, s);
        qDebug() << "mouse event type" << event->pos();
        qDebug() << event->modifiers();
        //2.2 task
        if (event->modifiers() & Qt::KeyboardModifier::ControlModifier){
            QString s = QString("x = %1 y = %2").arg(x).arg(y);
            QPoint p (event->globalPos().x(), event->globalPos().y());
            QToolTip::showText(p, s);
        }

    }
    else {
        if (event->button() == Qt::MouseButton::LeftButton ){
            this->isDrawing = true;
            event->accept();
        }
        else {
            QWidget::mousePressEvent(event);
        }

    }
}

//1.2
void Widget::paintEvent(QPaintEvent *event) {

    qDebug() << "global" << QCursor::pos();
    QPoint clientPos = mapFromGlobal(QCursor::pos());
    qDebug() << "client" << clientPos;
    QPainter painter(this);
    QRect rect  = this->rect();

    painter.drawLine(QPoint(0, 0), clientPos);
    painter.drawLine(QPoint(0, (rect.top()) + rect.bottom()) / 2, clientPos);
    painter.drawLine(QPoint(0, rect.bottom()), clientPos);
    painter.drawLine(QPoint((rect.left() + rect.right()) / 2, 0), clientPos);
    painter.drawLine(QPoint((rect.left() + rect.right()) / 2, rect.bottom()), clientPos);
    painter.drawLine(QPoint(rect.right(),  0), clientPos);
    painter.drawLine(QPoint(rect.right(), (rect.top() + rect.bottom()) / 2), clientPos);
    painter.drawLine(QPoint(rect.right(), rect.bottom()), clientPos);


}

Widget::~Widget()
{
}



void Widget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton){
        this->isDrawing = false;
        setCursor(this->generalCurs);
        event->accept();
    }
    else {
        QWidget::mousePressEvent(event);
    }
}

void Widget::resizeEvent(QResizeEvent * event){
    QSize newSize = event->size();
    QString title = QString("width = %1; height = %2").arg(newSize.width()).arg(newSize.height());
    setWindowTitle(title);
}


void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (isDrawing){
        QPoint cursPoint = QCursor::pos();
        QRect widgetFrame = geometry();
        if (widgetFrame.contains(cursPoint)){
            setCursor(this->drawingCurs);
            update();
        } else {
            unsetCursor();
        }

    }

}
