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

BTNode* BTNode::TakeInputRecursive()
{
	int RootData;

	std::cout << "What is the data for this node?\n";

	std::cin >> RootData;

	if (RootData == -1)
	{
		return NULL;
	}

	BTNode* NewRoot = new BTNode(RootData);

	NewRoot->LHChild = TakeInputRecursive();
	NewRoot->RHChild = TakeInputRecursive();

	return NewRoot;

}

BTNode* BTNode::TakeInputLevelWise()
{
	int input;
	std::queue<BTNode*> LevelWiseQueue;

	std::cout << "What is the Root Data: \n";
	std::cin >> input;

	BTNode* NewRoot = new BTNode(input);

	LevelWiseQueue.push(NewRoot);

	while (!LevelWiseQueue.empty())
	{
		BTNode* FrontNode = LevelWiseQueue.front();
		LevelWiseQueue.pop();

		std::cout << "What is the LH Child of " << FrontNode->Data << ":\n";
		int LHData;
		std::cin >> LHData;

		if (LHData != -1)
		{
			//1) Generate Node 2) Push to Queue 3) Connect to root/previous nodes
			BTNode* GenLHChild = new BTNode(LHData);
			LevelWiseQueue.push(GenLHChild);
			FrontNode->LHChild = GenLHChild;
		}

		std::cout << "What is the RH Child of "<< FrontNode->Data << ":\n";
		int RHData;
		std::cin >> RHData;

		if (RHData != -1)
		{
			//1) Generate Node 2) Push to Queue 3) Connect to root/previous nodes
			BTNode* GenRHChild = new BTNode(RHData);
			LevelWiseQueue.push(GenRHChild);
			FrontNode->RHChild = GenRHChild;
		}

	}

	return NewRoot;

	return nullptr;
}

BTNode::~BTNode()
{
	delete LHChild;
	delete RHChild;
}
