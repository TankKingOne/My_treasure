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
		if (cur->val == val)             //��ǰ�ڵ���Ҫɾ��
		{
			//�Ȼ�ȡnext�ڵ�
			next = cur->next;
			free(cur);
			cur = next;
			if (prev == NULL)     //Ҫɾ�ڵ��Ƿ�Ϊͷ���
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
		}
		else          //��ǰ�ڵ㲻��Ҫɾ��
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
		//�Ȼ�ȡ��һ���ڵ�
		next = cur->next;
		//���ĵ�ǰ�ڵ�ָ��
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
	//ͳ������ڵ����
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
