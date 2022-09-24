#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int a = 0;
//	//printf("hello world\n");
//	scanf("%d", &a);
//	printf("%d\n", a);
//
//	return 0;
//}


//编写一个程序输出"hello world!"。
/*#include <stdio.h>
int main()
{

    printf("hello world!");

    return 0;

}*/


//编写一个程序输出一个“*”组成的三角形，最底边有七个“*”。
/*#include <stdio.h>
int main()
{

    printf("   * \n  *** \n ***** \n*******\n");

    return 0;

}*/


//编写一个程序能够计算已知三条边的三角形的面积。
#include <stdio.h>
#include <math.h>
int main()
{

    float a,b,c,s,l;

    scanf("%f %f %f", &a, &b, &c);

    l=(a+b+c)/2;

    printf("s=%f\n",sqrt(l*(l-a)*(l-b)*(l-c)));

    return 0;

}


//编写一个程序能够计算一元二次方程的根。
/*#include <stdio.h>
#include <math.h>
int main()
{
    printf("请输入一元二次方程方程的abc值:\n");

    float a,b,c,x1,x2,s,l;

    scanf("%f %f %f", &a, &b, &c);

    s=b*b-4*a*c;

    l=sqrt(s);

    x1=(-b+l)/2*a,x2=(-b-l)/2*a;

    printf("该方程的表达式为: \n(%f)x*x+(%f)x+(%f)=0 \n",a,b,c);

    if(s<0)

        printf("该方程没有实数根。");

    else

        printf("该方程的两个实数根为:x1=%f,x2=%f \n",x1,x2);

    return 0;

}*/


/*编写一个程序，该程序编译、连接和运行后，在屏幕上显示下列信息：
We study the C Programming language.
We all like it.*/
/*#include <stdio.h>
int main()
{

    printf("We study the C Programing language. \nWe all like it.\n");

    return 0;

}*/


//编写一个程序，在屏幕上显示你的姓名、学号和出生日期。
/*#include <stdio.h>
int main()
{

    printf("姓名：张三 \n学号：10020222022001 \n出生日期：2000年1月1日\n");

    return 0;

}*/


/*编写一个程序，在屏幕上显示下列信息：
This Program prints a formulate:
72*88=6336
要求：
(1)必须按上面样式，分两行输出；
(2)6336不能出现在程序中，必须是程序计算出来的，可用%d的格式控制符输出。*/
/*#include <stdio.h>
int main()
{

    printf("This Program prints a formulate: \n72*88=%d\n",72*88);

    return 0;

}*/