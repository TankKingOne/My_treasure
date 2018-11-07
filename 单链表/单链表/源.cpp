#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char elemtype;
typedef struct node     /* ������Ͷ��� */
{
	elemtype data;
	struct node *next;
} LinkList;
LinkList *head;   /* LinkListΪ�������������*/ 



LinkList *LinkedListInit()       //��ͷ���ĵ�����ĳ�ʼ��
{
	LinkList *L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	return L;
}


LinkList *Create_LinkListR()        /*β�巨*/		
{	
	elemtype  ix;
	LinkList  *head, *p, *tail;
	head = (LinkList *) malloc (sizeof(LinkList));
	if(head == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		return head;
	}
	head->next = NULL;
	tail = head; 
	printf("����������ֱ������0������\n");
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
	LinkList  *p = head->next; /*pָ��ͷ���*/ 
	int j = 0;
	while(p->next != NULL)
	{	
		j ++;
		p=p->next; 	/*p��ָ���ǵ�j�����*/ 

	}
	return j;
}


LinkList *GetData_LinkList(LinkList *head, int i)  //����Ų���
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
		printf("����λ�ô���\n");
		return  NULL;
	}
}


LinkList * Search_LinkList(LinkList *head, elemtype key) //��ֵ����
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
	printf("�� %d ���ҵ���\n", num);
	return p;
}


int InsList(LinkList *L, int i, elemtype e)
{  /*�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��  */
      LinkList *pre, *s; 
      int k; 
      pre = L;   k=0; 
      while(pre!=NULL  &&  k<i-1)  
      /* �ڵ�i��Ԫ��֮ǰ���룬 �����ҵ���i-1������Ԫ�صĴ洢λ��, ʹָ��preָ���� */ 
	{
		pre = pre->next; 
        k=k+1; 
	} 
	if(! pre)      
/* �����ǰλ��preΪ�գ� ��ʾ�����껹δ������i��������һ���ǲ���λ�ò��������� */  
		{ 
			printf("����λ�ò�����");
			return 0;   
		} 
		s=(LinkList*)malloc(sizeof(LinkList));    /* Ϊe����һ���µĽ�㲢��sָ���� */ 
		s->data=e;                        /* �����������ֵe����s�������� */ 
		s->next=pre->next;                   /* ��ɲ������ */ 
		pre->next=s;  
  return 1;
} 


void DeleteLinklist(LinkList *head, int i)
{
    LinkList *q, *p;
    if (i==1) q=head;
    else q=GetData_LinkList(head, i-1);  //���Ҵ�ɾ���ڵ��ֱ��ǰ��

    if(q!=NULL && q->next!=NULL)  //��ֱ��ǰ�������д�ɾ��������
    {
        p = q->next;  //pָ���ɾ�����
        q->next=p->next;  //�Ƴ���ɾ�����
        free(p);  //�ͷ����Ƴ��Ľ��p�Ŀռ�
    }
    else printf("�Ҳ���Ҫɾ���Ľ��");
}


int PrintList(LinkList *head)
{
	LinkList *p = head->next;//�������õ�ָ�� ��Ҫֱ����ͷָ���ƶ�
	printf("��ǰ������ľ�������Ϊ:\n");
	//p = head;//��ͷ��ʼ
	if(p == NULL)
		return 0;
	while(p != NULL)//p=nullʱ��β�� ����ѭ��
	{
		printf("%c ", p->data);//��ӡ�ڵ�����
		p = p->next;//�����һ��λ��
	}
	printf("\n");
	return 1;
} 

void menu()
{
	system("cls");
	printf("\n");
	printf("\t\t***************��ӭʹ�õ�����Ļ�������****************\n");
	printf("\t\t***************    1. ��ʼ��������     ****************\n");
	printf("\t\t***************    2. β�巨������     ****************\n");
	printf("\t\t***************    3. ��������     ****************\n");
	printf("\t\t***************    4. ���ָ��λ��     ****************\n");
	printf("\t\t***************    5. ���Ԫ��λ��     ****************\n");
	printf("\t\t***************    6. ����λ��ǰ��     ****************\n");
	printf("\t\t***************    7. ɾ������λ��     ****************\n");
	printf("\t\t***************    8. ���������       ****************\n");
	printf("\t\t***************    0. �˳�ϵͳ         ****************\n");
	printf("\t\t*******************************************************\n");
	printf("\t\t��ѡ��(0-8):");
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
				printf("����ռ�ʧ�ܣ�");
			}
			else
				printf("�������ʼ���ɹ���\n");
			break;
		case 2:
			L = Create_LinkListR();
			break;
		case 3:
			len = LinkList_Length(L);
			printf("��������Ϊ�� %d \n", len);
			break;
		case 4:
			printf("������Ҫ�����λ��> ");
			scanf("%d", &x);
			p = GetData_LinkList(L, x);
			printf("%c\n", p->data);
			break;
		case 5:
			printf("������Ԫ��> ");
			getchar();
			scanf("%c", &key);
			*Search_LinkList(L, key);
			break;
		case 6:
			printf("������ǰ��λ��> ");
			scanf("%d", &x);
			getchar();
			printf("�����������> ");
			scanf("%c", &key);
			InsList(L, x+1, key);
			break;
		case 7:
			printf("\n������Ҫɾ����λ��> ");
			scanf("%d", &x);
			DeleteLinklist(L, x);
			if (1 == flag)
				printf("ɾ���ɹ���\n");
			break;
		case 8:
			PrintList(L);
			break;
		case 0: 
			quit = 1; 
			break;
		default:
			printf("������0~8֮�������\n");
			break;
		}
		if(quit == 1)
			break;
		system("pause");
		printf("���������\n");

	}


	return 0;
}


