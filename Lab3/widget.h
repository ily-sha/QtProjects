#ifndef WIDGET_H
#define WIDGET_H
#include <QVBoxLayout>
#include <QFrame>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QLayout* createConfigLayout();
    QLayout* createDynamicLayout(int layoutType);
    void connectItems();

    QSpinBox * spinBox;
    QSlider * slider;
    QLineEdit* lineEdit;
    QLabel *label;
    QComboBox * comboBox;


public slots:
    void valueChangedStr(QString str);
    void valueChangedInt(int str);
    void comboBoxChanged(int index);
    void disableButtonClicked();
};


#endif // WIDGET_H
