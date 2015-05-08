#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct ARC
{
	int len,begin_id,end_id;
	struct ARC *next;
}Arc,*pArc;

typedef struct NODE
{
	char data;
	int id;
	struct NODE *next_node;
	struct ARC *next_arc;
}Node,*pNode;

typedef struct graph
{
	int node_num,arc_num;
	char kind;
	pNode node;
	pArc arc;
}Graph,*pGraph;

bool InitGraph(pGraph &G)
{
	G=(pGraph)malloc(sizeof(Graph));
	G->arc=	NULL;
	G->node=NULL;
	G->kind='2';
	return true;
}

void InsertNode(pNode &N,pNode &e)
{
	if(!e) return;
	e->next_node=NULL;
	e->next_arc=NULL;
	if(!N)
	{
		N=e;
	}
	else
	{
		pNode p=N;
		while(p->next_node)
		{
			p=p->next_node;
		}
		p->next_node=e;
	}
}

void InsertArc(pNode &N,pArc &e)
{
	if(!e) return;
	e->next=NULL;
	if(!(N->next_arc))
	{
		N->next_arc=e;
	}
	else
	{
		pArc p=N->next_arc;
		while(p->next)
		{
			p=p->next;
		}
		p->next=e;
	}
}

bool CreateGraph(pGraph &G)
{
	printf("请输入图的点数和边数:\n");
	scanf("%d %d",&(G->node_num),&(G->arc_num));
	printf("请选择图的种类:\n1.无向边\t2.有向边\n");
	G->kind=getch();
	pNode e;
	for(int i=0;i<G->node_num;i++)
	{
		e=(pNode)malloc(sizeof(Node));
		e->id=i;
		InsertNode(G->node,e);
	}

	pArc A=NULL;
	pNode N=NULL;
	for(int i=0;i<G->arc_num;i++)
	{
		A=(pArc)malloc(sizeof(Arc));
		printf("请输入第%d条边:\n",i+1);
		scanf("%d %d",&(A->begin_id),&(A->end_id));
		N=G->node;
		while(N->id!=A->begin_id)
		{
			N=N->next_node;
		}
		InsertArc(N,A);
		if(G->kind=='1')
		{
			pArc a=(pArc)malloc(sizeof(Arc));
			a->begin_id=A->end_id;
			a->end_id=A->begin_id;
			N=G->node;
			while(N->id!=a->begin_id)
			{
				N=N->next_node;
			}
			InsertArc(N,a);
		}
	}
}

bool PrintGraph(pGraph &G)
{
	pNode N=G->node;
	printf("-------------------\n");
	while(N)
	{
		printf("%d ",N->id);
		pArc A=N->next_arc;
		while(A)
		{
			printf("%d ",A->end_id);
			A=A->next;
		}
		printf("\n");
		N=N->next_node;
	}
	printf("-------------------\n");
	return true;
}

int main(void)
{
	printf("+++++++图的邻接表储存结构++++++++\n\n")
	pGraph G;
	InitGraph(G);
	CreateGraph(G);
	PrintGraph(G);
	return 0;
}


