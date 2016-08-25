#include "stdafx.h"
#include "TArray.h"
#include <iostream>

using namespace std;

TArray::TArray()
{
}

TArray::~TArray()
{
}

int TArray::ForArray()
{
	int i, *p;
	int a[10] = { 12,23,85,8,54,77,89,44,20,95 };
	p = &a[0];
	for (i = 0; i < 10; i++)
	{
		cout << *p << "  ";//先打印
		p++;//再移到下一位
	}
	cout << "what the fuck";

	return 0;
}

int TArray::Malloc()
{
	//void *p = malloc(100);
	//cout << sizeof(p);

	//char str[] = "Hello";
	//char *p = str;
	//cout << sizeof(p);

	return 0;
}