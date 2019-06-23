#ifndef COLOR_SELECT_H
#define COLOR_SELECT_H

#include "ui_ColorSelect.h"
#include <QWidget>

class ColorSelect : public QWidget, Ui::ColorSelect
{
  Q_OBJECT

public:
  ColorSelect(QWidget* parent = 0);
  
private slots:
  void colorChanged();
};




#endif