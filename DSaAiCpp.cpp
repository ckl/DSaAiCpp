// DSaAiCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "IntSLList.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	IntSLList l;
	IntSLList *p = &l;
	cout << "p points to: " << p << endl;
	cin.get();

	return 0;
}

