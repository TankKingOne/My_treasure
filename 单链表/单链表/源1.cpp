//# include<stdio.h>
//# include<stdlib.h>
//# include<string.h>
//# define MAXSIZE 2000                        //最大长度为2000 
//typedef int elemtype;
//typedef struct student
//	{
//		elemtype data[MAXSIZE];
//		int last;
//	}SequenList;
//
//
//SequenList *Init_InformationTable()               //初始化链表
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
//int InformationTable_Length (SequenList * L)       //求顺序表长度
//{
//	return( L->last+1);
//}
//
//int getElem(SequenList *L, elemtype pos)   //获取顺序表中指定位置处的元素值
//{
//    if(pos<1 || pos>L->last+1)
//    {
//        printf("查找位置有错误，无法获取指定位置的数据\n");
//        return 0;
//    }
//	else
//    printf("在位置为 %d 处，查找到了元素：%d\n",pos,L->data[pos-1]);
//}
//
//int deleteList(SequenList *L, int pos/*,elemtype *elem*/) //删除指定位置元素
//{
//    int i;
//    if(pos<1 || pos>L->last+1)
//    {
//        printf("删除的位置有误，无法从该位置删除数据\n");
//        return 0;
//    }
//    for(i=pos;i<L->last+1;i++)
//	{
//        L->data[i-1]=L->data[i];	
//    }
//	L->last --;
//	printf("删除数据成功！\n");
//    return 1;
//}
//
//int locateElem(SequenList *L, elemtype e)  //查找指定元素位置
//{
//    int i,p = 0;
//    for(i=0;i<L->last+1;i++)
//    {
//        //printf("在%d层循环...\n",i);
//        if(L->data[i] == e)
//        {
//            printf("在第%d处，查找到了元素:%d\n",i+1,e);
//            return 1;
//        }
//    }
//	if( p == 0)
//		printf("未找到该元素！\n");
//    return 0;
//}
//
//
//SequenList *creatInformationTable(SequenList *L)  //输入数据表
//{
//	elemtype x;
//	printf("请输入元素(终止输入请输入0即可)：\n");
//	scanf("%d", &x);
//	while (x != 0)
//	{
//		L->last += 1;
//		L->data[L->last] = x;
//		scanf("%d", &x);
//	}
//	printf("顺序表建立成功！\n");
//	return L;
//}
//
//int printTable(SequenList *L)             //打印
//{
//    if(L->last+1==0)
//    {   
//		printf("链表为空\n");
//        return 0;
//    }
//    int i;
//    for(i=0;i<L->last+1;i++)
//	{
//        printf("第 %d 个数据是 %d\n",i+1,L->data[i]);
//    }
//    printf("\n");
//    return 1;
//}
//
//int insertList(SequenList *L, int pos,elemtype elem)          //插入
//{
//    int i;
//    if(pos<1 || pos>L->last+2)
//    {
//        printf("插入的位置有误，无法插入数据\n");
//        return 0;
//    }
//	if(L->last>=MAXSIZE-1)
//	{
//		printf("表已满无法插入\n");
//		return -1;
//	}
//    for (i=L->last;i>=pos-1;i--)
//    {
//        L->data[i+1]=L->data[i];
//    }
//    L->data[pos-1] = elem;
//    L->last++;
//	printf("插入成功！\n");
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
//	"**                      欢迎使用信息管理系统                        **\n"
//	"**                                                                  **\n"
//	"**                       1.信息表初始化                             **\n" 
//	"**                       2.建立信息表                               **\n" 
//	"**                       3.信息表的长度                             **\n"
//	"**                       4.查询第n条信息                            **\n"
//	"**                       5.查询信息位置                             **\n"
//	"**                       6.插入指定信息                             **\n"
//	"**                       7.删除指定位置信息                         **\n"
//	"**                       8.打印信息表                               **\n"
//	"**                       0.退出系统                                 **\n"
//	"**                                                                  **\n"
//	"**                                                                  **\n"
//	"**********************************************************************\n"
//	);
//	printf("请输入相应的数字选择相对应的功能\n");
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
//		Head();			//调用子函数
//		scanf("%d", &s);
//
//		switch (s)
//		{
//		case 1:{
//					 L = Init_InformationTable();
//					 if (L==NULL)
//					 {
//						 printf("申请顺序表内存空间失败，程序结束！\n");
//						 return 0;
//					 }
//					 else
//						 printf("信息表初始化成功！\n");
//				 }; break;
//		case 2: { 
//					*creatInformationTable(L);
//				   }; break;
//		case 3: {
//					  len = InformationTable_Length(L);
//					  printf("顺序表的长度为：%d\n", len);
//				  }; break;
//		case 4: {
//					  printf("请输入要输出元素的位置\n");
//					  scanf("%d",&key);
//					  getElem(L,key);
//				  }; break;
//		case 5: {
//					  printf("请输入元素：");
//					  scanf("%d", &key);
//					  locateElem(L,key);
//				  }; break;
//		case 6: {
//					  printf("请输入插入位置（前）:");
//					  scanf("%d", &i);
//					  printf("插入的元素为：");
//					  scanf("%d", &x);
//					  insertList(L, i, x);
//				  }; break;
//		case 7: {
//					  printf("请输入想要删除的元素：");
//					  scanf("%d", &i);
//					  deleteList(L,i);
//		}; break;
//		case 8: printTable(L); break;
//		case 0: quit = 1; break;
//		default:printf("请输入0~8之间的数字\n"); break;
//		}
//		if (quit == 1)
//		{
//			break;
//		}
//		system("pause");
//		printf("程序结束！\n");
//	}
//	return 0;
//}
