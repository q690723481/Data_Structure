#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* creatList()//�����������ظ�����ĵ�ַ,������ͷ�ڵ㣬ͷ�ڵ�data��㣬
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
struct Node* creatNode(int data)//�����ڵ㣬���ظýڵ�ĵ�ַ,��ʱ�ڵ��ָ�������ǿ�
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;//ָ������Ϊ��
	return newNode;

}
void printList(struct Node* headNode)//��ӡ����
{
	struct Node* pMove = headNode->next;
	while (pMove)
	{
		printf("%d", pMove->data);
		printf("  %x\n", pMove->next);
		pMove = pMove->next;

	}
}
void insertNodeByHead(struct Node* headNode, int data)//��ͷ�ڵ��������
{
	struct Node* newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void deleteNodeByAppoin(struct Node* headNode, int posData)//��������ɾ��ָ��������
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (!(headNode->next))
	{
		printf("����Ϊ��!!!");
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
				printf("û���ҵ����ݣ�ɾ��ʧ�ܣ�\n");
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