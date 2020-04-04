#ifndef MERGESORTOR_H
#define MERGESORTOR_H
#include "common.h"
class MergeSortor
{
public:
	MergeSortor();
	~MergeSortor();
	int run(int *pInput,int inputLen);
	int getResult(int *pResult);
protected:
private:
	int privateRun(int *pInput,int *pOutput,int inputLen);
	int merge(int *pLeftInput,int leftLen,
				int *pRightInput,int rightLen,
				int *pOutput);

private:
	int mResultLen;
	int *mpResult;
};

#endif