#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool isDrawing;
    bool isСontouring;
    bool isMoving;
    QRect drawingRect;
    QPoint startDrawingPoint;
    QPixmap * drawingPixmap;
    QRect conturingRect;
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * event );
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void saveRect();
    void configLeftButton(QMouseEvent * event);
};

#endif // WIDGET_H
