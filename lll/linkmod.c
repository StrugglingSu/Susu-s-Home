#include<stdlib.h>
#include <stdio.h>
typedef struct node
{
    struct node *link;
    int value;
}Node;

/*
** 插入到一个有序单链表。函数的参数是一个指向链表根指针的指针，以及一个需要插入的新值。
*/
 
#define FALSE 0
#define TRUE 1
 
int sll_insert(Node **rootp,int new_value)
{
	Node *current;
	Node *previous;
	Node *new;
	
	/*
	** 得到指向第1个节点的指针。
	*/
	current = *rootp;
	previous = NULL;
 
	/*
	** 寻找正确的插入位置，方法是按序访问链表，直到到达一个其值大于或等于新值的节点。
	*/
	while (current != NULL && current->value < new_value) {
 
		previous = current;
		current = current->link;
	}
 
	/*
	** 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，函数返回FALSE。
	*/
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL) {
		return FALSE;
	}
	new->value = new_value;
 
	/*
	** 把新节点插入到链表中，并返回TRUE。
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
** 插入到一个有序单链表。函数的参数是一个指向链表第一个节点的指针的指针，以及一个需要插入的新值。
*/
 
#define FALSE 0
#define TRUE 1
 
int sll_insert(Node **linkp,int new_value)
{
	Node *current;
	Node *new;
 
	/*
	** 寻找正确的插入位置，方法是按序访问链表，直到到达一个其值大于或等于新值的节点。
	*/
	while ((current = *linkp) != NULL && current->value < new_value) {
 
		linkp = &current->link;
	}
 
	/*
	** 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，函数返回FALSE。
	*/
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL) {
		return FALSE;
	}
	new->value = new_value;
 
	/*
	** 在链表中插入新节点，并返回TRUE。
	*/
	new->link = current;
	*linkp = new;
	return TRUE;
}

