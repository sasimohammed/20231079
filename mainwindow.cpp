#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QInputDialog>
#define _IMAGE_CLASS_H
#include "Image_Class.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->ninie->hide();
  ui->eight->hide();
   ui->two->hide();

}


MainWindow::~MainWindow() { delete ui; }
QImage brightImage;
bool applyFilter = false;
QImage bright(QImage img, int percent)
{
  if (!applyFilter) {
      return img;
    }
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
    }
  return img;
}
QImage dark(QImage img, int percent)
{
  if (!applyFilter) {
      return img;
    }
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
  return img;
}
QImage gray(QImage img)
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

  return img;
}
QImage purple(QImage image)
{
  if (!applyFilter) {
      return image;
    }

  for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
        {
          QColor color(image.pixel(i, j));
          int green = color.green();
          // Reduce the intensity of the green channel by 35%
          green = static_cast<int>(green * 0.65);
          color.setGreen(green);
          image.setPixelColor(i, j, color);
        }
    }
    return image;
}

QImage blackandwight(QImage img)
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


  return img;
}
QImage inverter(QImage img)
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
  return img;
}
QImage flipH(QImage image)
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
    }
  return image2;
}
QImage flipV(QImage image)
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
          QRgb pixel = image.pixel(i, image.height() - 1 - j);

                 // Copy pixel from original image to flipped image
          image2.setPixel(i, j, pixel);
        }
    }
  return image2;
}
QImage sunlight(QImage image)
{
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

  return image;
}
QImage flip_90(QImage img)
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
  return image2;
  // Convert to 32 bit format for easy pixel manipulation


}
QImage flip_180(QImage img)
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
  return image2;
  // Convert to 32 bit format for easy pixel manipulation


}
QImage flip_270(QImage img)
{
  if (!applyFilter) {
      return img;
    }
  QImage image2(img.width(),img.height(), QImage::Format_RGB32);
  for(int i=0; i<image2.width(); i++)
    {
      for(int j=0; j<image2.height(); j++)
        {
          QColor color(img.pixelColor(img.width()-1-j, i));
          image2.setPixelColor(i, j, color);
        }
    }
  return image2;
  // Convert to 32 bit format for easy pixel manipulation


}
QImage oldtv(QImage img)
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
              int random = rand() % 5; // Generate a random value between 0 and 39
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

  return img;

}
QImage infrared(QImage img)
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

                 // Calculate luminance
          int in = static_cast<int>(0.2126 * r + 0.7152 * g + 0.0722 * b);
          // Map luminance to a gradient of red shades
          int redValue = 255 - in; // Invert luminance to get red shades

                 // Set red channel to the mapped red value
          r = in;
          // Set green and blue channels to a fraction of the redValue to get shades of red
          g = static_cast<int>(redValue * 0.9); // Adjust the multiplier to control the gradient
          b = static_cast<int>(redValue * 0.9); // Adjust the multiplier to control the gradient

                 // Set the new pixel value
          QRgb newPixel = qRgb(r, g, b);
          img.setPixel(i, j, newPixel);
        }
    }

  for(int i = 0; i < width; ++i) {
      for(int j = 0; j < height; ++j) {
          QRgb pixel = img.pixel(i, j);
          int r = qRed(pixel);
          int g = qGreen(pixel);
          int b = qBlue(pixel);

                 // If any of the color channels is 255, set the red channel to 255
          if (r == 255 || g == 255 || b == 255) {
              r = 255;
            }

                 // Set the new pixel value
          QRgb newPixel = qRgb(r, g, b);
          img.setPixel(i, j, newPixel);
        }
    }



  return img;
}

void MainWindow::on_brows_clicked()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.xpm *.jpg)"));
  if (!fileName.isEmpty())
    {
      QPixmap image;
      image.load(fileName);
      QLabel *imageLabel = new QLabel;
      imageLabel->setPixmap(image);
      imageLabel->show();

      int w = ui->image->width();
      int h = ui->image->height();
      ui->image->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));
      brightImage = image.toImage(); // Convert QPixmap to QImage and store it in brightImage
    }
}
void MainWindow::on_purprle_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(purple(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_bright_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(bright(brightImage, 90)).scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_dark_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(dark(brightImage, 50)).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_gray_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(gray(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_inverter_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(inverter(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_blackwight_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(blackandwight(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

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
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(oldtv(brightImage)).scaled(w, h, Qt::KeepAspectRatio));


}


void MainWindow::on_flip_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(flipH(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_flipv_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(flipV(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_sunilght_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(sunlight(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::on_rotation_clicked()
{
  applyFilter = true;
  if (!applyFilter) {
      ui->ninie->hide();
      ui->eight->hide();
       ui->two->show();
    } else {
      ui->ninie->show();
      ui->eight->show();
       ui->two->show();
    }

  // Toggle the state of the buttons
}

void MainWindow::on_eight_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(flip_90(brightImage)).scaled(w, h, Qt::KeepAspectRatio));


}

void MainWindow::on_ninie_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(flip_180(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_two_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(flip_270(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}

