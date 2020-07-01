#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_INIT_SIZE 20//定义最大空间为20
#define STACKINCREMENT  10//当超过最大空间时，增加10的空间

typedef int ElemType;
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
	s->base = s->top;
	s->stackSize = STACK_INIT_SIZE;

}

void Push(sqStack* s, ElemType e)//进栈
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)  return;
	}
	*(s->top) = e;
	s->top++;


}
void Pop(sqStack* s, ElemType* e)//出栈
{
	if (s->top == s->base) return ;
	*e = *(s->top);
	s->top -= 1;
}
int StackLen(sqStack s)//得到栈元素的个数
{
	return (s.top - s.base);//C语言指针减指针得到的是元素的个数，而不是指针的相减，这一点和汇编不一样
}
void PrintStack(sqStack* s)
{
	ElemType *pMove;
	if (s->base = s->top)
	{
		printf("栈为空,打印失败");
		return ;
	}
	pMove = s->top;
	for (; pMove >= s->base; pMove--)
	{
		printf("%d\t%p\n", *pMove, pMove);
	}

}


void main()
{
	sqStack s ;
	InitStack(&s);
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	Push(&s, 5);
	Push(&s, 6);
	Push(&s, 7);
	Push(&s, 8);


	PrintStack(&s);
	system("pause");
	

}