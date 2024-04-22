#include "bar.h"
#include <QPainter>


MyScrollBar::MyScrollBar(QWidget *parent) : QScrollBar(parent) {}

void MyScrollBar::paintEvent(QPaintEvent *event)
{
  QScrollBar::paintEvent(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

         // Calculate the position and size of the handle
  double min = this->minimum();
  double max = this->maximum();
  double range = max - min;
  double value = this->value();
  double ratio = (value - min) / range;
  int handlePos = ratio * (this->width() - 20);  // Adjust 20 if you change the handle size

  QRect handleRect(handlePos, 0, 20, 20);  // Adjust these values to change the handle size
  painter.setBrush(QColor("gray"));
  painter.drawRoundedRect(handleRect, 10, 10);
}
