#include <QApplication>
#include "Buto.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	Buto button;
	button.setText("Process");
	button.setVisible(true);

	return app.exec();
}
