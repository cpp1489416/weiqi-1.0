#include "thetree.h"


thetree::thetree()
{
	ptheInfo = new vector < treeInfo > ;
	ptheInfo->at(9).firstChild = nullptr;
	ptheInfo->push_back(ptheInfo->at(9));
}


thetree::~thetree()
{
}
