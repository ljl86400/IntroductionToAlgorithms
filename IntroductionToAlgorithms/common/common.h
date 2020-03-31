#pragma once

#ifdef CREATDLL_EXPORTS
#define DLL_API __declspec(dllexport)  
#else
#define DLL_API __declspec(dllimport)  
#endif

#include <iostream>
#include <string>


extern "C" DLL_API void printIntArray(int *pArray,int arrayLen);