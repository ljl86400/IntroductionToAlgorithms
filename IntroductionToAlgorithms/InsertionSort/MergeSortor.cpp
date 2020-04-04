#include "MergeSortor.h"
#include<ostream>

MergeSortor::MergeSortor()
{
	mpResult = NULL;
	mResultLen = 0;

}


MergeSortor::~MergeSortor()
{
	if (NULL != mpResult)
	{
		delete []mpResult;
	}
}

int MergeSortor::run(int *pInput,int inputLen)
{
	if (0 != inputLen && NULL != pInput)
	{
		mpResult = new int[inputLen];
		mResultLen = inputLen;
		privateRun(pInput,mpResult,inputLen);
	}
	return 0;
}

int MergeSortor::getResult(int *pResult)
{
	memcpy(pResult,mpResult,mResultLen*sizeof(int));
	return 0;
}

int MergeSortor::privateRun(int *pInput,int *pOutput,int inputLen)
{
	printIntArray(pInput,inputLen);
	int leftLen = inputLen/2;
	int rightLen = inputLen - leftLen;

	int *leftArray = new int[leftLen];
	int *rightArray = new int[rightLen];

	int *leftOutputArray = new int[leftLen];
	int *rightOutputArray = new int[rightLen];
	memcpy(leftArray,pInput,leftLen*sizeof(int));
	memcpy(rightArray,&pInput[leftLen],rightLen*sizeof(int));
		
	if (inputLen > 2)
	{
		privateRun(leftArray,leftOutputArray,leftLen);
		privateRun(rightArray,rightOutputArray,rightLen);
		merge(leftOutputArray,leftLen,rightOutputArray,rightLen,pOutput);
	}
	else
	{
		merge(leftArray,leftLen,rightArray,rightLen,pOutput);
	}
	printIntArray(pOutput,inputLen);

	delete []leftArray;
	delete []rightArray;
	delete []leftOutputArray;
	delete []rightOutputArray;
	return 0;
}


int MergeSortor::merge(int *pLeftInput,int leftLen,
					   int *pRightInput,int rightLen,
					   int *pOutput)
{
	int outLen = leftLen + rightLen;

	int leftIndex = 0;
	int rightIndex = 0;
	for (int iloop1 =0; iloop1 < outLen; iloop1 ++)
	{
		if (leftIndex < leftLen && rightIndex < rightLen)
		{
			if (pLeftInput[leftIndex] <= pRightInput[rightIndex])
			{
				pOutput[iloop1] = pLeftInput[leftIndex];
				leftIndex ++;
			} 
			else
			{
				pOutput[iloop1] = pRightInput[rightIndex];
				rightIndex ++;
			}
		} 
		else if(leftIndex >= leftLen)
		{
			pOutput[iloop1] = pRightInput[rightIndex];
			rightIndex ++;
		}
		else if(rightIndex >= rightLen)
		{
			pOutput[iloop1] = pLeftInput[leftIndex];
			leftIndex ++;
		}
	}

	return 0;
}