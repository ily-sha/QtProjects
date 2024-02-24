#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <myscene.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MyScene *scene;
    ~MainWindow();

public slots:
    void onNewItem(QPen pen, QRectF rect);

private slots:
    void on_actionColor_triggered();
    void on_actionactionSetting_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
