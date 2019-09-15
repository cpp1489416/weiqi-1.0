#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL>
#include <QWidget>
#include "global.h"

#define SEED 36
#define STARTANG 0.2 * PI
#define PI 3.1415926535897932384626
#define BANH 0.15
#define GE2 1.414

#define CIRCLE(X,Y) (X)+(Y)))))))))))))))))))))))))))))))))))))))

class GLWidget : public QGLWidget
{
	Q_OBJECT
public:
	explicit GLWidget(QGLWidget *parent = 0);
	~GLWidget();

	struct LocationIsB{
		int x;
		int y;
		int isB;
	};
	//////////
	struct LocationWQ{
		int x;
		int y;
	};///当前位置
	
	///////////
	struct DownEventInfo{
		LocationWQ present;
		LocationWQ* deths;
		int issdethBlack;
		int count;
	}downeventinfo;



	inline bool isBlack(){
		return isB == -1 ? true : false;
	}
	void clearWQ();
	void pushBack(int x, int y);

signals:
	void downevent();



	//virtual 

	///////////
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void keyPressEvent(QKeyEvent *e);
	void mouseMoveEvent(QMouseEvent * e);
	void mousePressEvent(QMouseEvent * e);

private:


	QMatrix qma;

	//int count;

	LocationWQ loc;
	//绘图：
	GLfloat circles[SEED + 1][2];
	GLfloat circlesBa[SEED + 1][2];
	enum HatchType{
		Ban, Qi, None, Jie
	}hatchtype;


#define i i




	int isB = 1;


	//棋局：
	signed int qiju[19][19];
	signed int sqiju[19][19];


	//qi:::::
	void updateQi();
	void downStone();
	void ilookforsame(int x, int y);
	LocationWQ irw[360];
	bool isBan;
	bool isLive;
	int istart = 0;
	int icount;
	struct JieInFo{
		LocationWQ a; //1
		LocationWQ b; //2
		bool isACT = true;
	}jieinfo;
	bool isEditale = true;

	/////////endqi
};

#endif // GLWIDGET_H