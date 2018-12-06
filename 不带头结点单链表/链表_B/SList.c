#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListInit(SList* plist)
{
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* next = cur->_next;
	while (cur)
	{
		free(cur);
		cur = next;
		next = next->_next;
	}
	plist->_head = NULL;
}


SListNode* BuySListNode(SLTDataType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	NewNode->_data = x;
	NewNode->_next = NULL;
	return NewNode;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	newNode->_next = plist->_head;
	plist->_head = newNode;
}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	plist->_head = plist->_head->_next;
	free(cur);
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->_next = pos->_next;
	pos->_next = newNode;
}

void SListEraseAfter(SListNode* pos)
{
	SListNode* cur = pos->_next;
	pos->_next = cur->_next;
	free(cur);
}

void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_next->_data == x)
		{
			SListNode* p = cur->_next;
			cur->_next = p->_next;
			free(p);
		}
	}
}



void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void houshan(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* next = cur->_next;
	while (next->_next)
	{
		cur = next;
		next = next->_next;
	}
	free(next);
	cur->_next = NULL; 

}


void TestSList()
{
	SList p;
	SListInit(&p);
	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	houshan(&p);
	//SListPopFront(&p);
	SListPrint(&p);
}