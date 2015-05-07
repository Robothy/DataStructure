//ʵ������ķ�ת

#include "stdio.h"
#include "stdlib.h"
#define OK 1;

#define List_Init_Length 5
#define Increment 3

typedef struct Data
{
    int num;
}Data,*pData;

typedef struct list
{
    pData data;
    int Length;
    int ListSize;
}List,*pList;

void List_Init(List &L)
{
    L.data=(pData)malloc(List_Init_Length*sizeof(Data));
    L.Length=List_Init_Length;
    L.ListSize=0;

    /*****��ʼ��5��ֵ*****/
    int DATA[]={3,4,12,32,67};
    for(int i=0;i<List_Init_Length;i++)
    {
        L.data[i].num=DATA[i];
        L.ListSize++;
    }
}

int Insert_Link(List &L,Data &data)
{
    /**�����ڴ�**/
    if(L.ListSize==L.Length)
    {
        L.data=(pData)realloc(L.data,(L.ListSize+Increment)*sizeof(Data));
        L.ListSize+=Increment;
    }
    for(int i=0;i<L.Length;i++)
    {
        if(L.data[i].num>=data.num)
        {
            int j;
            for(j=L.Length;j>i;j--)
            {
                L.data[j]=L.data[j-1];
            }
            L.data[i]=data;
            break;
        }
        else
        {
            L.data[L.Length]=data;
        }
    }
    L.Length++;
    return OK;
}

int Print_List(List &L)
{
    for(int i=0;i<L.Length;i++)
    {
        printf("%d ",L.data[i].num);
    }
    return OK;
}

int main(void)
{
    List L;
    List_Init(L);///��ʼ��
    Data data;///�ȴ����������
    printf("����ǰ��");
    Print_List(L);
    printf("\n�������������ݣ�");
    scanf("%d",&(data.num));
    Insert_Link(L,data);
    printf("\n�����");
    Print_List(L);
    return 0;
}
