#include <stdio.h> 
#include <iostream>
#include <malloc.h>
using namespace std; 
typedef int status;
typedef int elemtype;
typedef struct LNode{
	elemtype data;
	struct LNode *next;	//�����*nextΪָ��ṹ��LNode���͵�ָ�� 
}LNode,*linklist;		// *linklist�����һ���б�ͷָ�룬Ҳ�ǽṹ������ 
 
 
//��λ�����n��Ԫ�ص�ֵ����������ͷ���ĵ����� 
status createlist(linklist &l,int n)
{int i; 
linklist p; 
	l=(linklist)malloc(sizeof(linklist));
	l->next=NULL;//�Ƚ���һ����ͷ���ĵ����� 
	for(i=n;i>0;i--)
	{
		p=(linklist)malloc(sizeof(linklist));//�����½�� 
		cout<<"�������"<<i<<"�����ݣ�";
		cin>>p->data;
		p->next=l->next;
		l->next=p;	
	 } 
	 i=0;
	 cout<<endl<<"���������"; 
	 for(p=l->next;p!=NULL;p=p->next)
	 	cout<<p->data<<"  ";
	 	cout<<endl<<endl;
	 return 0; 
}
 
void mergelist(linklist &la,linklist &lb,linklist &lc)
{//��֪������la��lb�Ե���˳������
//�鲢la��lb�õ�������lc��lcҲ�Ե���˳������ 
 
	linklist pa,pb,pc,p;
	pa=la->next;
	pb=lb->next;
	lc=pc=la;					//��la��ͷ�����lc��ͷ��� 
	while(pa&&pb)				//pa��pb����Ϊ��ʱ 
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;				//pcָ��lc�б��е�ǰ���һ����� 
			pa=pa->next; 
		}
		else 
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;	
		}	
	}
		pc->next=pa?pa:pb;		//����ʣ��� 
		free(lb);				//�ͷ�lb��ͷ��� 
	 cout<<endl<<"���lc��"; 
	 for(p=lc->next;p!=NULL;p=p->next)
	 	cout<<p->data<<"  ";
	 	cout<<endl<<endl;
}
 
int main()
{	
	linklist la,lb,lc;
	cout<<"����la"<<endl;
	createlist(la,5);
	cout<<"����lb"<<endl; 
	createlist(lb,4);
	mergelist(la, lb,lc);
 } 
