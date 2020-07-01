#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int num;
	char name[20];
	int math;
};
struct Node
{
	struct stu data;
	struct Node* next;
};
struct Node* creatList()//创建链表，返回该链表的地址,即创建头节点，头节点data随便，
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
struct Node* creatNode(struct stu data)//创建节点，返回该节点的地址,此时节点的指针区域还是空
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;//指针域定义为空
	return newNode;

}
void printList(struct Node* headNode)//打印链表
{
	struct Node* pMove = headNode->next;
	printf("学号\t姓名\t成绩\t地址\n");
	while (pMove)
	{
		printf("%d\t%s\t%d\t%x\n", pMove->data.num, pMove->data.name, pMove->data.math,pMove->next);
		pMove = pMove->next;

	}
}
void insertNodeByHead(struct Node* headNode, struct stu data)//从头节点插入数据
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
		while (posNode->data.num != posData)
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
	while (1)
	{
		printf("请输入编号:");
		scanf("%d", &list->data.num);
		printf("请输入姓名;");
		scanf("%s", &list->data.name);
		printf("请输入math成绩:");
		scanf("%d", &list->data.math);
		insertNodeByHead(list, list->data);
		printList(list);
		
		printf("continue(Y/N?)\n");
		getchar();//吃一个回车
		int choice=getchar();
		if (choice == 'N' || choice == 'n')
		{
			break;
		}
	}



}