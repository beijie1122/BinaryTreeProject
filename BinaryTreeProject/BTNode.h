#pragma once
#include <iostream>
class BTNode
{
public:

	int Data;
	BTNode* LHChild;
	BTNode* RHChild;

	BTNode();

	BTNode(int Element);

	void PrintRecursive(BTNode* Root);

	BTNode* TakeInputRecursive();

	~BTNode();

};

