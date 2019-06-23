#include "selectshapedialog.h"
#include "mydatatypes.h"
#include "mydatasource.h"
#include <QtGui/QtGui>

SelectShapeDialog::SelectShapeDialog(QWidget *parent) :
    QDialog(parent)
{
    QListWidget* listWidget = new QListWidget(this);

    QPushButton* okButton = new QPushButton(tr("Ok"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    QPushButton* cancelButton = new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    QHBoxLayout* buttonBarLayout = new QHBoxLayout;
    buttonBarLayout->addWidget(okButton);
    buttonBarLayout->addWidget(cancelButton);
    layout->addLayout(buttonBarLayout);

    this->setLayout(layout);
    this->setWindowTitle(tr("Select Shape"));

    loadList(listWidget);

}

void SelectShapeDialog::loadList(QListWidget* listWidget)
{
    MyDataSource dataSource;
    QList<GeometricShape> shapes(dataSource.getShapes());

    GeometricShape shape;
    Q_FOREACH(shape, shapes) {
        QListWidgetItem* item = new QListWidgetItem(listWidget);
        item->setText(shape.description);
        item->setIcon(QIcon(QString(":/shape_%1.png").arg(shape.code)));
    }
}
