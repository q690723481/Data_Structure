#include<stdio.h>
#include<stdlib.h>
typedef int QElemType;
typedef struct QNode//����һ����������QNode
{
	QElemType data;
	struct QNode* next;
}QNode;

typedef struct QList//������еĶ�ͷ�Ͷ�βָ��
{
	QNode* front;
	QNode* rear;
}QList;

void InitQueue(QList* list)//�����ն���
{
	list->front=list->rear = (QNode*)malloc(sizeof(QNode));
	list->front->next = NULL;
}
void InsertNode_rear(QList *list,QElemType data)//�Ӷ�β����Ԫ��data
{
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->next = NULL;
	list->rear->next = newNode;
	list->rear = newNode;

}
void DeleteNode_front(QList* list, QElemType *e)//�Ӷ�ͷɾ��Ԫ�أ�����ֵ����e��
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