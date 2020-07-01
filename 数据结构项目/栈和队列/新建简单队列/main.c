#include<stdio.h>
#include<stdlib.h>
typedef int QElemType;
typedef struct QNode//定义一个数据类型QNode
{
	QElemType data;
	struct QNode* next;
}QNode;

typedef struct QList//定义队列的队头和队尾指针
{
	QNode* front;
	QNode* rear;
}QList;

void InitQueue(QList* list)//创建空队列
{
	list->front=list->rear = (QNode*)malloc(sizeof(QNode));
	list->front->next = NULL;
}
void InsertNode_rear(QList *list,QElemType data)//从队尾插入元素data
{
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->next = NULL;
	list->rear->next = newNode;
	list->rear = newNode;

}
void DeleteNode_front(QList* list, QElemType *e)//从队头删除元素，并把值放入e中
{   
	*e = list->front->next->data;
	QNode *p = list->front->next;
	list->front->next = list->front->next->next;
	free(p);
}
void PrintList(QList *list)
{
	if (list->front==list->rear)
	{
		printf("Queue is NULL\n");
	}
	else
	{
		QNode* pMove = list->front->next;
		for (; pMove < list->rear; pMove = pMove->next)
		{
			printf("%d\t%p\n", pMove->data, pMove->next);
		}
		printf("%d\t%p\n", pMove->data, pMove->next);
	}

}
void main()
{
	int e;
	int* pe = &e;
	QList list;
	QList* pList = &list;
	InitQueue(&list);
	PrintList(&list);
	InsertNode_rear(&list, 1);
	InsertNode_rear(&list, 2);
	InsertNode_rear(&list, 3);
	InsertNode_rear(&list, 4);
	InsertNode_rear(&list, 5);
	InsertNode_rear(&list, 6);

	PrintList(&list);
	InsertNode_rear(&list, 7);
	PrintList(pList);
	DeleteNode_front(pList, pe);
	printf("%d", e);




}