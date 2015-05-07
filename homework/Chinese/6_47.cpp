#include "stdio.h"
#include "stdlib.h"
#include "string.h"

///定义树的结构体类型
typedef struct BiTree
{
	char data;
	struct BiTree *Lchild;
	struct BiTree *Rchild;
}BiTree,*pBiTree;

///定义一个队列的节点
typedef struct node
{
	pBiTree Tnode;
	struct node *next;
}Node,*pNode;

///定义一个队列类型的结构体
typedef struct
{
	pNode Front;
	pNode Rear;
}Queue,*pQueue;

///初始化结构体类型
bool InitQueue(pQueue &Q)
{
	Q=(pQueue)malloc(sizeof(Queue));
	Q->Front=NULL;
	Q->Rear=NULL;
	return true;
}

///入队
bool EnterQueue(pQueue &Q,pNode &e)
{
	if(!e) return false;
	if(!Q) InitQueue(Q);
	if(Q->Rear==NULL)
	{
		Q->Rear=e;
		Q->Front=e;
	}
	else
	{
		e->next=Q->Front;
		Q->Front=e;
		Q->Rear->next=Q->Front;
	}
	return true;
}

///出队
bool OutQueue(pQueue &Q,pNode &e)
{
	if(!Q||Q->Rear==NULL) return false;
	e=Q->Rear;
	if(Q->Front==Q->Rear)
	{
		Q->Front=Q->Rear=NULL;
		free(Q);
		if(Q) Q=NULL;
	}
	else
	{
        pNode p=Q->Front;
        pNode q;
        while(p!=e)
		{
			q=p;
			p=p->next;
		}
		Q->Rear=q;
		q=p->next;
	}
	e->next=NULL;
}

///销毁队列
bool DestroyQueue(pQueue &Q)
{
	pNode e;
	while(Q)
	{
		OutQueue(Q,e);
		free(e);
	}
	return true;
}

///判断队列是否为空
bool IsQueueEmpty(pQueue &Q)
{
	if(!Q||Q->Rear==NULL) return true;
	else return false;
}

///建立一棵二叉树
bool CreateTree(pBiTree &T,char *&data)
{
	T=NULL;
	if(*(data)==' ') return false;
	T=(pBiTree)malloc(sizeof(BiTree));
	T->data=*data;
	data++;
	CreateTree(T->Lchild,data);
	data++;
	CreateTree(T->Rchild,data);
	return true;
}

///打印一棵二叉树
bool PrintBiTree(pBiTree &T)
{
	pBiTree p=T;
	if(!p) return false;
	printf("%c",T->data);
	PrintBiTree(T->Lchild);
	PrintBiTree(T->Rchild);
}

///访问二叉树的节点
bool VisitTnode(pBiTree &tnode)
{
	if(!tnode) return false;
	printf("%c",tnode->data);
	return true;
}


///利用队列按层次从左到右访问二叉树
bool LevelTraverse(pBiTree &T)
{
	if(!T) return false;
	pQueue Q;
	pNode e=(pNode)malloc(sizeof(Node));
	pBiTree p=T;
	InitQueue(Q);
	e->Tnode=T;
	e->next=NULL;
	EnterQueue(Q,e);
	while(!IsQueueEmpty(Q))
	{
		OutQueue(Q,e);
		p=e->Tnode;
		VisitTnode(p);
		//free(e);
		//e=NULL;
		if(p->Lchild)
		{
			e=(pNode)malloc(sizeof(Node));
			e->Tnode=p->Lchild;
			e->next=NULL;
			EnterQueue(Q,e);
		}
		if(p->Rchild)
		{
			e=(pNode)malloc(sizeof(Node));
			e->Tnode=p->Rchild;
			e->next=NULL;
			EnterQueue(Q,e);
		}
	}
	DestroyQueue(Q);
	return true;
}


int main(void)
{
	pBiTree T;
	char *data="-+a  *b  -c  d  /e  f  ";
	CreateTree(T,data);
	LevelTraverse(T);
	return 0;
}
