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

void BTNode::PrintRecursive(BTNode* Root)
{
	//This is Base Case, not Edge Case due to BT not having a vector for the stems 
	if (Root == NULL)
	{
		return;
	}
	std::cout << Root->Data << ": ";

	if (Root->LHChild)
	{
		std::cout << " L " << Root->LHChild->Data;
	}
	
	if (Root->RHChild)
	{
		std::cout << " R " << Root->RHChild->Data;
	}

	std::cout << "\n";

	PrintRecursive(Root->LHChild);
	PrintRecursive(Root->RHChild);
}

BTNode::~BTNode()
{
	delete LHChild;
	delete RHChild;
}
