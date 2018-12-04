#define _CRT_SECURE_NO_WARNINGS 1

#include"DLinkList.h"

void ListInit(List* plist)
{
	assert(plist);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	ListNode* next = cur->_next;
	while (cur != plist->_head)
	{
		free(cur);
		cur = next;
		next = next->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("结点申请失败！");
		exit(1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* newNode = BuyListNode(x);
	ListNode* cur = plist->_head->_prev;
	newNode->_prev = cur;
	newNode->_next = plist->_head;
	cur->_next = newNode;
	plist->_head->_prev = newNode;
}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("%d<-->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void ListPopBack(List* plist)
{
	assert(plist && plist->_head->_next);
	ListNode* cur = plist->_head->_prev;
	ListNode* prev = cur->_prev;
	prev->_next = plist->_head;
	plist->_head->_prev = prev;
	cur->_prev = NULL;
	cur->_next = NULL;
}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* newNode = BuyListNode(x);
	ListNode* next = plist->_head->_next;
	newNode->_next = next;
	next->_prev = newNode;
	newNode->_prev = plist->_head;
	plist->_head->_next = newNode;
}

void ListPopFront(List* plist)
{
	assert(plist && plist->_head->_next);
	ListNode* cur = plist->_head->_next;
	ListNode* next = cur->_next;
	plist->_head->_next = next;
	next->_prev = plist->_head;
	cur->_next = NULL;
	cur->_prev = NULL;
	free(cur);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	newNode->_next = pos;
	newNode->_prev = prev;
	prev->_next = newNode;
	pos->_prev = newNode;
}

// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	pos->_next = NULL;
	pos->_prev = NULL;
	free(pos);
}

void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = ListFind(plist, x);
	ListErase(cur);
}

void TestSList()
{
	List p;
	ListInit(&p);
	ListPushBack(&p, 1);
	ListPushBack(&p, 2);
	ListPushBack(&p, 3);
	ListPushBack(&p, 4);
	ListPushFront(&p, 8);
	ListPushFront(&p, 7);
	ListPushFront(&p, 6);
	ListPushFront(&p, 5);
	ListPrint(&p);

	ListRemove(&p, 3);
	ListPrint(&p);

	ListPopBack(&p);
	ListPrint(&p);

	ListPopFront(&p);
	ListPrint(&p);

	ListErase(ListFind(&p, 7));
	ListPrint(&p);

	ListDestory(&p);

}
