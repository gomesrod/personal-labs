#ifndef MY_TEXT_RENDER_H
#define MY_TEXT_RENDER_H

#include <QtGui>
#include <QTextLayout>

class TextRender : public QWidget {

public:
	TextRender(QWidget* parent = 0);

protected:
	virtual void paintEvent (QPaintEvent * event);
};

#endif