#define _CRT_SECURE_NO_WARNINGS 1

//203
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while (cur)
	{
		if (cur->val == val)             //当前节点需要删除
		{
			//先获取next节点
			next = cur->next;
			free(cur);
			cur = next;
			if (prev == NULL)     //要删节点是否为头结点
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
		}
		else          //当前节点不需要删除
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//206
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while (cur)
	{
		//先获取下一个节点
		next = cur->next;
		//更改当前节点指向
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

//876
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* cur = head;
	int count = 0;
	int mid = 0;
	//统计链表节点个数
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	mid = count / 2;
	cur = head;
	while (mid--)
	{
		cur = cur->next;
	}

	return cur;
}
