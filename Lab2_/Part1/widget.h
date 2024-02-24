#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QToolTip>
#include <QPixmap>
#include <QCursor>
#include <QResizeEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool isDrawing = false;
    QCursor drawingCurs;
    QCursor generalCurs;


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent ( QMouseEvent * event );
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent * event);
};
#endif // WIDGET_H
