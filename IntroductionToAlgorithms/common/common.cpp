// common.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "common.h"

void printIntArray(int *pArray,int arrayLen)
{
	for (int iloop1 = 0; iloop1 < arrayLen; iloop1 ++)
	{
		std::cout << pArray[iloop1] << ",";
	}
	std::cout << std::endl;
	return;
}

