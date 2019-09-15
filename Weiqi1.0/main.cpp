#include "weiqi.h"
#include "weiqiw.h"
#include <QtWidgets/QApplication>
#include "wglwidget.h"

#define K 2
void downevent(GLWidget::DownEventInfo* downinfo);
GLWidget* glo;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Weiqi w;

	//WeiqiW wed(&w);
	//glo = new GLWidget;
	
	//glo->show();

	//glo->setEventDown(downevent);
	
	//wed.show();
	w.show();
	return a.exec();
}

