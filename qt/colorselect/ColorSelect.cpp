#include "ColorSelect.h"
#include <QMessageBox>

ColorSelect::ColorSelect(QWidget* parent)
    : QWidget(parent)
{
  setupUi(this);
  
  spinRed->setValue(sliderRed->value());
  spinGreen->setValue(sliderGreen->value());
  spinBlue->setValue(sliderBlue->value());
  
  // Update the colored label
  colorChanged();
}

void ColorSelect::colorChanged()
{
  QString colorVal = QString("#%1%2%3")
		    .arg(sliderRed->value(), 2, 16, QChar('0'))
		    .arg(sliderGreen->value(), 2, 16, QChar('0'))
		    .arg(sliderBlue->value(), 2, 16, QChar('0'));
  txtColor->setStyleSheet(QString("QLineEdit { background: %1 }").arg(colorVal));
  txtColor->setText(colorVal);
}