#include <QApplication>
#include <QLabel>

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	
	QLabel* label = new QLabel("Hello Qt !");
	label->show();
	
	int ret = app.exec();
	
	delete label;

	return ret;
}
