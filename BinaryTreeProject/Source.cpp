#include <iostream>
#include "BTNode.h"

int main()
{
	BTNode* BTTest = new BTNode(5);

	BTNode* LHTest = new BTNode(25);

	BTNode* RHTest = new BTNode(10);

	BTTest->LHChild = LHTest;

	BTTest->RHChild = RHTest;

	//BTTest = BTTest->TakeInputRecursive();

	BTTest = BTTest->TakeInputLevelWise();

	BTTest->PrintRecursive(BTTest);

	BTTest->~BTNode();

	return 0;
}