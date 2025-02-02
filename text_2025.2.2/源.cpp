#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int arr[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&arr + 1);
	int* ptr2 = (int*)(*(arr + 1));

	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}