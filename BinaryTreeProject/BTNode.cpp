#include "BTNode.h"

BTNode::BTNode()
{
	this->LHChild = NULL;
	this->RHChild = NULL;
}

BTNode::BTNode(int Element)
{
	this->Data = Element;
	this->LHChild = NULL;
	this->RHChild = NULL;
}

BTNode::~BTNode()
{
	delete LHChild;
	delete RHChild;
}
