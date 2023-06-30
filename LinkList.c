#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> //malloc()函数的头文件,malloc()函数用于开创一个空间用于存放所需要的数据,参数是所需空间的大小
#define NULL 0
#define NAME Linked_list //用于更改结构体类型名
#define LEN sizeof(struct NAME) //结构体类型所需的内存长度
int n = 0; //用全局变量n来计算链表的长度
struct NAME
{
	int num;
	char name[20];
	struct NAME* next; //指向下一个链表结点首地址的指针
};

// //链表的创建
struct NAME* creat() //定义一个指针函数(返回值是指针的函数)实现动态链表的创建
{
	struct NAME* p1, * p2, * head = NULL; //head用于存储链表头结点
	p1 = p2 = (struct NAME*)malloc(LEN); //强制类型转换，因为malloc()函数的返回值的指针类型和结构体不同
	//有些情况需要用p1 != NULL来检查malloc之后空间是不是不够,如果空间不够则malloc返回空指针NULL
	scanf("%d%s", &p1->num, &p1->name);
	while (p1->num != NULL) //num = 0标记链表结束位置
	{
		n++;
		//把第一个结点地址赋给head指针，如果不是第一个结点就让next指针指向下一个结点的首地址
		(n == 1) ? (head = p1) : (p2->next = p1);
		p2 = p1; //p2指针移动到下一个结点的首地址(p1指针所存储的地址)
		p1 = (struct NAME*)malloc(LEN); //新创建一个结点
		scanf("%d%s", &p1->num, &p1->name);
	}
	p2->next = NULL; //链表结束使最后一个结点的next指针指向NULL(空指针)
	return head; //返回值是一个指针，指向链表头结点的位置
}

// //链表的输出
void print(struct NAME* head)
{
	struct NAME* p;
	p = head;
	if (head != NULL)
	{
		do
		{
			printf("%d\t%s\n", p->num, p->name);
			p = p->next;
		} while (p != NULL);
	}
}

// //链表的删除
struct NAME* del(struct NAME* head, long num) //返回值还是一个结构体类型的指针，便于删除之后还能对新链表进行打印等操作
{
	struct NAME* p1, * p2;
	if (head == NULL)
	{
		printf("\nList null!\n");
		return head; //注意返回值
	}
	p1 = head;
	p2 = p1;
	while (num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num == p1->num)
	{
		if (p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
		printf("delete:%d\n", num);
		n = n - 1; //注意全局变量用法
	}
	else
	{
		printf("%d not been found!\n", num);
	}
	return head; //注意返回值
}

// //链表的插入
struct NAME* insert(struct NAME* head, struct NAME* stud) //注意返回值类型
{
	struct NAME* p0, * p1, * p2;
	p1 = head;
	p0 = stud;
	p2 = p1;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->num > p1->num) && (p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num <= p1->num)
		{
			if (head == p1)
			{
				head = p0;
			}
			else
			{
				p2->next = p0;
			}
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;
	return head; //注意返回值
}

void main()
{
	struct NAME* head, stu;
	int del_num;
	printf("input records:\n");
	head = creat();
	print(head);
	printf("\n input the deleted number:\n");
	scanf("%d", &del_num);
	head = del(head, del_num);
	print(head);
	printf("\n input the inserted record:\n");
	scanf("%d%s", &stu.num, &stu.name);
	head = insert(head, &stu);
	print(head);
}