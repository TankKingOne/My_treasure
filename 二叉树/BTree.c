#define _CRT_SECURE_NO_WARNINGS 1


#include"Queue.h"

BTNode* BinaryTreeBuy(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BinaryTreeBuy(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
		return NULL;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k-1) + BinaryTreeLevelKSize(root->_right, k-1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret == NULL)
	{
		ret = BinaryTreeFind(root->_right, x);
		return ret;
	}
	return NULL;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);
		if (front->_left != NULL)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right != NULL)
		{
			QueuePush(&q, front->_right);
		}
	}
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		
		if (front == NULL)
			break;

		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	while (QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
		{
			QueueDestory(&q);
			return 0;
		}
		QueuePop(&q);
	}
	return 1;
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

void TestBinaryTree();

void Test1()
{
	char arr[] = "ABD##E#H##CF##G##";
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	BTNode* root = BinaryTreeCreate(arr, sz, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root, 3));
	BTNode* ret = BinaryTreeFind(root, 'A');
	printf("%c \n", ret->_data);
	BinaryTreeLevelOrder(root);
	printf("\n%d\n",BinaryTreeComplete(root));
	BinaryTreeDestory(root);
}
