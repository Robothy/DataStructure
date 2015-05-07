#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define OK 1

///储存数据的结构体
typedef struct

{
	 int num;
	 char name[30];
}Data,*pData;

///链结
typedef struct Stu

{
	 Data data;
	 struct Stu *next;
}Stu,*pStu;

///初始化链表，并给头赋值
int List_Init(pStu &L)

{
	 L=(pStu)malloc(sizeof(Stu));
	 strcpy(L->data.name,"test");
	 L->data.num=0;
	 L->next=NULL;
	 return OK;
}

///增加一个链结，遍历至尾部增加
int Add_Link(pStu &L, Stu e)
{
	 pStu p = L;
	 while (p->next!= NULL)
	 {
		 p = p->next;
	 }
	 p->next=(pStu)malloc(sizeof(Stu));
	 p->next->data=e.data;
	 p->next->next=NULL;
	 return OK;
}

///打印整个链表
int Print_List(pStu &L)

{
	 pStu p=L;
	 while (p!= NULL)
	 {
		 printf("%d %s\n", p->data.num, p->data.name);
		 p = p->next;
	 }
	 return 0;
}

///回收内存
int Destory_List(pStu &L)
{
	 pStu p;
	 while(L)
	 {
		 p=L;
		 L=L->next;
		 free(p);
	 }
	 return OK;
}

///转换
///思路：将链表的节点逐个取出，然后首部插入，即新取出的链结作为首部
///最终结果为最后取出的节点成为转换后链表首部，将地址赋予L
int Change_List(pStu &L)
{
    pStu p,q,s;
    p=L;
    q=p->next;
    p->next=NULL;
    while(q)
    {
        s=q;
        q=q->next;
        s->next=p;
        p=s;
    }
    L=p;
return 1;
}

int main(void)
{
     pStu L=NULL;
	 List_Init(L);
	 Stu e[]={{1,"luo"},{2,"fu"},{3,"xiang"},{4,"1312441117"}};
	 for(int i=0;i<4;i++)
     {
         Add_Link(L,e[i]);///给链表增加4个链结
     }
     printf("转换前的链表：\n");
	 Print_List(L);///打印转换前的链表
	 Change_List(L);///转换
	 printf("\n\n转换后的链表：\n");
	 Print_List(L);///打印转换后的链表
	 Destory_List(L);///回收内存
	 return 0;
}
