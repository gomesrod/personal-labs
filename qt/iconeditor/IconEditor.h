#include <QWidget>
#include <QImage>

class IconEditor : public QWidget
{
	Q_OBJECT

public:
	IconEditor(QWidget* parent = 0);

	virtual QSize IconEditor::sizeHint() const;

	virtual void paintEvent(QPaintEvent* event);
	virtual void IconEditor::mousePressEvent(QMouseEvent* event);

	int getZoom() {return zoomFactor;}

public slots:
	void setZoom(int z);

private:
	int zoomFactor;
	int iconSize;
	QImage image;

	void paintPixelAt(const QPoint& screenPoint);
	void clearPixelAt(const QPoint& screenPoint);

	QPoint screenPointToImagePixel(const QPoint& screenPoint);
};
