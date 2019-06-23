#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    this->
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(accept()));
}

MyDialog::~MyDialog()
{
    delete ui;
}
