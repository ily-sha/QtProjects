#include "myscene.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPainter>

MyScene::MyScene(QWidget *parent) : QGraphicsScene(nullptr){
    this->isdrawing = false;
    setSceneRect(0, 0, 1000, 1000);
    drawingShape = 0;
    pen = new QPen;
    connect(
        this, SIGNAL(addNewItem(QPen, QRectF)),
        (QObject * )parent, SLOT(onNewItem(QPen,QRectF))
    );
}



void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    this->startDrawingPoint = event->scenePos();
    this->currentShape = new QGraphicsRectItem(startDrawingPoint.x(), startDrawingPoint.y(), 0, 0);
    this->currentShape->setPen(*pen);
    this->currentShape->setFlags(QGraphicsItem::ItemIsMovable & QGraphicsItem::ItemIsSelectable);
    this->isdrawing = true;
    this->drawingShape = 1;
    addItem(currentShape);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (drawingShape == 1){
        QGraphicsRectItem* rectItem = qgraphicsitem_cast<QGraphicsRectItem*>(currentShape);
        QRectF rect(startDrawingPoint.x(), startDrawingPoint.y(),
                    std::abs(startDrawingPoint.x() - event->scenePos().x()),
                    std::abs(startDrawingPoint.y() - event->scenePos().y()));

        rectItem->setRect(rect);
        currentShape = rectItem;
    }
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    emit addNewItem(*pen, qgraphicsitem_cast<QGraphicsRectItem*>(currentShape)->rect());
    drawingShape = 0;
    isdrawing = false;
    currentShape = nullptr;
}





void MyScene::setPen(QPen *pen){
    delete this->pen;
    this->pen = pen;
}
