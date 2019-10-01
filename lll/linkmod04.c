/*设head1和head2是两个非空单向链表，数据值有重复且升序排序
将head1和head2合并成一个升序链
*/
 
#include<stdio.h>
#include<stdlib.h>
 
//定义结构体单元 
typedef struct node{
	int data;//结构体数据域 
	struct node* next;//结构体指针域 
}ElemSN;
//逆向创建单向链表（头插法）
ElemSN *PreCreatLink(int a[],int n)
{
	ElemSN *head=NULL,*p;
	int i;
	for(i=n-1;i>-1;i--)
	{
		p=(ElemSN*)malloc(sizeof(ElemSN));
		p->data=a[i];
		p->next=head;
		head=p;
	}
	return head;
 } 
 
 
 ElemSN* Combine(ElemSN *head1,ElemSN *head2)
 {
 	ElemSN *head,*p,*tail;
 	head=NULL;
 	while(head1&&head2)
 	{
 		if(head1->data<head2->data)
 		{
 			p=head1;
 			head1=head1->next;
		 }
		else
		{
			p=head2;
			head2=head2->next;
		}
		p->next=NULL; 
		if(!head)
		head=tail=p;
		else
		{
			tail=tail->next=p;
		}
	 }
	 if(head1)
	 p=head1;
	 else
	 p=head2;
	 tail->next=p;
	 return head;
 }
 
   //打印链表所有结点的值
   void PrintLink(ElemSN* head)
 {
 	ElemSN *p=head;
 	for(;p;p=p->next)
 	printf("%d ",p->data);
 } 
  
 
 int main(void)
 {
 	ElemSN *head1,*head2,*head;
 	int i,j;
 	int a[10]={0};
 	int b[10]={0};
 	
 	for(i=0;i<10;i++)
 	scanf("%d",&a[i]);
 	for(i=0;i<10;i++)
 	scanf("%d",&b[i]);
 	
 	head1=PreCreatLink(a,10);    //创建链表head1 
 	head2=PreCreatLink(b,10);    //创建链表head2 
 	head=Combine(head1,head2);  //将两个有序链表合并成一个有序链表 
 	PrintLink(head);       //输出链表 
 	return 0;
  }

