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

	void PreOrderTraversal(BTNode* Root);

	void PostOrderTraversal(BTNode* Root);

	int BTHeight(BTNode* Root);

	bool SymmetricHelperFunct(BTNode* Left, BTNode* Right);

	bool SymmetricBT(BTNode* Root);

	bool IsValueinBT(BTNode* Root, int Value);

	BTNode* TakeInputRecursive();

	BTNode* TakeInputLevelWise();

	~BTNode();

};

