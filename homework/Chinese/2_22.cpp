#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define OK 1

///�������ݵĽṹ��
typedef struct

{
	 int num;
	 char name[30];
}Data,*pData;

///����
typedef struct Stu

{
	 Data data;
	 struct Stu *next;
}Stu,*pStu;

///��ʼ����������ͷ��ֵ
int List_Init(pStu &L)

{
	 L=(pStu)malloc(sizeof(Stu));
	 strcpy(L->data.name,"test");
	 L->data.num=0;
	 L->next=NULL;
	 return OK;
}

///����һ�����ᣬ������β������
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

///��ӡ��������
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

///�����ڴ�
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

///ת��
///˼·��������Ľڵ����ȡ����Ȼ���ײ����룬����ȡ����������Ϊ�ײ�
///���ս��Ϊ���ȡ���Ľڵ��Ϊת���������ײ�������ַ����L
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
         Add_Link(L,e[i]);///����������4������
     }
     printf("ת��ǰ������\n");
	 Print_List(L);///��ӡת��ǰ������
	 Change_List(L);///ת��
	 printf("\n\nת���������\n");
	 Print_List(L);///��ӡת���������
	 Destory_List(L);///�����ڴ�
	 return 0;
}
