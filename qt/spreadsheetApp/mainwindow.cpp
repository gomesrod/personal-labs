#include "../finddialog/FindDialog.h"
#include "../gotocell/GoToCellDialog.h"
#include "../sortdialog/sortdialog.h"

#include "mainwindow.h"
#include "spreadsheet.h"

#include <QtGui>

MainWindow::MainWindow()
{
	spreadsheet = new Spreadsheet;
	setCentralWidget(spreadsheet);

	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();

	readSettings();

	findDialog = 0;

	setWindowIcon(QIcon(":/images/icon.png"));
	setCurrentFile("");
}

void MainWindow::createActions()
{
	newAction = new QAction(tr("&New"), this);
	newAction->setIcon(QIcon(":/images/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new spreadsheet file"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	openAction = new QAction(tr("&Open"), this);
	openAction->setIcon(QIcon(":/images/new.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open a spreadsheet file"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(tr("&Save"), this);
	saveAction->setIcon(QIcon(":/images/new.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save the current spreadsheet file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAction = new QAction(tr("Save &As..."), this);
	saveAsAction->setIcon(QIcon(":/images/new.png"));
	saveAsAction->setShortcut(QKeySequence::SaveAs);
	saveAsAction->setStatusTip(tr("Save the current spreadsheet to a new file"));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

	////////////////////
	for (int i = 0; i < MaxRecentFiles; ++i) {
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit the application"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	////////////////////////////////////////
	selectAllAction = new QAction(tr("All")), this));
	selectAllAction->setShortcut(QKeySequence::SelectAll);
	selectAllAction->setStatusTip(tr("Select all the cells"));
	connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));
}