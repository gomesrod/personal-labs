#include "MainWindow.h"
#include "IconEditor.h"
#include <QtGui/QtGui>

MainWindow::MainWindow()
{
	this->setGeometry(200, 200, 400, 400);

	editor = new IconEditor;

	this->setCentralWidget(editor);

	/* ******* MAIN TOOLBAR ********************/
	QToolBar* mainToolbar = new QToolBar(tr("Main toolbar"));
	mainToolbar->setMovable(false);
	this->addToolBar(Qt::TopToolBarArea, mainToolbar);


	/* ******* ZOOM TOOLBAR ********************/
	QToolBar* zoomToolbar = new QToolBar(tr("View toolbar"));
	zoomToolbar->setMovable(false);
	this->addToolBar(Qt::LeftToolBarArea, zoomToolbar);
	
	QWidget* zommToolbarContents = new QWidget;
	QVBoxLayout* zoomToolbarLayout = new QVBoxLayout(zoomToolbar);

	QSlider* slider = new QSlider(Qt::Vertical);
	slider->setRange(1, 20);
	slider->setToolTip(tr("Adjust the zoom factor"));
	slider->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
	
	connect(slider, SIGNAL(valueChanged(int)), editor, SLOT(setZoom(int)));
	connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateZoomDisplay(int)));
	
	zoomLabel = new QLabel;

	slider->setValue(editor->getZoom());

	zoomToolbarLayout->addWidget(new QLabel(tr("Zoom")));
	zoomToolbarLayout->addWidget(slider);
	zoomToolbarLayout->addWidget(zoomLabel);
	zoomToolbarLayout->spacing();

	zommToolbarContents->setLayout(zoomToolbarLayout);
	zoomToolbar->addWidget(zommToolbarContents);
}

void MainWindow::updateZoomDisplay(int z)
{
	zoomLabel->setText(QString::number(z) + " x");
}
