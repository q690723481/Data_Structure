#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* creatList()//创建链表，返回该链表的地址,即创建头节点，头节点data随便，
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
struct Node* creatNode(int data)//创建节点，返回该节点的地址,此时节点的指针区域还是空
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;//指针域定义为空
	return newNode;

}
void printList(struct Node* headNode)//打印链表
{
	struct Node* pMove = headNode->next;
	while (pMove)
	{
		printf("%d", pMove->data);
		printf("  %x\n", pMove->next);
		pMove = pMove->next;

	}
}
void insertNodeByHead(struct Node* headNode, int data)//从头节点插入数据
{
	struct Node* newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void deleteNodeByAppoin(struct Node* headNode, int posData)//在链表中删除指定的数据
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (!(headNode->next))
	{
		printf("链表为空!!!");
		return 0;
	}
	else
	{
		while (posNode->data!=posData)
		{
			posNodeFront = posNode;
			posNode = posNode->next;
			if (posNode == NULL)
			{
				printf("没有找到数据，删除失败！\n");
				return;
			}
		}
	     posNodeFront->next = posNode->next;
	     free(posNode);
	     return;
			

	}
}


void main()
{
	struct Node* list = creatList();
	insertNodeByHead(list, 5);
	insertNodeByHead(list, 4);
	insertNodeByHead(list, 3);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 1);
	printList(list);
	deleteNodeByAppoin(list, 3);
	printList(list);
	system("pause");



}