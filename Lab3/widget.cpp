#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QWidget>
#include <QDebug>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QString>
#include <QComboBox>


Widget::Widget(QWidget *parent): QWidget(parent) {
    QHBoxLayout * mainLayout = new QHBoxLayout(this);
    QFrame * dynamicFrame = new QFrame();
    dynamicFrame->setObjectName("dynamicFrame");
    dynamicFrame->setLayout(createDynamicLayout(0));
    mainLayout->addWidget(dynamicFrame);
    mainLayout->addLayout(createConfigLayout());
    dumpObjectTree();
}

void Widget::comboBoxChanged(int index){
    comboBox->setCurrentIndex(index);
    QFrame * dynamicFrame = findChild<QFrame *>("dynamicFrame");
    QList<QObject *> f = dynamicFrame->children();
    for (QObject * i: f){
        delete i;
    }
    QLayout * newLayout = createDynamicLayout(index);
    dynamicFrame->setLayout(newLayout);
    newLayout->activate();
}


void Widget::disableButtonClicked(){
    QFrame * dynamicFrame = findChild<QFrame *>("dynamicFrame");
    if (dynamicFrame->isEnabled()){
        dynamicFrame->setDisabled(true);
    } else {
         dynamicFrame->setDisabled(false);
    }

}

QLayout* Widget::createConfigLayout(){
    QVBoxLayout * layout = new QVBoxLayout();
    QPushButton * exitButton = new QPushButton("exit");
    exitButton->connect(
        exitButton, SIGNAL(clicked(bool)),
        this, SLOT(close())
    );
    QPushButton * disableButton = new QPushButton("disable");
    connect(
        disableButton, SIGNAL(pressed()),
        this, SLOT(disableButtonClicked())
    );
    comboBox = new QComboBox();
    comboBox->addItem("Horizontal");
    comboBox->addItem("Vertical");
    comboBox->addItem("Grid");
    connect(
        comboBox, SIGNAL(currentIndexChanged(int)),
        this, SLOT(comboBoxChanged(int))
    );
    layout->addWidget(comboBox);
    layout->addWidget(disableButton);
    layout->addWidget(exitButton);
    return layout;
}


void Widget::valueChangedStr(QString changedValue){
    valueChangedInt(changedValue.toInt());
}

void Widget::valueChangedInt(int changedValue){
    slider->setValue(changedValue);
    spinBox->setValue(changedValue);
    lineEdit->setText(QString("%1").arg(changedValue));
    label->setNum(changedValue);
}


void Widget::connectItems() {
    connect(
        spinBox, SIGNAL(valueChanged(int)),
        this, SLOT(valueChangedInt(int))
    );
    connect(
        slider, SIGNAL(valueChanged(int)),
        this, SLOT(valueChangedInt(int))
    );
    connect(
        lineEdit, SIGNAL(textChanged(QString)),
        this, SLOT(valueChangedStr(QString))
    );

}

QLayout* Widget::createDynamicLayout(int layoutType) {
    QLayout * layout;
    switch (layoutType){
    case 0:
        layout = new QHBoxLayout();
        break;
    case 1:
        layout = new QVBoxLayout();
        layout->setAlignment(layout, Qt::AlignCenter);
        break;
    }
    spinBox = new QSpinBox();
    spinBox->setRange(0, 100);
    spinBox->setFixedSize(spinBox->sizeHint());
    slider = new QSlider(Qt::Orientation::Horizontal);
    slider->setRange(0, 100);
    lineEdit = new QLineEdit;
    QIntValidator * intValidator = new QIntValidator(0, 99, lineEdit);
    lineEdit->setValidator(intValidator);
    label = new QLabel();
    if (layoutType == 2){
        QGridLayout * gridLayout = new QGridLayout();
        gridLayout->addWidget(spinBox, 0, 0);
        gridLayout->addWidget(lineEdit, 0, 1);
        gridLayout->addWidget(slider, 1, 0);
        gridLayout->addWidget(label, 1, 1);
        layout = gridLayout;
    } else {
        layout->addWidget(spinBox);
        layout->addWidget(lineEdit);
        layout->addWidget(slider);
        layout->addWidget(label);
    }
    connectItems();
    return layout;
}

Widget::~Widget()
{
}

