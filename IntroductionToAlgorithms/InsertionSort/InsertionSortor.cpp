#include "InsertionSortor.h"
#include <ostream>
#include "common.h"

InsertionSortor::InsertionSortor()
{
	mpBuf = NULL;
	mBufLen = 0;
}

InsertionSortor::~InsertionSortor()
{
	delete []mpBuf;
}

void InsertionSortor::run(int *pInput,int inputLen)
{
	if (0 != inputLen && NULL != pInput)
	{
		privateRun(pInput,inputLen);
	}
	return;
}

void InsertionSortor::getResult(int *pResult)
{
	memcpy(pResult,mpBuf,mBufLen*sizeof(int));
	return;
}

void InsertionSortor::privateRun(int *pInput,int inputLen)
{
	mBufLen = inputLen;
	mpBuf = new int[mBufLen];
	memcpy(mpBuf,pInput,inputLen*sizeof(int));
	for (int iloop1 = 1; iloop1 < mBufLen ; iloop1 ++)
	{
		int tempInt = mpBuf[iloop1];

		int iloop2 = iloop1 - 1;
		while (iloop2 >= 0 && mpBuf[iloop2] > tempInt)
		{
			mpBuf[iloop2 + 1] = mpBuf[iloop2];
			iloop2 --;
		}
		mpBuf[iloop2 + 1] = tempInt;
		printIntArray(mpBuf,inputLen);
	}
	return;
}