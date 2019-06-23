#include <QPushButton>

class QProgressDialog;
class QTimer;

class Buto : public QPushButton
{
	Q_OBJECT

public:
	Buto(QWidget* parent = 0);

private slots:
	void doProcess();
	void partialWorkCompleted();

private:
	QProgressDialog* progress;
	QTimer* timer;
};
