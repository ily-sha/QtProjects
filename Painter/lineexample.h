#ifndef LINEEXAMPLE_H
#define LINEEXAMPLE_H
#include <QPen>
#include <QWidget>

namespace Ui {
class LineExample;
}

class LineExample : public QWidget
{
    Q_OBJECT

public:
    explicit LineExample(QWidget *parent = nullptr);
    ~LineExample();
    QPen* pen;
    void setPen(QPen* pen);


private:
    Ui::LineExample *ui;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // LINEEXAMPLE_H
