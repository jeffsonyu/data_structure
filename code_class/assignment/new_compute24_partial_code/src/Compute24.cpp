#include <iostream>
#include "OperationSetA.h"
#include "OperationSetB.h"
using namespace std;

int main(int argn, char* argc[])
{
	BaseOperations* baseOp;
	if (argn<2 || argc[1][0] == '1'){
		OperationSetA cp24A;
		cp24A.Read();
		cp24A.Display();
		/*********************/
	}
	else{
		OperationSetB cp24B;
		// cp24B.Read();
		// cp24B.Display();
		/*********************/
	}
	/*
	 *
	 *
	 *
	 *
	 */
	
	return 0;
}

