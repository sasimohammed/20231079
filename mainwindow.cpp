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
  ui->fancy->hide();
  ui->normal->hide();
  ui->red->hide();
  ui->blue->hide();
ui->only_blue->hide();
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
QImage only_blue_frame(QImage image)
{
  if (!applyFilter) {
      return image;
    }
  for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
        {
          // Iterate over RGB channels
          for (int k = 0; k < 3; k++)
            {
              // Check if pixel is within the frame boundaries
              if (((i >= 0 && i <= 9) || (j >= 0 && j <= 9) || (i >= image.width() - 9 && i <= image.width() - 1) ||
                   (j >= image.height() - 9 && j <= image.height() - 1)))
                {
                  image.setPixelColor(i, j, QColor(0, 0, 255)); // Set color to blueish
                }

                     // Check if pixel is within the inner blue frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 0)
                {
                  image.setPixelColor(i, j, QColor(53, 53, 53)); // Set color to blue
                }

                     // Check if pixel is within the inner blue frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 1)
                {
                  image.setPixelColor(i, j, QColor(116, 116, 116)); // Set color to green
                }

                     // Check if pixel is within the inner blue frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 2)
                {
                  image.setPixelColor(i, j, QColor(0, 0, 255)); // Set color to light blue
                }
            }
        }
    }
  return image;


}
QImage red_frame(QImage image)
{
  if (!applyFilter) {
      return image;
    }
  for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
        {
          // Iterate over RGB channels
          for (int k = 0; k < 3; k++)
            {
              // Check if pixel is within the frame boundaries
              if (((i >= 0 && i <= 9) || (j >= 0 && j <= 9) || (i >= image.width() - 9 && i <= image.width() - 1) ||
                   (j >= image.height() - 9 && j <= image.height() - 1)))
                {
                  image.setPixelColor(i, j, QColor(180, 0, 0)); // Set color to redish
                }

                     // Check if pixel is within the inner red frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 0)
                {
                  image.setPixelColor(i, j, QColor(139, 0, 0)); // Set color to dark red
                }

                     // Check if pixel is within the inner red frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k != 0)
                {
                  image.setPixelColor(i, j, QColor(255, 0, 0)); // Set non-red channels to 0
                }
            }
        }
    }
   return image;
}
QImage blueW_frame(QImage image)
{
  if (!applyFilter) {
      return image;
    }
  for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
        {
          // Iterate over RGB channels
          for (int k = 0; k < 3; k++)
            {
              // Check if pixel is within the frame boundaries
              if (((i >= 0 && i <= 9) || (j >= 0 && j <= 9) || (i >= image.width() - 9 && i <= image.width() - 1) ||
                   (j >= image.height() - 9 && j <= image.height() - 1)))
                {
                  image.setPixelColor(i, j, QColor(241, 241, 241)); // Set color to blueish
                }

                     // Check if pixel is within the inner blue frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 0)
                {
                  image.setPixelColor(i, j, QColor(53, 53, 53)); // Set color to blue
                }

                     // Check if pixel is within the inner blue frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 1)
                {
                  image.setPixelColor(i, j, QColor(116, 116, 116)); // Set color to green
                }

                     // Check if pixel is within the inner blue frame boundaries
              if ((((j > 9 && j <= 22) && (i > 9 && i < image.width() - 9)) ||
                   ((j >= image.height() - 22 && j < image.height() - 9) && (i > 9 && i <= image.width() - 9)) ||
                   ((i > 9 && i <= 22) && (j > 9 && j <= image.height() - 22)) ||
                   ((i >= image.width() - 22 && i < image.width() - 9) && (j > 9 && j <= image.height() - 22))) && k == 2)
                {
                  image.setPixelColor(i, j, QColor(0, 0, 255)); // Set color to light blue
                }
            }
        }
    }
  return image;

}

  // Convert to 32 bit format for easy pixel manipulation
QImage fancy_frame(QImage image)
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
                  image.setPixelColor(i, j, QColor(0, 0, 255)); // Blue color
                }

                     // Green border
              if ((((j > 10 && j <= 25) && (i > 10 && i < image.width() - 10)) || ((j >= image.height() - 25 && j < image.height() - 10) && (i > 10 && i < image.width() - 10)) || ((i > 10 && i <= 25) && (j > 10 && j <= image.height() - 25)) || ((i >= image.width() - 25 && i < image.width() - 10) && (j > 10 && j <= image.height() - 25))) && k == 1)
                {
                  image.setPixelColor(i, j, QColor(0, 255, 0)); // Green color
                }

                     // Red border
              if ((((j > 10 && j <= 25) && (i > 10 && i < image.width() - 10)) || ((j >= image.height() - 25 && j < image.height() - 10) && (i > 10 && i < image.width() - 10)) || ((i > 10 && i <= 25) && (j > 10 && j <= image.height() - 25)) || ((i >= image.width() - 25 && i < image.width() - 10) && (j > 10 && j <= image.height() - 25))) && k == 2)
                {
                  image.setPixelColor(i, j, QColor(0, 0, 255)); // Red color
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



  return image;
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


void MainWindow::on_frame_clicked()
{
  applyFilter = true;
  if (!applyFilter) {
      ui->fancy->hide();
      ui->normal->hide();

    } else {
      ui->fancy->show();
      ui->normal->show();

    }


}
void MainWindow::on_fancy_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(fancy_frame(brightImage)).scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_normal_clicked()
{
  applyFilter = true;
  if (!applyFilter) {
      ui->red->hide();
      ui->blue->hide();
 ui->only_blue->hide();
    } else {
      ui->red->show();
      ui->blue->show();
      ui->only_blue->show();

    }

}

void MainWindow::on_red_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(red_frame(brightImage)).scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_blue_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(blueW_frame(brightImage)).scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_only_blue_clicked()
{
  applyFilter = true;
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(QPixmap::fromImage(only_blue_frame(brightImage)).scaled(w, h, Qt::KeepAspectRatio));


}

