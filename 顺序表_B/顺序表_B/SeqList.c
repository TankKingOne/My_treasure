#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	psl->_size = 0;
	psl->_capicity = capacity;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->_array)
	{
		free(psl->_array);
		psl->_array = NULL;
		psl->_capicity = psl->_size = 0;
	}
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->_size == psl->_capicity)
	{
		psl->_capicity *= 2;
		psl->_array = realloc(psl->_array, psl->_capicity*sizeof(SLDataType));
		assert(psl->_array);
	}
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl && psl->_size > 0);
	psl->_size--;
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_array[psl->_size++] = x;
}

void SeqListPushFront(SeqList* psl, SLDataType x)   //前插
{
	assert(psl);
	CheckCapacity(psl);
	int end = psl->_size - 1;
	while (end >= 0)
	{
		psl->_array[end + 1] = psl->_array[end];
		end--;
	}
	psl->_array[0] = x;
	psl->_size++;
}


void SeqListPopFront(SeqList* psl)                  //前删
{
	assert(psl&&psl->_size > 0);
	size_t begin = 0;
	while (begin <= psl->_size - 1)
	{
		psl->_array[begin] = psl->_array[begin + 1];
		begin++;
	}
	psl->_size--;
}


int SeqListFind(SeqList* psl, SLDataType x) //查找
{
	assert(psl);
	size_t i = 0;
	for (i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}


void SeqListInsert(SeqList* psl, size_t pos, SLDataType x) //指定位置插入指定元素
{
	assert(psl && pos <= psl->_size);
	CheckCapacity(psl);
	size_t end = psl->_size;
	while (end > pos)
	{
		psl->_array[end] = psl->_array[end - 1];
		end--;
	}
	psl->_array[pos] = x;
	psl->_size++;
}

void SeqListErase(SeqList* psl, size_t pos)  //删除指定位置
{
	assert(psl && psl->_size > 0);
	size_t begin = pos;
	while (begin < psl->_size)
	{
		psl->_array[begin] = psl->_array[begin+1];
		begin++;
	}
	psl->_size--;
}


void SeqListRemove(SeqList* psl, SLDataType x) //查找删除
{
	int ret = SeqListFind(psl, x);
	SeqListErase(psl, ret);
}


void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	psl->_array[pos] = x;
}

void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	int finish = psl->_size - 1;
	int i = 0;
	while (finish)
	{
		int exchange = 0;
		for (i = 0; i <= finish; i++)
		{
			if (psl->_array[i-1] > psl->_array[i])
			{
				size_t tmp = psl->_array[i-1];
				psl->_array[i-1] = psl->_array[i];
				psl->_array[i] = tmp;
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
		finish--;
	}
}

int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int left = 0;
	int right = psl->_size - 1;
	int mid = left + (right - left) / 2;
	while (left < right)
	{
		if (psl->_array[mid] < x)
		{
			left = mid + 1;
			mid = left + (right - left) / 2;
		}
		else if (psl->_array[mid] > x)
		{
			right = mid - 1;
			mid = left + (right - left) / 2;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	int begin = 0;
	int end = psl->_size - 1;
	SLDataType tmp;
	while (begin < end)
	{
		if (psl->_array[begin] != x)
		{
			begin++;
			//end--;
		}
		else
		{
			while (psl->_array[end] == x)
			{
				end--;
			}
			tmp = psl->_array[begin];
			psl->_array[begin] = psl->_array[end];
			psl->_array[end] = tmp;
			begin++;
			end--;
		}
	}
	int num = psl->_size - end;
	while (--num)
	{
		psl->_size--;
	}
}

void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		printf("%d ", psl->_array[i]);
	}
	printf("\n");
}

void SeqListTest()
{
	SeqList p;
	SeqListInit(&p, 5);
	SeqListPushBack(&p, 1);
	SeqListPushBack(&p, 2);
	SeqListPushBack(&p, 3);
	SeqListPushBack(&p, 4);
	SeqListPopBack(&p);
	//SeqListDestory(&p);
	SeqListPushFront(&p, 0);
	SeqListPopFront(&p);
	SeqListPrint(&p);
}

void SeqListTest2()
{
	SeqList p;
	SeqListInit(&p, 5);
	SeqListPushBack(&p, 1);
	SeqListPushBack(&p, 2);
	SeqListPushBack(&p, 3);
	SeqListPushBack(&p, 4);
	SeqListPushBack(&p, 5);
	SeqListPrint(&p);
	printf("find index: %d\n", SeqListFind(&p, 0));
	printf("find index: %d\n", SeqListFind(&p, 1));
	printf("find index: %d\n", SeqListFind(&p, 2));
	printf("find index: %d\n", SeqListFind(&p, 3));
	printf("find index: %d\n", SeqListFind(&p, 4));
}

void SeqListTest3()
{
	SeqList p;
	SeqListInit(&p, 5);
	SeqListPushBack(&p, 1);
	SeqListPushBack(&p, 2);
	SeqListPushBack(&p, 3);
	SeqListPushBack(&p, 4);
	SeqListPushBack(&p, 5);
	SeqListPushBack(&p, 6);
	SeqListPushBack(&p, 7);
	SeqListPushBack(&p, 10);
	SeqListPrint(&p);
	SeqListInsert(&p, 1, 100);
	SeqListPrint(&p);
	SeqListErase(&p, 5);
	SeqListPrint(&p);
	SeqListRemove(&p, 10);
	SeqListPrint(&p);

}

void SeqListTest4()
{
	SeqList s;
	SeqListInit(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListInsert(&s, 2, 30);
	SeqListInsert(&s, 0, 30);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	SeqListDestory(&s);
}


void SeqListTest5()
{
	SeqList p;
	SeqListInit(&p, 5);
	SeqListPushBack(&p, 1);
	SeqListPushBack(&p, 2);
	SeqListPushBack(&p, 3);
	SeqListPushBack(&p, 4);
	SeqListPushBack(&p, 5);
	SeqListModify(&p, 3, 100);
	SeqListPrint(&p);
}


void SeqListTest6()
{
	SeqList p;
	SeqListInit(&p, 5);
	SeqListPushBack(&p, 7);
	SeqListPushBack(&p, 5);
	SeqListPushBack(&p, 3);
	SeqListPushBack(&p, 9);
	SeqListPushBack(&p, 8);
	SeqListPushBack(&p, 4);
	SeqListPushBack(&p, 2);
	SeqListPrint(&p);
	SeqListBubbleSort(&p);
	printf("%d ", SeqListBinaryFind(&p, 1));
	printf("%d ", SeqListBinaryFind(&p, 2));
	printf("%d ", SeqListBinaryFind(&p, 3));
	printf("%d ", SeqListBinaryFind(&p, 5));
	printf("%d ", SeqListBinaryFind(&p, 7));
	printf("%d ", SeqListBinaryFind(&p, 8));
	printf("%d ", SeqListBinaryFind(&p, 9));
	printf("\n");
	SeqListPrint(&p);

}

void SeqListTest7()
{
	SeqList p;
	SeqListInit(&p, 5);
	SeqListPushBack(&p, 7);
	SeqListPushBack(&p, 2);
	SeqListPushBack(&p, 3);
	SeqListPushBack(&p, 2);
	SeqListPushBack(&p, 8);
	SeqListPushBack(&p, 4);
	SeqListPushBack(&p, 2);
	//SeqListBubbleSort(&p);
	SeqListPrint(&p);
	SeqListRemoveAll(&p, 2);
	SeqListPrint(&p);
	SeqListBubbleSort(&p);
	SeqListPrint(&p);

}