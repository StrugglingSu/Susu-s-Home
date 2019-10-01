#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node, *pNode;

int main()
{
	int a[10];
	int i,j;
	int temp=0;
	
	for(i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	}
	Node *L,*s;
	
	s=(Node *)malloc(sizeof(Node));
	
	s->data=a[0];
	s->next=NULL;
	for(i=1;i<3;i++)
	{
		L=(Node *)malloc(sizeof(Node));
		L->data=a[i];

		if(L->data<s->data)
		//ͷ�巨
		{
			
			L->next=s;
			s->next=L->next;
		} //β�巨 
		else
		{
			s->next=L;
			s=L;
		}
	}
	
	while(L)
	{
		printf("%d",s->data);
		s=s->next;
	}
	printf("\n");
	
	return 0;
}
