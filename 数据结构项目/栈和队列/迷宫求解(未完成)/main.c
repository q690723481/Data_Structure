#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_INIT_SIZE 20//�������ռ�Ϊ20
#define STACKINCREMENT  10//���������ռ�ʱ������10�Ŀռ�

typedef int ElemType;
typedef struct
{
	ElemType* base;//ջ��ָ��
	ElemType* top;//ջ��ָ��
	int stackSize;//����ջ�Ĵ�С
}sqStack;
void InitStack(sqStack* s)//����һ����ջ
{
	s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base) return;
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;

}

void Push(sqStack* s, ElemType e)//��ջ
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)  return;
		s->top = s->base + s->stackSize;
		s->stackSize += STACKINCREMENT;
	}
	*(s->top++) = e;



}
void Pop(sqStack* s, ElemType* e)//��ջ
{
	if (s->top == s->base) return;
	*e = *(--s->top);

}
int StackLen(sqStack s)//�õ�ջԪ�صĸ���
{
	return (s.top - s.base);//C����ָ���ָ��õ�����Ԫ�صĸ�����������ָ����������һ��ͻ�಻һ��
}
void PrintStack(sqStack* s)
{
	ElemType* pMove;
	if (s->base == s->top)
	{
		printf("ջΪ��,��ӡʧ��");
		return;
	}
	pMove = s->base;
	for (; pMove < s->top; pMove++)
	{
		//printf("%c\t%p\n", *pMove, pMove);
		printf("%c", *pMove);
	}

}
void CreatMaze(int* Maze[10][10])//����һ��maze�Թ�
{
	int newMaze[10][10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						  1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
						  1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
						  1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
						  1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
						  1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
						  1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
						  1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
						  1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
						  1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Maze[i][j] = newMaze[i][j];
		}
	}
}
void PrintMaze(int* Maze[10][10])//��ӡ������Թ�
{

}

void main()
{
	int Maze[10][10] = { 0 };
	int* pm = Maze;
	CreatMaze(pm);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%3d", Maze[i][j]);
		}
		printf("\n");
	}

	system("pause");


}