#include "global.h"
#include "WeiqiW.h"
#include <qpainter.h>
#include <QMouseEvent>
#include <qfont.h>



WeiqiW::WeiqiW(QWidget *parent)
{
	setMouseTracking(true);
	qlabel1 = new QLabel;
	qlabel1->setParent(this);
	qlabel1->showNormal();
	QFont qfont("微软雅黑", 20, 20);
	this->setFont(qfont);
	qlabel1->setFont(qfont);
	qlabel1->setMinimumSize(3000, 30);

	resize(800, 600);
	setWindowTitle("我是中文" + this->windowTitle());

}

WeiqiW::~WeiqiW(){

}

void WeiqiW::paintEvent(QPaintEvent *event)
{
	
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	
	painter.setMatrix(qma);

	QPen qpen;
	qpen.setWidthF(.025);
	painter.setPen(qpen);
	painter.drawLine(-10, 0, 10, 0);
	painter.drawLine(0, 10, 0, -10);
	QRectF qre(-9.5, -9.5, 19, 19);
	painter.drawRect(qre);
	
	//	QPainter painter(this);
	
	for (int xi = -9; xi <= 9; xi++){	
		
		painter.drawLine(xi, 9, xi, -9);
	}
		
	for (int yi = -9; yi <= 9; yi++){
		painter.drawLine(-9, yi, 9, yi);



	}

	//painter.setPen(Qt::transparent);
	for (int i = 0; i <= count - 2; i += 2){
		
		painter.setBrush(Qt::black);
		painter.drawEllipse(thep[i]);
		i++;
		painter.setBrush(Qt::white);

		painter.drawEllipse(thep[i]);
	}
	
	painter.setBrush(Qt::red);
	painter.drawEllipse(thep[count - 1]);
	qpen.setWidthF(0.2);
	painter.setPen(qpen);
	//painter.drawRect(x - 10, y - 10, 20, 20);
	painter.drawPoint(loc.x, loc.y);

}


//
void WeiqiW::mouseMoveEvent(QMouseEvent * e){	
	static Location last = {};
	QPointF point = qma.inverted().map((QPointF)e->pos());
	loc.x = qRound(point.x()); loc.y = qRound(point.y());
	if (last.x == loc.x && last.y + loc.y) return;
	
	last = loc;
	

}

void WeiqiW::resizeEvent(QResizeEvent * event){
	qma.reset();
	qma.translate(this->rect().width() / 2, this->rect().height() / 2);

	float wid = this->rect().width(); float hei = this->rect().height();
	float w, h;
	if (wid > hei)
		qma.scale(hei / 20, -hei / 20);
	else
		qma.scale(wid / 20, -wid / 20);

	
	qlabel1->setText("当前大小：" + QString::number(this->rect().width(), 10) + "," + QString::number(this->rect().height(), 10));
}

void WeiqiW::mousePressEvent(QMouseEvent * e){
	//int xi, yi;

	//QRectF re(8,)
	thep[count].adjust(loc.x - .5, loc .y - .5, loc.x + .5, loc.y + .5);
	
	
	count++;
	update();

}