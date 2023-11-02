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

void BTNode::LevelOrderTraversal(BTNode* Root)
{
	std::queue<BTNode*> TraversalQueue;

	TraversalQueue.push(Root);
	TraversalQueue.push(NULL);

	//std::cout << "The Root value is " << Root->Data << "\n";

	while (!TraversalQueue.empty())
	{
		BTNode* First = TraversalQueue.front();
		TraversalQueue.pop();

		if (First == NULL)
		{
			std::cout << "\n";
			if (!TraversalQueue.empty())
			{
				TraversalQueue.push(NULL);
			}
		}
		else
		{
			std::cout << First->Data << ": ";


			if (First->LHChild)
			{
				TraversalQueue.push(First->LHChild);
			}

			if (First->RHChild)
			{
				TraversalQueue.push(First->RHChild);
			}
		}
	}
}

int BTNode::CountNodes(BTNode* Root)
{
	if (Root == NULL)
	{
		return 0;
	}

	return CountNodes(Root->LHChild) + CountNodes(Root->RHChild) + 1;
}

void BTNode::InOrderTraversal(BTNode* Root)
{
	if (Root == NULL)
	{
		return;
	}

	InOrderTraversal(Root->LHChild); //Left

	std::cout << Root->Data; //Data

	InOrderTraversal(Root->RHChild); //Right


}

void BTNode::PreOrderTraversal(BTNode* Root)
{
	if (Root == NULL)
	{
		return;
	}

	std::cout << Root->Data; //Data 

	PreOrderTraversal(Root->LHChild); //Left 

	PreOrderTraversal(Root->RHChild); //Right

}

void BTNode::PostOrderTraversal(BTNode* Root)
{
	if (Root == NULL)
	{
		return;
	}

	PostOrderTraversal(Root->LHChild);

	PostOrderTraversal(Root->RHChild);

	std::cout << Root->Data;
}

int BTNode::BTHeight(BTNode* Root)
{
	if (Root == NULL)
	{
		return 0;
	}

	int LHHeight = BTHeight(Root->LHChild);
	int RHHEight = BTHeight(Root->RHChild) ;

	return std::max(LHHeight, RHHEight) + 1;

}

bool BTNode::SymmetricHelperFunct(BTNode* Left, BTNode* Right)
{
	if (Left == NULL && Right != NULL)
	{
		return false;
	}
	if (Left != NULL && Right == NULL)
	{
		return false;
	}
	if (Left == NULL && Right == NULL)
	{
		return true;
	}
	if (Left->Data != Right->Data)
	{
		return false;
	}

	return SymmetricHelperFunct(Left->LHChild, Right->RHChild) &&
		SymmetricHelperFunct(Left->RHChild, Right->LHChild);

}

bool BTNode::SymmetricBT(BTNode* Root)
{
	if (Root == NULL)
	{
		return true;
	}
	
	return SymmetricHelperFunct(Root->LHChild, Root->RHChild);
	
}

bool BTNode::IsValueinBT(BTNode* Root, int Value)
{
	if (Root->Data == Value)
	{
		return true;
	}


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
