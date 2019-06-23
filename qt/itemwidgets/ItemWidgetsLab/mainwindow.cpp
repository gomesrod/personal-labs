#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectshapedialog.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chooseGeometricPicture()
{
    SelectShapeDialog dialog(this);
    dialog.exec();
    if (dialog.result() == QDialog::Accepted) {
        QMessageBox::information(this, tr("Accepted"), tr("Select Shape"));
    }
}

