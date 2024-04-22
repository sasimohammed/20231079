#ifndef BAR_H
#define BAR_H

#include <QScrollBar>

class MyScrollBar : public QScrollBar
{
public:
  MyScrollBar(QWidget *parent = 0);

protected:
  void paintEvent(QPaintEvent *event) override;
};

#endif // BAR_H
