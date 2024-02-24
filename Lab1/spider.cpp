#include "spider.h"
#include<QDebug>
#include<QIcon>
#include<QPalette>
#include<QPixmap>
#include<QBrush>
#include<QGuiApplication>
#include<QScreen>
#include<QColorDialog>
#include<QFileDialog>
#include<QMouseEvent>
#include<QWidget>
#include<QToolTip>


Spider::Spider(QWidget *parent): QMainWindow(parent){

//Задание 1. ФЛАГИ
  qDebug() << "Stating window flags: " << this->windowFlags();
  Qt::WindowFlags flags = Qt::Widget;
  flags |= Qt::Dialog;                                  //SplashScreen;
  flags |= Qt::CustomizeWindowHint;                     //Выключает значения флагов, заданных  по умолчанию.
  flags |= Qt::WindowStaysOnTopHint;                    //Информирует оконную систему, что окно должно находиться поверх всех.
  flags |= Qt::WindowTitleHint;                         //Задает заголовок окна.
  flags |= Qt::WindowCloseButtonHint;                   //Добавляет закрывающую кнопку.
  flags |= Qt::WindowShadeButtonHint;
  flags |= Qt::WindowSystemMenuHint;                    //Добавляет системное меню окна, и, возможно, закрывающую кнопку.
  flags |= Qt::WindowMaximizeButtonHint;                //Добавляет кнопку разворачивания
  this->setWindowFlags(flags);
  qDebug() << "Updated window flags: " << this->windowFlags();

//Задание 2. Состояние главного окна приложения
  //Qt::WindowStates st = Qt::WindowMinimized;          //Минимизированное (свернутое в панель задач)
  //Qt::WindowStates st = Qt::WindowMaximized;          //Максимизированное
  Qt::WindowStates st = Qt::WindowNoState;              //Нормальное
  this->setWindowState(st);

//Задание 3. Заголовок главного окна
  this->setWindowTitle(tr("Spider"));


//Задание 4.1. Иконка

  QIcon icon("C:/Users/ilya/Downloads/Burger_148.bmp");
  this->setWindowIcon(icon);

//Задание 4.2. пиктограмма приложения в Windows
  //Не получилось


//Задание 5.1. Сделать цвет фона разным в активном и неактивном состояниях
  QPalette palette = this->palette();
  qDebug() << "Palete: " << palette;
  palette.setColor(QPalette::Active, QPalette::Window, QColor(Qt::blue));
  palette.setColor(QPalette::Inactive, QPalette::Window, QColor(Qt::gray));
  this->setPalette(palette);

//Задание 5.2 картинка в качестве фона окна
  QPixmap pix;
  bool b =pix.load("C:/Users/ilya/Downloads/Burger_148.bmp");
  if (b){  qDebug() << "Picture loaded! ";}
  QBrush brush(pix);
  palette.setColor(QPalette::Active, QPalette::Window, QColor(Qt::blue));
  palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
  this->setPalette(palette);
  this->setWindowOpacity(qreal (0.75));

//Задание 6.1 Размеры и расположение окна
  qDebug() << "Initial Frame Geometry: " << this->frameGeometry();
  qDebug() << "Initial Position: " << this->pos();

//  this->setGeometry(300,500,50,200);

  qDebug() << "Updated Frame Geometry: " << this->frameGeometry();
  qDebug() << "Updated Position: " << this->pos();

//Задание 6.2 окно в любой четверти экрана
  QScreen *screen = QGuiApplication::primaryScreen();
  QRect availableGeometry = screen->availableGeometry();
  double halfScreenW = availableGeometry.width() / 2;
  double halfScreenH = availableGeometry.height() / 2;

  int quadrant = 1;                                                 // Выбор четверти экрана

  double quadrantXOffset = (quadrant % 2) * halfScreenW;
  double quadrantYOffset = (quadrant / 2) * halfScreenH;

  double windowX = availableGeometry.x() + quadrantXOffset;
  double windowY = availableGeometry.y() + quadrantYOffset;

  //this->setGeometry(windowX, windowY, 50, 200);
  qDebug() << "New Updated Position: " << this->pos();

//Задание 6.3 минимальный/максимальный размер окна
//  this->setMaximumSize(1000, 1000);
//  this->setMinimumSize(50, 50);

//Задание 6.4 Фиксированный размер окна
//  QSize imageSize = pix.size();
//  qDebug() << "imageSize: " << imageSize;
//  this->setMaximumSize(imageSize);
//  this->setFixedSize(imageSize);


 //Задание 7.1 любой из предоставляемых Qt курсоров
  this->setCursor(Qt::CursorShape::ForbiddenCursor);

//Задание 7.2 вид курсора.
  QPixmap curs;
  bool l =curs.load("C:/Users/ilya/Downloads/Burger_148.bmp");
  if(l){
      curs.setMask(QBitmap("C:/Users/ilya/Downloads/Burger_148.bmp"));
      QCursor cur(curs);
      this->setCursor(cur);
  }

//Задание 8.1 Диалог для выбора цвета фона
  QColor chosenColor = QColorDialog::getColor(Qt::white, this, "Choose Background Color");
  if (chosenColor.isValid()) {
      QPalette palette = this->palette();
      palette.setColor(QPalette::Active, QPalette::Window, chosenColor);
      this->setPalette(palette);
  }

//Задание 8.1 Загрузка картинки фона
  QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл картинки", ".", "*.png *.jpeg *.jpg");

      if (!fileName.isEmpty()) {
          QPixmap backgroundPixmap;
          bool loaded = backgroundPixmap.load(fileName);
          if (loaded) {
              QPalette palette = this->palette();
              QBrush brush(backgroundPixmap);
              palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
              palette.setColor(QPalette::Active, QPalette::Window, QColor(Qt::blue));
              this->setPalette(palette);
              this->setWindowOpacity(qreal(0.75));

              QSize imageSize = backgroundPixmap.size();
//              this->setMaximumSize(imageSize);
//              this->setFixedSize(imageSize);
          } else {
              qDebug() << "Не удалось загрузить картинку!";
          }
      } else {
          qDebug() << "Выбор файла отменен!";
      }
  }


//2.1 task
void Spider::mousePressEvent (QMouseEvent * event ){
      if (event->button() == Qt::MouseButton::RightButton){
          int x = event->pos().x();
          int y = event->pos().y();
          QString s = QString("x = %1 y = %2").arg(x).arg(y);
          QPoint p (event->globalPos().x(), event->globalPos().y());
//          QToolTip::showText(p, s);
          qDebug() << "mouse event type" << event->pos();
          qDebug() << event->modifiers();
          //2.2 task
          if (event->modifiers() & Qt::KeyboardModifier::ControlModifier){
              QString s = QString("x = %1 y = %2").arg(x).arg(y);
              QPoint p (event->globalPos().x(), event->globalPos().y());
              QToolTip::showText(p, s);
          }

      }
      else {
          QWidget::mousePressEvent(event);      }
}


void Spider::paintEvent(QPaintEvent *event)
{
}


//2 part

Spider::~Spider()
{
}


