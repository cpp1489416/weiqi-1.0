#include "wglwidget.h"
#include <QtGui>
#include <QtCore>
#include <QtOpenGL>


GLWidget::GLWidget(QGLWidget *parent) :
QGLWidget(parent)
{
	setMouseTracking(true);
	for (int x = 0; x <= 18; x++){
		for (int y = 0; y <= 18; y++){
			qiju[x][y] = 0;
			sqiju[x][y] = 0;
		}
	}
	
	isB = true;
	loc = { 9, 9 };
	hatchtype = HatchType::Qi;
	icount = 0;
}

//���Ƕ��麯������������д�ú���
void GLWidget::initializeGL()
{
	//setGeometry(300, 150, 640, 480);//���ô��ڳ�ʼλ�úʹ�С
	glShadeModel(GL_SMOOTH);//������Ӱƽ��ģʽ
	////////////////////////////glShadeModel(GL_FLAT);
	glClearColor(0.0, 0.0, 0.3, 0.0);//�ı䴰�ڵı�����ɫ������������ò�����ú�û��ʲôЧ��
	glClearDepth(1.0);//������Ȼ���
	glEnable(GL_DEPTH_TEST);//������Ȳ���
	glDepthFunc(GL_LEQUAL);//������Ȳ�������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//����͸��У��
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	//glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	//glEnable(GL_MULTISAMPLE);
	0[this].update();
	nullptr;
	
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LINE_STIPPLE);
	glLoadIdentity();//���õ�ǰ��ģ�͹۲����,�þ�ִ����󣬽������ƶ�������Ļ������

	//���߽�
	glColor3f(1, 1, 1);
	glLineWidth(.1f);
	glBegin(GL_QUADS);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glEnd();

	//ת������
	glScalef(0.1, 0.1, 0);
	glTranslatef(-9, -9, 0);


	//glRotatef(-60, 1, 0, 0); glRotatef(30,0, 1, 0);
	//glRotatef(30, 0, 0, 1);
	//
	glColor3f(0, 0, 0);

	//����,������ʱ��
	glBegin(GL_LINES);
	for (int x = 0; x <= 18; x++)
	{
		glVertex2f(x, 18);
		glVertex2f(x, 0);
		glVertex2f(0, x);
		glVertex2f(18, x);
	}
	glEnd();

	//��9����
	glPointSize(2.5f);
	glBegin(GL_POINTS);
	glVertex2i(15, 15); glVertex2i(9, 15); glVertex2i(3, 15);
	glVertex2i(3, 9); glVertex2i(9, 9); glVertex2i(9, 3);
	glVertex2i(3, 3); glVertex2i(15, 3); glVertex2i(15, 9);
	glEnd();

	//�������ʱ��
	glLineWidth(.9f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(18, 18);
	glVertex2i(0, 18);
	glVertex2i(0, 0);
	glVertex2i(18, 0);
	glEnd();
	glLineWidth(.1f);
	//

	renderText(2, 10, "ghjtjh t", QFont("΢���ź�", -1, 22));

	//��ʼ������;
	/////////////////////////////////////////////////////////////////////////////////
#define DRAWCIR for (int i = 0; i <= SEED; i++){glVertex2f(circles[i][0] + x, circles[i][1] + y);}
	////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/*hjlkhioujijlkjikjljioii*/
	for (int x = 0; x <= 18; x++){
		for (int y = 0; y <= 18; y++){
			if (-1 == qiju[x][y]){
				glColor3f(1, 1, 1);
				glBegin(GL_TRIANGLE_FAN);// : glBegin(GL_LINE_STRIP);
				glVertex2f(x, y);
				DRAWCIR;
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);// : glBegin(GL_LINE_STRIP);
				DRAWCIR;
				glEnd();
			}
			else if (1 == qiju[x][y]){
				glColor3f(0, 0, 0);
				glBegin(GL_TRIANGLE_FAN);// : glBegin(GL_LINE_STRIP);
				glVertex2f(x, y);
				DRAWCIR;
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);// : glBegin(GL_LINE_STRIP);
				DRAWCIR;
				glEnd();
			}
		}
	}



#define DRAWCIRBa for (int i = 0; i <= SEED; i++){glVertex2f(circlesBa[i][0] + loc.x, circlesBa[i][1] + loc.y);}
#define SKX 0.1
#define SKY 0.1
#define DRAWSKR glVertex2f(loc.x, loc.y); glVertex2f(loc.x - SKX, loc.y - SKY); glVertex2f(loc.x + SKX, loc.y - SKY);


	//glLineWidth(1.0f);
	for (int x = 0; x <= 18; x++)
	{
		for (int y = 0; y <= 18; y++){
			switch (sqiju[x][y])
			{
			default:
				break;
			}
		}
	}


	//	if (qiju[loc.x][loc.y] != 0)
	//		return;
	switch (hatchtype)
	{
	case GLWidget::Ban:

		glColor4f(1, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(loc.x - BANH / GE2, loc.y - BANH / GE2);
		glVertex2f(loc.x + BANH / GE2, loc.y + BANH / GE2);
		glVertex2f(loc.x - BANH / GE2, loc.y + BANH / GE2);
		glVertex2f(loc.x + BANH / GE2, loc.y - BANH / GE2);
		glEnd();
		break;
	case GLWidget::Qi:
		if (qiju[loc.x][loc.y] == 0)
		{
			if (1 == isB){
				glColor4f(0, 0, 0, 1);
				glBegin(GL_TRIANGLE_FAN);
				DRAWSKR;
				glEnd();
				glColor4f(1, 1, 1, 1);
				glBegin(GL_LINE_LOOP);
				DRAWSKR;
				glEnd();

			}
			else{
				glColor4f(1, 1, 1, 1);
				glBegin(GL_TRIANGLE_FAN);
				DRAWSKR;
				glEnd();
				glColor4f(0, 0, 1, 1);
				glBegin(GL_LINE_LOOP);
				DRAWSKR;
				glEnd();
			}
		}
		else
		{
			glLineWidth(1.5);
			glColor4f(0, 0, 1, 1);

			int x = loc.x, y = loc.y;
			glBegin(GL_LINE_LOOP);
			DRAWCIR;
			glEnd();
		}

		break;
	case GLWidget::Jie:
		glColor3f(1, 0, 0);
		glLineWidth(2.5);
		glBegin(GL_LINES);
		glVertex2f(loc.x, loc.y + 0.15);
		glVertex2f(loc.x, loc.y);
		glVertex2f(loc.x, loc.y - 0.05);
		glVertex2f(loc.x, loc.y - 0.12);
		break;

	case GLWidget::None:
		glColor4f(1, 1, 1, 0);;
		break;
	default:
		break;
	}
	
	glColor3f(1, 0, 0);
	glLineWidth(1.5);
	glEnable(GL_LINE_STIPPLE);//
	glLineStipple(1, 0x0F0F);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= icount - 1; i++)
	{
		glVertex2i(irw[i].x, irw[i].y);
	}
	glEnd();


	// �����ó�Ai��Fw��Fl��Br��Ae��Pr��Id��Ps������İ�װ��ж�أ���ͨCSS��JavaScript��PHP��ASP��C��C������C#��Java�ȵ��ʵ�ƴд����ϤWindows��Linux��Mac��Android��IOS��WP8��ϵͳ�Ŀ��ػ�

}
 
void GLWidget::resizeGL(int width, int height)
{
	int dis = width>height ? height : width;
	glViewport((width - dis) / 2, (height - dis) / 2, dis, dis);//���õ�ǰ�ӿڣ����������ô��ڵģ�ֻ��  �������ﱻQt����װ����
	glMatrixMode(GL_PROJECTION);//ѡ��ͶӰ����
	glLoadIdentity();//����ѡ��õ�ͶӰ����
	// gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);//����͸��ͶӰ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();




	for (int i = 0; i <= SEED; i++){
		circles[i][0] = .46*cos(STARTANG + 2 * PI / SEED*i);
		circles[i][1] = .46*sin(STARTANG + 2 * PI / SEED*i);
	}

	for (int i = 0; i <= SEED; i++){
		circlesBa[i][0] = BANH*cos(STARTANG + 2 * PI / SEED*i);
		circlesBa[i][1] = BANH*sin(STARTANG + 2 * PI / SEED*i);
	}

	qma.reset();
	qma.translate(this->rect().width() / 2, this->rect().height() / 2);

	float wid = this->rect().width(); float hei = this->rect().height();
	float w, h;
	if (wid > hei)
		qma.scale(hei / 20, -hei / 20);
	else
		qma.scale(wid / 20, -wid / 20);
	qma.translate(-9, -9);
	qma = qma.inverted();


}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
	//e->ignore();

	switch (e->key())
	{
	case Qt::Key_Left:
		loc.x == 0 ? loc.x = 18 : loc.x -= 1;
		updateQi();
		break;
	case Qt::Key_Right:
		loc.x == 18 ? loc.x = 0 : loc.x += 1;
		updateQi();
		break;
	case Qt::Key_Up:
		loc.y == 18 ? loc.y = 0 : loc.y += 1;
		updateQi();
		break;
	case Qt::Key_Down:
		loc.y == 0 ? loc.y = 18 : loc.y -= 1;
		updateQi();
		break;
	case Qt::Key_Space:
		downStone();
		//	close();
		break;
	}

}

GLWidget::~GLWidget()
{
}

void GLWidget::mouseMoveEvent(QMouseEvent * e){
	static LocationWQ last;
	QPointF point = qma.map((QPointF)e->pos());
	loc.x = qRound(point.x()); loc.y = qRound(point.y());
	loc.x < 0 ? loc.x = 0 : (loc.x>18 ? loc.x = 18 : loc.x = loc.x);
	loc.y < 0 ? loc.y = 0 : (loc.y>18 ? loc.y = 18 : loc.y = loc.y);
	int x = loc.x, y = loc.y;
	if (last.x == loc.x && last.y == loc.y)
		return;

	updateQi();
	last = loc;
}

void GLWidget::mousePressEvent(QMouseEvent * e){
	downStone();
}

void GLWidget::updateQi(){
	if (qiju[loc.x][loc.y] != 0)
	{
		icount = 0;
		isLive = true;
		hatchtype = Qi;
		update();
		return;
	}

	istart = icount = 0;
	int x = loc.x, y = loc.y;
	qiju[x][y] = isB;
	// zuoxiayoushang

	isBan = true;
	if (x != 0)
	{
		if (qiju[x - 1][y] == 0)
		{
			isBan = false;
		}
		else if (qiju[x - 1][y] == -isB)
		{
			isLive = false;
			ilookforsame(x - 1, y);
			if (!isLive)
			{
				isBan = false;
				istart = icount;
			}
			else
			{
				icount = istart;
			}
		}
	}
	if (y != 0)
	{
		if (qiju[x][y - 1] == 0){ isBan = false; }

		else if (qiju[x][y - 1] == -isB)
		{

			isLive = false;
			ilookforsame(x, y - 1);
			if (!isLive)
			{
				isBan = false;
				istart = icount;
			}
			else{
				icount = istart;
			}
		}
	}
	if (x != 18)
	{
		if (qiju[x + 1][y] == 0){ isBan = false; }

		else if (qiju[x + 1][y] == -isB)
		{

			isLive = false;
			ilookforsame(x + 1, y);
			if (!isLive)
			{
				isBan = false;
				istart = icount;
			}
			else{ icount = istart; }
		}
	}
	if (y != 18)
	{
		if (qiju[x][y + 1] == 0){ isBan = false; }

		else if (qiju[x][y + 1] == -isB)
		{

			isLive = false;
			ilookforsame(x, y + 1);
			if (!isLive)
			{
				isBan = false;
				istart = icount;
			}
			else{ icount = istart; }
		}
	}

	if (isBan)
	{
		isLive = false;
		ilookforsame(x, y);
		if (!isLive)
		{
			hatchtype = Ban;
		}
		else
		{
			isLive = true;
			isBan = false;
			hatchtype = Qi;
			icount = 0;
		}
	}
	else
	{
		hatchtype = Qi;
	}

	if (1 == icount
		&& (x != 00 ? qiju[x - 1][y] == -isB : true)
		&& (y != 00 ? qiju[x][y - 1] == -isB : true)
		&& (x != 18 ? qiju[x + 1][y] == -isB : true)
		&& (y != 18 ? qiju[x][y + 1] == -isB : true)
		&& jieinfo.isACT == true
		&& jieinfo.b.x == x && jieinfo.b.y == y
		)
	{
		hatchtype = Jie;
	}

	qiju[loc.x][loc.y] = 0;
	update();
}

void GLWidget::downStone(){
	if (qiju[loc.x][loc.y] != 0 || isBan || Jie == hatchtype)
		return;
	int x = loc.x, y = loc.y;


	qiju[x][y] = isB;
	
	if (1 == icount
		&& (x != 00 ? qiju[x - 1][y] == -isB : true)
		&& (y != 00 ? qiju[x][y - 1] == -isB : true)
		&& (x != 18 ? qiju[x + 1][y] == -isB : true)
		&& (y != 18 ? qiju[x][y + 1] == -isB : true)
		)
	{
		jieinfo.b.x = irw[0].x;
		jieinfo.b.y = irw[0].y;
		jieinfo.isACT = true;
	}
	else
	{
		jieinfo.isACT = false;
	}
	
  	for (int i = 0; i <= icount - 1; i++)
	{
		qiju[irw[i].x][irw[i].y] = 0;
	}
	isB = -isB;
	
	////
	if (isEditale){
		downeventinfo.count = icount;
		downeventinfo.deths = irw;
		downeventinfo.issdethBlack = -isB;
		downeventinfo.present.x = loc.x;
		downeventinfo.present.y = loc.y;
		emit downevent();
	}	
	
	////
	icount = 0;
	update();

}

void GLWidget::ilookforsame(int x, int y){
	if (isLive)
		return;

	for (int i = 0; i <= icount - 1; i++)
	{
		if (irw[i].x == x&&irw[i].y == y)
			return;
	}

	//������Ϣ;
	icount++;
	irw[icount - 1].x = x; irw[icount - 1].y = y;

	if (x != 0){
		if (qiju[x - 1][y] == qiju[x][y])
			ilookforsame(x - 1, y);
		else if (qiju[x - 1][y] == 0)
		{
			isLive = true;
			return;
		}
	}


	if (y != 0){
		if (qiju[x][y - 1] == qiju[x][y])
			ilookforsame(x, y - 1);
		else if (qiju[x][y - 1] == 0)
		{
			isLive = true;
			return;
		}
	}


	if (x != 18){
		if (qiju[x + 1][y] == qiju[x][y])
			ilookforsame(x + 1, y);
		else if (qiju[x + 1][y] == 0)
		{
			isLive = true;
			return;
		}
	}


	if (y != 18){
		if (qiju[x][y + 1] == qiju[x][y])
			ilookforsame(x, y + 1);
		else if (qiju[x][y + 1] == 0)
		{
			isLive = true;
			return;
		}
	}
}

void GLWidget::clearWQ(){
	for (int x = 0; x <= 18; x++){
		for (int y = 0; y <= 18; y++){
			qiju[x][y] = 0;
			update();
		}
	}
	isB = 1;
}

void GLWidget::pushBack(int x, int y){
	isEditale = false;
	loc.x = x;
	loc.y = y;
	updateQi();
	downStone();
	isEditale = true;
}