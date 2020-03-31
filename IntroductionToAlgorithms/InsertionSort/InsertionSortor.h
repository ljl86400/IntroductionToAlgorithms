#ifndef INSERTIONSORTOR
#define INSERTIONSORTOR

#include<ostream>

class InsertionSortor
{
public:
	InsertionSortor();
	~InsertionSortor();
	void run(int *pInput,int inputLen);
	void getResult(int *pResult);
protected:
private:
	void privateRun(int *pInput,int inputLen);
	

private:
	int *mpBuf;
	int mBufLen;
	int *mpResult;
};

#endif