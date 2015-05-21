#include "stdio.h"
#include "stdlib.h"

typedef struct arc
{
	char begin_id;
	unsigned int len;
	char end_id;
	struct arc *next;
}arc,*parc;

typedef struct node
{
	char node_id;
	struct arc *next_arc;
	struct node *next_node;
}node,*pnode;

typedef struct
{
	unsigned int node_num,arc_num;
	pnode Node;
	parc Arc;
}graph,*pgraph;

typedef struct Tree
{
	char node_id;
	struct Tree *Lchild;
	struct Tree *Rchlid;
}*pTree;

void init_graph(pgraph &G)
{
	if(!G)
	G=(pgraph)malloc(sizeof(graph));
}

void insert_arc(node &Node,parc &e)
{
	if(!e)	return;
	e->next=NULL;
	if(!Node.next_arc)
	{
		Node.next_arc=e;
	}
	else
	{
		parc p=Node.next_arc;
		while(p->next)
		{
			p=p->next;
		}
		p->next=e;
	}
}


void create_graph(pgraph &G)
{
	printf("input the amount of node:\n");
	fflush(stdin);
	scanf("%d",&(G->node_num));
	printf("input the amount if arc:\n");
	fflush(stdin);
	scanf("%d",&(G->arc_num));

	G->Node=(pnode)malloc((G->node_num)*sizeof(node));

	printf("input all node's id:\n");
	for(int i=0;i<G->node_num;i++)
	{
		scanf("%c",&(G->Node[i].node_id));
		G->Node[i].next_arc=NULL;
	}

	parc e=NULL;
	for(int i=0;i<G->arc_num;i++)
	{
		e=(parc)malloc(sizeof(arc));
		printf("input the %dth arc:\n",i);
		fflush(stdin);
		scanf("%c %d %c",&(e->begin_id),&(e->len),&(e->end_id));
		for(int j=0;j<G->node_num;j++)
		{
			if(G->Node[j].node_id==e->begin_id)
			{
				insert_arc(G->Node[j],e);
				break;
			}
		}
	}
}

void print_graph(pgraph &G)
{
	if(!G)	return;
	printf("----------------------------\n");
	for(int i=0;i<G->node_num;i++)
	{
		printf("%c\t",G->Node[i].node_id);
		parc p=G->Node[i].next_arc;
		while(p)
		{
			printf("%c(%d)\t",p->end_id,p->len);
			p=p->next;
		}
		printf("\n");
	}
	printf("---------------------------\n");
}

void auto_create(pgraph &G)
{
	G->node_num=8;
	G->arc_num=14;
	G->Node=(pnode)malloc(G->node_num*sizeof(node));
	char *id="abcdefgh";
	arc ARC[14]={{'a',4,'b',NULL},{'a',3,'c',NULL},{'b',5,'c',NULL},{'b',5,'d',NULL},
			{'b',9,'e',NULL},{'c',5,'d',NULL},{'c',5,'h',NULL},
			{'d',7,'e',NULL},{'d',6,'f',NULL},{'d',5,'g',NULL},{'d',4,'h',NULL},{'e',3,'f',NULL},
			{'f',2,'g',NULL},{'g',6,'h',NULL}};
	for(int i=0;i<G->node_num;i++)
	{
		G->Node[i].node_id=*(id+i);
		G->Node[i].next_arc=NULL;
	}
	parc e=NULL,f=NULL;
	for(int i=0;i<G->arc_num;i++)
	{
		e=(parc)malloc(sizeof(arc));
		f=(parc)malloc(sizeof(arc));

		e->begin_id=ARC[i].begin_id;
		e->len=ARC[i].len;
		e->end_id=ARC[i].end_id;

		f->begin_id=ARC[i].end_id;
		f->len=ARC[i].len;
		f->end_id=ARC[i].begin_id;

		for(int j=0;j<G->node_num;j++)
		{
			if(G->Node[j].node_id==e->begin_id)
			{
				insert_arc(G->Node[j],e);
			}
			if(G->Node[j].node_id==f->begin_id)
			{
				insert_arc(G->Node[j],f);
			}
		}
	}
}

void print_bitree(pTree &T)
{
	if(T)
	{
		printf("%c ",T->node_id);
		print_bitree(T->Lchild);
		print_bitree(T->Rchlid);
	}
}

void prim(pgraph &G,pgraph &T)
{
    bool *is_cnn;
    is_cnn=(bool*)malloc(G->node_num*sizeof(bool));
    for(int i=0;i<G->node_num;i++)
	{
		*(is_cnn+i)=false;
	}
	T=G->Node[0];
	for(int i=0;i<G->node_num;i++)
	{
		if(!*(is_cnn+i))
		{

		}
	}
}

int main(void)
{
	pgraph G;
	pTree T;
	init_graph(G);
	//create_graph(G);
	auto_create(G);
	print_graph(G);
	return 0;
}































