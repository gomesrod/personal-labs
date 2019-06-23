#include <QMainWindow>

class IconEditor;
class QButtonGroup;
class QLabel;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	IconEditor* editor;
	QLabel* zoomLabel;
	QButtonGroup* selectColorButtons;
	
private slots:
	void updateZoomDisplay(int z);
};
