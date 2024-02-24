#ifndef SPIDER_H
#define SPIDER_H
#include <QMouseEvent>
#include <QMainWindow>
#include <QWidget>


class Spider : public QMainWindow
{
    Q_OBJECT

public:
    Spider(QWidget *parent = 0);

    ~Spider();
private:
    QCursor *spCursor;          //Почему это тут????

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent ( QMouseEvent * event );
};

#endif // SPIDER_H
