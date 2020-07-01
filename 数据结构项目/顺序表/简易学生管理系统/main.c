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
struct Node* creatList()//�����������ظ�����ĵ�ַ,������ͷ�ڵ㣬ͷ�ڵ�data��㣬
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
struct Node* creatNode(struct stu data)//�����ڵ㣬���ظýڵ�ĵ�ַ,��ʱ�ڵ��ָ�������ǿ�
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;//ָ������Ϊ��
	return newNode;

}
void printList(struct Node* headNode)//��ӡ����
{
	struct Node* pMove = headNode->next;
	printf("ѧ��\t����\t�ɼ�\t��ַ\n");
	while (pMove)
	{
		printf("%d\t%s\t%d\t%x\n", pMove->data.num, pMove->data.name, pMove->data.math,pMove->next);
		pMove = pMove->next;

	}
}
void insertNodeByHead(struct Node* headNode, struct stu data)//��ͷ�ڵ��������
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
		while (posNode->data.num != posData)
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
	while (1)
	{
		printf("��������:");
		scanf("%d", &list->data.num);
		printf("����������;");
		scanf("%s", &list->data.name);
		printf("������math�ɼ�:");
		scanf("%d", &list->data.math);
		insertNodeByHead(list, list->data);
		printList(list);
		
		printf("continue(Y/N?)\n");
		getchar();//��һ���س�
		int choice=getchar();
		if (choice == 'N' || choice == 'n')
		{
			break;
		}
	}



}