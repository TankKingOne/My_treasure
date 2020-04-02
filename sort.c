#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*********************************    栈的实现    *****************************************/

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		assert(ps->_a != NULL);
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

/**********************************************************************************************************/
void Print(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int *arr, int n)
{
	int end = 0;
	int tmp = 0;
	int i = 0;
	for (i = 0; i < n - 1; ++i)
	{
		end = i;
		tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}

void InsertSortTest()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void ShellSort(int *arr, int n)
{
	int gap = n;
	int i = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i < n - gap; ++i)
		{
			if (arr[i] > arr[i + gap])
				Swap(&arr[i], &arr[i + gap]);
		}
	}
}

void ShellSortTest()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	ShellSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void SelectSort(int *arr, int n)
{
	int max = 0;
	int end = n - 1;
	int i = 0;
	while (end > 0)
	{
		max = 0;
		for (i = 0; i <= end; ++i)
		{
			if (arr[i] > arr[max])
				max = i;
		}
		if (arr[max] != arr[end])
		{
			Swap(&arr[max], &arr[end]);
		}
		end--;
	}
}

void SelectSortTest()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void AdjustDown(int *arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1) < n && arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int *arr, int n)
{
	int parent = 0;
	int i = 0;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}
	for (i = n - 1; i >= 0; --i)
	{
		Swap(&arr[0], &arr[i]);
		AdjustDown(arr, 0, i);
	}
}

void HeapSortTest()
{
	int arr[] = { 5,8,6,9,3,4,2,1,7,5 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void BubbleSort(int *arr, int n)
{
	int i = n - 1;
	int j = 0;
	int exchange = 0;
	while (i >= 0) 
	{
		for (j = 0; j <= i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				exchange = 1;
			}
		}
		i--;
		if (exchange == 0)
			break;
	}
}

void BubbleSortTest()
{
	int arr[] = { 5,8,6,9,3,4,2,1,7,5 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

int PartSort_1(int *arr, int begin, int end)
{
	int key = begin;
	while (begin < end)
	{
		while (begin < end && arr[key] <= arr[end])
		{
			--end;
		}
		while (begin < end && arr[begin] <= arr[key])
		{
			++begin;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[key], &arr[end]);

	return begin;
}

void QuickSort_1(int *arr, int begin, int end) // 前后指针法
{
	if (end <= begin)
	{
		return;
	}
	int index = PartSort_1(arr, begin, end);
	QuickSort_1(arr, begin, index - 1);
	QuickSort_1(arr, index + 1, end);
}

int PartSort_2(int *a, int begin, int end)
{
	int tmp = a[begin];
	while (begin < end)
	{
		while (a[end] >= tmp && begin < end)
		{
			end--;
		}
		a[begin] = a[end];
		while (a[begin] <= tmp && begin < end)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = tmp;
	return begin;
}

void QuickSort_2(int *arr, int begin, int end) // 挖坑法
{
	if (end <= begin)
	{
		return;
	}
	int index = PartSort_2(arr, begin, end);
	QuickSort_2(arr, begin, index - 1);
	QuickSort_2(arr, index + 1, end);
}

void QuickSort_3(int *arr, int left, int right) // 非递归
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (StackEmpty(&st) != 0)
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		int div = PartSort_1(arr, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}
		if (div + 1 < end)
		{
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
	}
}

void QuickSortTest()
{
	int arr[] = { 5,8,6,9,3,4,2,1,7,5 };
	QuickSort_1(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));

	QuickSort_2(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));

	QuickSort_3(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));
}


void _MergeSort(int* a, int* tmp, int begin, int end)//归并排序
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + ((end - begin) >> 1);

	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int begin1 = begin; int end1 = mid;
	int begin2 = mid + 1; int end2 = end;

	int index = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	for (int i = 0; i < index; i++)
	{
		a[begin + i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
	tmp = NULL;
}

int main()
{
	InsertSortTest();
	ShellSortTest();
	SelectSortTest();
	HeapSortTest();
	BubbleSortTest();
	QuickSortTest();

	system("pause");
	return 0;
}