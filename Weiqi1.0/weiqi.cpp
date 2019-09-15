#include "weiqi.h"

Weiqi::Weiqi(QWidget *parent)
	: QMainWindow(parent)
{

	
	this->resize(1400, 600);	
	
	ptree = new QTreeView();
	pj = new GLWidget;

	this->setCentralWidget(pj);
	connect(pj, SIGNAL(downevent()), this, SLOT(adownevent()));
	
	model = new QStandardItemModel(ptree);
	model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("棋局信息"));
	QDockWidget *qdleft = new QDockWidget("步骤", this);
	qdleft->setFont(QFont("微软雅黑", 10, 10));
	
	qdleft->setWidget(ptree);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, qdleft);
	QDockWidget *qdright = new QDockWidget("gree", this);
	this->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, qdright);
	ptree->setModel(model);
	selectionModel = new QItemSelectionModel(model);
	ptree->setSelectionModel(selectionModel);
	//ptree->setRootIsDecorated(false);
	ptree->setExpandsOnDoubleClick(false);
	//ptree->setAllColumnsShowFocus(true);
	ptree->setSelectionMode(QAbstractItemView::SingleSelection);
	connect(selectionModel, SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(acurrentChanged(const QModelIndex &, const QModelIndex &)));
//	ptree->setAllColumnsShowFocus(true);
}

Weiqi::~Weiqi()
{

}

void Weiqi::adownevent(){
	//static 

	GLWidget::DownEventInfo* d = &pj->downeventinfo;
	GLWidget::LocationWQ r; r.x = d->present.x; r.y = d->present.y;
	wdata[numb].x = r.x; wdata[numb].y = r.y;

	QString qs;
	qs = (pj->isBlack() ? "▶ " : "▷ ") + QString::number(numb + 1) + "(" +  QString::number(d->present.x) + "," +QString::number(d->present.y) + ")";
	QStandardItem* item = new QStandardItem(qs);
	item->setEditable(false);
	model->appendRow(item);
	isablechanged = false;
	ptree->setCurrentIndex(model->index(numb, 0));
	isablechanged = true;
	numb++;
	
	if (d->count == 0){
		this->setWindowTitle(" ");
		return;
	}	
	
	qs = QString::number(d->present.x) + QString::number(d->present.y) + QString::number(d->count) + "!" + QString::number(d->issdethBlack) + "!!!死棋： \n";

	for (int i = 0; i <= d->count - 1; i++){
		qs += (QString::number(d->deths[i].x) + "," + QString::number(d->deths[i].y) + "  ");
	}
	//this->setWindowTitle(qs);
	//QMessageBox::information(NULL, "Title", qs, QMessageBox::Yes, QMessageBox::Yes);
	//this->

	
}

void Weiqi::keyPressEvent(QKeyEvent *e){	
	QApplication::sendEvent(pj, e);
	e->ignore();
}

void Weiqi::acurrentChanged(const QModelIndex & current, const QModelIndex & previous){
	if (isablechanged){
		pj->clearWQ();
		for (int i = 0; i <= current.row(); i++)
			pj->pushBack(wdata[i].x, wdata[i].y);
	}

	this->setWindowTitle(current.data().toString());
}