#include<stdio.h>
#include<stdlib.h>
struct Node
{   
	struct Node* last;
	int data;
	struct Node* next;
};

void creatList()//����һ��������
{
	struct Node* newList = (struct Node*)malloc(sizeof(struct Node));
	newList->data = NULL;
	newList->last = NULL;
	newList->next = NULL;
	return newList;
}
void creatnewNode(int data)//����һ���սڵ�
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