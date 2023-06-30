#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status是函数的类型。其值是函数结果状态代码

	// ----- 队列的链式存储实现 -----
typedef struct Queue_ElemType
{
	int num;
} QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct Link_Queue
{
	QueuePtr front; //队头指针
	QueuePtr rear; //队尾指针
}LinkQueue;
	// ----- 基本操作的函数原型说明 -----
		//构造一个空队列Q
Status InitQueue(LinkQueue& Q);
		//若队列为空队列，则返回TRUE，否则返回FALSE
Status QueueEmpty(LinkQueue Q);
		//返回Q的元素个数，即为队列的长度
int QueueLength(LinkQueue Q);
		//插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue& Q, QElemType e);
		//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
int DeQueue(LinkQueue& Q);

int main(void)
{
	int length_Q1 = 0, length_Q2 = 0, length_Q3 = 0;
	int n, x, output;
	srand((unsigned)time(NULL));
	QElemType random;
	LinkQueue Q1, Q2, Q3;
	InitQueue(Q1);
	InitQueue(Q2);
	InitQueue(Q3);
	printf("系统产生的随机数为:\n");
	for (n = 0; n < 20; n++)
	{
		x = rand() % 100;
		random.num = x;
		printf("%d\n", x);
		if (!(x % 3))
		{
			EnQueue(Q1, random);
		}
		else if (x % 3 == 1)
		{
			EnQueue(Q2, random);
		}
		else
		{
			EnQueue(Q3, random);
		}
	}
	length_Q1 = QueueLength(Q1);
	length_Q2 = QueueLength(Q2);
	length_Q3 = QueueLength(Q3);
	printf("\nQ1队中的随机数为\n");
	while (!QueueEmpty(Q1))
	{
		printf("%d ", DeQueue(Q1));
	}
	printf("\nQ1队列中元素个数为:%d\n", length_Q1);
	printf("\nQ2队中的随机数为\n");
	while (!QueueEmpty(Q2))
	{
		printf("%d ", DeQueue(Q2));
	}
	printf("\nQ2队列中元素个数为:%d\n", length_Q2);
	printf("\nQ3队中的随机数为\n");
	while (!QueueEmpty(Q3))
	{
		printf("%d ", DeQueue(Q3));
	}
	printf("\nQ3队列中元素个数为:%d\n", length_Q3);
	return 0;
}

	// ----- 基本操作的算法描述 -----
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) //存储分配失败
	{
		exit(OVERFLOW);
	}
	Q.front->next = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int QueueLength(LinkQueue Q)
{
	int length = 0;
	QueuePtr p = Q.front;
	while (p->next)
	{
		p = p->next;
		++length;
	}
	return length;
}
Status EnQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)	//存储分配失败
	{
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
int DeQueue(LinkQueue& Q)
{
	QueuePtr p;
	int e;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	p = Q.front->next;
	e = p->data.num;
	Q.front->next = p->next;
	if (Q.rear == p) //如果被删的元素是最后一个，需要对队尾指针重新赋值(指向头结点)
	{
		Q.rear = Q.front;
	}
	free(p);
	return e;
}