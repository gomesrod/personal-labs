#include "FindDialog.h"

#include <QApplication.h>
#include <QLabel.h>

#include <memory>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	std::auto_ptr<FindDialog> dialog(new FindDialog);

	dialog->show();

	return app.exec();
}
