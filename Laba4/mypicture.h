#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>

class MyPicture : public QWidget{
    Q_OBJECT
public:
    explicit MyPicture(QWidget *parent = nullptr);
    QPixmap * pixmap;
    double scale;

public slots:
    void repaintImage(int value);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MYPICTURE_H
