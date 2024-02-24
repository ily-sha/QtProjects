#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
namespace Ui {
class Dialog;
}

class Dialog: public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QPen * pen;
    QPen* getPen();


public slots:
    void thickChanged(int value);
    void colorChooseClicked();
    void styleChanged(int value);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
