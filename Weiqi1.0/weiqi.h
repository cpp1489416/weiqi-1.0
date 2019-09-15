#ifndef WEIQI_H
#define WEIQI_H

#include <QtWidgets/QMainWindow>
#include "wglwidget.h"

class Weiqi : public QMainWindow
{
	Q_OBJECT

public:
	
	Weiqi(QWidget *parent = 0);
	~Weiqi();
	void downevent(GLWidget::DownEventInfo* downinfo);
	
protected:
	void keyPressEvent(QKeyEvent *e);


	
private:
	GLWidget* pj;
	QTreeView *ptree;
	QStandardItemModel* model;
	QStandardItem* itemProject;
	QItemSelectionModel* selectionModel;
	GLWidget::LocationWQ wdata[500];
	int numb = 0;
	bool isablechanged;
private slots:
	void adownevent();
	void acurrentChanged(const QModelIndex & current, const QModelIndex & previous);
};

#endif // WEIQI_H
