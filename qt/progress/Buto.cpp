#include "Buto.h"

#include <QProgressDialog>
#include <QTimer>
#include <QMessageBox>

Buto::Buto(QWidget* parent)
	: QPushButton(parent)
{
	connect(this, SIGNAL(clicked()), this, SLOT(doProcess()));
}

void Buto::doProcess()
{
	progress = new QProgressDialog(this);
	progress->setRange(0, 100);
	progress->setValue(0);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(partialWorkCompleted()));
	timer->start(100);
}

void Buto::partialWorkCompleted()
{
	int newValue = progress->value() + 1;
	progress->setValue(newValue);

	if (newValue == 100) {
		QMessageBox::information(this, tr("Notification"), tr("Work complete"));
		timer->stop();
	}
}
