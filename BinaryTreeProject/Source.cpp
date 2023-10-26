#include <iostream>
#include "BTNode.h"

int main()
{
	BTNode* BTTest = new BTNode(5);

	BTNode* LHTest = new BTNode(2);

	BTNode* RHTest = new BTNode(10);

	BTTest->LHChild = LHTest;

	BTTest->RHChild = RHTest;

	BTTest->~BTNode();

	return 0;
}