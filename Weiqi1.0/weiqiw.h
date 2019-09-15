#ifndef WeiqiW_H
#define WeiqiW_H

#include <qwidget.h>
#include <qlabel.h>



class QPaintEvent;
class QLabel;
class WeiqiW : public QWidget
{
	Q_OBJECT

private:
	QLabel *qlabel1;

	QRectF thep[5000];
	int count = 0;

	QMatrix qma;
	struct Location{
		int x; int y;
	}loc;///µ±«∞Œª÷√

public:
	WeiqiW(QWidget *parent);
	~WeiqiW();
	
	//float x, y;
	float def;

protected:
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent * event);
	void resizeEvent(QResizeEvent * event);
	void mousePressEvent(QMouseEvent * event);
};

#endif // WeiqiW_H
