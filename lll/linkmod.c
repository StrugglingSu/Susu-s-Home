#include<stdlib.h>
#include <stdio.h>
typedef struct node
{
    struct node *link;
    int value;
}Node;

/*
** ���뵽һ�����������������Ĳ�����һ��ָ��������ָ���ָ�룬�Լ�һ����Ҫ�������ֵ��
*/
 
#define FALSE 0
#define TRUE 1
 
int sll_insert(Node **rootp,int new_value)
{
	Node *current;
	Node *previous;
	Node *new;
	
	/*
	** �õ�ָ���1���ڵ��ָ�롣
	*/
	current = *rootp;
	previous = NULL;
 
	/*
	** Ѱ����ȷ�Ĳ���λ�ã������ǰ������������ֱ������һ����ֵ���ڻ������ֵ�Ľڵ㡣
	*/
	while (current != NULL && current->value < new_value) {
 
		previous = current;
		current = current->link;
	}
 
	/*
	** Ϊ�½ڵ�����ڴ棬������ֵ�洢���½ڵ��У�����ڴ����ʧ�ܣ���������FALSE��
	*/
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL) {
		return FALSE;
	}
	new->value = new_value;
 
	/*
	** ���½ڵ���뵽�����У�������TRUE��
	*/
	new->link = current;
	if (previous == NULL) {
	    *rootp = new;
	}
	else {
	    previous->link = new;
	}
	return TRUE;
}
/*
** ���뵽һ�����������������Ĳ�����һ��ָ��������һ���ڵ��ָ���ָ�룬�Լ�һ����Ҫ�������ֵ��
*/
 
#define FALSE 0
#define TRUE 1
 
int sll_insert(Node **linkp,int new_value)
{
	Node *current;
	Node *new;
 
	/*
	** Ѱ����ȷ�Ĳ���λ�ã������ǰ������������ֱ������һ����ֵ���ڻ������ֵ�Ľڵ㡣
	*/
	while ((current = *linkp) != NULL && current->value < new_value) {
 
		linkp = &current->link;
	}
 
	/*
	** Ϊ�½ڵ�����ڴ棬������ֵ�洢���½ڵ��У�����ڴ����ʧ�ܣ���������FALSE��
	*/
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL) {
		return FALSE;
	}
	new->value = new_value;
 
	/*
	** �������в����½ڵ㣬������TRUE��
	*/
	new->link = current;
	*linkp = new;
	return TRUE;
}
