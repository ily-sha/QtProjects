#include "dialog.h"
#include "ui_dialog.h"
#include <QColorDialog>

Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog)
{
    ui->setupUi(this);
    pen = new QPen();
    QComboBox* style = ui->style;
    ui->thick->setValue(1);
    style->addItem("SolidLine");
    style->addItem("DashLine");
    style->addItem("DotLine");
    style->addItem("DashDotLine");
    style->addItem("DashDotDotLine");
    qDebug() << ui->lineExample->geometry();
    ui->lineExample->setPen(pen);
    qDebug() << ui->lineExample->geometry();
}

Dialog::~Dialog()
{
    delete ui;
}

QPen* Dialog::getPen(){
    return pen;
}

void Dialog::styleChanged(int style){
    switch (style) {
    case 0:
        pen->setStyle(Qt::PenStyle::SolidLine);
        break;
    case 1:
        pen->setStyle(Qt::PenStyle::DashLine);
        break;
    case 2:
        pen->setStyle(Qt::PenStyle::DotLine);
        break;
    case 3:
        pen->setStyle(Qt::PenStyle::DashDotLine);
        break;
    case 4:
        pen->setStyle( Qt::PenStyle::DashDotDotLine);
        break;
    }
    ui->lineExample->update();
}

void Dialog::thickChanged(int value){
    pen->setWidth(value);
    ui->lineExample->update();
}

void Dialog::colorChooseClicked(){
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid()) {
        pen->setColor(color);
        ui->lineExample->update();
    }

}

