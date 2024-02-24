#include "widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>
#include <QPainter>
#include <QPaintDevice>


Widget::Widget(QWidget *parent): QWidget(parent){
    bool isDrawing = false;
    bool isСontouring = false;
    bool isMoving = false;
    QPoint startDrawingPoint;
    QRect drawingRect;
    QRect conturingRect;
    drawingPixmap = new QPixmap(rect().width(), rect().height());
    QPainter p(drawingPixmap);
    p.fillRect(rect(), Qt::white);


}

Widget::~Widget(){
}


void Widget::paintEvent(QPaintEvent *event){
    QPainter mainPainter(this);
    mainPainter.drawPixmap(0, 0, *drawingPixmap);
    if (isDrawing){
        drawingRect = QRect(startDrawingPoint, mapFromGlobal(QCursor::pos()));
        mainPainter.drawRect(drawingRect);
    }
    else if (isСontouring) {
        if (drawingRect.contains(mapFromGlobal(QCursor::pos()))){
            conturingRect = QRect(startDrawingPoint, mapFromGlobal(QCursor::pos()));
            QPen pen(Qt::PenStyle::DashLine);
            pen.setColor(Qt::red);
            mainPainter.setPen(pen);
            mainPainter.drawRect(conturingRect);
        }
        else {
            mainPainter.drawPixmap(0, 0, *drawingPixmap);
        }
    }
    else if (isMoving){
        QPainter drawingPainter(drawingPixmap);
        drawingPainter.eraseRect(rect());
        drawingRect.moveTo(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y());
        mainPainter.drawRect(drawingRect);
    }
}

//extra task
void Widget::saveRect(){
    QPainter drawingPainter(drawingPixmap);
    drawingPainter.drawRect(drawingRect);
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
    switch (event->button()) {
    case Qt::MouseButton::RightButton:
        saveRect();
        isDrawing = false;
        break;
    case Qt::MouseButton::LeftButton:
        isСontouring = false;
        break;
    default:
        QWidget::mousePressEvent(event);
    }

}


void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (isDrawing || isСontouring || isMoving) {
        update();
    }
}

void Widget::configLeftButton(QMouseEvent * event){
    if (event->modifiers() & Qt::KeyboardModifier::ShiftModifier){
        isMoving = true;
        return;
    }
    isСontouring = true;
}

void Widget::mousePressEvent (QMouseEvent * event ){
    qDebug() << "mousePressEvent" << isСontouring  << "  " <<isDrawing;
    switch (event->button())
    {
    case Qt::MouseButton::RightButton:
        isDrawing = true;
        startDrawingPoint = mapFromGlobal(QCursor::pos());
        break;
    case Qt::MouseButton::LeftButton:
        configLeftButton(event);
        break;
    default:
        QWidget::mousePressEvent(event);
    }
     qDebug() << "mousePressEvent" << isСontouring  << "  " <<isDrawing;
}




