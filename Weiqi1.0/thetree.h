#include "global.h"
#include "wglwidget.h"
#include <iostream>
#pragma once
using namespace std;

typedef int T;
class thetree
{
public:


	struct treeInfo{
		GLWidget::LocationIsB data;
		GLWidget::LocationIsB ** firstChild;

	};
	vector<treeInfo>* ptheInfo;



public:

	thetree();
	~thetree();


};

