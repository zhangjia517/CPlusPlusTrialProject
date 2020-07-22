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
	cout << strAdd("Hello");
}

string COUT::strAdd(string str1)
{
	return str1 + " World!";
}