#include"stdio.h"
#include "stdlib.h"
#include "string.h"
//Copyright by Robothy @ 2015
namespace data_structure
{
class List
	{
		public:
			typedef struct Data
			{
				int num;
				char name[30];
			}Data,*pData;
			typedef struct Link
			{
				Data data;
				struct Link *next;
			}Link,*pLink;

			bool List_Init(pLink &L)
			{
				L=(pLink)malloc(sizeof(Link));
				L->next=NULL;
				return true;
			}

			bool Print_List(pLink &L)
			{
				if(!L)
				{
					printf("list is null!\n");
					return false;
				}
				else
				{
					pLink p=L->next;
					while(p)
					{
						printf("%d %s\n",p->data.num,p->data.name);
						p=p->next;
					}
					printf("---------------luxuriant line--------------\n");
					return true;
				}
			}

			bool Insert_Link(pLink &L,pLink e=NULL)
			{
				pLink p=L;
				while(p->next)
				{
					p=p->next;
				}
				p->next=(pLink)malloc(sizeof(Link));
				if(!e)
				{
					printf("num=");
					scanf("%d",&(p->next->data.num));
					printf("name=");
					scanf("%s",(p->next->data.name));
					p->next->next=NULL;
				}
				else
				{
					p->next->data=e->data;
					p->next->next=NULL;
				}
				return true;
			}
			bool Destory_List(pLink &L)
			{
				/*pLink p,q;
				p=L;
				Print_List(p);
				while(p->next)
				{
					q=p->next;
					free(p);
					p=q;
					Print_List(q);
				}
				free(p);*/

				pLink p;
				while(L)
				{
					p=L;
					L=L->next;
					free(p);
				}
				return true;
			}

			bool Connect_List(pLink &L,pLink &M,pLink &N)
			{
				if(M&&N)
				{
					L->next=M->next;
					pLink p=L;
					while(p->next)
					{
						p=p->next;
					}
					p->next=N->next;
					free(N);
				}
				else if(M)
				{
					L=M;
				}
				else
				{
					L=N;
				}
				return true;
			}

			bool Delete_Link(pLink &L,int mink,int maxk)///delete link, mink < link.num < maxk
			{
				if(mink>=maxk)	return false;
				else
				{
					pLink p=L,q=L->next;
					{
						while(q)
						{
							if(q->data.num>mink&&q->data.num<maxk)
							{
								p->next=q->next;
								free(q);
								q=p->next;
								if(!q)	break;
							}
							else
							{
								p=q;
								q=q->next;
							}
						}
					}
				}
				return true;
			}
	};

class Stack
{
public:
	typedef struct Data
		{
			int num;
			char name[30];
		}Data,*pData;
};
}
