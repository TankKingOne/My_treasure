//# include<stdio.h>
//# include<stdlib.h>
//# include<string.h>
//# define MAXSIZE 2000                        //��󳤶�Ϊ2000 
//typedef int elemtype;
//typedef struct student
//	{
//		elemtype data[MAXSIZE];
//		int last;
//	}SequenList;
//
//
//SequenList *Init_InformationTable()               //��ʼ������
//{
//	SequenList *L;
//	L=(SequenList * )malloc(sizeof(SequenList));
//	if (L !=NULL)
//	{
//		L->last=-1;
//	}
//	return L;
//}
//
//int InformationTable_Length (SequenList * L)       //��˳�����
//{
//	return( L->last+1);
//}
//
//int getElem(SequenList *L, elemtype pos)   //��ȡ˳�����ָ��λ�ô���Ԫ��ֵ
//{
//    if(pos<1 || pos>L->last+1)
//    {
//        printf("����λ���д����޷���ȡָ��λ�õ�����\n");
//        return 0;
//    }
//	else
//    printf("��λ��Ϊ %d �������ҵ���Ԫ�أ�%d\n",pos,L->data[pos-1]);
//}
//
//int deleteList(SequenList *L, int pos/*,elemtype *elem*/) //ɾ��ָ��λ��Ԫ��
//{
//    int i;
//    if(pos<1 || pos>L->last+1)
//    {
//        printf("ɾ����λ�������޷��Ӹ�λ��ɾ������\n");
//        return 0;
//    }
//    for(i=pos;i<L->last+1;i++)
//	{
//        L->data[i-1]=L->data[i];	
//    }
//	L->last --;
//	printf("ɾ�����ݳɹ���\n");
//    return 1;
//}
//
//int locateElem(SequenList *L, elemtype e)  //����ָ��Ԫ��λ��
//{
//    int i,p = 0;
//    for(i=0;i<L->last+1;i++)
//    {
//        //printf("��%d��ѭ��...\n",i);
//        if(L->data[i] == e)
//        {
//            printf("�ڵ�%d�������ҵ���Ԫ��:%d\n",i+1,e);
//            return 1;
//        }
//    }
//	if( p == 0)
//		printf("δ�ҵ���Ԫ�أ�\n");
//    return 0;
//}
//
//
//SequenList *creatInformationTable(SequenList *L)  //�������ݱ�
//{
//	elemtype x;
//	printf("������Ԫ��(��ֹ����������0����)��\n");
//	scanf("%d", &x);
//	while (x != 0)
//	{
//		L->last += 1;
//		L->data[L->last] = x;
//		scanf("%d", &x);
//	}
//	printf("˳������ɹ���\n");
//	return L;
//}
//
//int printTable(SequenList *L)             //��ӡ
//{
//    if(L->last+1==0)
//    {   
//		printf("����Ϊ��\n");
//        return 0;
//    }
//    int i;
//    for(i=0;i<L->last+1;i++)
//	{
//        printf("�� %d �������� %d\n",i+1,L->data[i]);
//    }
//    printf("\n");
//    return 1;
//}
//
//int insertList(SequenList *L, int pos,elemtype elem)          //����
//{
//    int i;
//    if(pos<1 || pos>L->last+2)
//    {
//        printf("�����λ�������޷���������\n");
//        return 0;
//    }
//	if(L->last>=MAXSIZE-1)
//	{
//		printf("�������޷�����\n");
//		return -1;
//	}
//    for (i=L->last;i>=pos-1;i--)
//    {
//        L->data[i+1]=L->data[i];
//    }
//    L->data[pos-1] = elem;
//    L->last++;
//	printf("����ɹ���\n");
//    return 1;
//}
//
//
//void Head()
//{
//	system("cls");
//	printf(
//	"**********************************************************************\n"
//	"**                                                                  **\n"
//	"**                                                                  **\n"
//	"**                      ��ӭʹ����Ϣ����ϵͳ                        **\n"
//	"**                                                                  **\n"
//	"**                       1.��Ϣ���ʼ��                             **\n" 
//	"**                       2.������Ϣ��                               **\n" 
//	"**                       3.��Ϣ��ĳ���                             **\n"
//	"**                       4.��ѯ��n����Ϣ                            **\n"
//	"**                       5.��ѯ��Ϣλ��                             **\n"
//	"**                       6.����ָ����Ϣ                             **\n"
//	"**                       7.ɾ��ָ��λ����Ϣ                         **\n"
//	"**                       8.��ӡ��Ϣ��                               **\n"
//	"**                       0.�˳�ϵͳ                                 **\n"
//	"**                                                                  **\n"
//	"**                                                                  **\n"
//	"**********************************************************************\n"
//	);
//	printf("��������Ӧ������ѡ�����Ӧ�Ĺ���\n");
//}
//
//int main()
//{
//	SequenList *L;
//	int  quit = 0;
//	int len,key,x,i;
//	elemtype *e = 0;
//	int s;
//	while (1)
//	{
//		Head();			//�����Ӻ���
//		scanf("%d", &s);
//
//		switch (s)
//		{
//		case 1:{
//					 L = Init_InformationTable();
//					 if (L==NULL)
//					 {
//						 printf("����˳����ڴ�ռ�ʧ�ܣ����������\n");
//						 return 0;
//					 }
//					 else
//						 printf("��Ϣ���ʼ���ɹ���\n");
//				 }; break;
//		case 2: { 
//					*creatInformationTable(L);
//				   }; break;
//		case 3: {
//					  len = InformationTable_Length(L);
//					  printf("˳���ĳ���Ϊ��%d\n", len);
//				  }; break;
//		case 4: {
//					  printf("������Ҫ���Ԫ�ص�λ��\n");
//					  scanf("%d",&key);
//					  getElem(L,key);
//				  }; break;
//		case 5: {
//					  printf("������Ԫ�أ�");
//					  scanf("%d", &key);
//					  locateElem(L,key);
//				  }; break;
//		case 6: {
//					  printf("���������λ�ã�ǰ��:");
//					  scanf("%d", &i);
//					  printf("�����Ԫ��Ϊ��");
//					  scanf("%d", &x);
//					  insertList(L, i, x);
//				  }; break;
//		case 7: {
//					  printf("��������Ҫɾ����Ԫ�أ�");
//					  scanf("%d", &i);
//					  deleteList(L,i);
//		}; break;
//		case 8: printTable(L); break;
//		case 0: quit = 1; break;
//		default:printf("������0~8֮�������\n"); break;
//		}
//		if (quit == 1)
//		{
//			break;
//		}
//		system("pause");
//		printf("���������\n");
//	}
//	return 0;
//}
