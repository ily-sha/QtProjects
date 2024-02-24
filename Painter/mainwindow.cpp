#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MyScene(this);
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView->setScene(scene);
    ui->tableWidget->setColumnCount(5);
    QStringList list;
    list << "Shape type" << "Geometry" << "PenStyle" << "PenWidth" << "Color";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    QHeaderView* pheader =ui->tableWidget->horizontalHeader();
    pheader->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onNewItem(QPen pen, QRectF rect) {
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    QTableWidgetItem* shape = new QTableWidgetItem(QString("rect"));
    QTableWidgetItem* rectSize = new QTableWidgetItem(QString("width: %1; height: %2").arg(rect.width()).arg(rect.height()));
    QString penStyleStr;
    switch (pen.style()) {
    case Qt::PenStyle::SolidLine:
        penStyleStr = "SolidLine";
        break;
    case Qt::PenStyle::DashLine:
        penStyleStr = "DashLine";
        break;
    case Qt::PenStyle::DotLine:
        penStyleStr = "DotLine";
        break;
    case Qt::PenStyle::DashDotLine:
        penStyleStr = "DashDotLine";
        break;
    case Qt::PenStyle::DashDotDotLine:
        penStyleStr = "DashDotDotLine";
        break;
    }
    QTableWidgetItem* penStyle = new QTableWidgetItem(penStyleStr);
    QTableWidgetItem* penWidth = new QTableWidgetItem(QString("%1").arg(pen.width()));
    QTableWidgetItem* color = new QTableWidgetItem(QString("red: %1, blue: %2, green: %3").arg(pen.color().red()).arg(pen.color().blue()).arg(pen.color().green()));
    ui->tableWidget->setItem(row, 0, shape);
    ui->tableWidget->setItem(row, 1, rectSize);
    ui->tableWidget->setItem(row, 2, penStyle);
    ui->tableWidget->setItem(row, 3, penWidth);
    ui->tableWidget->setItem(row, 4, color);
}




void MainWindow::on_actionColor_triggered(){
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid()) {

        QPen *pen = new QPen;
        pen->setColor(color);
        scene->setPen(pen);
    }
}


void MainWindow::on_actionactionSetting_triggered()
{
    Dialog dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        QPen * pen = dlg.getPen();
        scene->setPen(pen);
        qDebug() << pen;
    }

}

