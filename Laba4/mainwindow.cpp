#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    QIntValidator * intValidator = new QIntValidator(0, 99, ui->lineEdit);
    ui->lineEdit->setValidator(intValidator);
    connect(
        ui->lineEdit, SIGNAL(textChanged(QString)),
        this, SLOT(valueChangedStr(QString))
    );
    ui->spinBox_2->setValue(100);
}


void MainWindow::valueChangedStr(QString text){
    ui->spinBox_2->setValue(text.toInt());
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_2_triggered()
{
    QMessageBox::about(this, "Мяу", "Мяяяяяяяу");
}

