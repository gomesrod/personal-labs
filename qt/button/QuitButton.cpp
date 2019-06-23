#include <QApplication>
#include <QPushButton>

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	QPushButton* button = new QPushButton("QUIT !");

	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
	button->show();
	
	int appretcode = app.exec();

	delete button;

	return appretcode;
}
