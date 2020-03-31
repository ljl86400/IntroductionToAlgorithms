#include <stdlib.h>
#include "InsertionSortor.h"
#include "common.h"

int main()
{
	int inputArray[] = {5,8,14,5,7,5,8,5,1,7,5};
	int arraySize = sizeof(inputArray)/sizeof(int);
	int *pSortResult = new int[11];

	InsertionSortor sortor;
	sortor.run(inputArray,arraySize);
	sortor.getResult(pSortResult);

	printIntArray(pSortResult,arraySize);

	delete []pSortResult;
	getchar();
	return 0;
}