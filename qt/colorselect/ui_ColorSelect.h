/********************************************************************************
** Form generated from reading UI file 'ColorSelect.ui'
**
** Created: Mon 2. Dec 15:23:25 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSELECT_H
#define UI_COLORSELECT_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorSelect
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblRed;
    QSlider *sliderRed;
    QSpinBox *spinRed;
    QLabel *lblGreen;
    QSlider *sliderGreen;
    QSpinBox *spinGreen;
    QLabel *lblBlue;
    QSlider *sliderBlue;
    QSpinBox *spinBlue;
    QLineEdit *txtColor;

    void setupUi(QWidget *ColorSelect)
    {
        if (ColorSelect->objectName().isEmpty())
            ColorSelect->setObjectName(QString::fromUtf8("ColorSelect"));
        ColorSelect->resize(191, 120);
        layoutWidget = new QWidget(ColorSelect);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 169, 100));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblRed = new QLabel(layoutWidget);
        lblRed->setObjectName(QString::fromUtf8("lblRed"));

        gridLayout->addWidget(lblRed, 0, 0, 1, 1);

        sliderRed = new QSlider(layoutWidget);
        sliderRed->setObjectName(QString::fromUtf8("sliderRed"));
        sliderRed->setMaximum(255);
        sliderRed->setValue(100);
        sliderRed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderRed, 0, 1, 1, 1);

        spinRed = new QSpinBox(layoutWidget);
        spinRed->setObjectName(QString::fromUtf8("spinRed"));
        spinRed->setMaximum(255);

        gridLayout->addWidget(spinRed, 0, 2, 1, 1);

        lblGreen = new QLabel(layoutWidget);
        lblGreen->setObjectName(QString::fromUtf8("lblGreen"));

        gridLayout->addWidget(lblGreen, 1, 0, 1, 1);

        sliderGreen = new QSlider(layoutWidget);
        sliderGreen->setObjectName(QString::fromUtf8("sliderGreen"));
        sliderGreen->setMaximum(255);
        sliderGreen->setValue(100);
        sliderGreen->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderGreen, 1, 1, 1, 1);

        spinGreen = new QSpinBox(layoutWidget);
        spinGreen->setObjectName(QString::fromUtf8("spinGreen"));
        spinGreen->setMaximum(255);

        gridLayout->addWidget(spinGreen, 1, 2, 1, 1);

        lblBlue = new QLabel(layoutWidget);
        lblBlue->setObjectName(QString::fromUtf8("lblBlue"));

        gridLayout->addWidget(lblBlue, 2, 0, 1, 1);

        sliderBlue = new QSlider(layoutWidget);
        sliderBlue->setObjectName(QString::fromUtf8("sliderBlue"));
        sliderBlue->setMaximum(255);
        sliderBlue->setValue(100);
        sliderBlue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBlue, 2, 1, 1, 1);

        spinBlue = new QSpinBox(layoutWidget);
        spinBlue->setObjectName(QString::fromUtf8("spinBlue"));
        spinBlue->setMaximum(255);

        gridLayout->addWidget(spinBlue, 2, 2, 1, 1);

        txtColor = new QLineEdit(layoutWidget);
        txtColor->setObjectName(QString::fromUtf8("txtColor"));

        gridLayout->addWidget(txtColor, 3, 0, 1, 3);


        retranslateUi(ColorSelect);
        QObject::connect(sliderRed, SIGNAL(valueChanged(int)), spinRed, SLOT(setValue(int)));
        QObject::connect(sliderGreen, SIGNAL(valueChanged(int)), spinGreen, SLOT(setValue(int)));
        QObject::connect(sliderBlue, SIGNAL(valueChanged(int)), spinBlue, SLOT(setValue(int)));
        QObject::connect(spinRed, SIGNAL(valueChanged(int)), sliderRed, SLOT(setValue(int)));
        QObject::connect(spinGreen, SIGNAL(valueChanged(int)), sliderGreen, SLOT(setValue(int)));
        QObject::connect(spinBlue, SIGNAL(valueChanged(int)), sliderBlue, SLOT(setValue(int)));
        QObject::connect(sliderBlue, SIGNAL(valueChanged(int)), ColorSelect, SLOT(colorChanged()));
        QObject::connect(sliderGreen, SIGNAL(valueChanged(int)), ColorSelect, SLOT(colorChanged()));
        QObject::connect(sliderRed, SIGNAL(valueChanged(int)), ColorSelect, SLOT(colorChanged()));

        QMetaObject::connectSlotsByName(ColorSelect);
    } // setupUi

    void retranslateUi(QWidget *ColorSelect)
    {
        ColorSelect->setWindowTitle(QApplication::translate("ColorSelect", "Form", 0));
        lblRed->setText(QApplication::translate("ColorSelect", "Red", 0));
        lblGreen->setText(QApplication::translate("ColorSelect", "Green", 0));
        lblBlue->setText(QApplication::translate("ColorSelect", "Blue", 0));
        txtColor->setInputMask(QApplication::translate("ColorSelect", "\\#HHHHHH; ", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorSelect: public Ui_ColorSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSELECT_H
