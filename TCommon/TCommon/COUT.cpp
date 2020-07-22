#include "stdafx.h"
#include "COUT.h"
#include <iostream>
#include<string>

using namespace std;

COUT::COUT()
{
}

COUT::~COUT()
{
}

void COUT::Execute()
{
	int* p = nullptr;
	int i = 5;
	p = &i;
	int j = *p;

	cout << strAdd("Hello");
	cout << "p: \n";
	cout << p;
}

string COUT::strAdd(string str1)
{
	return str1 + " World!\n";
}