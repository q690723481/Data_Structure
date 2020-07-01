#include<stdio.h>
#include<stdlib.h>
struct Node
{   
	struct Node* last;
	int data;
	struct Node* next;
};

void creatList()//创建一个空链表
{
	struct Node* newList = (struct Node*)malloc(sizeof(struct Node));
	newList->data = NULL;
	newList->last = NULL;
	newList->next = NULL;
	return newList;
}
void creatnewNode(int data)//创建一个空节点
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->last = NULL;
	newNode->next = NULL;
	return newNode;
}
void insert_nextNode(struct Node* newNode,int data)
{
	creatnewNode(data)
}