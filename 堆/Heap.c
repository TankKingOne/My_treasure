#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Swap(HPDataType* a, HPDataType* b)
{
	assert(a && b);

	HPDataType* tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);
	//对堆进行初始化
	//int i = 0;
	//hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * n);
	//for (i = 0; i < n; i++)
	//{
	//	hp->_array[i] = a[i];
	//}
	//hp->_size = n;
	//hp->_capacity = n;

	for (int i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	//hp->_array = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		hp->_capacity = hp->_capacity * 2;
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	
	AdjustUp(hp, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);

	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->_size == 0 ? 0 : 1;
}

void AdjustDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void AdjustUp(Heap* ph, int child)
{
	assert(ph);

	int parent = (child - 1) >> 1;
	//开始调整，直到child == 0
	while (child > 0)
	{
		if (ph->_array[parent] < ph->_array[child])
		{
			Swap(&ph->_array[parent], &ph->_array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		//如果child小于或者等于parent的话，那就不用调整堆了
		else
		{
			break;
		}
	}
}

void HeapPrint(Heap* hp)
{
	assert(hp);

	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void Sort(HPDataType* a, int n)
{
	assert(a);

	int start_size = n;

	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	while (n > 0)
	{
		Swap(&a[0], &a[n - 1]);
		n--;

		AdjustDown(a, n, 0);
	}
	n = start_size;
}



void TestHeap()
{
	Heap hp;
	HPDataType arr[] = { 34, 35, 32, 54, 65, 87, 9, 56, 90 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapInit(&hp, arr, size);
	HeapPrint(&hp);

	HeapPush(&hp, 100);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	printf("堆的堆顶元素为:%d\n", HeapTop(&hp));

	printf("堆的大小:%d\n", HeapSize(&hp));

	if (HeapEmpty(&hp))
	{
		printf("堆不为空!\n");
	}
	else
	{
		printf("堆为空!\n");
	}

	////堆排序
	////从小到大（大顶堆）
	////HeapSortSmallToBig(hp._a, hp._size);
	//HeapPrint(&hp);
	////从大到小
	////HeapSortBigToSmall(hp._a, hp._size);
	Sort(&arr, 0);
	HeapPrint(&hp);

	//HeapDestory(&hp);
}