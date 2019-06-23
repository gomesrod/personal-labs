#include "sortdialog.h"

#include <QApplication>
#include <QUiLoader>
#include <QFile>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	// Execucao normal (classe gerada a partir do .ui)
	SortDialog* dialog = new SortDialog;
	dialog->setColumnRange('C', 'F');
	dialog->show();
	
	// Execucao com dialog carregado dinamicamente
	//QUiLoader uiLoader;
	//QFile file("sortdialog.ui");
	//QWidget* sortDialog = uiLoader.load(&file);
	//if (sortDialog) {
	//	sortDialog->show();
	//}

	return app.exec();
}

