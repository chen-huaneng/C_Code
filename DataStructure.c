// 文件后缀为.cpp为C++文件（C Plus Plus），才有函数名(类型名& 变量名)的用法
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <windows.h>
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status; // Status是函数的类型。其值是函数结果状态代码

// ===== 线性表的顺序存储结构及运算实现 =====

// ----- 线性表的动态分配顺序存储结构 -----

// typedef struct student_information
// {
// 	int Num;
// } ElemType; //ElemType是某个确定的、将由用户自行定义的、含某个关系运算的数据对象
// #define LIST_INIT_SIZE 100 //存储空间初始分配量
// #define LISTINCREMENT 10 //存储空间分配增量
// typedef struct SqList
// {
// 	ElemType* elem; //存储空间分配基址，定义了一个struct student_information类型的指针
// 	int length; //当前长度
// 	int listsize; //当前分配的存储容量，以sizeof(ElemType)为单位
// } SqList; //Sequence List

// ----- 基本操作的函数原型说明 -----

//		//Status (*compare)()为指向函数的指针，用于比较
// Status compare_equal(ElemType x, ElemType y);
// Status compare(ElemType* pa, ElemType* pb);
//		//顺序表的初始化，构造一个空的线性表L
// Status InitList_Sq(SqList& L);
//		//在顺序线性表L的第i个元素之前插入新的元素e，i的合法值为1<=i<=ListLength_Sq(L)+1
// Status ListInsert_Sq(SqList& L, int i, ElemType e);
//		//在顺序线性表L中删除第i个元素，并用e返回其值，i的合法值为1<=i<=ListLength_Sq(L)
// Status ListDelete_Sq(SqList& L, int i, ElemType& e);
//		//在顺序线性表L中查找第i个值与e满足compare()的元素的位序，若找到，则返回其在L中的位序，否则返回0
// int LocateElem_Sq(SqList L, ElemType e);
//		//将两个元素按照从小到大的升序排列的顺序表A和B合并成一个元素按照升序排列的顺序表C，
//		//已知顺序线性表La和Lb的元素按值非递减排列，归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列
// void MergeList_Sq(SqList La, SqList Lb, SqList& Lc);
//		//打印线性表
// Status PrintList_Sq(SqList& L);
//		//求线性表的表长
// int ListLength_Sq(SqList& L);
//		//输入线性表的数据
// Status WriteList_Sq(SqList& L);

// ----- 基本操作的算法描述 -----

// Status compare_equal(ElemType x, ElemType y) //例如，判断x、y是否完全相等
//{
//	int flag;
//	(x.Num == y.Num) ? (flag = TRUE) : (flag = FALSE);
//	return flag;
// }
// Status compare(ElemType* pa, ElemType* pb) //例如，判断pa、pb的Score大小，如果pa的Score<=pb的Score则返回1，否则返回0
// {
// 	int flag;
// 	(pa->Num <= pb->Num) ? (flag = TRUE) : (flag = FALSE);
// 	return flag;
// }
// Status InitList_Sq(SqList& L)
// {
// 	//<stdlib.h>库函数void* malloc(size_t size)分配所需的内存空间，并返回一个指向它的指针，如果请求失败，则返回NULL
// 	L.elem = (ElemType*)malloc((LIST_INIT_SIZE) * sizeof(ElemType)); //强制类型转换
// 	if (!L.elem)
// 	{
// 		exit(OVERFLOW); //存储分配失败，<stdlib.h>库函数void exit(int Status)
// 	}
// 	L.length = 0; //空表长度为0
// 	L.listsize = LIST_INIT_SIZE; //初始存储容量
// 	return OK;
// }
// Status ListInsert_Sq(SqList& L, int i, ElemType e)
//{
//	ElemType* p;
//	if (i<1 || i>L.length + 1) //i值不合法
//	{
//		return ERROR;
//	}
//	if (L.length >= L.listsize) //当前存储空间已满，增加容量
//	{
//		//<stdlib.h>库函数void *realloc(void *ptr, size_t size)尝试重新调整之前调用malloc或calloc所分配的ptr所指向的内存块的大小
//		//该函数返回一个指针 ，指向重新分配大小的内存。如果请求失败，则返回 NULL
//		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType)); //强制类型转换
//		if (!newbase) //存储分配失败
//		{
//			return ERROR;
//		}
//		L.elem = newbase; //新基址
//		L.listsize += LISTINCREMENT; //增加存储容量
//	}
//	ElemType* q = &(L.elem[i - 1]); //q为插入位置，下标从0开始
//	for (p = &(L.elem[L.length - 1]); p >= q; --p) //从最后一个元素开始移动
//	{
//		*(p + 1) = *(p); //插入位置及之后的元素右移
//	}
//	*q = e; //插入e
//	++L.length; //表长增加1
//	return OK;
// } //时间复杂度为O(n)
// Status ListDelete_Sq(SqList& L, int i, ElemType& e)
//{
//	ElemType* p, * q;
//	if (i<1 || i>L.length)
//	{
//		return ERROR; //i值不合法
//	}
//	p = &(L.elem[i - 1]); //p为被删除元素的位置
//	e = *p; //被删除元素的值赋给e
//	q = L.elem + L.length - 1; //表尾元素的位置
//	for (++p; p <= q; ++p)
//	{
//		*(p - 1) = *p; //被删除元素之后的元素上移
//	}
//	--L.length; //表长减少1
//	return OK;
// } //时间复杂度为O(n)
// int LocateElem_Sq(SqList L, ElemType e)
//{
//	//flag标志在顺序表中是否存在与e满足compare()的元素
//	int i, flag;
//	ElemType* p;
//	i = 1; //i的初值为第1个元素的位序
//	p = L.elem; //p的初值为第1和元素的存储位置
//	while (i <= L.length && !(*compare_equal)(*p++, e)) //如果是输出的话*p++先取p所指向的值再p++
//	{
//		++i;
//	}
//	(i <= L.length) ? (flag = i) : (flag = FALSE);
//	return flag;
// } //时间复杂度为O(n)
// void MergeList_Sq(SqList La, SqList Lb, SqList& Lc)
//{
//	ElemType* pa, * pb, * pc, * pa_last, *pb_last;
//	pa = La.elem;
//	pb = Lb.elem;
//	Lc.listsize = Lc.length = La.length + Lb.length; //Lc的长度为La和Lb之和
//	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
//	if (!Lc.elem) //存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	pa_last = La.elem + La.length - 1; //a表尾指针
//	pb_last = Lb.elem + Lb.length - 1; //b表尾指针
//	while (pa <= pa_last && pb <= pb_last) //归并
//	{
//		((*compare)(pa, pb)) ? (*pc++ = *pa++) : (*pc++ = *pb++);
//	}
//	while (pa <= pa_last)
//	{
//		*pc++ = *pa++; //插入La的剩余元素
//	}
//	while (pb <= pb_last)
//	{
//		*pc++ = *pb++; //插入Lb的剩余元素
//	}
// } //由于操作执行的是复制La、Lb的元素到Lc，所以时间复杂度为O(A.length+B.length)
// Status PrintList_Sq(SqList& L)
//{
//	ElemType* p = L.elem;
//	if (L.elem == NULL) //判断是否为空表
//	{
//		printf("\nThe Sequence List is NULL\n");
//		return FALSE;
//	}
//	int i;
//	printf("\nThe content of Sequence List are below:\n");
//	for (i = 0; i < L.length; i++)
//	{
//		printf("%d ", p[i].Num);
//	}
//	return TRUE;
// }
// int ListLength_Sq(SqList& L)
//{
//	if (L.length == 0)
//		return 0;
//	return L.length;
// }
// Status WriteList_Sq(SqList& L)
// {
// 	int length, i;
// 	ElemType* p = L.elem;
// 	if (L.length >= L.listsize)
// 	{
// 		return FALSE;
// 	}
// 	printf("\nPlease enter the length of Sequence List:\n");
// 	scanf("%d", &length);
// 	printf("\nPlease enter %d datum that you want put in the Sequence List:\n", length);
// 	L.length = length;
// 	for (i = 0; i < length; i++)
// 	{
// 		scanf("%d", &L.elem[i].Num);
// 	}
// 	return TRUE;
// }

// 主函数实现顺序表的建立、插入、删除、查询以及合并按非递减排列的两个顺序表的功能

// int main()
//{
//	SqList L;
//	InitList_Sq(L); //顺序表的初始化--构造一个空表
//	WriteList_Sq(L);
//	PrintList_Sq(L);
//	int i; //在顺序表的第i个位置插入一个值为e的新元素
//	ElemType Insert_Elem;
//	Insert_Elem.Num = 0;
//	printf("\nPlease enter the location you want to insert on Sequence List:\n");
//	scanf("%d", &i);
//	printf("\nPlease enter the data of the inserted element:\n");
//	scanf("%d", &Insert_Elem.Num);
//	ListInsert_Sq(L, i, Insert_Elem);
//	PrintList_Sq(L);
//	int j; //删除线性表的第j个元素
//	ElemType e;
//	printf("\nPlease enter the location you want to delete on Sequence List:\n");
//	scanf("%d", &j);
//	ListDelete_Sq(L, j, e);
//	printf("\nThe Sequence List after delete:");
//	PrintList_Sq(L);
//	printf("\n%d is the delete element\n", e.Num);
//	ElemType search; //在线性表中查找与给定值search相等的数据元素
//	search.Num = 0;
//	printf("Please enter the element you want to search:\n");
//	scanf("%d", &search.Num);
//	printf("The locate of element you search is:%d\n", LocateElem_Sq(L, search));
//	//将两个元素按照从小到大的升序排列的顺序表A和B合并成一个元素按照升序排列的顺序表C
//	SqList La, Lb, Lc;
//	InitList_Sq(La);
//	WriteList_Sq(La);
//	printf("\nThe Sequence List of A:");
//	PrintList_Sq(La);
//	InitList_Sq(Lb);
//	WriteList_Sq(Lb);
//	printf("\nThe Sequence List of B:");
//	PrintList_Sq(Lb);
//	MergeList_Sq(La, Lb, Lc);
//	printf("\nThe Sequence List of C after merge:");
//	PrintList_Sq(Lc);
//   return 0;
// }

// ===== 线性表的链式存储结构及运算实现 =====

// ----- 链式存储结构 -----

// typedef struct Lnode
//{
//	ElemType data; //数据域
//	struct Lnode* next; //指针域
// } LNode, * LinkList; //LinkList定义的是struct Lnode类型的指针

// ----- 基本操作的函数原型说明 -----

//		//在链表的头部插入结点建立单链表，逆位序输入（随机产生）n个元素的值，建立带表头结点的单链线性表L
// LinkList Create_LinkList_L1(int n);
//		//在链表的尾部插入结点建立单链表
// LinkList Create_LinkList_L2();
//		//H是带头结点的单链表，求表长
// int Length_LinkList_L(LinkList H);
// 		//按序号查找第i个数据元素，L为带头节点的单链表的头指针，当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
// Status GetElem_LinkList_L(LinkList L, int i, ElemType& e);
//		//将新结点s插入到第i个结点的位置上，在带头结点的单链线性表L的第i个元素之前插入元素e，i可以为表长＋1, 也就是在表尾插入元素
// Status Insert_LinkList_L(LinkList& L, int i, ElemType e);
//		//删除第i个元素，并由e返回其值，在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
// Status Delete_LinkList_L1(LinkList& L, int i, ElemType& e);
//		//删除所有值为x的结点，并返回值为x的结点个数
// int Delete_LinkList_L2(LinkList& H, ElemType x);
//		//打印链表的数据
// Status Print_LinkList_L(LinkList& H);
//		//将一个链表按逆序排列——三结点法
// LinkList ReverseOrder_LinkList_L(LinkList& H, int length);

// ----- 基本操作的算法描述 -----

// LinkList Create_LinkList_L1(int n) //逆位序输入（随机产生）n个元素的值，建立带表头结点的单链线性表L
//{
//	LinkList p, H = (LinkList)malloc(sizeof(LNode));
//	int i;
//	H->next = NULL; //先建立带头节点的单链表，头结点的data中没有数据，因为在之后的操作中可能要丢弃头结点
//	for (i = n; i > 0; i--)
//	{
//		p = (LinkList)malloc(sizeof(LNode)); //生成新节点
//		//<stdlib.h>库函数int rand(void)返回一个范围在0到RAND_MAX之间的伪随机数，RAND_MAX是一个常量
//		scanf("%d", &p->data.Num);
//		p->next = H->next;
//		H->next = p; //插入到表头
//	}
//	return H;
// }
// LinkList Create_LinkList_L2()
//{
//	LinkList H = (LinkList)malloc(sizeof(LNode));
//	H->next = NULL; //空表
//	LNode* s, * r = H;
//	int x; //设元素的类型为int
//	scanf("%d", &x);
//	while (x != -1) //-1结束输入
//	{
//		s = (LinkList)malloc(sizeof(LNode));
//		s->data.Num = x;
//		r->next = s;
//		r = s;
//		s->next = NULL;
//		scanf("%d", &x);
//	}
//	return H;
// }
// int Length_LinkList_L(LinkList H)
//{
//	LNode* p = H;
//	int j = 0; //头结点的data没有数据，因此j = 0
//	while (p->next)
//	{
//		p = p->next;
//		j++;
//	}
//	return j;
// }
// Status GetElem_LinkList_L(LinkList L, int i, ElemType& e)
//{
//	LinkList p;
//	p = L->next;
//	int j = 1; //初始化，p指向第一个结点，j为计数器
//	while (p && j < i) //顺指针向后查找，直到p指向第i个元素或p为空
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p || j > i)
//	{
//		return ERROR; //第i个元素不存在，或i值不合法
//	}
//	e = p->data; //取第i个元素
//	return OK;
// }
// Status Insert_LinkList_L(LinkList& L, int i, ElemType e)
//{
//	LinkList p = L, s;
//	int j = 0; //p指向表头，j就为0，p指向第一个结点，j就为1
//	while (p && j < i - 1) //找第i-1个结点
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p && j > i - 1) //j>i-1 出现在i小于1的情况，即i不合法的情况
//	{
//		return ERROR;
//	}
//	s = (LinkList)malloc(sizeof(LNode)); //j=i-1，生成新结点
//	s->data = e;
//	s->next = p->next; //插入L中
//	p->next = s;
//	return OK;
// }
// Status Delete_LinkList_L1(LinkList& L, int i, ElemType& e)
//{
//	LinkList p = L, q;
//	int j = 0;
//	while (p->next && j < i - 1) //寻找第i-1个结点，并保证第i个结点存在
//	{
//		p = p->next;
//		j++;
//	}
//	if (!(p->next) || j > i - 1) //删除位置不合理
//	{
//		return ERROR;
//	}
//	q = p->next; //删除并释放结点
//	p->next = q->next;
//	e = q->data;
//	free(q); //释放到存储池
//	return OK;
// }
// int Delete_LinkList_L2(LinkList& H, ElemType x)
//{
//	LNode* p, * q = H;
//	int count = 0, num = x.Num;
//	while (q->next) //指针作为条件表达式时，所要判断的条件实际上就是该指针是否为一空指针
//	{
//		p = q->next;
//		if (p->data.Num == num) //逐个判断结点值，为x则删除
//		{
//			count++;
//			q->next = p->next;
//			free(p);
//		}
//		else
//		{
//			q = p; //继续移动
//		}
//	}
//	return count;
// }
// Status Print_LinkList_L(LinkList& H)
//{
//	if (!H->next)
//	{
//		return ERROR;
//	}
//	LNode* p = H;
//	while (p->next)
//	{
//		p = p->next;
//		printf("%d ", p->data.Num);
//	}
//	return OK;
// }
// LinkList ReverseOrder_LinkList_L(LinkList& H,int length)
//{
//	if (length == 1)
//	{
//		return H;
//	}
//	LNode* before, * current, * after;
//	before = H->next; //before指向第一个结点
//	current = before->next; //current指向第二个结点
//	after = current->next; //after指向第三个结点
//	before->next = NULL; //第一个结点指向NULL
//	while (after->next)
//	{
//		current->next = before; //让中间结点指向前一个结点
//		before = current;
//		current = after;
//		after = after->next; //三个结点沿着原链表继续移动
//	}
//	after->next = current;
//	current->next = before; //连接最后三个
//	H->next = after; //更改头结点
//	return H;
// }

// ===== 线性表的典型应用 =====

// 将一个链表按逆序排列

// int main()
//{
//	LNode* H;
//	int length;
//	printf("\nPlease enter the datum of list:\n");
//	H = Create_LinkList_L2();
//	printf("\nThe length of LinkList is:%d\n", length = Length_LinkList_L(H));
//	printf("\nThe datum of LinkList:\n");
//	Print_LinkList_L(H);
//	H = ReverseOrder_LinkList_L(H, length);
//	printf("\nThe datum of LinkList after order:\n");
//	Print_LinkList_L(H);
//	return 0;
// }

// 两个链式线性表多项式的合并

// typedef struct Polynomial
//{
//	float coef;
//	float exp; //coef为系数域，exp为指数域
//	struct Polynomial* next; //指针域
// } PNomial, * PolyNomial;

// ----- 基本操作的函数原型说明 -----

//		//多项式的输入
// PolyNomial Input_LinkList();
//		//求链表的长度
// int Length_LinkList(PolyNomial H);
//		//打印链表的多项式
// Status Print_LinkList(PolyNomial& L);
//		//降幂排列并删去排序后多项式系数为0的结点
// PolyNomial Descending_Permutation_LinkList(PolyNomial& H, int& length);
//		//多项式求和，前提是LA和LB已经按照降幂排列
// PolyNomial Adding_LinkList_LAB(PolyNomial& LA, PolyNomial& LB);

// ----- 基本操作的算法描述 -----

// PolyNomial Input_LinkList()
//{
//	PolyNomial H = (PolyNomial)malloc(sizeof(PNomial));
//	PNomial* s, * r = H;
//	float x, y; //设元素的类型为int
//	H->next = NULL; //先建立带头节点的单链表，头结点的data中没有数据，因为在之后的操作中可能要丢弃头结点
//	scanf("%f%f", &x, &y);
//	while (x != 0) //多项式的系数为0结束输入
//	{
//		s = (PolyNomial)malloc(sizeof(PNomial)); //生成新节点
//		s->coef = x;
//		s->exp = y;
//		r->next = s;
//		r = s;
//		s->next = NULL;
//		scanf("%f%f", &x, &y);
//	}
//	return H;
// }
// int Length_LinkList(PolyNomial H)
//{
//	PNomial* p = H;
//	int j = 0; //头结点的data没有数据，因此j = 0
//	while (p->next)
//	{
//		p = p->next;
//		j++;
//	}
//	return j;
// }
// Status Print_LinkList(PolyNomial& L)
//{
//	if (!L->next)
//	{
//		return ERROR;
//	}
//	PNomial* p = L;
//	p = p->next;
//	while (p)
//	{
//		printf("%f*x^%f", p->coef, p->exp);
//		p = p->next;
//		if (p)
//		{
//			printf("+");
//		}
//	}
//	return OK;
// }
// PolyNomial Descending_Permutation_LinkList(PolyNomial& H, int& length)
//{
//	if (!H->next)
//	{
//		return NULL;
//	}
//	PNomial* current, * after;
//	float swap;
//	int i, j;
//	current = H->next;
//	after = current->next;
//	for (i = 1; i < length; i++) //类似选择排序算法降幂排列
//	{
//		for (j = i + 1; j <= length; j++)
//		{
//			if (after->exp > current->exp) //降幂排列
//			{
//				swap = after->exp;
//				after->exp = current->exp;
//				current->exp = swap;
//				swap = after->coef;
//				after->coef = current->coef;
//				current->coef = swap;
//			}
//			else if (after->exp == current->exp) //合并同类项并将后面的同类项置为0方便接下来的删除结点
//			{
//				current->coef += after->coef;
//				after->coef = 0;
//				after->exp = 0;
//			}
//			after = after->next;
//		}
//		current = current->next;
//		after = current->next;
//	}
//	current = H->next;
//	after = current->next;
//	for (i = 1; i < length; i++) //删去多余的结点
//	{
//		if (!after->coef) //coef == 0即多项式系数为0时删去该结点
//		{
//			current->next = after->next;
//			free(after);
//			after = current->next;
//		}
//		else
//		{
//			current = current->next;
//			after = current->next;
//		}
//	}
//	return H;
// }
// PolyNomial Adding_LinkList_LAB(PolyNomial& LA, PolyNomial& LB)
//{
//	PNomial* qa = LA, * qb = LB, * del, * follow_qa = qa, * temp;
//	while (qa->next && qb->next) //qa用于移动链表LA，qb用于移动链表LB，比较多项式的指数一共有三种情况
//	{
//		if (qa->exp > qb->exp) //第一种情况
//		{
//			follow_qa = qa; //follow_qa一直作为qa的前一个结点
//			qa = qa->next;
//		}
//		else if (qa->exp == qb->exp) //第二种情况
//		{
//			qa->coef += qb->coef; //合并同类项
//			if (qa->coef)
//			{
//				follow_qa = qa;
//				qa = qa->next;
//			}
//			else //当系数为0时释放空间，节省内存
//			{
//				del = qa; //del用于存储要删除的结点
//				qa = qa->next;
//				free(del);
//			}
//			del = qb; //释放LB链表的结点
//			qb = qb->next;
//			free(del);
//		}
//		else //最后一种情况 qa->exp < qb->exp
//		{
//			temp = qb; //在qa的前一个结点即follow_qa后面新增一个结点temp即将qb结点插入到LA链表中
//			qb = qb->next;
//			follow_qa->next = temp;
//			temp->next = qa;
//		}
//	}
//	if (qb->next) //如果LB还有剩余结点，将LB链表剩下的多项式接在LA后面
//	{
//		qa->next = qb;
//	}
//	return LA;
// }

// 建立两个存储多项式的链表LA、LB并输入数据，按照降幂排列，然后打印出合并后并且降幂排列的多项式

// int main()
//{
//	PNomial* LA, * LB;
//	int lengthLA, lengthLB;
//	//建立存储多项式的链表LA并输入数据，按照降幂排列
//	printf("\nPlease enter the datum of LA:\n"); //输入LA的数据
//	LA = Input_LinkList();
//	Print_LinkList(LA);
//	lengthLA = Length_LinkList(LA);
//	printf("\nThe length of LA:%d\n", lengthLA);
//	printf("\nThe datum after order:\n");
//	LA = Descending_Permutation_LinkList(LA, lengthLA); //降幂排序
//	Print_LinkList(LA);
//	lengthLA = Length_LinkList(LA); //重新计算表长
//	printf("\nThe length of LA:%d\n", lengthLA);
//	//建立存储多项式的链表LB并输入数据，按照降幂排列
//	printf("\nPlease enter the datum of LB:\n"); //输入LB的数据
//	LB = Input_LinkList();
//	Print_LinkList(LB);
//	lengthLB = Length_LinkList(LB);
//	printf("\nThe length of LB:%d\n", lengthLB);
//	printf("\nThe datum after order:\n");
//	LB = Descending_Permutation_LinkList(LB, lengthLB); //降幂排序
//	Print_LinkList(LB);
//	lengthLB = Length_LinkList(LB); //重新计算表长
//	printf("\nThe length of LB:%d\n", lengthLB);
//	//进行合并多项式并将结果存储在LA链表中
//	printf("\nThe LinkList after adding:\n");
//	LA = Adding_LinkList_LAB(LA, LB);
//	lengthLA = Length_LinkList(LA);
//	LA = Descending_Permutation_LinkList(LA, lengthLA);
//	Print_LinkList(LA);
//	printf("\nThe length of LinkList after adding:%d\n", lengthLA);
//	return 0;
// }

// ===== 栈和队列的实现 =====

// ----- 栈的顺序存储实现 -----

// #define STACK_INIT_SIZE 100 //分配栈存储空间初始量
// #define STACKINCREMENT 10 //栈存储空间分配增量
// typedef struct Stack_ElemType
//{
//	int num;
// }SElemType;
// typedef struct Sequence_Stack
//{
//	SElemType* base; //栈底指针，base == NULL时表明栈不存在
//	SElemType* top; //栈顶指针，top == base可作为栈空的标志，非空栈的栈顶指针始终在栈顶元素的下一个位置上
//	int stacksize; //表示栈当前可用的最大容量，以元素为单位
// }SqStack;

// ----- 基本操作的函数原型说明 -----

//		//构造一个空栈
// Status InitStack(SqStack& S);
//		//销毁栈S，S不再存在
// Status DestroyStack(SqStack& S);
//		//把S置为空栈
// Status ClearStack(SqStack& S);
//		//若栈S为空栈，则返回TRUE，否则返回FALSE
// Status StackEmpty(SqStack S);
//		//返回S的元素个数，即栈的长度
// int StackLength(SqStack S);
//		//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
// Status GetTop(SqStack S, SElemType& e);
//		//插入元素为e为新的栈顶元素
// Status Push(SqStack& S, SElemType e);
//		//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
// Status Pop(SqStack& S, SElemType& e);
//		//从栈顶到栈底依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败
// Status StackTraverse(SqStack S, Status(*visit)());

// ----- 基本操作的算法描述 -----

// Status InitStack(SqStack& S)
//{
//	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType)); //构造一个空栈S
//	if (!S.base)
//	{
//		exit(OVERFLOW); //存储分配失败
//	}
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
// }
// Status GetTop(SqStack S, SElemType& e)
//{
//	if (S.top == S.base)
//	{
//		return ERROR;
//	}
//	e = *(S.top - 1); //栈顶指针始终在栈顶元素的下一个位置上
//	return OK;
// }
// Status Push(SqStack& S, SElemType e)
//{
//	if (S.top - S.base >= S.stacksize) //栈满，追加存储空间
//	{
//		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
//
//		if (!S.base) //存储分配失败
//		{
//			//<stdlib.h>库函数void exit(int status)立刻终止调用进程，任何属于该进程的打开的文件描述符都会被关闭
//			//该进程的子进程由进程 1 继承，初始化，且会向父进程发送一个 SIGCHLD 信号。
//			exit(OVERFLOW);
//		}
//		S.top = S.base + S.stacksize; //满栈时栈顶指针指向栈顶元素的下一个位置
//		S.stacksize += STACKINCREMENT;
//	}
//	*S.top++ = e; //先存放，后自增
//	return OK;
// }
// Status Pop(SqStack& S, SElemType& e)
//{
//	if (S.top == S.base)
//	{
//		return ERROR;
//	}
//	e = *--S.top; //先自减，再赋值
//	return OK;
// }

// ----- 队列的链式存储实现 -----

// typedef struct Queue_ElemType
//{
//
// } QElemType;
// typedef struct QNode
//{
//	QElemType data;
//	struct QNode* next;
// }QNode, * QueuePtr;
// typedef struct Link_Queue
//{
//	QueuePtr front; //队头指针
//	QueuePtr rear; //队尾指针
// }LinkQueue;

// ----- 基本操作的函数原型说明 -----

//		//构造一个空队列Q
// Status InitQueue(LinkQueue& Q);
//		//销毁队列Q，Q不再存在
// Status DestroyQueue(LinkQueue& Q);
//		//将Q清为空队列
// Status ClearQueue(LinkQueue& Q);
//		//若队列为空队列，则返回TRUE，否则返回FALSE
// Status QueueEmpty(LinkQueue Q);
//		//返回Q的元素个数，即为队列的长度
// int QueueLength(LinkQueue Q);
//		//若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
// Status GetHead(LinkQueue Q, QElemType& e);
//		//插入元素e为Q的新的队尾元素
// Status EnQueue(LinkQueue& Q, QElemType e);
//		//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
// Status DeQueue(LinkQueue& Q, QElemType& e);

// ----- 基本操作的算法描述 -----

// Status InitQueue(LinkQueue& Q)
//{
//	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
//	if (!Q.front) //存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	Q.front->next = NULL;
//	return OK;
// }
// Status DestroyQueue(LinkQueue& Q)
//{
//	while (Q.front)
//	{
//		Q.rear = Q.front->next; //用队尾指针辅助移动
//		free(Q.front);
//		Q.front = Q.rear;
//	}
//	return OK;
// }
// Status QueueEmpty(LinkQueue Q)
//{
//	if (Q.front == Q.rear)
//	{
//		return TRUE;
//	}
//	else
//	{
//		return FALSE;
//	}
// }
// int QueueLength(LinkQueue Q)
//{
//	int length = 0;
//	QueuePtr p = Q.front;
//	while (p->next)
//	{
//		p = p->next;
//		++length;
//	}
//	return length;
// }
// Status EnQueue(LinkQueue& Q, QElemType e)
//{
//	QueuePtr p;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (!p)	//存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	p->data = e;
//	p->next = NULL;
//	Q.rear->next = p;
//	Q.rear = p;
//	return OK;
// }
// Status DeQueue(LinkQueue& Q, QElemType& e)
//{
//	QueuePtr p;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (Q.front == Q.rear)
//	{
//		return ERROR;
//	}
//	p = Q.front->next;
//	e = p->data;
//	Q.front->next = p->next;
//	if (Q.rear == p) //如果被删的元素是最后一个，需要对队尾指针重新赋值(指向头结点)
//	{
//		Q.rear = Q.front;
//	}
//	free(p);
//	return OK;
// }

// ----- 循环队列——队列的顺序存储实现 -----

// #define MAXQSIZE 100 //最大队列长度
// typedef struct Squence_Queue
//{
//	QElemType* base; //初始化的动态分配存储空间
//	int front; //头指针，若队列不空，则指向队列头元素
//	int rear; //尾指针，若队列不空，指向队列尾元素的下一个位置
// }SqQueue;

// ----- 基本操作的算法描述 -----

// Status InitQueue(SqQueue& Q) //函数重载
//{
//	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
//	if (!Q.base) //存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	Q.front = Q.rear = NULL;
//	return OK;
// }
// Status QueueEmpty(SqQueue& Q)
//{
//	if (Q.rear == Q.front) //队空条件
//	{
//		return TRUE;
//	}
//	else
//	{
//		return FALSE;
//	}
// }
// int QueueLength(SqQueue Q)
//{
//	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE; //在循环队列中Q.rear - Q.front可能为负数，所以加上MAXQSIZE
// }
// Status GetHead(SqQueue& Q, QElemType& e)
//{
//	if (Q.rear == Q.front) //队空则报错
//	{
//		return FALSE;
//	}
//	e = Q.base[Q.front];
//	return TRUE;
// }
// Status EnQueue(SqQueue& Q, QElemType e)
//{
//	if ((Q.rear + 1) % MAXQSIZE == Q.front) //通过牺牲一个存储单元来判断队列是否已满
//	{
//		return ERROR;
//	}
//	Q.base[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % MAXQSIZE; //在逻辑上变成了环状，但是实际存储还是线性的
//	return OK;
// }
// Status DeQueue(SqQueue& Q, QElemType& e)
//{
//	if (Q.front == Q.rear) //队列为空
//	{
//		return ERROR;
//	}
//	e = Q.base[Q.front];
//	Q.front = (Q.front + 1) % MAXQSIZE;
//	return OK;
// }

// ===== 栈和队列的应用 =====

// 数制转换

// void conversion(int n) //对于输入的任意一个非负十进制整数，打印输出与其等值的n进制数
//{
//	InitStack(S); //构造空栈
//	scanf("%d", &N);
//	while (N)
//	{
//		Push(S, N% n);
//		N.num = N / n;
//	}
//	while (!StackEmpty(S))
//	{
//		Pop(S, e);
//		printf("%d", e);
//	}
// }

// 栈与递归的实现(n阶Hanoi塔问题)

// void hanoi(int n, char x, char y, char z)
//		//将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘按规则搬到塔座z上，y可作辅助塔座。
//		//搬动操作move(x,n,z)可定义为(c是初值为0的全局变量，对搬动计数):printf("%i.Move disk %i from %c to %c\n",++c,n,x,z);
//{
//	if (n == 1)
//	{
//		move(x, 1, z); //将编号为1的圆盘从x移到z
//	}
//	else
//	{
//		hanoi(n - 1, x, z, y); //将x上编号为1至n-1的圆盘移到y，z作为辅助塔座
//		move(x, n, z); //将编号为n的圆盘从x移到z
//		hanoi(n - 1, y, x, z); //将y上编号为1至n-1的圆盘移到z，x作为辅助塔座
//	}
// }

// 表达式求值

// #define STACK_INIT_SIZE 100 //分配栈存储空间初始量
// #define STACKINCREMENT 10 //栈存储空间分配增量
// typedef int SElemType;
// typedef struct Sequence_Stack
//{
//	SElemType* base; //栈底指针，base == NULL时表明栈不存在
//	SElemType* top; //栈顶指针，top == base可作为栈空的标志，非空栈的栈顶指针始终在栈顶元素的下一个位置上
//	SElemType stacksize; //表示栈当前可用的最大容量，以元素为单位
// }SqStack;

// ----- 基本操作的函数原型说明 -----

//		//构造一个空栈
// Status InitStack(SqStack& S);
//		//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
// SElemType GetTop(SqStack S);
//		//插入元素为e为新的栈顶元素
// Status Push(SqStack& S, SElemType e);
//		//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
// Status Pop(SqStack& S, SElemType& e);
//		//判断读入字符是否为运算符
// Status In(char e);
//		//比较运算符的优先级，a为纵轴值，b为横轴值
// SElemType Precede(char a, char b);
//		//计算a(theta)b结果
// int Operate(SElemType i, char theta, SElemType j);
//		//算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈
// SElemType EvaluateExpression();

// 表达式求值main()

// int main()
//{
//	printf("请输入算术表达式,并以#结束：");
//	printf("表达式结果是：%d", EvaluateExpression());
//	return 0;
// }

// ----- 基本操作的算法描述 -----

// Status InitStack(SqStack& S) //构造一个空栈
//{
//     S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType)); //构造一个空栈S
//     if (!S.base)
//     {
//         exit(OVERFLOW); //存储分配失败
//     }
//     S.top = S.base;
//     S.stacksize = STACK_INIT_SIZE;
//     return OK;
// }
// Status Push(SqStack& S, SElemType e) //插入元素为e为新的栈顶元素
//{
//     if (S.top - S.base >= S.stacksize) //栈满，追加存储空间
//     {
//         S.base = (SElemType*)realloc(S.base, ((S.stacksize) + STACKINCREMENT) * sizeof(SElemType));
//         if (!S.base) //存储分配失败
//         {
//             //<stdlib.h>库函数void exit(int status)立刻终止调用进程，任何属于该进程的打开的文件描述符都会被关闭
//             //该进程的子进程由进程 1 继承，初始化，且会向父进程发送一个 SIGCHLD 信号。
//             exit(OVERFLOW);
//         }
//         S.top = S.base + S.stacksize; //满栈时栈顶指针指向栈顶元素的下一个位置
//         S.stacksize += STACKINCREMENT;
//     }
//     *(S.top++) = e; //先存放，后自增
//     return OK;
// }
// Status Pop(SqStack& S, SElemType& e) //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
//{
//     if (S.top == S.base)
//     {
//         return ERROR;
//     }
//     e = *(--S.top); //先自减，再赋值
//     return OK;
// }
// SElemType GetTop(SqStack S) //若栈不空，则返回S的栈顶元素，否则返回ERROR
//{
//     if (S.top == S.base)
//     {
//         return ERROR;
//     }
//     return *(S.top - 1); //栈顶指针始终在栈顶元素的下一个位置上
// }
// Status In(char e) //判断读入字符是否为运算符
//{
//     if (e == '+' || e == '-' || e == '*' || e == '/' || e == '(' || e == ')' || e == '#')
//         return OK;
//     else
//         return ERROR;
// }
// SElemType Precede(char a, char b) //比较运算符的优先级，a为纵轴值，b为横轴值
//{
//     char f = NULL;
//     if (a == '+' || a == '-')
//     {
//         if (b == '+' || b == '-' || b == ')' || b == '#')
//             f = '>';
//         else if (b == '*' || b == '/' || b == '(')
//             f = '<';
//     }
//     else if (a == '*' || a == '/')
//     {
//         if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#')
//             f = '>';
//         else if (b == '(')
//             f = '<';
//     }
//     else if (a == '(')
//     {
//         if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
//             f = '<';
//         else if (b == ')')
//             f = '=';
//     }
//     else if (a == ')')
//     {
//         if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#')
//             f = '>';
//     }
//     else if (a == '#')
//     {
//         if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
//             f = '<';
//         else if (b == '#')
//             f = '=';
//     }
//     return f;
// }
// int Operate(SElemType i, char theta, SElemType j) //计算a(theta)b结果
//{
//     int result = NULL;
//     switch (theta)
//     {
//     case '+':
//         result = i + j;
//         break;
//     case '-':
//         result = i - j;
//         break;
//     case '*':
//         result = i * j;
//         break;
//     case '/':
//         if (j) //如果分母不为0
//         {
//             result = i / j;
//             break;
//         }
//         else
//         {
//             printf("\n分母不能为0\n");
//             break;
//         }
//     }
//     return result;
// }
// SElemType EvaluateExpression() //算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈
//{
//     SqStack OPND, OPTR;
//     SElemType a, b, theta, x, temp1 = 0, temp2 = 0; //ch为当前读入字符, theta为运算符，x仅仅只是变量寄存弹出值，对计算表达式无影响
//     char ch;
//     InitStack(OPND); //初始化OPND栈，寄存操作数和运算结果
//     InitStack(OPTR); //初始化OPTR栈，寄存运算符
//     Push(OPTR, '#');
//     ch = getchar();
//     while (ch != '#' || GetTop(OPTR) != '#')
//     {
//         if (!In(ch)) //ch不是运算符则进OPND栈
//         {
//             temp1 = ch - '0'; //数字字符转换为对应整数
//             Push(OPND, temp1);
//             temp2 = temp1; //暂时存储temp1，防止出栈之后前一个数字被丢弃找不到前一个数字
//             ch = getchar();
//             while (!In(ch)) //判断下一个字符是否仍为数字
//             {
//                 temp1 = ch - '0';
//                 temp2 = 10 * temp2 + temp1;
//                 Pop(OPND, x); //先将上一个数字出栈再将其入栈
//                 Push(OPND, temp2);
//                 ch = getchar();
//             }
//         }
//         else
//         {
//             switch (Precede(GetTop(OPTR), ch)) //优先级选择
//             {
//             case '<': //栈顶元素优先权低
//                 Push(OPTR, ch);
//                 ch = getchar();
//                 break;
//             case '>':  //退栈并将运算结果入栈
//                 Pop(OPTR, theta);
//                 Pop(OPND, b);
//                 Pop(OPND, a);
//                 Push(OPND, Operate(a, theta, b));
//                 break;
//             case '=': //脱括号并接收下一字符
//                 Pop(OPTR, x);
//                 ch = getchar();
//                 break;
//             }
//         }
//     }
//     return GetTop(OPND);
// }

// 队列实现20个随机数的分类——按照模3的余数分类

// ----- 队列的链式存储实现 -----

// typedef struct Queue_ElemType
//{
//	int num;
// } QElemType;
// typedef struct QNode
//{
//	QElemType data;
//	struct QNode* next;
// }QNode, * QueuePtr;
// typedef struct Link_Queue
//{
//	QueuePtr front; //队头指针
//	QueuePtr rear; //队尾指针
// }LinkQueue;

// ----- 基本操作的函数原型说明 -----

//			//构造一个空队列Q
// Status InitQueue(LinkQueue& Q);
//			//若队列为空队列，则返回TRUE，否则返回FALSE
// Status QueueEmpty(LinkQueue Q);
//			//返回Q的元素个数，即为队列的长度
// int QueueLength(LinkQueue Q);
//			//插入元素e为Q的新的队尾元素
// Status EnQueue(LinkQueue& Q, QElemType e);
//			//若队列不空，用e返回其值，否则返回ERROR
// int DeQueue(LinkQueue& Q);

// 队列实现20个随机数的分类——按照模3的余数分类main()

// int main(void)
//{
//	int length_Q1 = 0, length_Q2 = 0, length_Q3 = 0;
//	int n, x;
//	srand((unsigned)time(NULL));
//	QElemType random;
//	LinkQueue Q1, Q2, Q3;
//	InitQueue(Q1);
//	InitQueue(Q2);
//	InitQueue(Q3);
//	printf("系统产生的随机数为:\n");
//	for (n = 0; n < 20; n++)
//	{
//		x = rand() % 100;
//		random.num = x;
//		printf("%d\n", x);
//		if (!(x % 3))
//		{
//			EnQueue(Q1, random);
//		}
//		else if (x % 3 == 1)
//		{
//			EnQueue(Q2, random);
//		}
//		else
//		{
//			EnQueue(Q3, random);
//		}
//	}
//	length_Q1 = QueueLength(Q1);
//	length_Q2 = QueueLength(Q2);
//	length_Q3 = QueueLength(Q3);
//	printf("\nQ1队中的随机数为\n");
//	while (!QueueEmpty(Q1))
//	{
//		printf("%d ", DeQueue(Q1));
//	}
//	printf("\nQ1队列中元素个数为:%d\n", length_Q1);
//	printf("\nQ2队中的随机数为\n");
//	while (!QueueEmpty(Q2))
//	{
//		printf("%d ", DeQueue(Q2));
//	}
//	printf("\nQ2队列中元素个数为:%d\n", length_Q2);
//	printf("\nQ3队中的随机数为\n");
//	while (!QueueEmpty(Q3))
//	{
//		printf("%d ", DeQueue(Q3));
//	}
//	printf("\nQ3队列中元素个数为:%d\n", length_Q3);
//	return 0;
// }

// ----- 基本操作的算法描述 -----

// Status InitQueue(LinkQueue& Q)
//{
//	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
//	if (!Q.front) //存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	Q.front->next = NULL;
//	return OK;
// }
// Status QueueEmpty(LinkQueue Q)
//{
//	if (Q.front == Q.rear)
//	{
//		return TRUE;
//	}
//	else
//	{
//		return FALSE;
//	}
// }
// int QueueLength(LinkQueue Q)
//{
//	int length = 0;
//	QueuePtr p = Q.front;
//	while (p->next)
//	{
//		p = p->next;
//		++length;
//	}
//	return length;
// }
// Status EnQueue(LinkQueue& Q, QElemType e)
//{
//	QueuePtr p;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (!p)	//存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	p->data = e;
//	p->next = NULL;
//	Q.rear->next = p;
//	Q.rear = p;
//	return OK;
// }
// int DeQueue(LinkQueue& Q)
//{
//	QueuePtr p;
//	int e;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (Q.front == Q.rear)
//	{
//		return ERROR;
//	}
//	p = Q.front->next;
//	e = p->data.num;
//	Q.front->next = p->next;
//	if (Q.rear == p) //如果被删的元素是最后一个，需要对队尾指针重新赋值(指向头结点)
//	{
//		Q.rear = Q.front;
//	}
//	free(p);
//	return e;
// }

// ===== 数组和广义表 =====

// ----- 数组的顺序存储表示 -----

// #include <stdarg.h> //标准头文件，提供宏va_start、va_arg和va_end，用于存取变长参数表
// #define MAX_ARRAY_DIM 8 //假设数组维数的最大值为8
// typedef int ElemType;
// typedef struct Seq_Array
//{
//	ElemType* base; //数组元素基址，由InitArray分配
//	int dim; //数组维数
//	int* bounds; //各维长度组成的一维数组的基址，数组维界基址，由InitArray分配
//	int* constants; //常量组成的一维数组，用于计算数组的某个元素的存储位置的一组常量，数组映像函数常量基址，由InitArray分配
// }Array;

// ----- 基本操作的函数原型说明 -----

//		//若维数dim和随后的各维长度合法，则构造相应的数组A，并返回OK
// Status InitArray(Array& A, int dim, ...);
//		//销毁数组A
// Status DestroyArray(Array& A);
//		//A是n维数组，e为元素变量，随后是n个下标值，若各下标值不超界，则e赋值为所指定的A的元素值，并返回OK
// Status Value(ElemType& e, Array A, ...);
//		//A是n维数组，e为元素变量，随后是n个下标值，若各下标值不超界，则将e的值赋所指定的A的元素，并返回OK
// Status Assign(Array& A, ElemType e, ...);
//		//若ap指示的各下标值合法，则求出该元素在A中相对地址off
// Status Locate(Array A, va_list ap, int& off);

// 建立一个三维数组，实现数组在以行序优先的存储结构，各维的长度由用户从键盘输入

// int main()
//{
//	Array A;
//	int dim = 3, length, width, height, x, y, z, i = 0;
//	printf("创建三维数组A:\n请输入三维数组的各维度长度:");
//	scanf("%d%d%d", &length, &width, &height);
//	InitArray(A, dim, length, width, height);
//	printf("\nA.bounds = %d %d %d", A.bounds[0], A.bounds[1], A.bounds[2]);
//	printf("\nA.constants = %d %d %d", A.constants[0], A.constants[1], A.constants[2]);
//	printf("\n%d页%d行%d列矩阵元素如下:\n",length,width,height);
//	for (x = 0; x < length; x++)
//	{
//		for (y = 0; y < width; y++)
//		{
//			for (z = 0; z < height; z++)
//			{
//				A.base[i] = z + 10 * y + 100 * x;
//				printf("A[%d][%d][%d] = %d ",x,y,z,A.base[i]);
//				i++;
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//	DestroyArray(A);
//	return 0;
// }

// ----- 基本操作的算法描述 -----

// Status InitArray(Array& A, int dim, ...)
//{
//	if (dim<1 || dim>MAX_ARRAY_DIM)
//	{
//		return ERROR;
//	}
//	A.dim = dim;
//	A.bounds = (int*)malloc(dim * sizeof(int));
//	if (!A.bounds)
//	{
//		exit(OVERFLOW);
//	}
//	int elemtotal = 1, i; //若各维长度合法，则存入A.bounds，并求出A的元素总数elemtotal;
//	va_list ap;
//	va_start(ap, dim); //ap为va_list类型，是存放变长参数表信息的数组
//	for (i = 0; i < dim; i++)
//	{
//		A.bounds[i] = va_arg(ap, int); //[i]可以理解为相对于指针初始地址的偏移量
//		if (A.bounds[i] < 0)
//		{
//			return UNDERFLOW;
//		}
//		elemtotal *= A.bounds[i];
//	}
//	va_end(ap);
//	A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType));
//	if (!A.base)
//	{
//		exit(OVERFLOW);
//	}
//	A.constants = (int*)malloc(dim * sizeof(int)); //求映像函数的常数ci，并存入A.constants[i-1]，i = 1,...,dim
//	if (!A.constants)
//	{
//		exit(OVERFLOW);
//	}
//	A.constants[dim - 1] = 1; //L代表存储单元，L = 1，指针的增减以元素的大小为单位
//	for (i = dim - 2; i >= 0; --i)
//	{
//		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
//	}
//	return OK;
// }
// Status DestroyArray(Array& A)
//{
//	if (!A.base)
//	{
//		return ERROR;
//	}
//	free(A.base);
//	A.base = NULL;
//	if (A.bounds)
//	{
//		return ERROR;
//	}
//	free(A.bounds);
//	A.bounds = NULL;
//	if (A.constants)
//	{
//		return ERROR;
//	}
//	free(A.constants);
//	A.constants = NULL;
//	return OK;
// }
// Status Locate(Array A, va_list ap, int& off)
//{
//	off = 0;
//	int i;
//	for (i = 0; i < A.dim; i++)
//	{
//		int ind = va_arg(ap, int); //ind == index下标
//		if (ind < 0 || ind >= A.bounds[i])
//		{
//			return OVERFLOW;
//		}
//		off += A.constants[i] * ind;
//	}
//	return OK;
// }
// Status Value(ElemType& e, Array A, ...)
//{
//	va_list ap;
//	va_start(ap, A);
//	int result, off;
//	if ((result = Locate(A, ap, off)) <= 0)
//	{
//		return result;
//	}
//	e = *(A.base + off);
//	return OK;
// }
// Status Assign(Array& A, ElemType e, ...)
//{
//	va_list ap;
//	va_start(ap, e);
//	int result, off;
//	if ((result = Locate(A, ap, off)) <= 0)
//	{
//		return result;
//	}
//	*(A.base + off) = e;
//	return OK;
// }

//----- 稀疏矩阵的三元组顺序表存储表示 -----

// #define MAXSIZE 125 //假设非零元个数的最大值为125
// #define MAX_COL_MATRIX_M 20 //矩阵M的最大列数假定为20
// typedef int ElemType;
// typedef struct Matric_Triple
//{
//	int i, j; //该非零元的行下标和列下标
//	ElemType e;
// }Triple;
// typedef struct TSMatrix
//{
//	Triple data[MAXSIZE + 1]; //非零元三元组表，data[0]未用
//	int mu, nu, tu; //矩阵的行数、列数和非零元个数
// }TSMatrix;

// ----- 基本操作的函数原型说明 -----

//		//创建稀疏矩阵
// Status CreateSMatrix(TSMatrix& M, int row, int col, int num);
//		//若稀疏矩阵存在，销毁稀疏矩阵
// Status DestroySMatrix(TSMatrix& M);
//		//若稀疏矩阵存在，输出稀疏矩阵
// Status PrintSMatrix(TSMatrix& M);
//		//若稀疏矩阵M存在，由稀疏矩阵M复制得到T
// Status CopySMatrix(TSMatrix M, TSMatrix& T);
//		//若稀疏矩阵M与N的行数和列数对应相等，则求稀疏矩阵的和Q = M + N
// Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix& Q);
//		//若稀疏矩阵M与N的行数和列数对应相等，则求稀疏矩阵的差Q = M - N
// Status SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix& Q);
//		//若稀疏矩阵M的列数等于N的行数，则求稀疏矩阵乘积Q = M * N
// Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix& Q);
//		//采用三元组表存储表示，求稀疏矩阵M的转置矩阵T，算法复杂度为O(nu*tu)
// Status TransposeSMatrix(TSMatrix M, TSMatrix& T);
//		//快速转置，采用三元组表存储表示，求稀疏矩阵M的转置矩阵T，算法复杂度为O(nu+tu)
// Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T);

// ----- 基本操作的算法描述 -----

// Status CreateSMatrix(TSMatrix& M, int row, int col , int num)
//{
//	if (num) //如果存在非零元素
//	{
//		M.mu = row;
//		M.nu = col;
//		M.tu = num;
//		int elem_num;
//		for (elem_num = 1; elem_num <= num; elem_num++)
//		{
//			printf("请按行序顺序输入第%d个非零元素所在的行<1~%d>，列<1~%d>，元素值:", elem_num, row, col);
//			scanf("%d%d%d", &M.data[elem_num].i, &M.data[elem_num].j, &M.data[elem_num].e);
//		}
//		return OK;
//	}
//	else
//	{
//		M.mu = row;
//		M.nu = col;
//		M.tu = 0;
//		return ERROR;
//	}
// }
// Status PrintSMatrix(TSMatrix& M)
//{
//	if (M.tu) //如果存在非零元素
//	{
//		printf("\n稀疏矩阵对应的三元组表为:\n");
//		printf("%d行%d列%d个非零元素\n", M.mu, M.nu, M.tu);
//		printf("行\t列\t元素值\n");
//		int i;
//		for (i = 1; i <= M.tu; i++)
//		{
//			printf("%d\t%d\t%d\n", M.data[i].i, M.data[i].j, M.data[i].e);
//		}
//		return OK;
//	}
//	else
//	{
//		return ERROR;
//	}
// }
// Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix& Q)
//{
//	if (N.tu || M.tu) //如果两个矩阵至少有一个非零元素
//	{
//		Q.mu = M.mu;
//		Q.nu = M.mu;
//		int n = 1, m = 1, count = 1, flag = 0; //flag用于标志相同的代码段，减少代码长度；count用于计算矩阵Q的非零元素个数
//		while (m <= M.tu) //遍历矩阵M的非零元素并与矩阵N相加
//		{
//			if (M.data[m].i < N.data[n].i) //先比较矩阵M、N的非零元素的行号
//			{
//				flag = 1;
//			}
//			else if (M.data[m].i > N.data[n].i)
//			{
//				flag = -1;
//			}
//			else //M.data[m].i == N.data[n].i
//			{
//				if (M.data[m].j < N.data[n].j) //如果行号相等，再比较矩阵M、N的非零元素的列号
//				{
//					flag = 1;
//				}
//				else if (M.data[m].j > N.data[n].j)
//				{
//					flag = -1;
//				}
//				else //M.data[m].j == N.data[n].j
//				{
//					int sum = M.data[m].e + N.data[n].e;
//					if (sum) //判断同行同列的元素和是否为0，为0则不将元素和存储在Q中
//					{
//						Q.data[count].i = M.data[m].i;
//						Q.data[count].j = M.data[m].j;
//						Q.data[count].e = sum;
//						count++;
//					}
//					n++;
//					m++;
//				}
//			}
//			if (flag == 1) //flag = 1时，将矩阵M的非零元素放入Q中
//			{
//				Q.data[count].i = M.data[m].i;
//				Q.data[count].j = M.data[m].j;
//				Q.data[count].e = M.data[m].e;
//				count++;
//				m++;
//			}
//			else if (flag == -1) //flag = -1时，将矩阵N的非零元素放入Q中
//			{
//				Q.data[count].i = N.data[n].i;
//				Q.data[count].j = N.data[n].j;
//				Q.data[count].e = N.data[n].e;
//				count++;
//				n++;
//			}
//		}
//		while (m <= M.tu) //把矩阵M剩余的非零元素加到Q中
//		{
//			Q.data[count].i = M.data[m].i;
//			Q.data[count].j = M.data[m].j;
//			Q.data[count].e = M.data[m].e;
//			count++;
//			m++;
//		}
//		while (n <= N.tu) //把矩阵N剩余的非零元素加到Q中
//		{
//			Q.data[count].i = N.data[n].i;
//			Q.data[count].j = N.data[n].j;
//			Q.data[count].e = N.data[n].e;
//			count++;
//			n++;
//		}
//		Q.tu = count - 1; //在最后一次count会多自增一次
//		return OK;
//	}
//	else
//	{
//		return ERROR;
//	}
// }
// Status TransposeSMatrix(TSMatrix M, TSMatrix& T)
//{
//	T.mu = M.nu;
//	T.nu = M.mu;
//	T.tu = M.tu;
//	if (T.tu)
//	{
//		int q = 1, col, p;
//		for (col = 1; col <= M.nu; ++col) //遍历矩阵M的所有列
//		{
//			for (p = 1; p <= M.tu; ++p) //遍历矩阵M的所有非零元素
//			{
//				if (M.data[p].j == col) //转置
//				{
//					T.data[q].i = M.data[p].j;
//					T.data[q].j = M.data[p].i;
//					T.data[q].e = M.data[p].e;
//					++q;
//				}
//			}
//		}
//		return OK;
//	}
//	else
//	{
//		return ERROR;
//	}
// }
// Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T)
//{
//	T.mu = M.nu;
//	T.nu = M.mu;
//	T.tu = M.tu;
//	//num[col]表示矩阵M中第col列中非零元的个数，cpot[col]指示M中第col列的第一个非零元在M.data中的恰当位置
//	int col, num[MAX_COL_MATRIX_M] = { 0 }, t, cpot[MAX_COL_MATRIX_M] = { 0 }, p, q;
//	if (T.tu)
//	{
//		for (t = 1; t <= M.tu; ++t)
//		{
//			++num[M.data[t].j]; //求M中每一列含非零元个数
//		}
//		cpot[1] = 1;
//		for (col = 2; col <= M.nu; ++col) //求第col列中第一个非零元在M.data中的序号
//		{
//			cpot[col] = cpot[col - 1] + num[col - 1]; //非零元个数 + 第col-1列的第一个非零元位置 = 第col列的第一个非零元的相对位置
//		}
//		for (p = 1; p <= M.tu; p++)
//		{
//			col = M.data[p].j;
//			q = cpot[col];
//			T.data[q].i = M.data[p].j;
//			T.data[q].j = M.data[p].i;
//			T.data[q].e = M.data[p].e;
//			++cpot[col]; //移动到矩阵T中下一个非零元存储位置
//		}
//		return OK;
//	}
//	else
//	{
//		return ERROR;
//	}
// }

// 稀疏矩阵三元组的转置和求和main()

// int main()
//{
//	int col, row, num;
//	printf("创建矩阵M:\n请输入矩阵的行数，列数，非零元数:");
//	scanf("%d%d%d", &row, &col, &num);
//	TSMatrix M, N, Q;
//	CreateSMatrix(M, row, col, num);
//	PrintSMatrix(M);
//	printf("\n矩阵N<M的转置>:\n");
//	FastTransposeSMatrix(M, N);
//	PrintSMatrix(N);
//	printf("\n矩阵Q<M+N>:\n");
//	AddSMatrix(M, N, Q);
//	PrintSMatrix(Q);
//	return 0;
// }

// ===== 树和二叉树 =====

// ----- 树的孩子表链表示法的存储结构 -----

// #define MAX_TREE_SIZE 100
// typedef char TElemType;
//
// typedef struct CTNode
//{
//	int child;
//	struct CTNode* next;
// }*ChildPtr;
// typedef struct
//{
//	TElemType data;
//	ChildPtr firstchild;
// }CTBox;
// typedef struct
//{
//	CTBox nodes[MAX_TREE_SIZE];
//	int n, r;	//节点数、边数
// }CTree;

// ----- 二叉树的二叉链表存储表示 -----

// typedef char TElemType;
// typedef struct BiTNode
//{
//	TElemType data;
//	struct BiTNode* lchild, * rchild; //左右孩子指针
// }BiTNode, * BiTree;

//----- 栈的顺序存储实现 -----

// #define STACK_INIT_SIZE 100 //分配栈存储空间初始量
// #define STACKINCREMENT 10 //栈存储空间分配增量
// #define STACK_SIZE 100
// typedef BiTree SElemType;
// typedef struct Sequence_Stack
//{
//	SElemType* base; //栈底指针，base == NULL时表明栈不存在
//	SElemType* top; //栈顶指针，top == base可作为栈空的标志，非空栈的栈顶指针始终在栈顶元素的下一个位置上
//	int stacksize; //表示栈当前可用的最大容量，以元素为单位
// }SqStack;

//----- 基本操作的函数原型说明 -----

//		//构造一个空栈
// Status InitStack(SqStack& S);
//		//若栈S为空栈，则返回TRUE，否则返回FALSE
// Status StackEmpty(SqStack S);
//		//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
// Status GetTop(SqStack S, SElemType& e);
//		//插入元素为e为新的栈顶元素
// Status Push(SqStack& S, SElemType e);
//		//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
// Status Pop(SqStack& S, SElemType& e);

//----- 基本操作的算法描述 -----

// Status InitStack(SqStack& S)
//{
//	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType)); //构造一个空栈S
//	if (!S.base)
//	{
//		exit(OVERFLOW); //存储分配失败
//	}
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
// }
// Status GetTop(SqStack S, SElemType& e)
//{
//	if (S.top == S.base)
//	{
//		return ERROR;
//	}
//	e = *(S.top - 1); //栈顶指针始终在栈顶元素的下一个位置上
//	return OK;
// }
// Status Push(SqStack& S, SElemType e)
//{
//	if (S.top - S.base >= S.stacksize) //栈满，追加存储空间
//	{
//		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
//
//		if (!S.base) //存储分配失败
//		{
//			//<stdlib.h>库函数void exit(int status)立刻终止调用进程，任何属于该进程的打开的文件描述符都会被关闭
//			//该进程的子进程由进程 1 继承，初始化，且会向父进程发送一个 SIGCHLD 信号。
//			exit(OVERFLOW);
//		}
//		S.top = S.base + S.stacksize; //满栈时栈顶指针指向栈顶元素的下一个位置
//		S.stacksize += STACKINCREMENT;
//	}
//	*S.top++ = e; //先存放，后自增
//	return OK;
// }
// Status Pop(SqStack& S, SElemType& e)
//{
//	if (S.top == S.base)
//	{
//		return ERROR;
//	}
//	e = *--S.top; //先自减，再赋值
//	return OK;
// }
// Status StackEmpty(SqStack S)
//{
//	if (S.top == S.base)
//	{
//		return OK;
//	}
//	return ERROR;
// }

// ----- 基本操作的函数原型说明 -----

//		//按先序次序输入二叉树中结点的值(一个字符)，空格字符表示空树，构造二叉链表表示的二叉树T
// Status CreateBiTree(BiTree& T);
//		//采用二叉链表存储结构，Visit是对结点操作的应用函数，先序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。一旦Visit()失败，则操作失败
// Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//		//采用二叉链表存储结构，Visit是对结点操作的应用函数，中序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。一旦Visit()失败，则操作失败
// Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//		//采用二叉链表存储结构，Visit是对结点操作的应用函数，后序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。一旦Visit()失败，则操作失败
// Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//		//采用二叉链表存储结构，Visit是对结点操作的应用函数，层序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。一旦Visit()失败，则操作失败
// Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//		//打印元素e的值
// Status PrintElement(TElemType e);

// ----- 基本操作的算法描述 -----

// Status CreateBiTree(BiTree& T)
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '.')
//	{
//		T = NULL;
//	}
//	else
//	{
//		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
//		{
//			exit(OVERFLOW);
//		}
//		T->data = ch; //生成根结点
//		CreateBiTree(T->lchild); //构造左子树
//		CreateBiTree(T->rchild); //构造右子树
//	}
//	return OK;
// }
//			//调用示例：PreOrderTraverse(T,PrintElement);
// Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) //递归算法
//{
//	if (T)
//	{
//		if (Visit(T->data))
//		{
//			if (PreOrderTraverse(T->lchild, Visit))
//			{
//				if (PreOrderTraverse(T->rchild, Visit))
//				{
//					return OK;
//				}
//			}
//		}
//		return ERROR;
//	}
//	else
//	{
//		return OK;
//	}
// }
// Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) //非递归算法
//{
//	SqStack S;
//	BiTNode* p;
//	InitStack(S);
//	Push(S, T); //根指针进栈
//	while (!StackEmpty(S))
//	{
//		while (GetTop(S, p) && p) //向左走到尽头
//		{
//			Push(S, p->lchild);
//		}
//		Pop(S, p); //空指针退栈
//		if (!StackEmpty(S)) //访问结点，向右一步
//		{
//			Pop(S, p);
//			if (!Visit(p->data))
//			{
//				return ERROR;
//			}
//			Push(S, p->rchild);
//		}
//	}
//	return OK;
// }
// Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) //另外一种非递归算法
//{
//	SqStack S;
//	BiTNode* p;
//	InitStack(S);
//	p = T;
//	while (p || !StackEmpty(S)) //p或Stack不为空
//	{
//		if (p) //根指针进栈，遍历左子树
//		{
//			Push(S, p);
//			p = p->lchild;
//		}
//		else //根退栈，访问根结点，遍历右子树
//		{
//			Pop(S, p); //弹栈，将p指向被弹结点
//			if (!Visit(p->data)) //所访问结点不存在
//			{
//				return ERROR;
//			}
//			p = p->rchild;
//		}
//	}
//	return OK; //p为空并且Stack为空
// }
// Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) //递归算法
//{
//	if (T)
//	{
//		if (PostOrderTraverse(T->lchild, Visit))
//		{
//			if (PostOrderTraverse(T->rchild, Visit))
//			{
//				if (Visit(T->data))
//				{
//					return OK;
//				}
//			}
//		}
//		return ERROR;
//	}
//	else
//	{
//		return OK;
//	}
// }
// Status PrintElement(TElemType e)
//{
//	printf("%c ", e);
//	return OK;
// }
// BiTree FindNode(BiTree T, TElemType e) //查找值为e的结点，递归算法，还可以改进一下，判断二叉树中是否存在该元素
//{
//	if (!T) //判断树是否为空
//	{
//		return NULL;
//	}
//	if (T->data == e)
//	{
//		return T;
//	}
//	else
//	{
//		if (FindNode(T->lchild, e)) //左子树查找
//		{
//			return FindNode(T->lchild, e);
//		}
//		else //右子树查找
//		{
//			return FindNode(T->rchild, e);
//		}
//	}
// }
// int TreeDepth(BiTree T) //递归算法计算二叉树的深度
//{
//	if (!T)
//	{
//		return 0;
//	}
//	int ldepth, rdepth, len;
//	ldepth = TreeDepth(T->lchild); //左子树的深度
//	rdepth = TreeDepth(T->rchild); //右子树的深度
//	len = (ldepth > rdepth) ? (ldepth) : (rdepth); //判断左右子树的高度大小
//	//树的高度是从根结点到叶子结点的最长路径上结点数量，所以子树的深度加上根节点的高度就是树的高度
//	return 1 + len;
// }

// ----- main() -----

// int main(void)
//{
//	BiTNode* T;
//	printf("请按照先序输入要创建的二叉树，空结点以'.'代替:\n");
//	CreateBiTree(T); //递归先序构造二叉树
//	printf("递归先序遍历二叉树:");
//	PreOrderTraverse(T, PrintElement); //递归先序遍历二叉树
//	printf("\n非递归中序遍历二叉树:");
//	InOrderTraverse(T, PrintElement); //非递归中序遍历二叉树
//	printf("\n递归后序遍历二叉树:");
//	PostOrderTraverse(T, PrintElement); //递归后序遍历二叉树
//	getchar(); //消除输入结点之后缓冲区中残留的回车
//	TElemType e;
//	printf("\n请输入要查找的元素:");
//	scanf("%c", &e);
//	printf("\n所要查找的元素为%c", FindNode(T, e)->data); //查找值为e的结点
//	printf("\n树的深度为:%d", TreeDepth(T)); //求二叉树的高度
//	return 0;
// }

// ----- 二叉树的二叉线索存储表示 -----

// typedef char TElemType;
// typedef enum PointerTag { Link, Thread }; //Link == 0:指针,Thread == 1:线索
// typedef struct BiThrNode
//{
//	TElemType data;
//	struct BiThrNode* lchild, * rchild; //左右孩子指针
//	PointerTag LTag, RTag; //左右标志
// }BiThrNode, * BiThrTree;
// BiThrTree pre_1 = NULL; //pre_1作为全局变量便于在先序线索化的不同函数之间使用
// BiThrTree pre = NULL; //pre作为全局变量便于在中序线索化的不同函数之间使用

// ----- 基本操作的函数原型说明 -----

//		//线索化二叉树的创建，含初始化LTag和RTag
// Status ThrtCreateBiTree(BiThrTree& T);
//		//打印二叉树存储的数据
// Status PrintElement(TElemType e);
//		//以结点p为根的子树先序线索化
// void PreThreading(BiThrTree p);
//		//带头结点的二叉树先序线索化
// Status PreOrderThreading(BiThrTree& Thrt, BiThrTree T);
//		//Thrt指向头结点，头结点的左链lchild指向根结点，先序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit
// Status PreOrderTraverse_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e));
//		//中序线索化二叉树
// void InThreading(BiThrTree p);
//		//中序遍历二叉树T，并将其中序线索化，Thrt指向线索化后的树的头结点
// Status InOrderThreading(BiThrTree& Thrt, BiThrTree T);
//		//Thrt指向头结点，头结点的左链lchild指向根结点，中序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit
// Status InOrderTraverse_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e));

// ----- 基本操作的算法描述 -----

// Status ThrtCreateBiTree(BiThrTree& T) //线索化二叉树的创建，含初始化LTag和RTag
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '.')
//	{
//		T = NULL;
//		return ERROR;
//	}
//	else
//	{
//		if (!(T = (BiThrNode*)malloc(sizeof(BiThrNode))))
//		{
//			exit(OVERFLOW);
//		}
//		T->data = ch; //生成根结点
//		//构造左子树，如果存在左子树则赋值RTag为Link，否则赋值为Thread
//		(ThrtCreateBiTree(T->lchild)) ? (T->LTag = Link) : (T->LTag = Thread);
//		//构造右子树，如果存在右子树则赋值RTag为Link，否则赋值为Thread
//		(ThrtCreateBiTree(T->rchild)) ? (T->RTag = Link) : (T->RTag = Thread);
//	}
//	return OK;
// }
// Status PrintElement(TElemType e)
//{
//	printf("%c ", e);
//	return OK;
// }
// void PreThreading(BiThrTree p) //以结点p为根的子树先序线索化
//{
//	if (p) //p非空
//	{
//		//由于在创建二叉树的时候已经将LTag和RTag初始化了，所以在线索化的过程中不需要再次进行初始化
//		if (p->LTag == Thread) //如果p的左孩子为空，则建前驱线索
//		{
//			p->lchild = pre_1; //指向前驱结点
//		}
//		if (pre_1->RTag == Thread) //如果pre_1的右孩子为空，则建后继线索
//		{
//			pre_1->rchild = p; //指向后继结点
//		}
//		pre_1 = p; //保持pre指向p的前驱
//		if (p->LTag == Link) //只有结点有左孩子的时候才遍历左子树，否则会陷入死循环
//		{
//			PreThreading(p->lchild); //左子树线索化
//		}
//		if (p->RTag == Link) //同上
//		{
//			PreThreading(p->rchild); //右子树线索化
//		}
//	}
// }
// Status PreOrderThreading(BiThrTree& Thrt, BiThrTree T) //带头结点的二叉树先序线索化
//{
//	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
//	{
//		exit(OVERFLOW);
//	}
//	Thrt->LTag = Link; //有左子树
//	Thrt->RTag = Thread; //建头结点
//	Thrt->rchild = Thrt; //右指针回指
//	if (!T) //若二叉树空，则左指针回指
//	{
//		Thrt->lchild = Thrt;
//	}
//	else
//	{
//		Thrt->lchild = T; //左指针指向T
//		pre_1 = Thrt; //全局变量pre（T的前驱）赋初值
//		PreThreading(T); //先序遍历进行先序线索化
//		pre_1->rchild = Thrt;
//		pre_1->RTag = Thread; //最后一个结点线索化
//		Thrt->rchild = pre_1; //形成闭环
//	}
// }
////Thrt指向头结点，头结点的左链lchild指向根结点，先序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit
// Status PreOrderTraverse_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e))
//{
//	BiThrNode* p = Thrt->lchild; //p指向根节点
//	while (p != Thrt) //空树或遍历结束时，p == Thrt
//	{
//		Visit(p->data);
//		//判断左孩子是否存在，只要左孩子不存在，就访问右孩子，即使右孩子不存在也能访问到后继结点
//		(p->LTag == Link) ? (p = p->lchild) : (p = p->rchild);
//	}
//	return OK;
// }
// void InThreading(BiThrTree p) //中序线索化二叉树
//{
//	if (p) //p非空
//	{
//		InThreading(p->lchild); //左子树线索化
//		//由于在创建二叉树的时候已经将LTag和RTag初始化了，所以在线索化的过程中不需要再次进行初始化
//		//将其分为p的左孩子和pre的右孩子而不是分为p的左右孩子是为了方便建立前驱和后继
//		if (p->LTag == Thread) //如果p的左孩子为空，则建前驱线索
//		{
//			p->lchild = pre;
//		}
//		if (pre->RTag == Thread) //如果pre的右孩子为空，则建后继线索
//		{
//			pre->rchild = p; //这样更容易建立后继结点
//		}
//		pre = p; //保持pre指向p的前驱
//		InThreading(p->rchild); //右子树线索化
//	}
// }
// Status InOrderThreading(BiThrTree& Thrt, BiThrTree T) //中序遍历二叉树T，并将其中序线索化，Thrt指向线索化后的树的头结点
//{
//	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
//	{
//		exit(OVERFLOW);
//	}
//	Thrt->LTag = Link;
//	Thrt->RTag = Thread; //建头结点
//	Thrt->rchild = Thrt; //右指针回指
//	if (!T) //若二叉树空，则左指针回指
//	{
//		Thrt->lchild = Thrt;
//	}
//	else
//	{
//		Thrt->lchild = T;
//		pre = Thrt; //全局变量pre（T的前驱）赋初值
//		InThreading(T); //中序遍历进行中序线索化
//		pre->rchild = Thrt;
//		pre->RTag = Thread; //最后一个结点线索化
//		Thrt->rchild = pre; //形成闭环
//	}
//	return OK;
// }
////Thrt指向头结点，头结点的左链lchild指向根结点，中序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit
// Status InOrderTraverse_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e))
//{
//	BiThrNode* p = Thrt->lchild; //p指向根节点
//	while (p != Thrt) //空树或遍历结束时，p == Thrt
//	{
//		while (p->LTag == Link) //中序遍历，找最左下结点
//		{
//			p = p->lchild;
//		}
//		if (!Visit(p->data)) //访问其左子树为空的结点
//		{
//			return ERROR;
//		}
//		while (p->RTag == Thread && p->rchild != Thrt) //访问后继结点
//		{
//			p = p->rchild;
//			Visit(p->data);
//		}
//		p = p->rchild; //p进至其右子树根
//	}
//	return OK;
// }

// ----- main() -----

// int main()
//{
//	BiThrNode* In_T, * In_Thrt;
//	printf("请按照先序输入要创建的二叉树，空结点以'.'代替:\n");
//	ThrtCreateBiTree(In_T); //递归先序构造二叉树
//	InOrderThreading(In_Thrt, In_T); //建立中序线索二叉树
//	printf("\n中序遍历线索二叉树:");
//	InOrderTraverse_Thr(In_Thrt, PrintElement); //中序遍历线索二叉树
//	getchar(); //消除缓冲区中残余的换行符/空格
//	BiThrNode* Pre_T, * Pre_Thrt;
//	printf("\n请按照先序输入要创建的二叉树，空结点以'.'代替:\n");
//	ThrtCreateBiTree(Pre_T);
//	PreOrderThreading(Pre_Thrt, Pre_T); //建立先序线索二叉树
//	printf("\n先序遍历线索二叉树:");
//	PreOrderTraverse_Thr(Pre_Thrt, PrintElement); //先序遍历二叉树
//	return 0;
// }

// ----- 哈夫曼树和哈夫曼编码的存储表示 -----

// #define MAX 100	//假设数组序号最大值为100
// typedef struct
//{
//	 int weight;	//权值
//	 int parent, lchild, rchild;	//双亲、左右孩子下标
// }HTNode, * HuffmanTree;	//动态分配数组存储哈夫曼树
// typedef char** HuffmanCode;	//全局变量，动态分配数组存储哈夫曼编码表
// void Select(HuffmanTree HT, int k, int& s1, int& s2)	//在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
//{
//	int i, min1 = MAX, min2 = MAX;
//	s1 = s2 = 0;
//	for (i = 1; i <= k; i++)
//	{
//		if (HT[i].parent == 0)
//		{
//			if (HT[i].weight < min1)
//			{
//				min2 = min1;
//				s2 = s1;
//				min1 = HT[i].weight;
//				s1 = i;
//			}
//			else if (HT[i].weight < min2)
//			{
//				min2 = HT[i].weight;
//				s2 = i;
//			}
//		}
//	}
//	return;
// }
// void Create_HuffmanTree(HuffmanTree& HT, int* w, int n)
//{	//创建哈夫曼树
//	if (n <= 1)	//叶子结点数不够
//	{
//		return;
//	}
//	int m = 2 * n - 1, i;
//	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));	//0号单元未用
//	for (i = 1; i <= n; ++i)
//	{
//		HT[i].weight = w[i-1];
//		HT[i].lchild = HT[i].rchild = HT[i].parent = 0;
//	}
//	for (i = n + 1; i <= m; ++i)
//	{
//		HT[i].weight = HT[i].lchild = HT[i].rchild = HT[i].parent = 0;
//	}
//	for (i = n + 1; i <= m; i++)	//建哈夫曼树
//	{	//在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
//		int s1, s2;
//		Select(HT, i - 1, s1, s2);
//		HT[s1].parent = HT[s2].parent = i;
//		HT[i].lchild = s1;
//		HT[i].rchild = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;
//	}
//	return;
// }
// void HuffmanCoding_FromLeafToRoot(HuffmanTree& HT, HuffmanCode& HC, int n)	//从叶子出发遍历哈夫曼树求哈夫曼编码
//{	//从叶子结点到根逆向求每个字符的哈夫曼编码
//	int m = 2 * n - 1, i;
//	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));	//分配n个字符编码的头指针向量，0号未用
//	char* cd = (char*)malloc(n * sizeof(char));	//分配求编码的工作空间
//	cd[n - 1] = '\0';	//编码结束符
//	for (i = 1; i <= n; i++)
//	{	//逐个字符求哈夫曼编码
//		int start = n - 1;	//编码结束符位置
//		int c, f;
//		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)	//从叶子到根逆向求编码
//		{
//			(HT[f].lchild == c) ? (cd[--start] = '0') : (cd[--start] = '1');
//		}
//		HC[i] = (char*)malloc((n - start) * sizeof(char));	//为第i个字符编码分配空间
//		strcpy(HC[i], &cd[start]);	//从cd复制编码(串)到HC
//	}
//	free(cd);	//释放工作空间
// }
// void HuffmanCoding_FromRootToLeaf(HuffmanTree& HT, HuffmanCode& HC, int n)	//从根出发遍历哈夫曼树求哈夫曼编码
//{	//无栈非递归遍历哈夫曼树，求哈夫曼编码
//	int m = 2 * n - 1, i, k = m, cdlen = 0;
//	char* cd = (char*)malloc(n * sizeof(char));	//分配求编码的工作空间
//	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));	//分配n个字符编码的头指针向量，0号未用
//	for (i = 1; i <= m; ++i)
//	{
//		HT[i].weight = 0;	//遍历哈夫曼树时用作结点状态标志
//	}
//	while (k)
//	{
//		if (HT[k].weight == 0)
//		{	//向左
//			HT[k].weight = 1;
//			if (HT[k].lchild != 0)	//有左孩子
//			{
//				k = HT[k].lchild;
//				cd[cdlen++] = '0';
//			}
//			else if (HT[k].rchild == 0)	//没有左孩子且没有右孩子
//			{	//登记叶子结点的字符的编码
//				HC[k] = (char*)malloc((cdlen + 1) * sizeof(char));
//				cd[cdlen] = '\0';
//				strcpy(HC[k], cd);	//复制编码(串)
//			}
//		}
//		else if (HT[k].weight == 1)
//		{	//向右
//			HT[k].weight = 2;
//			if (HT[k].rchild != 0)	//有右孩子
//			{
//				k = HT[k].rchild;
//				cd[cdlen++] = '1';
//			}
//			else //没有右孩子
//			{	//HT[k].weight == 2,退回
//				HT[k].weight = 0;
//				k = HT[k].parent;
//				--cdlen;	//退回父节点，编码长度减1
//			}
//		}
//	}
// }

// ----- main() -----

// int main()	//构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC
//{
//	int weight[30], i, n, * p = &weight[1];
//	char str[30], c;
//	HuffmanTree HT;
//	HuffmanCode HC;
//	printf("请输入要编码的字母个数:");
//	scanf("%d", &n);
//	printf("请输入要编码的字母及其权值，以空格分隔:\n");
//	while ((c = getchar()) != '\n');	//清空缓冲区
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%c%d", &str[i], &weight[i]);
//		while ((c = getchar()) != '\n');	//清空缓冲区
//	}
//	Create_HuffmanTree(HT, p, n);
//	printf("哈夫曼树各结点值:\n");
//	for (int j = 1; j <= 2 * n - 1; j++)
//	{
//		printf("%d ", HT[j].weight);
//	}
//	printf("\n");
//	HuffmanCoding_FromLeafToRoot(HT, HC, n);
//	for (int k = 1; k <= n; k++)
//	{
//		printf("%c的编码:%s\n", str[k], HC[k]);
//	}
//	return 0;
// }

// ===== 图 =====

// ----- 邻接矩阵的存储结构 -----

// #define MAX_VEX_NUM 100	//最大顶点个数
// #define MAXSIZE 100
// #define INFINITY 1024	//表示无穷，可以自己设定
// typedef char VertexType;	//顶点类型
// typedef struct
//{
//	VertexType vexs[MAX_VEX_NUM];	//顶点向量，vexs[i]即为第i个顶点，存储顶点相关信息
//	int adj[MAXSIZE][MAXSIZE];	//邻接矩阵
//	int vexnum, arcnum;	//顶点数和边数
// }MGraph;
//
// void CreateMGraph(MGraph& G)	//图邻接矩阵的存储实现
//{
//	int i, j, k, kind = 1;
//	printf("是否为无向图:\n1.是\n2.不是\n");
//	scanf("%d", &kind);
//	printf("请输入顶点数和边数(以空格分隔)：\n");
//	scanf("%d%d", &(G.vexnum), &(G.arcnum));
//	printf("请输入顶点信息（输入完一个结点回车一次）：\n");
//	for (i = 0; i < G.vexnum; i++)
//	{
//		//while (char ch = getchar() != '\n');
//		char ch = getchar();
//		scanf("%c", &(G.vexs[i]));
//	}
//	for (i = 0; i < G.vexnum; i++)
//	{
//		for (j = 0; j < G.vexnum; j++)
//		{
//			G.adj[i][j] = 0;	//初始化邻接矩阵
//		}
//	}
//	printf("请输入每条边对应的两个顶点的序号(以空格分隔，输入完一对顶点回车一次)：\n");
//	for (k = 0; k < G.arcnum; k++)
//	{
//		//while (char ch = getchar() != '\n');
//		char ch = getchar();
//		scanf("%d%d", &i, &j);	//输入e条边
//		G.adj[i][j] = 1;
//		if (1 == kind)
//		{
//			G.adj[j][i] = 1;
//		}
//	}	//若加入边(i,j)则G.adj[i][j] = 1
// }
// void CreateMGraph_Prim(MGraph& G)	//图邻接矩阵的存储实现——Prim算法加上输入权值
//{
//	int i, j, k, kind = 1;
//	printf("是否为无向图:\n1.是\n2.不是\n");
//	scanf("%d", &kind);
//	printf("请输入顶点数和边数(以空格分隔)：\n");
//	scanf("%d%d", &(G.vexnum), &(G.arcnum));
//	printf("请输入顶点信息（输入完一个结点回车一次）：\n");
//	for (i = 0; i < G.vexnum; i++)
//	{
//		while (char ch = getchar() != '\n');
//		scanf("%c", &(G.vexs[i]));
//	}
//	for (i = 0; i < G.vexnum; i++)
//	{
//		for (j = 0; j < G.vexnum; j++)
//		{
//			G.adj[i][j] = INFINITY;	//初始化邻接矩阵
//		}
//	}
//	printf("请输入每条边对应的两个顶点的序号以及权值(以空格分隔，输入完一对顶点回车一次)：\n");
//	for (k = 0; k < G.arcnum; k++)
//	{
//		int weight = INFINITY;
//		while (char ch = getchar() != '\n');
//		scanf("%d%d%d", &i, &j, &weight);	//输入e条边及其权值
//		G.adj[i][j] = weight;
//		if (1 == kind)	//无向图为对称矩阵
//		{
//			G.adj[j][i] = weight;
//		}
//	}	//若加入边(i,j)则G.adj[i][j] = 1
// }

// ----- 邻接表的存储结构 -----

// typedef struct ArcNode	//边结点
//{
//	int adjvex;	//邻接点域(adjvex)存储与顶点vi邻接的顶点在图中的位置(或序号)，指针域(nextarc)用来指向下一条边(或弧)的结点
//	struct ArcNode* nextarc;	//指向下一个边结点的指针域
// }ArcNode;
// typedef struct Vnode	//表头结点
//{
//	VertexType vertex;
//	ArcNode* firstarc;
// }VNode;
// typedef struct
//{
//	VNode adjlist[MAX_VEX_NUM];	//结构体数组
//	int vexnum, arcnum;	//图的当前顶点数和弧数
// }ALGraph;

// ----- 建立无向图的邻接表存储 -----

// void CreateALGraph(ALGraph& G)
//{
//	int i, j, k, kind = 1;
//	ArcNode* s, * e;
//	printf("请输入是否为无向图：\n1.是\n2.不是\n");
//	scanf("%d", &kind);
//	printf("请输入顶点数和边数(以空格隔开)：\n");
//	scanf("%d%d", &(G.vexnum), &(G.arcnum));
//	printf("请输入顶点信息（输入一个顶点回车一次）：\n");
//	for (i = 0; i < G.vexnum; i++)
//	{	//建立表头结点数组
//		while (char ch = getchar() != '\n');
//		scanf("%c", &(G.adjlist[i].vertex));
//		G.adjlist[i].firstarc = NULL;	//结构体数组的firstarc域置空
//	}
//	printf("请输入边的信息（分别输入该边连接的两个顶点，输入完毕后回车）：\n");
//	for (k = 0; k < G.arcnum; k++)	//在链表表头插入结点，从后向前建立链表
//	{	//注意：有向图和无向图的边数不同
//		while (char ch = getchar() != '\n');
//		scanf("%d%d", &i, &j);
//		s = (ArcNode*)malloc(sizeof(ArcNode));
//		s->adjvex = j;
//		s->nextarc = G.adjlist[i].firstarc;
//		G.adjlist[i].firstarc = s;
//		if (1 == kind)
//		{
//			e = (ArcNode*)malloc(sizeof(ArcNode));
//			e->adjvex = i;
//			e->nextarc = G.adjlist[j].firstarc;
//			G.adjlist[j].firstarc = e;
//		}
//	}
// }

// ----- 采用邻接表存储的图的深度优先遍历 -----

// #define MAX_VERTEX_NUM 100
// bool visited[MAX_VERTEX_NUM];	//访问标志数组
// Status(*VisitFunc)(int v);	//函数变量，指向函数的指针
//
// int LocateVex(ALGraph G, VertexType u)
//{	// 初始条件:图G存在,u和G中顶点有相同特征
//	// 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		char* p = &u, * q = &G.adjlist[i].vertex;
//		if (strcmp(p, q) == 0)
//		{
//			printf("yes");
//			return i;
//		}
//	}
//	printf("no");
//	return -1;
// }
// VertexType& GetVex(ALGraph G, int v)
//{	//初始条件: 图G存在,v是G中某个顶点的序号。操作结果: 返回v的值
//	if (v >= G.vexnum || v < 0)
//	{
//		exit(ERROR);
//	}
//	return G.adjlist[v].vertex;
// }
// int FirstAdjVex(ALGraph G, int v)
//{	//初始条件: 图G存在,v是G中某个顶点
//	//操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1
//	ArcNode* p = G.adjlist[v].firstarc;
//	if (p)	//v存在邻接点就返回邻接顶点的序号，否则返回-1
//	{
//		return p->adjvex;
//	}
//	else
//	{
//		return -1;
//	}
// }
// int NextAdjVex(ALGraph G, int v, int w)
//{	//初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点
//	//操作结果: 返回v的(相对于w的)下一个邻接顶点的序号,若w是v的最后一个邻接顶点,则返回-1
//	ArcNode* p = G.adjlist[v].firstarc;
//	while (p && p->adjvex != w)	//指针p不空且所指下一个结点不空且不是w，即v1存在邻接点且邻接点未到w
//	{
//			p = p->nextarc;
//	}
//	if (!p || !p->nextarc)	//没找到w或w是最后一个邻接点则返回-1，否则返回下一个邻接点的序号
//	{
//		return -1;	//返回-1跳出循环
//	}
//	else //p->adjvex==w
//	{
//		return p->nextarc->adjvex;	// 返回v的(相对于w的)下一个邻接顶点的序号
//	}
// }
// Status Print_Graph(int v)
//{
//	printf("%c->", v);
//	return 0;
// }
// void DFS(ALGraph G, int v)
//{	//从第v个顶点出发递归地深度优先遍历图G
//	int w;
//	visited[v] = true;
//	VisitFunc(G.adjlist[v].vertex);	//访问第v个顶点
//	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))	//当w = -1 的时候退出循环，即NextAdjVex()返回值为-1或者FirstAdjVex()的返回值为-1
//	{
//		if (!visited[w])
//		{
//			DFS(G, w);	//对v的尚未访问的邻接顶点w递归调用DFS
//		}
//	}
// }
// void DFSTraverse(ALGraph G, Status(Visit)(int v))
//{	//对图G作深度优先遍历
//	int v;
//	VisitFunc = Visit;	//使用全局变量使被调用函数DFS不必设函数指针参数
//	for (v = 0; v < G.vexnum; v++)
//	{
//		visited[v] = false;	//访问标志数组初始化
//	}
//	for (v = 0; v < G.vexnum; v++)
//	{
//		if (!visited[v])
//		{
//			DFS(G, v);	//对尚未访问的顶点调用DFS
//			printf("\n");
//		}
//	}
// }

// ----- 采用邻接矩阵存储的图的广度优先遍历 -----

// typedef int QElemType;
// typedef struct QNode
//{
//	QElemType data;
//	struct QNode* next;
// }QNode, * QueuePtr;
// typedef struct Link_Queue
//{
//	QueuePtr front; //队头指针
//	QueuePtr rear; //队尾指针
// }LinkQueue;
//
// Status InitQueue(LinkQueue& Q);
// Status EnQueue(LinkQueue& Q, QElemType v);
// Status QueueEmpty(LinkQueue Q);
// Status DeQueue(LinkQueue& Q, QElemType& u);
// int FirstAdjVex(MGraph G, int v);
// int NextAdjVex(MGraph G, int v, int w);
//
// int FirstAdjVex(MGraph G, int v)
//{	// 初始条件: 图G存在,v是G中某个顶点
//	 操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		if (G.adj[v][i])	//如果存在邻接点
//		{
//			return i;
//		}
//	}
//	return -1;
// }
// int NextAdjVex(MGraph G, int v, int w)
//{	// 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点
//	 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号,若w是v的最后一个邻接顶点,则返回-1
//	for (int i = w + 1; i < G.vexnum; i++)
//	{
//		if (G.adj[v][i])
//		{
//			return i;
//		}
//	}
//	return -1;
// }
// void BFSTraverse(MGraph G, Status(*Visit)(int v))
//{	//按广度优先非递归遍历图G，使用辅助队列Q和访问标志数组visited
//	QElemType u, v, w;
//	LinkQueue Q;
//	for (v = 0; v < G.vexnum; v++)
//	{
//		visited[v] = FALSE;	//访问标志数组初始化
//	}
//	InitQueue(Q);	//置空的辅助队列Q
//	for (v = 0; v < G.vexnum; v++)
//	{
//		if (!visited[v])
//		{	//v尚未被访问
//			visited[v] = TRUE;
//			Visit(G.vexs[v]);	//访问v
//			EnQueue(Q, v);	//v入队列
//			while (!QueueEmpty(Q))
//			{	//当前队列非空
//				DeQueue(Q, u);	//队头元素出队并置为u
//				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
//				{
//					if (!visited[w])
//					{	//u的尚未访问的邻接顶点w入队列Q
//						visited[w] = TRUE;
//						Visit(G.vexs[w]);
//						EnQueue(Q, w);
//					}
//				}
//			}
//		}
//	}
// }

// ----- 构造最小生成树的Prim算法 -----

// #define VEX_NUM 10
////最小生成树问题在邻接矩阵中解决
// typedef struct	//closedge记录从U到V-U具有最小权值的边，closedge[i]对应adjvex与在V-U中的顶点vi之间的边
//{
//	VertexType adjvex;	//存储该边依附在U中的顶点
//	int lowcost;	//边的权值
// }closedge[MAX_VERTEX_NUM];
//
// int LocateVex(MGraph Gn, VertexType v0)
//{	// 初始条件:图G存在,u和G中顶点有相同特征
//	// 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1
//	for (int i = 0; i < Gn.vexnum; ++i)
//	{
//		if (Gn.vexs[i] == v0)
//		{
//			return i;
//		}
//	}
//	return -1;
// }
// int Mininum(closedge dge, MGraph Gn)	//函数声明
//{
//	int m, min = INFINITY;
//	for (int j = 0; j < Gn.vexnum; j++)
//	{
//		if ((dge[j].lowcost != 0) && (dge[j].lowcost < min))
//		{
//			min = dge[j].lowcost;
//			m = j;
//		}
//	}
//	return m;
// }
// void Prim(MGraph Gn, VertexType v0)
//{
//	closedge dge;
//	int k = LocateVex(Gn, v0);	//查找v0在顶点向量v[]中的序号
//	for (int j = 0; j < Gn.vexnum; j++)
//	{	//closedge数组初始化
//		if (j != k)
//		{	//排除v0，因为其已经在集合U中
//			dge[j].adjvex = v0;
//			dge[j].lowcost = Gn.adj[k][j];
//		}
//	}
//	dge[k].lowcost = 0;	//初始化U = {v0}
//	dge[k].adjvex = -1;
//	for (int i = 1; i < Gn.vexnum; i++)
//	{	//选择其余VEX_NUM-1个顶点
//		k = Mininum(dge, Gn);	//求权值最小的边，k值为边对应的U-V中顶点序号
//		printf("%c\t%c\t%d\n", dge[k].adjvex, Gn.vexs[k], dge[k].lowcost);	//dge[k].adjvex该边U中顶点，Gn.vexs[k]该边V-U中顶点
//		dge[k].lowcost = 0;	//顶点vk入U
//		for (int j = 0; j < Gn.vexnum; j++)
//		{	//新顶点入U后重新选择最小边
//			if (Gn.adj[k][j] < dge[j].lowcost)
//			{
//				dge[j].lowcost = Gn.adj[k][j];
//				dge[j].adjvex = Gn.vexs[k];
//			}
//		}
//	}
// }

// ----- 队列 -----

// Status InitQueue(LinkQueue& Q)
//{
//	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
//	if (!Q.front) //存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	Q.front->next = NULL;
//	return OK;
// }
// Status QueueEmpty(LinkQueue Q)
//{
//	if (Q.front == Q.rear)
//	{
//		return TRUE;
//	}
//	else
//	{
//		return FALSE;
//	}
// }
// Status EnQueue(LinkQueue& Q, QElemType e)
//{
//	QueuePtr p;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (!p)	//存储分配失败
//	{
//		exit(OVERFLOW);
//	}
//	p->data = e;
//	p->next = NULL;
//	Q.rear->next = p;
//	Q.rear = p;
//	return OK;
// }
// Status DeQueue(LinkQueue& Q, QElemType& e)
//{
//	QueuePtr p;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (Q.front == Q.rear)
//	{
//		return ERROR;
//	}
//	p = Q.front->next;
//	e = p->data;
//	Q.front->next = p->next;
//	if (Q.rear == p) //如果被删的元素是最后一个，需要对队尾指针重新赋值(指向头结点)
//	{
//		Q.rear = Q.front;
//	}
//	free(p);
//	return OK;
// }

// ----- main() -----

// int main()
//{
//	//深度优先遍历图
//	ALGraph G;
//	int v = 0;
//	CreateALGraph(G);
//	printf("深度遍历的结果：\n");
//	DFSTraverse(G, Print_Graph);
//
//	//广度优先遍历图
//	MGraph H;
//	CreateMGraph(H);
//	printf("广度遍历的结果：\n");
//	BFSTraverse(H, Print_Graph);
//
//	//构造最小生成树的Prim算法
//	MGraph GP;
//	CreateMGraph_Prim(GP);
//	Prim(GP, GP.vexs[0]);
//
//	return 0;
// }

// ----- Dijkstra算法实现 -----

// #define MAXVEX 100
// typedef int Patharc[MAXVEX][MAXVEX];
// typedef int ShortPathTable[MAXVEX];
// VertexType v0;	//改为全局变量，解决堆栈调用的报错问题
//
// void CreateMGraph_Dijkstra(MGraph& G)	//图邻接矩阵的存储实现——Dijkstra算法加上输入权值
//{
//	int i, j, k;
//	printf("请输入顶点数和边数(以空格分隔)：\n");
//	scanf("%d%d", &(G.vexnum), &(G.arcnum));
//	printf("请输入%d个顶点的信息（输入完一个结点回车一次）：\n", G.vexnum);
//	for (i = 0; i < G.vexnum; i++)
//	{
//		while (char ch = getchar() != '\n');
//		scanf("%c", &(G.vexs[i]));
//	}
//	for (i = 0; i < G.vexnum; i++)
//	{
//		for (j = 0; j < G.vexnum; j++)
//		{
//			G.adj[i][j] = INFINITY;	//初始化邻接矩阵
//		}
//	}
//	printf("请输入%d条弧对应的弧尾、弧头以及权值(以空格分隔，输入完一对顶点回车一次)：\n", G.vexnum);
//	for (k = 0; k < G.arcnum; k++)
//	{
//		int weight = INFINITY;
//		while (char ch = getchar() != '\n');
//		scanf("%d%d%d", &i, &j, &weight);	//输入e条边及其权值
//		G.adj[i - 1][j - 1] = weight;
//	}	//若加入边(i,j)则G.adj[i][j] = 1
// }
// void Dijkstra(MGraph G, VertexType v0, Patharc& P, ShortPathTable& D)
//{	//用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及其带权长度D[v]。
//	//若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点。
//	//final[v]为TRUE当且仅当v属于S,即已经求得从v0到v的最短路径。
//	int v, w, k = 0, min;
//	int final[MAXVEX];	//final[w] = 1表示求得顶点v0至vw的最短路径
//	for (v = 0; v < G.vexnum; v++)
//	{
//		final[v] = 0;	//全部顶点初始化为未知最短路径状态
//		D[v] = G.adj[v0][v];	//将与v0点有连线的顶点加上权值
//		for (int i = 0; i < G.vexnum; i++)
//		{	//初始化路径数组P为0
//			P[v][i] = 0;
//		}
//		if (D[v] < INFINITY)
//		{	//与源点有直接路径的路径数组初始化
//			P[v][v0] = TRUE;
//			P[v][v] = TRUE;
//		}
//	}
//	D[v0] = 0;	//v0至v0路径为0
//	final[v0] = 1;	//v0至v0不需要求路径
//	for (v = 1; v < G.vexnum; v++)
//	{	//开始主循环，每次求得v0到某个v顶点的最短路径
//		min = INFINITY;	//当前所知离v0顶点的最近距离
//		for (w = 0; w < G.vexnum; w++)
//		{	//寻找离v0最近的顶点
//			if (!final[w] && D[w] < min)	//不在S集合里的顶点
//			{
//				k = w;	//记录顶点的位置
//				min = D[w];	//w顶点离v0顶点更近
//			}
//		}
//		final[k] = 1;	//将目前找到的最近的顶点置为1
//		for (w = 0; w < G.vexnum; w++)
//		{	//修正当前最短路径及距离，如果经过v顶点的路径比现在这条路径的长度短的话
//			if (!final[w] && (min + G.adj[k][w] < D[w]))
//			{	//说明找到了更短的路径，修改D[w]和P[w]
//				D[w] = min + G.adj[k][w];	//修改当前路径长度
//				for (int i = 0; i < G.vexnum; i++)
//				{	//将当前路径的路径数组复制给找到更短的路径的路径数组
//					P[w][i] = P[k][i];
//				}
//				P[w][w] = TRUE;	//自身顶点置为1
//			}
//		}
//	}
// }
//
// int main()
//{
//	MGraph G;
//	Patharc P;
//	ShortPathTable D;
//	CreateMGraph_Dijkstra(G);
//	printf("请输入源点：");
//	while (char ch = getchar() != '\n');
//	scanf("%d", &v0);
//	v0--;	//自减一次适应邻接矩阵的存储方式
//	Dijkstra(G, v0, P, D);
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			printf("%d ", P[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d到各顶点的最短路径长度为：\n", v0 + 1);
//	for (int i = 1; i < G.vexnum; i++)
//	{
//		printf("%d-%d:%d\n", v0 + 1, i + 1, D[i]);
//	}
//	return 0;
// }

// ----- 静态查找表的顺序存储结构 -----

// #define LIST_INIT_SIZE 100 // 存储空间初始分配量
// typedef struct student_information
// {
// 	int Num;
// } ElemType; // ElemType是某个确定的、将由用户自行定义的、含某个关系运算的数据对象
// typedef int KeyType;
// typedef struct
// {
// 	ElemType* elem; // 存储空间分配的基地址，0号单元留空
// 	int length;		// 当前表长度
// } SSTable, SqList;

// ----- 线性表的操作 -----

// Status compare(ElemType* pa, ElemType* pb)// 例如，判断pa、pb是否相等，如果pa和pb相等则返回1，否则返回0
// {
// 	int flag;
// 	(pa->Num == pb->Num) ? (flag = TRUE) : (flag = FALSE);
// 	return flag;
// }
// Status InitList_Sq(SqList& L)
// {
// 	L.elem = (ElemType*)malloc((LIST_INIT_SIZE) * sizeof(ElemType)); // 强制类型转换
// 	if (!L.elem)
// 	{
// 		exit(OVERFLOW);
// 	}
// 	L.length = 0; // 空表长度为0
// 	return OK;
// }
// Status WriteList_Sq(SqList& L)
// {
// 	int length, i;
// 	ElemType* p = L.elem;
// 	printf("\nPlease enter the length of Sequence List:\n");
// 	scanf("%d", &length);
// 	printf("\nPlease enter %d datum that you want put in the Sequence List:\n", length);
// 	L.length = length;
// 	for (i = 1; i <= length; i++)
// 	{
// 		scanf("%d", &L.elem[i]);
// 	}
// 	return TRUE;
// }

// ----- 顺序查找 -----

// int LocateElem_Sq(SqList L, ElemType& e, Status(*compare)(ElemType* pa, ElemType* pb))
// {						  // 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。若找到,则返回其在L中的位序,否则返回0。
// 	int i = 1;			  // i的初值为第1个元素的位序
// 	ElemType* p = L.elem; // p的初值为第1个元素的存储位置
// 	p++;
// 	while (i <= L.length && !(*compare)(p, &e))
// 	{
// 		++i; // 从前往后查找
// 		p++;
// 	}
// 	int flag;
// 	(i <= L.length) ? (flag = i) : (flag = 0);
// 	return flag;
// }
//
// int Search_Seq(SSTable ST, KeyType key)
// { // 在顺序表ST中顺序查找其关键字等于Key的数据元素。若找到,则函数值为该元素在表中的位置,否则为0。
// 	int i;
// 	ST.elem[0].Num = key; // 哨兵
// 	for (i = ST.length; ST.elem[i].Num != key; --i)
// 		;
// 	return i; // 找不到时，i为0
// }

// ----- 二分查找 -----

// #define EQ(a, b) ((a) == (b))
// #define LT(a, b) ((a) < (b))
//
// int Search_Bin(SSTable ST, KeyType key)
// { // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0。
// 	int low, high, mid;
// 	low = 1;
// 	high = ST.length; // 置区间初值
// 	while (low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if (EQ(key, ST.elem[mid].Num))
// 		{
// 			return mid; // 找到待查元素
// 		}
// 		else if (LT(key, ST.elem[mid].Num))
// 		{
// 			high = mid - 1; // 继续在前半区间进行查找
// 		}
// 		else
// 		{
// 			low = mid + 1; // 继续在后半区间进行查找
// 		}
// 	}
// 	return 0; // 顺序表中不存在待查元素
// }

// ----- 排序 -----

// Status sort(SqList& L)
// {
// 	int i, j, swap;
// 	for (i = 1; i < L.length; i++)
// 	{
// 		for (j = i + 1; j <= L.length; j++)
// 		{
// 			if (L.elem[i].Num > L.elem[j].Num)
// 			{
// 				swap = L.elem[i].Num;
// 				L.elem[i].Num = L.elem[j].Num;
// 				L.elem[j].Num = swap;
// 			}
// 		}
// 	}
// 	return OK;
// }

// ----- 分块查找 -----

// #define MAX 6
// #define SIZE 5
//
// #define EQ(a, b) ((a) == (b))
// #define LT(a, b) ((a) < (b))
// typedef struct index
// {
// 	int key;
// 	int start;
// 	int length;
// } NewIndex;
//
// Status sort_index(NewIndex* index)
// {
// 	int i, j, swap, start;
// 	for (i = 1; i <= index->length; i++)
// 	{
// 		for (j = i + 1; j <= index->length; j++)
// 		{
// 			if (index[i].key > index[j].key)
// 			{
// 				swap = index[i].key;
// 				start = index[i].start;
// 				index[i].key = index[j].key;
// 				index[i].start = index[j].start;
// 				index[j].start = start;
// 				index[j].key = swap;
// 			}
// 		}
// 	}
// 	return OK;
// }
// int Search_Bin_index(NewIndex* index, KeyType key)
// { // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0。
// 	int low, high, mid;
// 	low = 1;
// 	high = index->length; // 置区间初值
// 	while (low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if (EQ(key, index[mid].key))
// 		{
// 			return mid; // 找到待查元素
// 		}
// 		else if (LT(key, index[mid].key))
// 		{
// 			high = mid - 1; // 继续在前半区间进行查找
// 		}
// 		else
// 		{
// 			low = mid + 1; // 继续在后半区间进行查找
// 		}
// 	}
// 	return 0; // 顺序表中不存在待查元素
// }
// int Search_Seq_index(SSTable ST, KeyType e, int key)
// { // 在顺序表ST中顺序查找其关键字等于Key的数据元素。若找到,则函数值为该元素在表中的位置,否则为0。
// 	int i;
// 	ST.elem[key].Num = e; // 哨兵
// 	for (i = ST.length; ST.elem[i].Num != e; --i)
// 		;
// 	return i; // 找不到时，i为0
// }

// ----- main() -----

// int main()
// {
// 	SqList L;
// 	ElemType e;
// 	Status(*p)(ElemType * pa, ElemType * pb) = compare;
// 	InitList_Sq(L);
// 	WriteList_Sq(L);
// 	// 顺序查找
// 	printf("Please enter the number you want find:");
// 	scanf("%d", &e.Num);
// 	// 改进前的顺序查找算法
// 	printf("改进前的顺序查找算法：\nThe number locate in:%d\n", LocateElem_Sq(L, e, p));
// 	// 改进后的顺序查找算法
// 	printf("改进后的顺序查找算法：\nThe number locate in:%d\n", Search_Seq(L, e.Num));
// 	// 二分查找
// 	sort(L);
// 	printf("二分查找之前的排序：\n");
// 	for (int i = 1; i <= L.length; i++)
// 	{
// 		printf("L.elem[%d].Num = %d\n", i, L.elem[i].Num);
// 	}
// 	printf("二分查找算法:\nThe number locate in:%d\n", Search_Bin(L, e.Num));
// 	// 分块查找
// 	int i;
// 	NewIndex index[MAX];
// 	index->length = 0;
// 	for (i = 1; i <= 5; i++)
// 	{
// 		index[i].key = 0;
// 		index[i].start = (i - 1) * SIZE + 1;
// 	}
// 	int j = 0;
// 	for (i = 1; i <= SIZE; i++)
// 	{
// 		j += SIZE;
// 		index->length += 1;
// 		for (int k = index[i].start; k <= j; k++)
// 		{
// 			if (index[i].key < L.elem[k].Num)
// 			{
// 				index[i].key = L.elem[k].Num;
// 			}
// 		}
// 	}
// 	sort_index(index);
// 	int key = Search_Bin_index(index, e.Num);
// 	printf("分块查找算法:\nThe number locate in:%d\n", Search_Seq_index(L, e.Num, key));
// 	return 0;
// }

// ----- 二叉排序树的存储结构 -----

// #define EQ(a, b) ((a) == (b))
// #define LT(a, b) ((a) < (b))
//
// typedef int ElemType;
//
// typedef struct BSTNode // 二叉树结构体
// {
//     ElemType data;                   // 每个节点的数据域包括关键字项和其他数据项
//     struct BSTNode *lchild, *rchild; // 左右孩子指针
// } BSTNode, *BSTree;
//
// typedef int KeyType;

// ----- 二叉排序树的基本操作 -----

// void InitTree(BSTree &T) // 初始化二叉排序树
// {
//     T = (BSTNode *)malloc(sizeof(BSTNode)); // 创建一个头结点
//     T->data = NULL;
//     T->lchild = T->rchild = NULL; // 头结点指针域和数据域都NULL
// }
// BSTree SearchBST(BSTree T, KeyType key)
// { // 在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功，则返回指向该数据元素结点的指针。否则返回空指针
//     if (!T || EQ(key, T->data))
//     {
//         printf("%d ", T->data);
//         return T; // 查找结束
//     }
//     else if (LT(key, T->data))
//     { // 在左子树中继续查找
//         printf("%d ", T->data);
//         return SearchBST(T->lchild, key);
//     }
//     else
//     { // 在右子树中继续查找
//         printf("%d ", T->data);
//         return SearchBST(T->rchild, key);
//     }
// }
// Status SearchBST(BSTree T, KeyType key, BSTree f, BSTree &p)
// { // （被调用函数）在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，
//     // 若查找成功，则指针p指向该元素结点，并返回TRUE，否则指针p指向查找路径上访问的最后一个结点并返回FALSE，
//     // 指针f指向T的双亲，其初始调用值为根结点的双亲NULL
//     if (!T)
//     {          // 查找不成功，或树为空树，空树时p返回值为NULL
//         p = f; // 查找不成功时p指向查找路径上访问的最后一个点
//         return FALSE;
//     }
//     else if (EQ(key, T->data))
//     {          // 查找成功
//         p = T; // T值随着递归的进程不断变化
//         return TRUE;
//     }
//     else if (LT(key, T->data))
//     {
//         return SearchBST(T->lchild, key, T, p); // 在左子树中继续查找
//     }
//     else
//     {
//         return SearchBST(T->rchild, key, T, p); // 在右子树中继续查找
//     }
// }
// // 二叉排序树中查找的非递归算法
// BSTNode *SearchBST1(BSTNode *bt, KeyType k)
// {
//     while (bt != NULL)
//     {
//         if (k == bt->data)
//         {
//             printf("%d ", bt->data);
//             return bt;
//         }
//         else if (k < bt->data)
//         {
//             printf("%d ", bt->data);
//             bt = bt->lchild;
//         }
//         else
//         {
//             printf("%d ", bt->data);
//             bt = bt->rchild;
//         }
//     }
//     return NULL;
// }
// Status InsertBST(BSTree &T, ElemType e)
// { // 当二叉排序树T中不存在关键字等于e.key的数据元素时，插入e并返回TRUE，否则返回FALSE
//     BSTree p = T, s;
//     if (!SearchBST(T, e, NULL, p)) // 注意实参
//     {                              // 查找不成功
//         s = (BSTree)malloc(sizeof(BSTree));
//         s->data = e;
//         s->lchild = s->rchild = NULL;
//         if (!p) // T为空树
//         {
//             T = s; // 插入s为新的根节点
//         }
//         else if (LT(e, p->data))
//         { // 插入s为左孩子
//             p->lchild = s;
//         }
//         else
//         { // 插入s为右孩子
//             p->rchild = s;
//         }
//         return TRUE;
//     }
//     else
//     {
//         return FALSE; // 树中已有关键字相同的结点，不再插入
//     }
// }
// void CreateTree(BSTree &T) // 创建二叉排序树
// {
//     int i = 0;
//     ElemType a;
//     printf("请输入根节点：");
//     scanf("%d", &a);
//     InsertBST(T, a); // 将数据填入二叉排序树的根结点
//     while (TRUE)     // 利用循环进行插入操作
//     {
//         if (a == -1) // 死循环结束条件
//         {
//             break;
//         }
//         i++;
//         printf("第%d步，请输入结点：", i);
//         scanf("%d", &a);
//         InsertBST(T, a); // 将数据导入到二叉排序树T中
//     }
// }
// void DispBST(BSTNode *bt)
// // 以括号表示法输出二叉排序树bt
// {
//     if (bt != NULL)
//     {
//         printf("%d", bt->data);
//         if (bt->lchild != NULL || bt->rchild != NULL)
//         {
//             printf("(");
//             DispBST(bt->lchild);
//             if (bt->rchild != NULL)
//             {
//                 printf(",");
//             }
//             DispBST(bt->rchild);
//             printf(")");
//         }
//     }
// }
// BSTNode *CreatBST(int *A, int n)
// // 由数组A中的关键字建立一棵二叉排序树
// {
//     BSTNode *bt = NULL; // 初始时bt为空树
//     int i = 1;
//     while (i <= n)
//     {
//         printf("第%d步，插入%d:", i, A[i]);
//         DispBST(bt);
//         printf("\n");
//         InsertBST(bt, A[i]); // 将A[i]插入二叉排序树T中
//         i++;
//     }
//     return bt; // 返回建立的二叉排序树的根指针
// }
// int out = -32767;
// int JudgeBST(BSTNode *bt) // 判断bt是否为BST
// {
//     int b1, b2;
//     if (bt == NULL)
//     {
//         return 1; // 空二叉树是排序二叉树
//     }
//     else
//     {
//         b1 = JudgeBST(bt->lchild);      // 返回对左子树的判断，非排序二叉树返回0，否则返回1
//         if (b1 == 0 || out >= bt->data) // 当左子树非排序二叉树，或中序前趋（全局变量）大于当前根结点时
//         {
//             return 0; // 返回“不是排序二叉树”
//         }
//         out = bt->data;            // 记录当前根为右子树的中序前趋
//         b2 = JudgeBST(bt->rchild); // 对右子树进行判断
//         return b2;
//     }
// }
// Status Delete(BSTree &p)
// { // 此为被调用函数从二叉排序树中删除结点p，并重接它的左或右子树
//     BSTree q, s;
//     if (!p->rchild)
//     { // 右子树空则只需重接它的左子树
//         q = p;
//         p = p->lchild;
//         // free(q);
//     }
//     else if (!p->lchild)
//     { // 左子树空则只需重接它的右子树
//         q = p;
//         p = p->rchild;
//         free(q);
//     }
//     else
//     { // 左右子树均不空
//         q = p;
//         s = p->lchild;
//         while (s->rchild)
//         { // 向右走到尽头
//             q = s;
//             s = s->rchild;
//         }
//         p->data = s->data;
//         if (q != p)
//         {
//             q->rchild = s->lchild; // 重接*q的右子树，s可能有左孩子
//         }
//         else
//         {                          // s一开始没有右子树的情况
//             q->lchild = s->lchild; // 重接*q的左子树
//             free(s);
//         }
//     }
//     return TRUE;
// }
// Status DeleteBST(BSTree &T, KeyType key)
// { // 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点p，并返回TRUE，否则返回FALSE
//     if (!T)
//     {
//         return FALSE; // 不存在关键字等于key的元素
//     }
//     else
//     {
//         if (EQ(key, T->data))
//         { // 找到关键字等于key的数据元素
//             return Delete(T);
//         }
//         else if (LT(key, T->data))
//         {
//             return DeleteBST(T->lchild, key);
//         }
//         else
//         {
//             return DeleteBST(T->rchild, key);
//         }
//     }
// }
// void Delete1(BSTNode *p, BSTNode *&r) // 当被删*p结点有左右子树时的删除过程
// {
//     BSTNode *q;
//     if (r->rchild != NULL)
//         Delete1(p, r->rchild); // 递归找最右下结点
//     else                       // 找到了最右下结点*r
//     {
//         p->data = r->data; // 将*r的关键字值赋给*p
//         q = r;
//         r = r->lchild; // 直接将其左子树的根结点放在被删结点的位置上
//         // free(q);       // 释放原*r的空间
//     }
// }

// ----- main() -----

// int main()
// {
//     BSTree T;
//     int a[11] = {-1, 4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
//     printf("创建排序二叉树:\n");
//     T = CreatBST(a, n);
//     printf("BTS:");
//     DispBST(T);
//     printf("\nT%s\n", (JudgeBST(T) ? "是一棵BST" : "不是一棵BST"));
//
//     int x = 6;
//     printf("查找%d关键字(递归):", x);
//     SearchBST(T, x);
//     printf("\n");
//     printf("查找%d关键字(非递归):", x);
//     SearchBST1(T, x);
//     printf("\n");
//
//     printf("删除操作:\n");
//     printf("原BST:");
//     DispBST(T);
//     printf("\n");
//
//     int x1 = 4, x2 = 5;
//     printf("删除结点%d:", x1);
//     BSTree f = NULL, p;
//     if (SearchBST(T, x1, f, p) != NULL)
//     {
//         DeleteBST(T, x1);
//         DispBST(T);
//         printf("\n");
//     }
//     printf("删除结点%d:", x2);
//     if (SearchBST(T, x2, f, p) != NULL)
//     {
//         DeleteBST(T, x2);
//         DispBST(T);
//         printf("\n");
//     }
//     return 0;
// }

// ----- 开放定址哈希表的存储结构 -----

// #define SUCCESS 1
// #define UNSUCCESS 0
// #define DUPLICATE -1
// #define NullKey -1163005939
// #define MAXSIZE 12 // MAXSIZE为当前容量
// #define EQ(a, b) ((a) == (b))
// #define LT(a, b) ((a) < (b))
// #define SIZE 11
//
// typedef int Status;
// typedef int KeyType;
// typedef struct
// {
//     KeyType key;
// } ElemType;
//
// int hashsize[10] = {3, 5, 11, 13, 17, 19, 23, 29, 31, 37}; // 哈希表容量递增表，一个合适的素数序列
// int m = NullKey;
// typedef struct
// {
//     ElemType *elem; // 动态分配数组
//     int count;      // 当前数据元素个数
//     int sizeindex;  // hashsize[sizeindex]为当前容量
// } HashTable;

// ----- 哈希表的基本操作 -----

// Status Hash(KeyType K)
// {
//     return (K % m);
// }
// void InitHashTable(HashTable &H)
// {
//     // 分配空间
//     H.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
//     H.count = 0;
//     H.sizeindex = 2;
//     m = hashsize[H.sizeindex];
//     // 初始化
//     int i;
//     for (i = 0; i < MAXSIZE; i++)
//     {
//         H.elem[i].key = NullKey;
//     }
// }
// Status collision(int p, int c)
// {
//     return (p + c) % m;
// }
// int SearchHash(HashTable H, KeyType K, int &count)
// {
//     int p = Hash(K);
//     while ((H.elem[p].key != NullKey) && (!EQ(K, (H.elem[p].key)))) // 并且关键字不相等
//     {
//         p = collision(p, ++count); // 求得下一个探查地址p
//     }
//     if (EQ(K, (H.elem[p].key)))
//     {
//         return p; // 查找成功，p返回待查数据元素位置
//     }
//     else
//     {
//         return UNSUCCESS; // 查找不成功(H.elem[p].key == NULL_KEY)
//     }
// }
// // 以开放定址等方法（出链地址法外）处理冲突的哈希表的查找过程
// Status SearchHash(HashTable H, KeyType K, int &p, int &c)
// {                                                                   // 在开放定址哈希表H中查找关键码为K的元素，若查找成功，以p指示待查数据元素在表中位置，
//                                                                     // 并返回SUCCESS，否则，以p指示插入位置，并返回UNSUCCESS，c用以计算冲突次数，其初值置为0
//     p = Hash(K);                                                    // 求得哈希地址
//     while ((H.elem[p].key != NullKey) && (!EQ(K, (H.elem[p].key)))) // 并且关键字不相等
//     {
//         p = collision(p, ++c); // 求得下一个探查地址p
//     }
//     if (EQ(K, (H.elem[p].key)))
//     {
//         return SUCCESS; // 查找成功，p返回待查数据元素位置
//     }
//     else
//     {
//         return UNSUCCESS; // 查找不成功(H.elem[p].key == NULL_KEY)
//     }
// }
// Status RecreateHashTable(HashTable &H)
// {
//     H.elem = (ElemType *)realloc(H.elem, (hashsize[++H.sizeindex]) * sizeof(ElemType));
//     return TRUE;
// }
// Status InsertHash(HashTable &H, ElemType e)
// { // 查找不成功时插入数据元素e到开放定址哈希表H中，并返回OK，若冲突次数过大，则重建哈希表
//     int c = 0;
//     int p;
//     if (SearchHash(H, e.key, p, c))
//     {
//         return DUPLICATE; // 表中已有与e相同关键字的元素
//     }
//     else if (c < hashsize[H.sizeindex] / 2) // 冲突次数c未达到上限，c的阈值可调
//     {                                       // 插入e
//         H.elem[p] = e;
//         ++H.count;
//         return OK;
//     }
//     else
//     { // 重建哈希表
//         RecreateHashTable(H);
//         if (InsertHash(H, e) == OK)
//         {
//             return OK;
//         }
//         return UNSUCCESS;
//     }
// }
// void DisplayHashTable(HashTable H)
// {
//     int i;
//     printf("\n哈希表地址:  \t");
//     for (i = 0; i < hashsize[H.sizeindex]; i++)
//     {
//         printf("%d\t", i);
//     }
//     printf("\n哈希表关键字:\t");
//     for (i = 0; i < hashsize[H.sizeindex]; i++)
//     {
//         if (H.elem[i].key != NullKey)
//         {
//             printf("%d\t", H.elem[i].key);
//         }
//         else
//         {
//             printf("\t");
//         }
//     }
//     printf("\n");
// }
// void Delete(HashTable &H, ElemType e)
// {
//     int count = 0;
//     int p = SearchHash(H, e.key, count);
//     H.elem[p].key = NullKey;
// }

// ----- main() -----

// int main()
// {
//     int i;       // 循环变量
//     HashTable H; // 哈希表
//     ElemType e;  // 查找的数据
//     int array[SIZE] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
//     int b;
//     InitHashTable(H);
//     for (i = 0; i < SIZE; i++)
//     {
//         e.key = array[i];
//         b = InsertHash(H, e);
//     }
//     DisplayHashTable(H);
//     int c = 1;
//     ElemType f;
//     f.key = 29;
//     int p = SearchHash(H, f.key, c);
//     if (p != UNSUCCESS)
//     {
//         printf("%d在哈希表中的位置：%d，查找次数；%d", f.key, p, c);
//     }
//     else
//     {
//         printf("未找到%d", f.key);
//     }
//     c = 0;
//     f.key = 77;
//     printf("\n删除关键字:%d", f.key);
//     Delete(H, f);
//     DisplayHashTable(H);
//     p = SearchHash(H, f.key, c);
//     if (p != UNSUCCESS)
//     {
//         printf("%d在哈希表中的位置：%d，查找次数；%d", f.key, p, c);
//     }
//     else
//     {
//         printf("未找到%d", f.key);
//     }
//     printf("\n插入关键字:%d", f.key);
//     InsertHash(H, f);
//     DisplayHashTable(H);
//     return 0;
// }

// ----- 排序数组的存储结构 -----

// #define EQ(a, b) ((a) == (b))
// #define LT(a, b) ((a) < (b))
// #define MAXSIZE 20 // 顺序表的最大长度
// #define DLTALENGTH 5
// typedef int KeyType; // 定义关键字类型
// typedef int InfoType;
// typedef struct
// {
//     KeyType key;        // 关键字项
//     InfoType otherinfo; // 其他数据项
// } RedType;              // 记录类型
// typedef struct
// {
//     RedType r[MAXSIZE + 1]; // r[0]闲置或者用作哨兵单元
//     int length;             // 顺序表长度
// } SqList;                   // 顺序表类型
//
// int dlta[DLTALENGTH] = {41, 19, 5, 1, 0};

// ----- 辅助函数 -----

// void Print(SqList L)
// {
//     for (int i = 1; i <= L.length; i++)
//     {
//         printf("%d ", L.r[i].key);
//     }
// }
//
// void Print(SqList L, SqList Q)
// {
//     for (int i = 1; i <= L.length; i++)
//     {
//         printf("<%d,%d> ", L.r[i].key, Q.r[i].key);
//     }
// }

// ----- 直接插入排序 -----

// void InsertSort(SqList &L)
// {
//     int i, j; // i为插入的趟数，j为待比较位
//     for (i = 2; i < L.length; ++i)
//     { // 共进行n-1趟插入
//         if (LT(L.r[i].key, L.r[i - 1].key))
//         {                    //'<'时，将L.r[i]插入有序子表
//             L.r[0] = L.r[i]; // 复制为哨兵
//             for (j = i - 1; LT(L.r[0].key, L.r[j].key); j--)
//             {
//                 L.r[j + 1] = L.r[j]; // 记录后移
//             }
//             L.r[j + 1] = L.r[0]; // 插入到正确位置，j左移一位，故j+1
//         }
//     }
// }

// ----- 折半插入排序 -----

// void BInsertSort(SqList &L)
// { // 对顺序表L作折半插入排序
//     int i, j, high, low, m;
//     for (i = 2; i <= L.length; ++i)
//     {                    // r[1]已在序列中
//         L.r[0] = L.r[i]; // 将L.r[i]暂存到L.r[0]中
//         low = 1;
//         high = i - 1;
//         while (low <= high)
//         {                         // 在r[low..high]中折半查找有序插入的位置
//             m = (low + high) / 2; // 折半
//             if (LT(L.r[0].key, L.r[m].key))
//             { // 插入点在低半区
//                 high = m - 1;
//             }
//             else
//             { // 插入点在高半区
//                 low = m + 1;
//             }
//         } // 退出循环的上一个状态是low,high,m重合
//         for (j = i - 1; j >= high + 1; --j)
//         {                        // high+1是待插入的位置
//             L.r[j + 1] = L.r[j]; // 记录后移
//         }
//         L.r[high + 1] = L.r[0]; // 插入到high +1
//     }
// }

// ----- 希尔排序 -----

// void ShellInsert(SqList &L, int dk)
// { // 对顺序表L作一趟希尔插入排序，前后记录位置的增量是dk，而不是1
//     int i, j;
//     for (i = dk + 1; i <= L.length; i++)
//     {
//         if (LT(L.r[i].key, L.r[i - dk].key))
//         {                    // 需将L.r[i]插入有序增量子表
//             L.r[0] = L.r[i]; // 暂存在L.r[0]
//             for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk)
//             {
//                 L.r[j + dk] = L.r[j]; // 记录后移，查找插入位置
//             }
//             L.r[j + dk] = L.r[0]; // 插入
//         }
//     }
// }
//
// void ShellSort(SqList &L, int dlta[], int t)
// { // t是数组长度，按增量序列dlta[0..t-1]对顺序表L作希尔排序
//     for (int k = 0; k < t; ++k)
//     {
//         printf("\n第%d趟排序结果:", k);
//         Print(L);
//         ShellInsert(L, dlta[k]); // 一趟增量为dlta[k]的插入排序
//     }
// }

// ----- 冒泡排序 -----

// void Bubble(SqList *p)
// {
//     int n = p->length;
//     for (int i = 1; i < n; i++)
//     { // 0号位置置空，作为数据暂存空间
//         int flag = 0;
//         for (int j = 1; j <= n - i; j++)
//         {
//             if (p->r[j].key > p->r[j + 1].key)
//             {
//                 p->r[0] = p->r[j];
//                 p->r[j] = p->r[j + 1];
//                 p->r[j + 1] = p->r[0];
//                 flag = 1;
//             }
//         }
//         if (flag == 0)
//         {
//             printf("排序结束");
//             break;
//         }
//     }
// }

// ----- 快速排序 -----

// int Partition(SqList &L, int low, int high)
// { // 交换顺序表L中子序列L.r[low..high]的记录，使枢轴记录到位，并返回其所在位置，此时，在它之前（后）的记录均不大（小）于它
//     KeyType pivotkey;
//     L.r[0] = L.r[low];       // 用子表的第一个记录作为枢轴记录
//     pivotkey = L.r[low].key; // 枢轴记录关键字
//     while (low < high)
//     { // 从表的两端交替地向中间扫描
//         while (low < high && L.r[high].key >= pivotkey)
//         {
//             --high;
//         }
//         L.r[low] = L.r[high]; // 将比枢轴记录小的记录移到低端
//         while (low < high && L.r[low].key <= pivotkey)
//         {
//             ++low;
//         }
//         L.r[high] = L.r[low]; // 将比枢轴记录大的记录移到高端
//     }
//     L.r[low] = L.r[0]; // 枢轴记录到位
//     return low;        // 返回枢轴位置
// }
//
// void QSort(SqList &L, int low, int high)
// { // 对顺序表L中的子序列L.r[low..high]进行快速排序
//     int pivotloc;
//     if (low < high)
//     {                                       // 待排序列长度大于1
//         pivotloc = Partition(L, low, high); // 将L.r[low..high]一分为二
//         QSort(L, low, pivotloc - 1);        // 对低子表递归排序，pivotloc是枢轴位置
//         QSort(L, pivotloc + 1, high);       // 对高子表递归排序
//     }
// }
//
// void QuickSort(SqList &L)
// { // 对顺序表L进行快速排序
//     QSort(L, 1, L.length);
// }

// ----- main() -----

// int main()
// {
//     SqList array;
//     array.length = MAXSIZE;
//     srand((unsigned int)time(NULL)); // 修改种子
//     for (int i = 1; i <= array.length; i++)
//     {
//         array.r[i].key = rand() % 100;
//     }
//     printf("\n排序前序列:");
//     Print(array);
//     char choice = '1';
//     while (choice == '1')
//     {
//         SqList copy = array;
//
//         printf("\n请选择排序方式:\n1.直接插入排序\n2.折半插入排序\n3.希尔排序\n4.快速排序\n");
//         char ch = getchar();
//         switch (ch)
//         {
//         case '1':
//             InsertSort(copy);
//             printf("\n直接插入排序后:");
//             Print(copy, array);
//             break;
//         case '2':
//             BInsertSort(copy);
//             printf("\n折半插入排序后:");
//             Print(copy, array);
//             break;
//         case '3':
//             ShellSort(copy, dlta, DLTALENGTH);
//             printf("\n希尔排序后:");
//             Print(copy, array);
//             break;
//         case '4':
//             QuickSort(copy);
//             printf("\n快速排序后:");
//             Print(copy, array);
//             break;
//         }
//         while (char d = getchar() != '\n')
//             ;
//         printf("\n是否继续选择其他排序方法:\n1.是\n2.否\n");
//         choice = getchar();
//         while (char d = getchar() != '\n')
//             ;
//     }
//     return 0;
// }

// ----- 排序数组的存储结构 -----

// #define EQ(a, b) ((a) == (b))
// #define LT(a, b) ((a) < (b))
// #define MAXSIZE 20
//
// typedef int KeyType; // 定义关键字类型
// typedef int InfoType;
// typedef struct
// {
//     KeyType key;        // 关键字项
//     InfoType otherinfo; // 其他数据项
// } RedType;              // 记录类型
// typedef struct
// {
//     RedType r[MAXSIZE + 1]; // r[0]闲置或者用作哨兵单元
//     int length;             // 顺序表长度
// } SqList, HeapType;         // 顺序表类型

// ----- 辅助函数 -----

// void Print(SqList L)
// {
//     for (int i = 1; i <= L.length; i++)
//     {
//         printf("%d ", L.r[i].key);
//     }
// }

// ----- 二路归并排序 -----

// void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
// { // 已知顺序线性表La和Lb的元素按值非递减排列，归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列
//     RedType *pa = La.r, *pb = Lb.r, *pc, *pa_last, *pb_last;
//     Lc.length = La.length + Lb.length;
//     pc = Lc.r;
//     pa_last = La.r + La.length - 1;
//     pb_last = Lb.r + Lb.length - 1;
//     while (pa <= pa_last && pb <= pb_last)
//     { // 归并
//         ((*pa).key <= (*pb).key) ? (*pc++ = *pa++) : (*pc++ = *pb++);
//         while (pa <= pa_last)
//         {
//             *pc++ = *pa++; // 插入La的剩余元素
//         }
//         while (pb <= pb_last)
//         {
//             *pc++ = *pb++; // 插入Lb的剩余元素
//         }
//     }
// }
//
// void Merge(RedType SR[], RedType *TR, int i, int m, int n)
// {             // 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
//     int j, k; // j是从m+1开始的SR[]中的数组下标，k是TR[]中的数组下标
//     for (j = m + 1, k = i; i <= m && j <= n; ++k)
//     { // 将SR中记录由小到大地并入TR
//         (LT(SR[i].key, SR[j].key)) ? (TR[k] = SR[i++]) : (TR[k] = SR[j++]);
//     }
//     if (i <= m)
//     { // 将剩余的SR[i..m]复制到TR
//         while (k <= n && i <= m)
//         {
//             TR[k++] = SR[i++];
//         }
//     }
//     if (j <= n)
//     { // 将剩余的SR[j..m]复制到TR
//         while (k <= n && j <= n)
//         {
//             TR[k++] = SR[j++];
//         }
//     }
// }
//
// void MSort(RedType SR[], RedType *TR1, int s, int t)
// { // 将SR[s..t]归并排序为TR1[s..t]
//     int m;
//     RedType TR2[MAXSIZE]; // 暂存序列
//     if (s == t)
//     {
//         TR1[t] = SR[s]; // 递归基本项
//     }
//     else
//     {
//         m = (s + t) / 2;          // 将SR[s..t]平分为SR[s..m]和SR[m+1..t]
//         MSort(SR, TR2, s, m);     // 递归地将SR[s..m]归并为有序的TR2[s..m]
//         MSort(SR, TR2, m + 1, t); // 将SR[m+1..t]归并为有序的TR2[m+1..t]
//         Merge(TR2, TR1, s, m, t); // 将TR2[s..m]和TR[m+1..t]归并到TR1[s..t]
//     }
// }
//
// void MergeSort(SqList &L)
// { // 对顺序表L作归并排序
//     MSort(L.r, L.r, 1, L.length);
// }

// ----- 堆排序算法 -----

// void HeapAdjust(HeapType &H, int s, int m)
// { // 已知H.r[s..m]中记录的关键字除H.r[s].key之外均满足堆的定义，本函数调整H.r[s]的关键字，使H.r[s..m]成为一个大顶堆(对其中记录的关键字而言)
//     int j;
//     RedType rc;
//     rc = H.r[s];
//     for (j = 2 * s; j <= m; j *= 2)
//     {
//         if (j < m && H.r[j].key < H.r[j + 1].key)
//         {        // 沿key较大的子结点向下筛选
//             ++j; // j为key较大的记录的下标
//         }
//         if (rc.key >= H.r[j].key)
//         {
//             break; // rc应插入在位置s上
//         }
//         H.r[s] = H.r[j];
//         s = j;
//     }
//     H.r[s] = rc; // 插入
// }
//
// void HeapSort(HeapType &H)
// {
//     int i;
//     RedType temp;     // 把H.r[1..H.length]建成大顶堆
//     for (i = H.length / 2; i > 0; --i)
//     {
//         HeapAdjust(H, i, H.length);
//     }
//     for (i = H.length; i > 1; --i)
//     {
//         temp = H.r[i]; // 将堆顶记录和当前未经排序子序列Hr[1..i]中最后一个记录相互交换
//         H.r[i] = H.r[1];
//         H.r[1] = temp;         // 将H.r[1..i-1]重新调整为大顶堆
//         HeapAdjust(H, 1, i - 1);
//     }
// }

// ----- main() -----

// int main()
// {
//     SqList array;
//     array.length = MAXSIZE;
//     srand((unsigned int)time(NULL)); // 修改种子
//     for (int i = 1; i <= array.length; i++)
//     {
//         array.r[i].key = rand() % 100;
//     }
//     printf("\n排序前序列:");
//     Print(array);
//     char choice = '1';
//     while (choice == '1')
//     {
//         SqList copy = array;
//         printf("\n请选择排序方式:\n1.二路归并排序\n2.堆排序\n");
//         char ch = getchar();
//         switch (ch)
//         {
//         case '1':
//             MergeSort(copy);
//             printf("\n二路归并排序后:");
//             Print(copy);
//             break;
//         case '2':
//             HeapSort(copy);
//             printf("\n堆排序后:");
//             Print(copy);
//             break;
//         }
//         while (char d = getchar() != '\n')
//             ;
//         printf("\n是否继续选择其他排序方法:\n1.是\n2.否\n");
//         choice = getchar();
//         while (char d = getchar() != '\n')
//             ;
//     }
//     return 0;
// }
