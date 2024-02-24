#ifndef MYSCENE_H
#define MYSCENE_H
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsScene>


class MyScene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit MyScene(QWidget *parent = nullptr);
    void setPen(QPen *pen);
signals:
    void addNewItem(QPen pen, QRectF rect);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QAbstractGraphicsShapeItem* currentShape;
    QPointF startDrawingPoint;
    int drawingShape;
    bool isdrawing;
    QPen* pen;
};



#endif // MYSCENE_H
