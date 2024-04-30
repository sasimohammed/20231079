#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QInputDialog>
#include <QPainter>
#include <QVector>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QPushButton>
#include<QFileDialog>
#include<QColordialog>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>
#include <QRect>
#include <QDebug>
#include <QDebug>
#include <QMouseEvent>
#include <QRubberBand>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include<dialog2.h>
#include <QGraphicsDropShadowEffect>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QImageWriter>
#include <QMessageBox>
#include <QFileDialog>
#include <QImageWriter>
#include <QFileInfo>
#include <QDir>
#include <QStack>
#include <QImage>
int check;
QColor current;
QImage image3;
int blurRadius;
QList<QPushButton*> buttons;
MainWindow::~MainWindow() { delete ui; }
QImage brightImage;
bool applyFilter = false;

QImage resizedImg ;
QStack<QImage> undoStack;
QStack<QImage> redoStack;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  QPushButton* button1 = ui->bright;
  QPushButton* button2 = ui->blur;
  QPushButton* button3 = ui->gray;
  QPushButton* button4 = ui->poster;
  QPushButton* button5 = ui->flip;
  QPushButton* button6 = ui->flipv;
  QPushButton* button7 = ui->blackwight;
  QPushButton* button8 = ui->frame;
  QPushButton* button9 = ui->sunilght;
  QPushButton* button10 = ui->purprle;
  QPushButton* button11= ui->inverter;
  QPushButton* button12 = ui->resize;
  QPushButton* button13 = ui->oldtv;
  QPushButton* button14= ui->infrafred;
  QPushButton* button15 = ui->dark;
  QPushButton* button16 = ui->detect;

  QPushButton* button17 = ui->rotation;
  QPushButton* button18= ui->merg;
  QPushButton* button19 = ui->crop;
  QPushButton* button20 = ui->popart;

  buttons.append(button1);
  buttons.append(button2);
  buttons.append(button3);
  buttons.append(button4);
  buttons.append(button5);
  buttons.append(button6);
  buttons.append(button7);
  buttons.append(button8);
  buttons.append(button9);
  buttons.append(button10);
  buttons.append(button11);
  buttons.append(button12);
  buttons.append(button13);
  buttons.append(button14);
  buttons.append(button15);
  buttons.append(button16);
  buttons.append(button17);
  buttons.append(button18);
  buttons.append(button19);
buttons.append(button20);

  QVBoxLayout * lay = new QVBoxLayout(this);
  for (QPushButton* button : buttons) {
      lay->addWidget(button);
    }
  ui->scrollContents->setLayout(lay);



  check=1;
  QPixmap pixmap2("C:/Users/Gaming 3/OneDrive/Documents/untitled17/pixekl craft.png");

  QPalette palette;

  this->setPalette(palette);



  palette.setBrush(QPalette::Window, pixmap2);

  this->setPalette(palette);
  if(check==1){
      connect(ui->bar, &QScrollBar::valueChanged, this, &MainWindow::applyBrightness);
    }
  else if(check==0){
      connect(ui->bar, &QScrollBar::valueChanged, this, &MainWindow::applydarkness);
    }
  else{
      connect(ui->bar, &QScrollBar::valueChanged, this, &MainWindow::applyblurs);

    }

  QPixmap pixmap("C:/Users/Gaming 3/OneDrive/Documents/untitled1/before.png");
  ui-> before->setPixmap(pixmap);
  QPixmap pixmap3("C:/Users/Gaming 3/OneDrive/Documents/untitled1/after.png");
  ui->after->setPixmap(pixmap3);
                                  // Replace with the path to your image
  ui->line1->setStyleSheet("QFrame {"
                            "  border: 1px #FFFFFF;"  // Change '2px' to make the line bolder or thinner
                            "}");



         // Check if the image is loaded successfully

  if(pixmap.isNull()) {
      qDebug() << "Failed to load the image!";
    } else {
      // Set the pixmap to the label

    }

  QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
  QGraphicsDropShadowEffect* effect2 = new QGraphicsDropShadowEffect();

  effect->setBlurRadius(10); // Adjust the blur radius to your liking
  effect->setXOffset(6); // Adjust the horizontal offset
  effect->setYOffset(6); // Adjust the vertical offset
  effect->setColor(QColor(100, 100, 100)); // Set the color of the shadow

  ui->image->setGraphicsEffect(effect);
  ui->image2->setGraphicsEffect(effect2);
  ui->image->setStyleSheet("QLabel { background-color : #D8D2D4; }");
  ui->image2->setStyleSheet("QLabel { background-color : #D8D2D4; }");

  ui->brows->setStyleSheet("QPushButton {"
                            "background-color: #0E004C;"  // Original color
                            "border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"  // Adjust as needed
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");


  ui->purprle->setStyleSheet("QPushButton {"
                            "background-color: #0E004C;"  // Original color
                            "border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"  // Adjust as needed
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");
  ui->bright->setStyleSheet("QPushButton {"
                             "background-color: #0E004C; border-radius: 6px;"
                             "width: 200px;"  // Adjust as needed
                             "height: 50px;"                              // Original color
                             "}"
                             "QPushButton:hover {"
                             "background-color: #444444;"  // Change as needed
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #C0408A;"  // Lighter color when pressed
                             "}");

  ui->inverter->setStyleSheet("QPushButton {"
                               "background-color: #0E004C; border-radius: 6px;"
                               "width: 200px;"  // Adjust as needed
                               "height: 50px;"                                // Original color
                               "}"
                               "QPushButton:hover {"
                               "background-color: #444444;"  // Change as needed
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #C0408A;"  // Lighter color when pressed
                               "}");


  ui->dark->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");
  ui->popart->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");

  ui->gray->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");
  ui->infrafred->setStyleSheet("QPushButton {"
                                "background-color:#0E004C; border-radius: 6px;"
                                "width: 200px;"  // Adjust as needed
                                "height: 50px;"                                 // Original color
                                "}"
                                "QPushButton:hover {"
                                "background-color: #444444;"  // Change as needed
                                "}"
                                "QPushButton:pressed {"
                                "background-color: #C0408A;"  // Lighter color when pressed
                                "}");


  ui->oldtv->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");
  ui->flip->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");


  ui->flipv->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");


  ui->sunilght->setStyleSheet("QPushButton {"
                               "background-color:#0E004C; border-radius: 6px;"
                               "width: 200px;"  // Adjust as needed
                               "height: 50px;"                                // Original color
                               "}"
                               "QPushButton:hover {"
                               "background-color: #444444;"  // Change as needed
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #C0408A;"  // Lighter color when pressed
                               "}");

  ui->rotation->setStyleSheet("QPushButton {"
                               "background-color: #0E004C; border-radius: 6px;"
                               "width: 200px;"  // Adjust as needed
                               "height: 50px;"                                // Original color
                               "}"
                               "QPushButton:hover {"
                               "background-color: #444444;"  // Change as needed
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #C0408A;"  // Lighter color when pressed
                               "}");


  ui->blackwight->setStyleSheet("QPushButton {"
                                 "background-color:#0E004C; border-radius: 6px;"
                                 "width: 200px;"  // Adjust as needed
                                 "height: 50px;"                                  // Original color
                                 "}"
                                 "QPushButton:hover {"
                                 "background-color: #444444;"  // Change as needed
                                 "}"
                                 "QPushButton:pressed {"
                                 "background-color: #C0408A;"  // Lighter color when pressed
                                 "}");

  ui->frame->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");


  ui->blur->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");


  ui->resize->setStyleSheet("QPushButton {"
                             "background-color: #0E004C; border-radius: 6px;"
                             "width: 200px;"  // Adjust as needed
                             "height: 50px;"                              // Original color
                             "}"
                             "QPushButton:hover {"
                             "background-color: #444444;"  // Change as needed
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #C0408A;"  // Lighter color when pressed
                             "}");


  ui->merg->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");

  ui->crop->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");
  ui->loadnew->setStyleSheet("QPushButton {"
                              "background-color: #0E004C; border-radius: 6px;"
                              "width: 200px;"  // Adjust as needed
                              "height: 50px;" // Original color
                              "}"
                              "QPushButton:hover {"
                              "background-color: #444444;"  // Change as needed
                              "}"
                              "QPushButton:pressed {"
                              "background-color: #C0408A;"  // Lighter color when pressed
                              "}");
  ui->applymerg->setStyleSheet("QPushButton {"
                                "background-color:#0E004C; border-radius: 6px;"
                                "width: 200px;"  // Adjust as needed
                                "height: 50px;"                                 // Original color
                                "}"
                                "QPushButton:hover {"
                                "background-color: #444444;"  // Change as needed
                                "}"
                                "QPushButton:pressed {"
                                "background-color: #C0408A;"  // Lighter color when pressed
                                "}");
  ui->fancy->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");
  ui->normal->setStyleSheet("QPushButton {"
                             "background-color: #0E004C; border-radius: 6px;"
                             "width: 200px;"  // Adjust as needed
                             "height: 50px;"                              // Original color
                             "}"
                             "QPushButton:hover {"
                             "background-color: #444444;"  // Change as needed
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #C0408A;"  // Lighter color when pressed
                             "}");
  ui->detect->setStyleSheet("QPushButton {"
                             "background-color: #0E004C; border-radius: 6px;"
                             "width: 200px;"  // Adjust as needed
                             "height: 50px;"                              // Original color
                             "}"
                             "QPushButton:hover {"
                             "background-color: #444444;"  // Change as needed
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #C0408A;"  // Lighter color when pressed
                             "}");
  ui->ninie->setStyleSheet("QPushButton {"
                             "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                             "}"
                             "QPushButton:hover {"
                             "background-color: #444444;"  // Change as needed
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #C0408A;"  // Lighter color when pressed
                             "}");
  ui->two->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                          "width: 200px;"  // Adjust as needed
                          "height: 50px;"                           // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");

  ui->eight->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");
  ui->start->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                            "width: 200px;"  // Adjust as needed
                            "height: 50px;"                             // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");
  ui->save->setStyleSheet("QPushButton {"
                            "background-color: #0E004C; border-radius: 6px;"
                           "width: 200px;"  // Adjust as needed
                           "height: 50px;"                            // Original color
                            "}"
                            "QPushButton:hover {"
                            "background-color: #444444;"  // Change as needed
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #C0408A;"  // Lighter color when pressed
                            "}");
  ui->poster->setStyleSheet("QPushButton {"
                           "background-color: #0E004C; border-radius: 6px;"
                             "width: 200px;"  // Adjust as needed
                             "height: 50px;"                              // Original color
                           "}"
                           "QPushButton:hover {"
                           "background-color: #444444;"  // Change as needed
                           "}"
                           "QPushButton:pressed {"
                           "background-color: #C0408A;"  // Lighter color when pressed
                           "}");
  ui->point->setStyleSheet("QPushButton {"
                             "background-color: #0E004C; border-radius: 6px;"
                                                          // Original color
                             "}"
                             "QPushButton:hover {"
                             "background-color: #444444;"  // Change as needed
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #C0408A;"  // Lighter color when pressed
                             "}");
  ui->ninie->hide();
  ui->eight->hide();
  ui->two->hide();
  ui->fancy->hide();
  ui->normal->hide();
  ui->loadnew->hide();
  ui->applymerg->hide();

  ui->point->hide();
  ui->bar->hide();
  ui->purprle->hide();
  ui->gray->hide();
  ui->bright->hide();
  ui->detect->hide();
  ui->merg->hide();
  ui->flip->hide();
    ui->inverter->hide();
  ui->brows->hide();
  ui->crop->hide();
    ui->resize->hide();
    ui->blur->hide();
      ui->frame->hide();
      ui->blackwight->hide();
        ui->rotation->hide();
        ui->image->hide();
          ui->image2->hide();
          ui->sunilght->hide();
            ui->oldtv->hide();
            ui->infrafred->hide();
              ui->dark->hide();
               ui->after->hide();
                ui->before->hide();
                  ui->flipv->hide();
                    ui->line1->hide();
                     ui->save->hide();
                    ui->poster->hide();
                       ui->scrollArea->hide();
}


QImage bright(QImage img, int percent,int w,int h)
{

  double factor = (percent / 100.0) + 1.0;
  for (int i = 0; i < img.width(); ++i)
    {
      for (int j = 0; j < img.height(); ++j)
        {
          QRgb pixel = img.pixel(i, j);
          int r = qBound(0, static_cast<int>(qRed(pixel) * factor), 255);
          int g = qBound(0, static_cast<int>(qGreen(pixel) * factor), 255);
          int b = qBound(0, static_cast<int>(qBlue(pixel) * factor), 255);
          img.setPixel(i, j, qRgb(r, g, b));
        }
    }  QImage resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  check=1;

  return resizedImg;

}
void saveImage(QImage img){
  if (img.isNull()) {
      QMessageBox::warning(nullptr, "Warning", "No image to save.");
      return;
    }

  // Get the file path and name from the user
  QString filePath = QFileDialog::getSaveFileName(nullptr, "Save Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg)");

  if (filePath.isEmpty()) {
      return; // User canceled the dialog
    }

  // Get the file format from the file extension
  QString fileFormat = QFileInfo(filePath).suffix().toLower();

  // Save the image
  QImageWriter writer(filePath, fileFormat.toUtf8());
  if (!writer.write(img)) {
      QMessageBox::critical(nullptr, "Error", "Failed to save image.");
      return;
    }

  QMessageBox::information(nullptr, "Success", "Image saved successfully.");
}
  // Check if the image is valid

void MainWindow::applyBrightness(int value)
{
  // Convert the scrollbar value to brightness percent


  int percent = value;
  int w = ui->image2->width();
  int h = ui->image2->height();
   check=1;
                                 // Apply the brightness filter
  QImage filteredImage = bright(brightImage, percent,w,h);

         // Convert the filtered image to QPixmap and display it

  ui->image2->setPixmap(QPixmap::fromImage(filteredImage).scaled(w, h, Qt::KeepAspectRatio));
}
QImage dark(QImage img, int percent,int w,int h)
{

  double factor =1.00- (percent / 100.0) ;
  for (int i = 0; i < img.width(); ++i)
    {
      for (int j = 0; j < img.height(); ++j)
        {
          QRgb pixel = img.pixel(i, j);
          int r = qBound(0, static_cast<int>(qRed(pixel) * factor), 255);
          int g = qBound(0, static_cast<int>(qGreen(pixel) * factor), 255);
          int b = qBound(0, static_cast<int>(qBlue(pixel) * factor), 255);
          img.setPixel(i, j, qRgb(r, g, b));
        }
    }
  resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  return resizedImg;

}
QImage pop(QImage& image, QColor color,int w,int h)

{
  for (int i = 0; i < image.width(); i++) {
      for (int j = 0; j < image.height(); j++) {
          QColor color = image.pixelColor(i, j);
          int h;
          if (i % 2 == 0 && j % 2 == 0) {
              h = qMax(0, color.red() - 50);
              color.setRed(h);
              h = qMax(0, color.green() - 50);
              color.setGreen(h);
              h = qMax(0, color.blue() - 50);
              color.setBlue(h);
            } else {
              h = qMin(255, color.red() + 50);
              color.setRed(h);
              h = qMin(255, color.green() + 50);
              color.setGreen(h);
              h = qMin(255, color.blue() + 50);
              color.setBlue(h);
            }
          image.setPixelColor(i, j, color);
        }
    }
  for (int i = 0; i < image.width(); i++) {
      for (int j = 0; j < image.height(); j++) {
          QColor color2 = image.pixelColor(i, j);
          // Calculate luminance
          int in = (int) (0.2126 * color2.red() + 0.7152 * color2.green() + 0.0722 * color2.blue());
          if (in >= 128) {
              // Change color to userColor
              color2.setRed(color.red());
              color2.setGreen(color.green());
              color2.setBlue(color.blue());
            } else {
              // Change color to dark yellow
              color2.setRed(color.red()/2);
              color2.setGreen(color.green()/2);
              color2.setBlue(color.blue()/2);

            }
          image.setPixelColor(i, j, color2);
        }
    }


   resizedImg =image.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  return resizedImg;

}

void MainWindow::applydarkness(int value)
{
  // Convert the scrollbar value to brightness percent
  int percent = value;
  int w = ui->image2->width();
  int h = ui->image2->height();
                                // Apply the brightness filter
  QImage filteredImage = dark(brightImage, percent,w,h);

         // Convert the filtered image to QPixmap and display it

  ui->image2->setPixmap(QPixmap::fromImage(filteredImage).scaled(w, h, Qt::KeepAspectRatio));
}
QImage light_blur(QImage img,int percent,int w,int h)
{

  blurRadius=percent;
  QVector<QVector<QVector<int>>> prefixSum(img.width(), QVector<QVector<int>>(img.height(), QVector<int>(3, 0)));


         // Calculate prefix sum for each color channel
  for (int k = 0; k < 3; k++) {
      // Calculate prefix sum for the first row
      for (int i = 0; i < img.height(); i++) {
          QColor color = img.pixelColor(0, i);
          int channelValue = (k == 0) ? color.red() : (k == 1) ? color.green() : color.blue();
          prefixSum[0][i][k] = channelValue;
          for (int j = 1; j < img.width(); j++) {
              color = img.pixelColor(j, i);
              channelValue = (k == 0) ? color.red() : (k == 1) ? color.green() : color.blue();
              prefixSum[j][i][k] = prefixSum[j - 1][i][k] + channelValue;
            }
        }
      // Calculate prefix sum for each cell in the image
      for (int i = 0; i < img.height(); i++) {
          for (int j = 0; j < img.width(); j++) {
              if (i > 0) {
                  prefixSum[j][i][k] += prefixSum[j][i - 1][k];
                }
            }
        }
    }

         // Apply the blur using the prefix sum
  QImage blurredImage(img.width(), img.height(), img.format());
  for (int i = 0; i < img.height(); i++) {
      for (int j = 0; j < img.width(); j++) {
          int r = 0, g = 0, b = 0;
          for (int k = 0; k < 3; k++) {
              int sum = prefixSum[qMin(j + blurRadius, img.width() - 1)][qMin(i + blurRadius, img.height() - 1)][k]
                        - (j - blurRadius > 0 ? prefixSum[j - blurRadius - 1][qMin(i + blurRadius, img.height() - 1)][k] : 0)
                        - (i - blurRadius > 0 ? prefixSum[qMin(j + blurRadius, img.width() - 1)][i - blurRadius - 1][k] : 0)
                        + ((j - blurRadius > 0 && i - blurRadius > 0) ? prefixSum[j - blurRadius - 1][i - blurRadius - 1][k] : 0);
              if (k == 0) r = sum / ((2 * blurRadius + 1) * (2 * blurRadius + 1));
              else if (k == 1) g = sum / ((2 * blurRadius + 1) * (2 * blurRadius + 1));
              else b = sum / ((2 * blurRadius + 1) * (2 * blurRadius + 1));
            }
          blurredImage.setPixelColor(j, i, QColor(r, g, b));
        }
    }

  img = blurredImage;
  check=2;// Update the original image with the blurred image
  QImage resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  return resizedImg;


}


QImage gray(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  img = img.convertToFormat(QImage::Format_ARGB32);

  int width = img.width();
  int height = img.height();

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = qRed(pixel);
          int g = qGreen(pixel);
          int b = qBlue(pixel);

                 // Calculate the average of RGB values
          int avg = (r + g + b) / 3;

                 // Set the new pixel value
          QRgb newPixel = qRgb(avg, avg, avg);
          img.setPixel(i, j, newPixel);
        }
    }
  QImage resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  return resizedImg;

}
QImage purple(QImage& image, QColor current,int w,int h)
{
  if (!applyFilter) {
      return image;
    }

  int chosenHue = current.hue();

  for (int i = 0; i < image.width(); i++) {
      for (int j = 0; j < image.height(); j++) {
          QColor color(image.pixel(i, j));

                 // Convert to HSV color space
          int h, s, v;
          color.getHsv(&h, &s, &v);

                 // Adjust the hue to match that of the chosen color
          color.setHsv(chosenHue, s, v);

          image.setPixelColor(i, j, color);
        }

    }
      // Scale the image to exactly match the size of the label
   resizedImg = image.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  return resizedImg;
}

QImage blackandwight(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  if (!applyFilter) {
      return img;
    }
  img = img.convertToFormat(QImage::Format_ARGB32);

  int width = img.width();
  int height = img.height();

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = qRed(pixel);
          int g = qGreen(pixel);
          int b = qBlue(pixel);

                 // Calculate the average of RGB values
          int avg = (r + g + b) ;
          if(avg>=255){
              QRgb newPixel = qRgb(255,255, 255);
              img.setPixel(i, j, newPixel);

            }
          else{

              QRgb newPixel = qRgb(0, 0, 0);
              img.setPixel(i, j, newPixel); // Set the new pixel value

            }
        }
    }
 resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  return resizedImg;


}
QImage inverter(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }

  img = img.convertToFormat(QImage::Format_ARGB32);

  int width = img.width();
  int height = img.height();

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = 255 - qRed(pixel);
          int g = 255 - qGreen(pixel);
          int b = 255 - qBlue(pixel);

                 // Set the new pixel value
          QRgb newPixel = qRgb(r, g, b);
          img.setPixel(i, j, newPixel);
        }
    }
  resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  return resizedImg;

}
QImage flipH(QImage& image,int w,int h)
{
  if (!applyFilter) {
      return image;
    }
  QImage image2 = QImage(image.width(), image.height(), QImage::Format_ARGB32);
  for (int i = 0; i < image2.width(); i++)
    {
      for (int j = 0; j < image2.height(); j++)
        {
          // Get the pixel from the original image
          QRgb pixel = image.pixel(image.width() - 1 - i, j);

                 // Copy pixel from original image to flipped image
          image2.setPixel(i, j, pixel);
        }
    }     brightImage = image2.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;

}
QImage flipV(QImage& image,int w,int h)
{
 undoStack.push(image);//
  if (!applyFilter) {
      return image;
    }
  QImage image2 = QImage(image.width(), image.height(), QImage::Format_ARGB32);
  for (int i = 0; i < image2.width(); i++)
    {
      for (int j = 0; j < image2.height(); j++)
        {
          // Get the pixel from the original image
          QRgb pixel = image.pixel(i, image.height() - 1 - j);

                 // Copy pixel from original image to flipped image
          image2.setPixel(i, j, pixel);
        }
    }
  brightImage = image2.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;
}
QImage sunlight(QImage& image,int w,int h)
{


  undoStack.push(image);//thie the original with teh original size
  if (!applyFilter) {
      return image;
    }
  // Convert to 32 bit format for easy pixel manipulation
  image = image.convertToFormat(QImage::Format_ARGB32);

  int width = image.width();
  int height = image.height();

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = image.pixel(i, j);
          int r = qRed(pixel);
          int g = qGreen(pixel);
          int b = qBlue(pixel);

                 // Reduce the intensity of the blue channel by 30%
          b = static_cast<int>(b * 0.7);

                 // Set the new pixel value
          QRgb newPixel = qRgb(r, g, b);
          image.setPixel(i, j, newPixel);
        }
    }
   resizedImg = image.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(resizedImg);
  return resizedImg;


}
QImage flip_90(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  QImage image2(img.height(), img.width(), QImage::Format_RGB32);
  for(int i=0; i<image2.width(); i++)
    {
      for(int j=0; j<image2.height(); j++)
        {
          QColor color(img.pixelColor(j, img.height()-1-i));
          image2.setPixelColor(i, j, color);
        }
    }
  brightImage = image2.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;

  // Convert to 32 bit format for easy pixel manipulation


}
QImage poster(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  int levels = 3;  // Number of color levels (adjust as needed)
  int scale = 256 / levels;

// Assume this is your image
  for(int i=0; i<img.width(); i++){
      for(int j=0; j<img.height(); j++){
          QColor color(img.pixel(i,j));
          int r = (color.red() / scale) * scale;
          int g = (color.green() / scale) * scale;
          int b = (color.blue() / scale) * scale;
          img.setPixel(i, j, qRgb(r,g,b));
        }
    }
  double factor = (50/ 100.0) + 1.0;
  for (int i = 0; i < img.width(); ++i)
    {
      for (int j = 0; j < img.height(); ++j)
        {
          QRgb pixel = img.pixel(i, j);
          int r = qBound(0, static_cast<int>(qRed(pixel) * factor), 255);
          int g = qBound(0, static_cast<int>(qGreen(pixel) * factor), 255);
          int b = qBound(0, static_cast<int>(qBlue(pixel) * factor), 255);
          img.setPixel(i, j, qRgb(r, g, b));
        }
    }

  brightImage = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;

         // Convert to 32 bit format for easy pixel manipulation


}

QImage frame(QImage&image, QColor color,int w,int h)
{
  for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
        {
          // Check if pixel is within the frame boundaries
          if (((i >= 0 && i <= 25) || (j >= 0 && j <= 25) || (i >= image.width() - 25 && i <= image.width() - 1) ||
               (j >= image.height() - 25 && j <= image.height() - 1)))
            {
              image.setPixelColor(i, j, color);
            }

        }
    }
  brightImage = image.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;
}



       // Convert to 32 bit format for easy pixel manipulation
QImage fancy_frame(QImage& image,QColor color,int w,int h)
{
  if (!applyFilter) {
      return image;
    }
  // Assuming 'image' is a QImage object

  for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
        {
          // Loop through each color channel (RGB)
          for (int k = 0; k < 3; k++)
            {
              // Outer frame (gray border)
              if (((i >= 0 && i <= 10) || (j >= 0 && j <= 10) || (i >= image.width() - 10 && i <= image.width() - 1) || (j >= image.height() - 10 && j <= image.height() - 1)))
                {
                  image.setPixelColor(i, j, QColor(241, 241, 241)); // Gray color
                }

                     // Blue border
              if ((((j > 10 && j <= 25) && (i > 10 && i < image.width() - 10)) || ((j >= image.height() - 25 && j < image.height() - 10) && (i > 10 && i < image.width() - 10)) || ((i > 10 && i <= 25) && (j > 10 && j <= image.height() - 25)) || ((i >= image.width() - 25 && i < image.width() - 10) && (j > 10 && j <= image.height() - 25))) && k == 0)
                {
                  image.setPixelColor(i, j, color); // Blue color
                }

                     // Green border
              if ((((j > 10 && j <= 25) && (i > 10 && i < image.width() - 10)) || ((j >= image.height() - 25 && j < image.height() - 10) && (i > 10 && i < image.width() - 10)) || ((i > 10 && i <= 25) && (j > 10 && j <= image.height() - 25)) || ((i >= image.width() - 25 && i < image.width() - 10) && (j > 10 && j <= image.height() - 25))) && k == 1)
                {
                  image.setPixelColor(i, j, color); // Green color
                }

                     // Red border
              if ((((j > 10 && j <= 25) && (i > 10 && i < image.width() - 10)) || ((j >= image.height() - 25 && j < image.height() - 10) && (i > 10 && i < image.width() - 10)) || ((i > 10 && i <= 25) && (j > 10 && j <= image.height() - 25)) || ((i >= image.width() - 25 && i < image.width() - 10) && (j > 10 && j <= image.height() - 25))) && k == 2)
                {
                  image.setPixelColor(i, j, color);
                }

                     // Thin white frame inside the outer frame
              if ((i >= 20 && i < 21) || (i >= image.width() - 21 && i < image.width() - 20) || (j >= 20 && j < 21) || (j >= image.height() - 21 && j < image.height() - 20))
                {
                  image.setPixelColor(i, j, QColor(255, 255, 255)); // White color
                }

                     // White frame inside the blue border
              if ((((j > 25 && j <= 33) && (i > 25 && i < image.width() - 25)) || ((j >= image.height() - 33 && j < image.height() - 25) && (i > 25 && i < image.width() - 25)) || ((i > 25 && i <= 33) && (j > 25 && j <= image.height() - 33)) || ((i >= image.width() - 33 && i < image.width() - 25) && (j > 25 && j <= image.height() - 33))))
                {
                  image.setPixelColor(i, j, QColor(255, 255, 255)); // White color
                }

                     // Two mini gray frames
              if ((((j > 27 && j <= 30) && (i > 27 && i < image.width() - 30)) || ((j >= image.height() - 30 && j < image.height() - 27) && (i > 27 && i < image.width() - 27)) || ((i > 27 && i <= 30) && (j > 27 && j <= image.height() - 30)) || ((i >= image.width() - 30 && i < image.width() - 27) && (j > 27 && j <= image.height() - 30))) || ((((j > 31 && j <= 33) && (i > 31 && i < image.width() - 33)) || ((j >= image.height() - 33 && j < image.height() - 31) && (i > 31 && i < image.width() - 31)) || ((i > 31 && i <= 33) && (j > 31 && j <= image.height() - 33)) || ((i >= image.width() - 33 && i < image.width() - 31) && (j > 31 && j <= image.height() - 33)))))
                {
                  image.setPixelColor(i, j, QColor(188, 188, 188)); // Gray color
                }

                     // Mini square inside the blue border
              if ((j > 33 && j <= 43 && i > 33 && i <= 43) || (i >= image.width() - 43 && i < image.width() - 33 && j > 33 && j <= 43) || (j >= image.height() - 43 && j < image.height() - 33 && i > 33 && i <= 43) || (i >= image.width() - 43 && i < image.width() - 33 && j >= image.height() - 43 && j < image.height() - 33))
                {
                  image.setPixelColor(i, j, QColor(255, 255, 255)); // White color
                }

                     // Horizontal line of the bigger square
              if (((j >= 47 && j <= 50) && (i > 33 && i <= 47)) || ((j >= 47 && j <= 50) && (i >= image.width() - 47 && i < image.width() - 33)) || ((j <= image.height() - 47 && j >= image.height() - 50) && (i >= image.width() - 47 && i < image.width() - 33)) || ((j <= image.height() - 47 && j >= image.height() - 50) && (i > 33 && i <= 47)))
                {
                  image.setPixelColor(i, j, QColor(255, 255, 255)); // White color
                }

                     // Vertical line of the bigger square
              if (((i >= 47 && i <= 50) && (j > 33 && j <= 50)) || ((i >= 47 && i <= 50) && (j >= image.height() - 50 && j < image.height() - 33)) || ((i <= image.width() - 47 && i >= image.width() - 50) && (j >= image.height() - 50 && j < image.height() - 33)) || ((i <= image.width() - 47 && i >= image.width() - 50) && (j > 33 && j <= 50)))
                {
                  image.setPixelColor(i, j, QColor(255, 255, 255)); // White color
                }
            }
        }
    }


   resizedImg = image.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  return resizedImg;


         // Convert to 32 bit format for easy pixel manipulation


}
QImage flip_180(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  QImage image2(img.width(),img.height(), QImage::Format_RGB32);
  for(int i=0; i<image2.width(); i++)
    {
      for(int j=0; j<image2.height(); j++)
        {
          QColor color(img.pixelColor(img.width()-1-i, img.height()-1-j));
          image2.setPixelColor(i, j, color);
        }
    }
  brightImage = image2.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;
  // Convert to 32 bit format for easy pixel manipulation


}
QImage flip_270(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  QImage image2(img.height(), img.width(), QImage::Format_RGB32);
  for(int i=0; i<img.width(); i++)
    {
      for(int j=0; j<img.height(); j++)
        {
          QColor color(img.pixelColor(i, j));
          image2.setPixelColor(j, img.width()-1-i, color);
        }
    }
  brightImage = image2.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  redoStack.push(brightImage);
  resizedImg=  brightImage;
  return resizedImg;

  // Convert to 32 bit format for easy pixel manipulation


}
QImage detect(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }
  img = img.convertToFormat(QImage::Format_ARGB32);

  int width = img.width();
  int height = img.height();

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = qRed(pixel);
          int g = qGreen(pixel);
          int b = qBlue(pixel);

                 // Calculate the average of RGB values
          int avg = (r + g + b) ;
          if(avg>=255){
              QRgb newPixel = qRgb(255,255, 255);
              img.setPixel(i, j, newPixel);

            }
          else{

              QRgb newPixel = qRgb(0, 0, 0);
              img.setPixel(i, j, newPixel); // Set the new pixel value

            }
        }
    }
  for (int i = 0; i < img.width() - 1; i++) {
      for (int j = 1; j < img.height() - 1; j++) {
          int d = std::min(img.width(), img.height()) / 200; // Border to be 0.05% of the min length
          if ((img.pixelColor(i, j).red() == 0 && img.pixelColor(i, j + 1).red() == 255) || // Horizontal right
              (img.pixelColor(i, j).red() == 255 && img.pixelColor(i, j + 1).red() == 0) || // Horizontal left
              (img.pixelColor(i + 1, j).red() == 0 && img.pixelColor(i, j).red() == 255) || // Vertical down
              (img.pixelColor(i + 1, j).red() == 255 && img.pixelColor(i, j).red() == 0) || // Vertical up
              (img.pixelColor(i + 1, j + 1).red() == 0 && img.pixelColor(i, j).red() == 255) || // Diagonal down-right
              (img.pixelColor(i + 1, j + 1).red() == 255 && img.pixelColor(i, j).red() == 0) || // Diagonal up-left
              (img.pixelColor(i + 1, j - 1).red() == 0 && img.pixelColor(i, j).red() == 255) || // Diagonal down-left
              (img.pixelColor(i + 1, j - 1).red() == 255 && img.pixelColor(i, j).red() == 0)) // Diagonal up-right
            {
              int D = d + j;
              for (; j < D && j < img.height() - 1; j++) {
                  for (int l = 0; l < img.depth(); l++) {
                      // Set pixel to black
                      img.setPixelColor(i, j, QColor(0, 0, 0));
                    }
                }
              j--; // Adjust j to skip the already processed pixels
            }
          else {
              for (int l = 0; l < img.depth(); l++) {
                  // Set pixel to white
                  img.setPixelColor(i, j, QColor(255, 255, 255));
                }
            }
        }
    }

   resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  return resizedImg;
  // Convert to 32 bit format for easy pixel manipulation
}


QImage crop(QImage& img,int w,int h,int x, int y)
{
  if (!applyFilter) {
      return img;
    }

  QImage img_new(w, h, QImage::Format_RGB32);
  for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
          QColor oldColor = img.pixelColor(x+ i, y + j);
          img_new.setPixelColor(i, j, oldColor);
        }
    }

  return img_new;
  // Convert to 32 bit format for easy pixel manipulation


}




void MainWindow::applyblurs(int value)
{
  // Convert the scrollbar value to brightness percent
  int percent = value;
  int w = ui->image2->width();
  int h = ui->image2->height();
                                 // Apply the brightness filter
  QImage filteredImage = light_blur(brightImage, percent,w,h);

         // Convert the filtered image to QPixmap and display it

  ui->image2->setPixmap(QPixmap::fromImage(filteredImage).scaled(w, h, Qt::KeepAspectRatio));
}


       // Convert to 32 bit format for easy pixel manipulation

QImage oldtv(QImage& img,int w,int h)
{
  if (!applyFilter) {
      return img;
    }


         // Convert to 32 bit format for easy pixel manipulation
  img = img.convertToFormat(QImage::Format_ARGB32);

  int width = img.width();
  int height = img.height();

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = qRed(pixel);
          int g = qGreen(pixel);
          int b = qBlue(pixel);

                 // Iterate over RGB channels
          // Iterate over RGB channels
          for(int k = 0; k < 3; ++k) {
              int random = rand() % 20; // Generate a random value between 0 and 39
              if (j % 2 == 0) { // For even rows
                  if (r - random < 0)
                    r = 0; // Ensure pixel value does not go below 0
                  else
                    r -= random; // Decrease pixel value by random amount
                  if (g - random < 0)
                    g = 0; // Ensure pixel value does not go below 0
                  else
                    g -= random; // Decrease pixel value by random amount
                  if (b - random < 0)
                    b = 0; // Ensure pixel value does not go below 0
                  else
                    b -= random; // Decrease pixel value by random amount
                }
              else { // For odd rows
                  if (r + random > 255)
                    r = 255; // Ensure pixel value does not exceed 255
                  else
                    r += random; // Increase pixel value by random amount
                  if (g + random > 255)
                    g = 255; // Ensure pixel value does not exceed 255
                  else
                    g += random; // Increase pixel value by random amount
                  if (b + random > 255)
                    b = 255; // Ensure pixel value does not exceed 255
                  else
                    b += random; // Increase pixel value by random amount
                }
            }

                 // Set the new pixel value
          QRgb newPixel = qRgb(r, g, b);
          img.setPixel(i, j, newPixel);
        }
    }
   resizedImg = img.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  return resizedImg;


}

QImage infrared(QImage& img)
{
  if (!applyFilter) {
      return img;
    }
  // Convert to 32 bit format for easy pixel manipulation
  img = img.convertToFormat(QImage::Format_ARGB32);


  for(int i = 0; i < img.width(); ++i) {
      for(int j = 0; j < img.height(); ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = qRed(pixel);
          double g = qGreen(pixel);
          double b = qBlue(pixel);

                 // Calculate luminance
          int luminance = static_cast<int>(0.2126 * r + 0.7152 * g + 0.0722 * b);

                 // Map luminance to a gradient of red shades
          r = 255 - luminance; // Invert luminance to get red shades
          g = 0;
          b = 0;

                 // Set the new pixel value
          QRgb newPixel = qRgb(r, g, b);
          img.setPixel(i, j, newPixel);
        }
    }


  return img;
}
QImage draw(QImage image)
{
  if (!applyFilter) {
      return image;
    }


         // Convert to 32 bit format for easy pixel manipulation
  QPainter painter(&image);

         // Set the color and width of the grid lines
  QPen pen;
  pen.setColor(Qt::black);
  pen.setWidth(1);

  painter.setPen(pen);

         // Determine the size of the squares in the grid
  int squareSize = 100; // Change this value to adjust the size of the squares

         // Draw the grid lines
  for (int x = 0; x < image.width(); x += squareSize)
    {
      painter.drawLine(x, 0, x, image.height());
    }
  for (int y = 0; y < image.height(); y += squareSize)
    {
      painter.drawLine(0, y, image.width(), y);
    }

         // End painting
  painter.end();
  return image;

}


QImage resize(QImage &img,int width,int height)
{
  if (!applyFilter) {
      return img;
    }
  resizedImg = img.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  return resizedImg;

}

void MainWindow::on_brows_clicked()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.xpm *.jpg)"));
  if (!fileName.isEmpty())
    {
      QPixmap image;
      image.load(fileName);

      int w = ui->image->width();
      int h = ui->image->height();

             // Scale the image to exactly match the size of the label
      ui->image->setPixmap(image.scaled(w, h));

      brightImage = image.toImage(); // Convert QPixmap to QImage and store it in brightImage
    }
}

QImage merg(QImage& img1,QImage& img2,int w,int h)
{
  if (!applyFilter) {
      return img1;
    }
  int width;
  int height;

  if (img1.width() * img1.height() >= img2.width() * img2.height())
    {
      width = img1.width();
      height = img1.height();

      QImage img_new_1 = img2.scaled(width, height);

      QImage img_merged(width, height, QImage::Format_RGB32);
      for (int i = 0; i <img_new_1.width(); i++)
        {
          for (int j = 0; j < img_new_1.height(); j++)
            {
              QColor color1 = img_new_1.pixelColor(i, j);
              QColor color2 = img1.pixelColor(i, j);

              int r = (color1.red() + color2.red()) / 2;
              int g = (color1.green() + color2.green()) / 2;
              int b = (color1.blue() + color2.blue()) / 2;

              img_merged.setPixelColor(i, j, QColor(r, g, b));
            }
        }
      QImage resizedImg =  img_merged.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

      return resizedImg;

    }
  else
    {
      width = img2.width();
      height = img2.height();

      QImage img_new_2 = img1.scaled(width, height);

      QImage img_merged(width, height, QImage::Format_RGB32);
      for (int i = 0; i < img_new_2.width(); i++)
        {
          for (int j = 0; j < img_new_2.height(); j++)
            {
              QColor color1 = img_new_2.pixelColor(i, j);
              QColor color2 = img2.pixelColor(i, j);

              int r = (color1.red() + color2.red()) / 2;
              int g = (color1.green() + color2.green()) / 2;
              int b = (color1.blue() + color2.blue()) / 2;

              img_merged.setPixelColor(i, j, QColor(r, g, b));
            }
        }
       resizedImg =  img_merged.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

      return resizedImg;

    }
}





void MainWindow::on_purprle_clicked()
{
  applyFilter = true;

  QColorDialog dialog(this);
  QPalette palette;
  palette.setColor(QPalette::Window, Qt::blue);
  dialog.setPalette(palette);
  dialog.setOption(QColorDialog::DontUseNativeDialog);

         // Use the dialog with the custom palette
  QColor color = dialog.getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
      current = color;
      // Apply the color filter to the image here
    }

  int w = ui->image2->width();
  int h = ui->image2->height();

         // Apply the purple filter to brightImage and convert it to QPixmap
  QPixmap pixmap = QPixmap::fromImage(purple(brightImage, current,w,h));

         // Scale the pixmap to fit ui->image2 and set it
  ui->image2->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
}




void MainWindow::on_bright_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();

  ui->image2->setPixmap(QPixmap::fromImage(bright(brightImage, 0,w,h)).scaled(w, h, Qt::KeepAspectRatio));
  if (applyFilter) {
 check=1;
      ui->bar->show();
    } else {

      ui->bar->hide();
    }

}

void MainWindow::on_dark_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();

  ui->image2->setPixmap(QPixmap::fromImage(dark(brightImage, 0,w,h)).scaled(w, h, Qt::KeepAspectRatio));
  if (applyFilter) {

      ui->bar->show();
    } else {

      ui->bar->hide();
    }

}

void MainWindow::on_gray_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(gray(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_inverter_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(inverter(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_blackwight_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(blackandwight(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_infrafred_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(infrared(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_oldtv_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(oldtv(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_flip_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(flipH(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));
}
void MainWindow::on_flipv_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(flipV(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_sunilght_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(sunlight(brightImage, w, h)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_rotation_clicked()
{
  applyFilter = true;
  if (!applyFilter) {
      ui->ninie->hide();
      ui->eight->hide();
      ui->two->hide();
    } else {
      ui->ninie->show();
      ui->eight->show();
      ui->two->show();
       ui->point->hide();
        ui->applymerg->hide();
         ui->loadnew->hide();
          ui->fancy->hide();
           ui->normal->hide();

    }

         // Toggle the state of the buttons
}
void MainWindow::on_eight_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(flip_90(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_ninie_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(flip_180(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_two_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(flip_270(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_frame_clicked()
{
  applyFilter = true;
  if (!applyFilter) {
      ui->fancy->hide();
      ui->normal->hide();

    } else {
      ui->fancy->show();
      ui->normal->show();
       ui->point->hide();
         ui->loadnew->hide();
            ui->applymerg->hide();
             ui->ninie->hide();
             ui->eight->hide();
              ui->two->hide();


    }
}
void MainWindow::on_fancy_clicked()
{
  applyFilter = true;
  QColorDialog dialog(this);
  QPalette palette;
  palette.setColor(QPalette::Window, Qt::blue);
  dialog.setPalette(palette);
  dialog.setOption(QColorDialog::DontUseNativeDialog);

         // Use the dialog with the custom palette
  QColor color = dialog.getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
      current = color;
      // Apply the color filter to the image here
    }

  int w = ui->image2->width();
  int h = ui->image2->height();

         // Apply the purple filter to brightImage and convert it to QPixmap
  ui->image2->setPixmap(QPixmap::fromImage(fancy_frame(brightImage,current,w,h).scaled(w, h, Qt::KeepAspectRatio)));
}

void MainWindow::on_normal_clicked()
{
  applyFilter = true;
  QColorDialog dialog(this);
  QPalette palette;
  palette.setColor(QPalette::Window, Qt::blue);
  dialog.setPalette(palette);
  dialog.setOption(QColorDialog::DontUseNativeDialog);

         // Use the dialog with the custom palette
  QColor color = dialog.getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
      current = color;
      // Apply the color filter to the image here
    }

  int w = ui->image2->width();
  int h = ui->image2->height();

         // Apply the purple filter to brightImage and convert it to QPixmap
  ui->image2->setPixmap(QPixmap::fromImage(frame(resizedImg,current,w,h).scaled(w, h, Qt::KeepAspectRatio)));

}

void MainWindow::on_blur_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();

  ui->image2->setPixmap(QPixmap::fromImage(light_blur(brightImage, 0,w,h)).scaled(w, h, Qt::KeepAspectRatio));
  if (!applyFilter) {

      ui->bar->show();
    } else {

      ui->bar->show();
    }

}
void MainWindow::on_resize_clicked()
{
  bool ok;
  int newWidth = QInputDialog::getInt(this, tr("Resize Image"),
                                       tr("Enter new width:"), 100, 1, 10000, 1, &ok);

  if (ok) {
      int newHeight = QInputDialog::getInt(this, tr("Resize Image"),
                                            tr("Enter new height:"), 100, 1, 10000, 1, &ok);

      if (ok) {
          int width;
          width =newWidth;
          int hieght=   newHeight;

          ui->image2->setPixmap(QPixmap::fromImage(brightImage).scaled(width, hieght, Qt::KeepAspectRatio));


        }
    }
}

void MainWindow::on_merg_clicked()
{
  applyFilter = true;
  if (applyFilter) {
      ui->loadnew->show();
       ui->point->hide();
        ui->normal->hide();
         ui->fancy->hide();
          ui->ninie->hide();
           ui->eight->hide();
            ui->two->hide();


    } else {
      ui->loadnew->show();


    }

}

void MainWindow::on_loadnew_clicked()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.xpm *.jpg)"));
  if (!fileName.isEmpty())
    {
      QPixmap image;
      image.load(fileName);

      int w = ui->image2->width();
      int h = ui->image2->height();

             // Scale the image to exactly match the size of the label
      ui->image2->setPixmap(image.scaled(w, h));

      image3= image.toImage(); // Convert QPixmap to QImage and store it in brightImage
    }
  applyFilter = true;
  if (!applyFilter) {
      ui->applymerg->hide();

    } else {
      ui->applymerg->show();

    }

}

void MainWindow::on_applymerg_clicked()
{


  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(merg(brightImage,image3,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_crop_clicked()
{
  applyFilter = true;
  if (!applyFilter) {
      ui->point->hide();

    } else {
      ui->point->show();
       ui->fancy->hide();
       ui->normal->hide();
       ui->ninie->hide();
        ui->eight->hide();
         ui->two->hide();
          ui->applymerg->hide();
           ui->loadnew->hide();





    }
}


void MainWindow::on_point_clicked()

{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(draw(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

  bool ok;
  int x = QInputDialog::getInt(this, tr("croped Image"),
                                tr("Enter the x_axis point:"), 100, 1, 10000, 1, &ok);

  if (ok) {
      int y = QInputDialog::getInt(this, tr("croped Image"),
                                    tr("Enter the x_axis point:"), 100, 1, 10000, 1, &ok);
      int w = QInputDialog::getInt(this, tr("croped Image"),
                                    tr("Enter the width of the croped image:"), 100, 1, 10000, 1, &ok);
      int h = QInputDialog::getInt(this, tr("croped Image"),
                                    tr("Enter the height of the croped image:"), 100, 1, 10000, 1, &ok);

      if (ok) {
          applyFilter = true;
          int w = ui->image->width();
          int h = ui->image->height();
          ui->image->setPixmap(QPixmap::fromImage(crop(brightImage,w,h,x,y)).scaled(w, h, Qt::KeepAspectRatio));

        }
    }

}
void MainWindow::on_image_linkActivated(const QString &link)
{
  // Set the style sheet on your scrollbar
  // Set the style sheet on your scrollbar
  bar->setStyleSheet(R"(
                      QScrollBar:horizontal {
                        border: none;
                        background: #A0227A;
                        height: 15px;  // Adjust this to make the line thicker
                        margin: 0px 20px 0 20px;
                      }

                      )");




}

void MainWindow::on_detect_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(detect(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_start_clicked()
{
  bool applyFilter = true;

  if (applyFilter) {
      // Code to apply filter and show widgets
      QPixmap pixmap("C:/Users/Gaming 3/OneDrive/Documents/untitled17/pixekl craft9.png");
      QPalette palette;
      palette.setBrush(this->backgroundRole(), QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
      this->setPalette(palette);
      ui->purprle->show();
      ui->gray->show();
      ui->bright->show();
      ui->detect->show();
      ui->merg->show();
      ui->flip->show();
      ui->inverter->show();
      ui->brows->show();
      ui->crop->show();
      ui->resize->show();
      ui->blur->show();
      ui->frame->show();
      ui->blackwight->show();
      ui->rotation->show();
      ui->image->show();
      ui->image2->show();
      ui->sunilght->show();
      ui->oldtv->show();
      ui->infrafred->show();
      ui->dark->show();
      ui->after->show();
      ui->before->show();
      ui->flipv->show();
      ui->line1->show();
       ui->start->hide();
        ui->save->show();
        ui->poster->show();
 ui->scrollArea->show();

    } else {

      ui->purprle->hide();
      ui->gray->hide();
      ui->bright->hide();
      ui->detect->hide();
      ui->merg->hide();
      ui->flip->hide();
      ui->inverter->hide();
      ui->brows->hide();
      ui->crop->hide();
      ui->resize->hide();
      ui->blur->hide();
      ui->frame->hide();
      ui->blackwight->hide();
      ui->rotation->hide();
      ui->image->hide();
      ui->image2->hide();
      ui->sunilght->hide();
      ui->oldtv->hide();
      ui->infrafred->hide();
      ui->dark->hide();
      ui->after->hide();
      ui->before->hide();
      ui->flipv->hide();
      ui->line1->hide();
       ui->poster->hide();


    }
}

void MainWindow::on_save_clicked()
{

    saveImage(resizedImg);
}

void MainWindow::on_umdo_clicked()
{
  if (!undoStack.isEmpty()) {


      // Push current image state onto redoStack
      redoStack.push(resizedImg);
      // Revert to the previous image state
      resizedImg = undoStack.pop();
      applyFilter = true;
      int w = ui->image2->width();
      int h = ui->image2->height();
      resizedImg = resizedImg.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

      // Update the display or widget that shows the image
      ui->image2->setPixmap(QPixmap::fromImage(resizedImg).scaled(w,h, Qt::KeepAspectRatio));
    }
}



void MainWindow::on_redo_clicked()
{

}

void MainWindow::on_poster_clicked()
{
  applyFilter = true;
  int w = ui->image2->width();
  int h = ui->image2->height();
  ui->image2->setPixmap(QPixmap::fromImage(poster(brightImage,w,h)).scaled(w, h, Qt::KeepAspectRatio));


}


void MainWindow::on_popart_clicked()
{

  applyFilter = true;
  QColorDialog dialog(this);
  QPalette palette;
  palette.setColor(QPalette::Window, Qt::blue);
  dialog.setPalette(palette);
  dialog.setOption(QColorDialog::DontUseNativeDialog);

         // Use the dialog with the custom palette
  QColor color = dialog.getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
      current = color;
      // Apply the color filter to the image here
    }
  int w = ui->image2->width();
  int h = ui->image2->height();

         // Apply the purple filter to brightImage and convert it to QPixmap
  ui->image2->setPixmap(QPixmap::fromImage(pop(brightImage,current,w,h).scaled(w, h, Qt::KeepAspectRatio)));
}



