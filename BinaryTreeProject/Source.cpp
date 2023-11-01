#include <iostream>
#include "BTNode.h"

int main()
{

	//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 

	BTNode* BTTest = new BTNode(5);

	BTNode* LHTest = new BTNode(25);

	BTNode* RHTest = new BTNode(10);

	BTTest->LHChild = LHTest;

	BTTest->RHChild = RHTest;

	//BTTest = BTTest->TakeInputRecursive();

	BTTest = BTTest->TakeInputLevelWise();

	BTTest->PrintRecursive(BTTest);

	BTTest->LevelOrderTraversal(BTTest);

	int CountNodes = BTTest->CountNodes(BTTest);

	std::cout << "The number of nodes in your tree is: " << CountNodes << "\n";

	BTTest->~BTNode();

	return 0;
}