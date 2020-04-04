#include <stdlib.h>
#include <iostream>
#include "InsertionSortor.h"
#include "MergeSortor.h"
#include "common.h"

int main()
{
	int inputArray[] = {3,41,52,26,38,57,9,49};
	int arraySize = sizeof(inputArray)/sizeof(int);

	
	int *pInsertionSortResult = new int[arraySize];
	InsertionSortor insertionSortorIns;
	insertionSortorIns.run(inputArray,arraySize);
	insertionSortorIns.getResult(pInsertionSortResult);
	printIntArray(pInsertionSortResult,arraySize);
	delete []pInsertionSortResult;
	std::cout << "Insertion sort\n\n\n";
	
	int *pMergeSortorResult = new int[arraySize];
	MergeSortor mergeSortorIns;
	mergeSortorIns.run(inputArray,arraySize);
	mergeSortorIns.getResult(pMergeSortorResult);
	printIntArray(pMergeSortorResult,arraySize);
	delete []pMergeSortorResult;
	std::cout << "Merge sort\n\n\n";

	getchar();
	return 0;
}