#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int x, y = 15;
	int *ip;
	ip = &y;
	cout << ip << " "
		<< &y << " "
		<< y << " "
		<< *ip;

	return 0;
}