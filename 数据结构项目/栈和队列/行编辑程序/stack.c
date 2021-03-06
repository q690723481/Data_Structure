#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_INIT_SIZE 20//定义最大空间为20
#define STACKINCREMENT  10//当超过最大空间时，增加10的空间

typedef char ElemType;
typedef struct
{
	ElemType* base;//栈底指针
	ElemType* top;//栈顶指针
	int stackSize;//定义栈的大小
}sqStack;
void InitStack(sqStack *s)//创建一个空栈
{
	s->base= (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base) return ;
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;

}

void Push(sqStack* s, ElemType e)//进栈
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
void Pop(sqStack* s, ElemType* e)//出栈
{
	if (s->top == s->base) return ;
	*e = *(--s->top);

}
int StackLen(sqStack s)//得到栈元素的个数
{
	return (s.top - s.base);//C语言指针减指针得到的是元素的个数，而不是指针的相减，这一点和汇编不一样
}
void PrintStack(sqStack* s)
{
	ElemType *pMove;
	if (s->base == s->top)
	{
		printf("栈为空,打印失败");
		return ;
	}
	pMove = s->base;
	for (; pMove < s->top; pMove++)
	{
		//printf("%c\t%p\n", *pMove, pMove);
		printf("%c", *pMove);
	}

}


void main()
{   
	char e = 0;
	char ch;
	sqStack s ;
	InitStack(&s);
	scanf("%c", &ch);
	while (ch!=EOF&&ch!='\n')
	{
		switch (ch)
		{
		case '#': Pop(&s, &e); break;
		default:Push(&s, ch);  break;
		}
		scanf("%c", &ch);
	}
	PrintStack(&s);
	system("pause");
	

}