#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

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

//int main()
//{
//	int n = 153;
//	int hundreds = n / 100;
//	int tens = n / 10 - hundreds * 10;
//	int ones = n % 10;
//	printf("%d\n", hundreds);
//	printf("%d\n", tens);
//	printf("%d\n", ones);
//	return 0;
//}


//void* up(char* str, int i, int n,int width)
//{
//	int o = 0;
//	if (i <= n / 2)
//	{
//		void* left = (char*)str + (n / 2 - i) * width;
//		void* right = (char*)str + (n / 2 + i) * width;
//		*(char*)left = '*';
//		*(char*)right = '*';
//	}
//	return str;
//}
//void* under(char* str, int i, int n, int width)
//{
//	void* left = (char*)str + (n / 2 - i) * width;
//	void* right = (char*)str + (n / 2 + i) * width;
//	*(char*)left = ' ';
//	*(char*)right = ' ';
//	return str;
//}
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	int width = 0;
//	printf("请输入你要显示的行数(为奇数)>:");
//	scanf("%d", &n);
//	char* arr = (char*) malloc((n+1) * sizeof(char));
//	if (arr == NULL)
//	{
//		printf("退出!!!");
//		return 0;
//	}
//	//打印空格
//	for (j = 0; j < n; j++)
//	{
//		arr[j] = ' ';
//	}
//	arr[n] = 0;
//	width = sizeof(arr[0]);
//	//打印上半部分
//	for (i = 0; i <= n/2 ; i++)
//	{
//		up(arr,i, n,width);
//		printf("   %s\n", arr);
//	}
//	//打印下半部分
//	for (i = (n / 2 ); i > 0; i--)
//	{
//		under(arr, i, n, width);
//		printf("   %s\n", arr);
//	}
//	if (arr != NULL)
//	{
//		free(arr);
//		arr = NULL;
//	}
//	return 0;
//}

//int main()
//{
//	int money = 0;
//	int empty = 0;
//	int total = 0;
//	printf("你的钱数__,__杯可以换一杯\n");
//	scanf("%d %d", &money,&empty);
//	total = money;
//	for (money; money >= empty; )
//	{
//		total = total + money / empty;
//		money = money / empty + money % empty;
//	}
//	printf("可以喝 %d 杯", total);
//	return 0;
//}


////乱序排奇数在偶数前
//int move_int(const void* e1, const void* e2)
//{
//	return -(*(int*)e1 % 2 - *(int*)e2 % 2);
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int width = sizeof(width);
//	qsort(arr, sz, width,move_int);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//从左边找偶数
		while ((left < right) && arr[left] % 2 == 1)
		{
			left++;
		}
		//从右边找奇数
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}
		//交换
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz= sizeof(arr) / sizeof(arr[0]);
	move(arr,sz);
	print(arr, sz);
	return 0;
}