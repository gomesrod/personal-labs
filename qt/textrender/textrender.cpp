#include "textrender.h"

TextRender::TextRender(QWidget* parent)
	: 	QWidget(parent)
{
}

void TextRender::paintEvent (QPaintEvent * event)
{
	QPainter painter(this);

	painter.fillRect(event->rect(), QBrush(QColor(255,255,255)));

	QFontMetrics fontMetrics(painter.font());

	QTextLayout textLayout("Teste 1\nText Layout\nLast Line");

	int leading = fontMetrics.leading();
	qreal height = 0;
	qreal rightmargin = 10;
	textLayout.beginLayout();
	while (1) {
		QTextLine line = textLayout.createLine();

		if (!line.isValid()) {
			qDebug("Invalid Line created!");
			break;
		}

		line.setLineWidth(100);
		height += leading;
		
		line.setPosition(QPointF(rightmargin, height));
		rightmargin += 5;
		height += line.height();
	}
	textLayout.endLayout();


	QVector<QTextLayout::FormatRange> formats;
	QTextLayout::FormatRange fmt1;
	fmt1.start = 5;
	fmt1.length = 6;
	QTextCharFormat tcfmt;
	tcfmt.setBackground(QBrush(QColor(230, 255, 230)));
	fmt1.format = tcfmt;
	formats.append(fmt1);

	QTextLayout::FormatRange fmt2;
	fmt2.start = 18;
	fmt2.length = 6;
	QTextCharFormat tcfmt2;
	tcfmt2.setBackground(QBrush(QColor(230, 225, 255)));
	fmt2.format = tcfmt2;
	formats.append(fmt2);


	textLayout.draw(&painter, QPoint(0, 0), formats);
	textLayout.drawCursor(&painter, QPointF(30,30), 1);

}