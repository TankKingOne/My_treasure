#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char elemtype;
typedef struct node     /* 结点类型定义 */
{
	elemtype data;
	struct node *next;
} LinkList;
LinkList *head;   /* LinkList为单链表的类型名*/ 



LinkList *LinkedListInit()       //带头结点的单链表的初始化
{
	LinkList *L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	return L;
}


LinkList *Create_LinkListR()        /*尾插法*/		
{	
	elemtype  ix;
	LinkList  *head, *p, *tail;
	head = (LinkList *) malloc (sizeof(LinkList));
	if(head == NULL)
	{
		printf("申请空间失败！\n");
		return head;
	}
	head->next = NULL;
	tail = head; 
	printf("请输入数据直到输入0结束：\n");
	scanf("%c", &ix);
	while ('0' != ix)
	{	
		p = (LinkList *)malloc(sizeof(LinkList));
		if(p == NULL)
			return head;
		p->data = ix;							
		tail->next = p;
		tail = p;
		tail->next = NULL;
		scanf("%c", &ix); 
		getchar(); 
	}
	return head;
}


int LinkList_Length (LinkList  *head)
{	
	LinkList  *p = head->next; /*p指向头结点*/ 
	int j = 0;
	while(p->next != NULL)
	{	
		j ++;
		p=p->next; 	/*p所指的是第j个结点*/ 

	}
	return j;
}


LinkList *GetData_LinkList(LinkList *head, int i)  //按序号查找
{	
	LinkList *p; 	
	int  j = 0;
	if (i <= 0)
		return NULL;	
	p = head;
	while( p->next && j<i )	
	{	
		p = p->next;
		j ++;

	}
	if (i == j)

	{
		p = p->next;
		
		return p;
	}
	else
	{
		printf("输入位置错误！\n");
		return  NULL;
	}
}


LinkList * Search_LinkList(LinkList *head, elemtype key) //按值查找
{	
	LinkList *p;
	p = head->next;
	int num = 0;
	while(p)
		if (p->data != key)
		{
			p = p->next;
			num ++;
		}
		else
			break;
	printf("在 %d 处找到。\n", num);
	return p;
}


int InsList(LinkList *L, int i, elemtype e)
{  /*在带头结点的单链表L中第i个位置插入值为e的新结点  */
      LinkList *pre, *s; 
      int k; 
      pre = L;   k=0; 
      while(pre!=NULL  &&  k<i-1)  
      /* 在第i个元素之前插入， 则先找到第i-1个数据元素的存储位置, 使指针pre指向它 */ 
	{
		pre = pre->next; 
        k=k+1; 
	} 
	if(! pre)      
/* 如果当前位置pre为空， 表示已找完还未数到第i个，所以一定是插入位置不合理所致 */  
		{ 
			printf("插入位置不合理！");
			return 0;   
		} 
		s=(LinkList*)malloc(sizeof(LinkList));    /* 为e申请一个新的结点并由s指向它 */ 
		s->data=e;                        /* 将待插入结点的值e赋给s的数据域 */ 
		s->next=pre->next;                   /* 完成插入操作 */ 
		pre->next=s;  
  return 1;
} 


void DeleteLinklist(LinkList *head, int i)
{
    LinkList *q, *p;
    if (i==1) q=head;
    else q=GetData_LinkList(head, i-1);  //先找待删除节点的直接前驱

    if(q!=NULL && q->next!=NULL)  //若直接前驱存在切待删除结点存在
    {
        p = q->next;  //p指向待删除结点
        q->next=p->next;  //移除待删除结点
        free(p);  //释放已移除的结点p的空间
    }
    else printf("找不到要删除的结点");
}


int PrintList(LinkList *head)
{
	LinkList *p = head->next;//建遍历用的指针 不要直接用头指针移动
	printf("当前单链表的具体数据为:\n");
	//p = head;//从头开始
	if(p == NULL)
		return 0;
	while(p != NULL)//p=null时到尾部 跳出循环
	{
		printf("%c ", p->data);//打印节点内容
		p = p->next;//向后移一个位置
	}
	printf("\n");
	return 1;
} 

void menu()
{
	system("cls");
	printf("\n");
	printf("\t\t***************欢迎使用单链表的基本操作****************\n");
	printf("\t\t***************    1. 初始化单链表     ****************\n");
	printf("\t\t***************    2. 尾插法建立表     ****************\n");
	printf("\t\t***************    3. 求单链表长度     ****************\n");
	printf("\t\t***************    4. 输出指定位置     ****************\n");
	printf("\t\t***************    5. 输出元素位置     ****************\n");
	printf("\t\t***************    6. 给定位置前插     ****************\n");
	printf("\t\t***************    7. 删除给定位置     ****************\n");
	printf("\t\t***************    8. 输出单链表       ****************\n");
	printf("\t\t***************    0. 退出系统         ****************\n");
	printf("\t\t*******************************************************\n");
	printf("\t\t请选择(0-8):");
}

int main()
{
	LinkList *L, *head, *p;
	char key;
	int num = 0, len = 0, quit = 0;
	int x = 0, flag = 0;
	while(1)
	{
		menu();
		scanf("%d", &num);
		switch(num)
		{
		case 1:
			L = LinkedListInit();
			if(L == NULL)
			{
				printf("申请空间失败！");
			}
			else
				printf("单链表初始化成功！\n");
			break;
		case 2:
			L = Create_LinkListR();
			break;
		case 3:
			len = LinkList_Length(L);
			printf("单链表长度为： %d \n", len);
			break;
		case 4:
			printf("请输入要输出的位置> ");
			scanf("%d", &x);
			p = GetData_LinkList(L, x);
			printf("%c\n", p->data);
			break;
		case 5:
			printf("请输入元素> ");
			getchar();
			scanf("%c", &key);
			*Search_LinkList(L, key);
			break;
		case 6:
			printf("请输入前插位置> ");
			scanf("%d", &x);
			getchar();
			printf("请输插入数据> ");
			scanf("%c", &key);
			InsList(L, x+1, key);
			break;
		case 7:
			printf("\n请输入要删除的位置> ");
			scanf("%d", &x);
			DeleteLinklist(L, x);
			if (1 == flag)
				printf("删除成功！\n");
			break;
		case 8:
			PrintList(L);
			break;
		case 0: 
			quit = 1; 
			break;
		default:
			printf("请输入0~8之间的数字\n");
			break;
		}
		if(quit == 1)
			break;
		system("pause");
		printf("程序结束！\n");

	}


	return 0;
}


