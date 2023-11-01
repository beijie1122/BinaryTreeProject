#pragma once
#include <iostream>
#include <queue>
class BTNode
{
public:

	int Data;
	BTNode* LHChild;
	BTNode* RHChild;

	BTNode();

	BTNode(int Element);

	void PrintRecursive(BTNode* Root);

	void LevelOrderTraversal(BTNode* Root);

	int CountNodes(BTNode* Root);

	void InOrderTraversal(BTNode* Root);

	BTNode* TakeInputRecursive();

	BTNode* TakeInputLevelWise();

	~BTNode();

};

