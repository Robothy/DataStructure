#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

typedef struct BiTree
{
	char data;
	struct BiTree *Lchild;
	struct BiTree *Rchild;
}*pBiTree,BiTree;

void CreateBiTree(pBiTree &T,char *&ch)
{
	T = NULL;
	if(*ch!=' ')
	{
		T = (pBiTree)malloc(sizeof(BiTree));
		T->data=*ch;
		ch++;
		CreateBiTree(T->Lchild,ch);
		CreateBiTree(T->Rchild,ch);
	}
	else
	{
		ch++;
		return;
	}
}


void OrderTree(pBiTree &T)
{
	if(T)
	{
		printf("%c",T->data);
		OrderTree(T->Lchild);
		OrderTree(T->Rchild);
	}
	else
	{
		return;
	}
}

void CountLeaves(pBiTree &T,unsigned int &Count)
{
    if(T)
    {
        Count++;
        CountLeaves(T->Lchild,Count);
        CountLeaves(T->Rchild,Count);
    }
    return;
}

int main(void)
{
	char *ch="-+a  *b  -c  d  /e  f  ";
	pBiTree T;

	CreateBiTree(T,ch);
	OrderTree(T);
	unsigned int Count=0;
	CountLeaves(T,Count);
	cout<< endl << "This BiTree has " << Count << " leaves!" <<endl;
	return 0;
}
