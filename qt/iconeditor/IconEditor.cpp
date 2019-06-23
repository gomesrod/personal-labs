#include "IconEditor.h"
#include <QPainter>
#include <QSizePolicy>
#include <QMouseEvent>

IconEditor::IconEditor(QWidget* parent)
	: QWidget(parent),
	  zoomFactor(8),
	  iconSize(16)
{
	this->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
	this->setAttribute(Qt::WA_StaticContents);

	image = QImage(iconSize, iconSize, QImage::Format_ARGB32);
	image.fill(qRgba(0,0,0,0));

	// Sample image - testing only
	image.setPixel(1, 1, qRgba(255,0,0,255));
	image.setPixel(1, 2, qRgba(255,0,0,255));
	image.setPixel(2, 1, qRgba(255,0,0,255));
	image.setPixel(1, 2, qRgba(255,0,0,255));
	image.setPixel(2, 2, qRgba(0,255,0,255));
	image.setPixel(3, 2, qRgba(0,255,0,255));
	image.setPixel(2, 3, qRgba(0,255,0,255));
	image.setPixel(3, 3, qRgba(0,255,0,255));
}

QSize IconEditor::sizeHint() const
{
	return QSize(iconSize*zoomFactor, iconSize*zoomFactor);
}

void IconEditor::paintEvent(QPaintEvent* /*event*/)
{
	QPainter painter(this);

	// Draw image pixels

	painter.setPen(Qt::NoPen);
	painter.fillRect(painter.viewport(), QColor(qRgba(255,255,255,255)));

	QRadialGradient transparentPixelGradient(width()/2, height()/2, width());
	transparentPixelGradient.setColorAt(0.0, qRgb(255, 255, 255));
	transparentPixelGradient.setColorAt(1.0, qRgb(240, 240, 255));

	for (int i = 0; i < iconSize; ++i) {
		for (int j = 0; j < iconSize; ++j) {
			QColor pixelColor = QColor::fromRgba(image.pixel(i, j));
			
			//TODO if (!event.region().intersect(pixelRectangle).isEmpty()) {
			
			if (pixelColor.alpha() == 255) {
				painter.setBrush(QBrush(pixelColor));
			} else {
				painter.setBrush(transparentPixelGradient);
			}
			
			painter.drawRect(i * zoomFactor, j * zoomFactor, zoomFactor, zoomFactor);
		}
	}
}

void IconEditor::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		paintPixelAt(event->pos());
	} else if (event->button() == Qt::RightButton) {
		clearPixelAt(event->pos());
	}
}

void IconEditor::paintPixelAt(const QPoint& screenPoint)
{
	QPoint pix = screenPointToImagePixel(screenPoint);
	image.setPixel(pix.x(), pix.y(), qRgb(100, 200, 50)); //TESTE - Selecionar cor atual
	update();
}

void IconEditor::clearPixelAt(const QPoint& screenPoint)
{
	QPoint pix = screenPointToImagePixel(screenPoint);
	image.setPixel(pix.x(), pix.y(), qRgba(0, 0, 0, 0));
	update();
}

QPoint IconEditor::screenPointToImagePixel(const QPoint& screenPoint)
{
	return QPoint(
		screenPoint.x() / zoomFactor,
		screenPoint.y() / zoomFactor
	);
}

void IconEditor::setZoom(int z)
{
	zoomFactor = z;
	updateGeometry();
	update();
}