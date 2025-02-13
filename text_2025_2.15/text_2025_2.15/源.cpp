#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<string.h>

//void rever(void* str, int sz)
//{
//	void* left = str;
//	void* right = (char*)str + sz - 1;
//	for (int i = 0; i < sz; i++)
//	{
//		if (left < right)
//		{
//			int temp = *(char*)left;
//			*(char*)left = *(char*)right;
//			*(char*)right = temp;
//			left = (char*)left + 1;
//			right = (char*)right - 1;
//		}
//	}
//}
//
//int main()
//{
//	char arr[256] = { 0 };
//	scanf("%s", arr);
//	int sz = strlen(arr);
//	rever(arr, sz);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int n = 0;
//	int input = 0;
//	int ret = 0;
//	int num = 0;
//	scanf("%d%d", &a ,&input);//a表示要计算的数，intput表示计算的次数
//	for (int i = 0; i < input; i++)
//	{
//		ret = ret * 10 + a;
//		num += ret;
//	}
//	printf("%d\n", num);
//	return 0;
//}

//int main()
//{
//	printf("0———10000的自幂数");
//	int i = 0;
//	for (i = 0; i <= 10000; i++)
//	{
//		//判断是否为水仙花数（自幂数）
//		//1.计算i的位数-n位数
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2.计算i的每一位的n次方和sum
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		//3.比较i==sum
//		if (i == sum)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

int main()
{
	int n = 153;
	int hundreds = n / 100;
	int tens = n / 10 - hundreds * 10;
	int ones = n % 10;
	printf("%d\n", hundreds);
	printf("%d\n", tens);
	printf("%d\n", ones);
	return 0;
}