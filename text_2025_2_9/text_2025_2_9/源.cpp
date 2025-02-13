#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>

//int main()
//{
//	unsigned long pulArray[] = {6,7,8,9,10};
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//	return 0;
//}

void menu()
{
	printf("************************************\n");
	printf("******1.数字             2.字符*****\n");
	printf("************  0.exit  **************\n");
	printf("************************************\n");
}

void reverse(void* str,int sz,int width)
{
	assert(str);
	void* left = str;
	void* right = (char*)str + sz * width - width;

	/*if (width == 1)
	{*/
		for (int i = 0; i < sz; i++)
		{
			if (left < right)
			{
				int  temp = *(char*)left;
				*(char*)left = *(char*)right;
				*(char*)right = temp;
				left = (char*)left + 1 * width;
				right = (char*)right - 1 * width;
			}
			else
				break;
		}
	//}
	/*else*/
	/*for (int i = 0; i < sz; i++)
	{
		if (left < right)
		{
			int temp = *(int*)left;
			*(int*)left = *(int*)right;
			*(int*)right = temp;
			left = (char*)left + 1 * width;
			right = (char*)right - 1 * width;
		}
		else
			break;
	}*/
}

int main()
{
	char arr[256] = { 0 };
	int* arr2 = NULL;//申请的内存地址指针
	int input = 0;//用户选则的操作
	int sz = 0;//计算的是数组元素的个数
	int width = 0;//计算的是数组里面的元素大小
	int n = 0;//动态数组的元素个数 
	printf("请选择你要执行的数据类型\n");
	menu();
	scanf("%d", &input);
	switch (input)
	{
	case 0:
		printf("退出!!!");
		break;
	case 1:
		do
		{
			printf("请输入你要输入的数的个数->(0----退出)\n");
			scanf("%d", &n);
			arr2 = (int*)malloc(n * sizeof(int));////分配内存空间
			printf("请输入要逆序的数字《请用ENTER键隔开》\n");
				for (int i = 0; i < n; i++)
				{
					scanf("%d", &arr2[i]);
				}
				sz = n ;
			width = sizeof(arr2[0]);
			reverse(arr2, sz, width);
			//打印
			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr2[i]);
			}
			printf("\n");
			//释放内存空间
			if (arr2 != NULL) {
				free(arr2);
				arr2 = NULL;
			}
		} while (n > 0);
		break;
	case 2:
		do
		{
			printf("请输入要逆序的字符（0----退出）:\n");
				scanf("%s", arr);
				if (arr[0]!= '0')
				{
					sz = strlen(arr);
					width = sizeof(arr[0]);
					reverse(arr, sz, width);
					printf("%s\n", arr);
				}
		} while (arr[0] != '0');
		break;
	default:
		printf("输入错误!!!");
		break;
	}
	return 0;
}
