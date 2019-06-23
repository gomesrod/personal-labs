#include <QtGui>
#include "textrender.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	TextRender* mywidget = new TextRender;
	mywidget->show();

	return app.exec();
}
