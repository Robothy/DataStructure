#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

typedef struct BiTree
{
	char data,tag;
	struct BiTree *Lchild;
	struct BiTree *Rchild;
	struct BiTree *next;
}*pBiTree,BiTree,LinkStack,*pLinkStack;

///Initialize the stack
void StackInit(pLinkStack &LS)
{
	LS = NULL;
}

///Print data
void ShowNode(pLinkStack &e)
{
    cout << e->data
    << endl;
}

///Pop from the stack
bool StackPop(pLinkStack &LS,pLinkStack &e)
{
    if(!LS) return false;
    e = LS;
    LS = LS->next;
    e->next = NULL;
    return true;
}

///Get the top of a stack without any influence on stack.
bool StackGetTop(pLinkStack &LS,pLinkStack &e)
{
	if(!LS) return false;
	e = LS;
	return true;
}

///Inorder traversal BiTree by recursion
void RecursionOrderTree(pBiTree &T)
{
	if(!T) return;
	cout << T->data;
	RecursionOrderTree(T->Lchild);
	RecursionOrderTree(T->Rchild);
}

///Push on
bool StackPush(pLinkStack &LS,pLinkStack &e)
{
    if(!e)  return false;
    e->next = LS;
    LS = e;
    return true;
}

///Show node's member's message
void ShowDetails(pBiTree &p)
{
	cout << "\n------------------\n";
	if(!p)
	{
		cout << "tag = ?" << endl;
		cout << "data = ?" << endl;
		if(!p)	cout << "p is NULL!" << endl;
	}
	else
	{
		cout << "tag = " << p->tag <<endl;
		cout << "data = " << p->data << endl;
		if(p)	cout << "p is not NULL!" << endl;
	}
	cout << "\n------------------\n";
	system("pause");
}

///Preorder traverasl BiTree by stack
void StackOrderTree(pBiTree &T)
{
	pBiTree p = T;
	pLinkStack LS;
	while(p||LS)
	{
		while(p)
		{
			cout << p->data;
			StackPush(LS,p);
			p = p->Lchild;
		}
		if(LS)
		{
			StackPop(LS,p);
			p = p->Rchild;
		}
	}
}

///Exchange BiTree's left child and right child
void ExchangeChild(pBiTree &T)
{
	pBiTree p = T,temp = NULL;
	pLinkStack LS,_LS;
	StackInit(LS);
	StackInit(_LS);
	int i=0;
	while(p||LS)
	{
		while(p)
		{
			StackPush(LS,p);
			p = p->Lchild;

		}
		if(LS)
		{
			StackPop(LS,p);
			StackPush(_LS,p);
			p = p->Rchild;
		}
	}
	while(_LS)
	{
		StackPop(_LS,p);
		temp = p->Lchild;
		p->Lchild = p->Rchild;
		p->Rchild = temp;
	}
}


/*************************************************************
///Another way to visit a stack.
void StackOrderTree(pBiTree &T)
{
	pLinkStack LS,e;
	pBiTree p,fp;
	p = T;
	do
	{
		if((!p&&LS->tag=='L')||(p&&p->tag=='L'))
		{
			LS->tag = 'R';
			p = LS->Rchild;
		}

		if(p&&p->tag!='L'&&p->tag!='R')///左子树，右子树都没被访问过
		{
			//cout << "visit Lchild!" << endl;
			//system("pause");

			cout << p->data;
			e=p;
			p->tag='L';
			p=p->Lchild;
			e->next=NULL;
			StackPush(LS,e);
		}

		if(LS->tag=='R')
		{
			//cout << "Pop" << endl;
			StackPop(LS,p);
			StackGetTop(LS,p);
			//ShowDetails(p);
		}

		/*if(!p||(p&&p->tag=='L'))///左子树被访问过，右子树没被访问过
		{
			cout << "visit Rchild!" << endl;
			//system("pause");
			if(!p)
			p = e;///p返回到上一个根
			p->tag = 'R';
			p = p->Rchild;///开始访问右子树
		}
		ShowDetails(p);
		if(!p||(p&&p->tag=='R'))
		{
			cout << "StackPop" << endl;
			//system("pause");
			StackPop(LS,p);
			ShowDetails(p);
		}
	}while(LS);
}

*************************************************************/

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


int main(void)
{
	char *ch="-+a  *b  -c  d  /e  f  ";
	pBiTree T;
	CreateBiTree(T,ch);
	RecursionOrderTree(T);cout << endl;
	StackOrderTree(T);
	cout << endl;
	ExchangeChild(T);
	cout << endl;
	return 0;
}
