#include "stdafx.h"
#include "TSqrt.h"
#include <iostream>
#include <windows.h>
#include "math.h"
#define eps 1e-7

using namespace std;

float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating VALUE
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits BACK to float
	x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy
	x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy
	x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy

	return 1 / x;
}

float SqrtByNewton(float x)
{
	float val = x;//����
	float last;//������һ�������ֵ
	do
	{
		last = val;
		val = (val + x / val) / 2;
	} while (abs(val - last) > eps);
	return val;
}

float SqrtByBisection(float n) //�ö��ַ�
{
	if (n < 0) //С��0�İ�������Ҫ�Ĵ���
		return n;
	float mid, last;
	float low, up;
	low = 0, up = n;
	mid = (low + up) / 2;
	do
	{
		if (mid*mid > n)
			up = mid;
		else
			low = mid;
		last = mid;
		mid = (up + low) / 2;
	} while (abs(mid - last) > eps);//���ȿ���
	return mid;
}

TSqrt::TSqrt()
{
	unsigned int LoopCount = 1000;
	float x = 65535;
	LARGE_INTEGER d1, d2, d3, d4, d5;
	QueryPerformanceCounter(&d1);
	for (unsigned int i = 0; i < LoopCount; i++)
		SqrtByBisection(x);
	QueryPerformanceCounter(&d2);
	for (unsigned int i = 0; i < LoopCount; i++)
		SqrtByNewton(x);
	QueryPerformanceCounter(&d3);
	for (unsigned int i = 0; i < LoopCount; i++)
		InvSqrt(x);
	QueryPerformanceCounter(&d4);
	for (unsigned int i = 0; i < LoopCount; i++)
		sqrt(x);
	QueryPerformanceCounter(&d5);

	printf("����sqrt(65535)����ĶԱ�\n");
	printf("--------------------------------------\n");
	printf("    ����     \t ʱ��\t  ������\n");
	printf("���ַ�     : %8.2f\t%8.8f\n", ((float)d2.QuadPart - (float)d1.QuadPart), SqrtByBisection(x));
	printf("ţ�ٵ����� : %8.2f\t%8.8f\n", ((float)d3.QuadPart - (float)d2.QuadPart), SqrtByNewton(x));
	printf("����ķ��� : %8.2f\t%8.8f\n", ((float)d4.QuadPart - (float)d3.QuadPart), InvSqrt(x));
	printf("System���� : %8.2f\t%8.8f\n", ((float)d5.QuadPart - (float)d4.QuadPart), sqrt(x));
	printf("--------------------------------------\n");
}

TSqrt::~TSqrt()
{
}