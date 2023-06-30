#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// //判断是一年的第几天
//int main() 
//{
//    //假设每个月都是30天，然后分别计算每个月的偏差，先不考虑闰年的问题
//    // 月份
//    //1   2   3   4   5   6   7   8   9   10   11   12
//    // 每个月相对30的偏差11
//    //1  -2   1   0   1   0   1   1   0    1    0    1
//    // 每个月相对偏差之和
//    //0   1  -1   0   0   1   1   2   3    3    4    4
//    //这里要注意对没有获取值的数初始化，否则会出现报错信息
//    int year, month, day, leap_year = 0, deviation = 0;
//    scanf("%d%d%d", &year, &month, &day);
//    //四年一闰，百年不闰，四百年一闰
//    //判断是否闰年，为闰年并且大于二月则leap_year的值为1
//    leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (month > 2);
//    if (month == 1 || month == 4 || month == 5)
//    {
//        deviation = 0;
//    }
//    else if (month == 2||month == 9||month == 7) 
//    {
//        deviation = 1;
//    }
//    else if (month == 8)
//    {
//        deviation = 2;
//    }
//    else if (month == 9 || month == 10)
//    {
//        deviation = 3;
//    }
//    else if (month == 11 || month == 12)
//    {
//        deviation = 4;
//    }
//    else if (month == 3)
//    {
//        deviation = -1;
//    }
//    printf("%d", leap_year + deviation + day + (month - 1) * 30);
//}

// //菱形
//int main() 
//{
//    int n, StarNumber, SpaceNumber,i,j;
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        StarNumber = 2 * i - 1;
//        SpaceNumber = n - i;
//        for (j = 0; j <= SpaceNumber; j++)
//        {
//            printf(" ");
//        }
//        for (j = 1; j <= StarNumber; j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    for (i = n-1; i >= 0; i--)
//    {
//        StarNumber = 2 * i - 1;
//        SpaceNumber = n - i+1;
//        for (j = 1; j <= SpaceNumber; j++)
//        {
//            printf(" ");
//        }
//        for (j = 1; j <= StarNumber; j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//} 

// //哥德巴赫猜想-1.0
//int main()
//{
//    int n, pm1, pm2, i, j;
//    scanf("%d", &n);
//    for (i = 4; i <= n; i += 2)
//    {
//        for (j = 3; j <= i; j += 2)
//        {
//            pm1 = Prime_Number(j);
//            if (pm1 != 0) 
//            {
//                pm2 = i - pm1;
//                if (Prime_Number(pm2) != 0)
//                {
//                    printf("%d+%d=%d\n", pm1, pm2, i);
//                    break;
//                }
//            }
//        }
//    }
//}
// //哥德巴赫猜想-2.0
//int sushu(int x)
//{
//	int i,flag = 1;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//		{
//			flag = 0;
//			break;
//		}
//	}
//	return flag;
//}
//int main()
//{
//	int i, a, j;
//	for (i = 4; i <= 1000; i+=2)
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (sushu(j) == 1)
//			{
//				a = i - j;
//				if (sushu(a) == 1)
//				{
//					printf("%d+%d=%d\n", a, j, i);
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}

// //最大公约数 最小公倍数
//int gcd(int a, int b)
//{
//	int t;
//	while (b != 0)
//	{
//		t = a % b;//不用判断a和b的大小，如果a<b会自动交换a,b的值再进行循环
//		a = b;
//		b = t;
//	}
//	return a; //不能返回b,因为b已经为0了
//}
//int lcm(int a, int b)
//{
//
//	return (a * b / gcd(a, b));
//}
//int main(void)
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	printf("%d %d", gcd(a, b), lcm(a, b));
//	return 0;
//}

// //统计句子中元音字母的个数
//int main()
//{
//	char lowerletter[5] = { 'a','e','i','o','u' }, upperletter[5] = { 'A','E','I','O','U' }, a = 'a', store[1] = { 'a' };
//	int i, count = 0, flag = 0, j;
//	scanf("%c", &store[0]);
//	for (j = 0; j <= 4; j++)
//	{
//		if (store[0] == upperletter[j])
//		{
//			flag = 1;
//			count++;
//			break;
//		}
//	}
//	while (a != '.')
//	{
//		scanf("%c", &a);
//		for (i = 0; i <= 4; i++)
//		{
//			(a == lowerletter[i]) ? (count++) : (count = count);
//		}
//	}
//	(flag == 1) ? (printf("是\n")) : (printf("不是\n"));
//	printf("%d", count);
//	return 0;
//}

// //统计单词的长度
//int main()
//{
//	int count = 0;
//	char a = 'a';
//	while (a != '.')
//	{
//		scanf("%c", &a);
//		count++;
//		if (a == ' ')
//		{
//			if (count - 1 != 0)
//			{
//				printf("%d ", count - 1);
//			}
//			count = 0;
//		}
//	}
//	(count - 1 != 0) ? (printf("%d ", count - 1)) : (count = count);
//	return 0;
//}

// //计算大写字母组成的字符串中不同字母个数
//int main() 
//{
//	char string[300];
//	int i, letter[26] = { 0 },count = 0; //将26个字母存在一个数组里面
//	gets(string);
//	for (i = 0; string[i]; i++)
//	{
//		if (string[i] <= 'Z' && string[i] >= 'A')
//		{
//			letter[string[i] - 65] = 1; //当找到一次就把值换成1，这样就不会重复计算
//		}
//	}
//	for (i = 0; i < 26; i++)
//	{
//		(letter[i] != 0) ? (count++) : (count = count);
//	}
//	printf("%d", count);
//}

// //统计字符串中某个字符出现次数
//int main() 
//{
//	char letter = 'a', string[500] = {0};
//	int i,count = 0;
//	scanf("%c", &letter);
//	gets(string);
//	for (i = 0; string[i]; i++)
//	{
//		if (string[i] == letter)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//}

// //删去英文句子中多余的空格，并且输出句子的长度
//int main()
//{
//	//目的：删除多余的空格
//	char string[300];
//	int i, count = 1,num = 0;
//	char c;
//	gets(string);
//	for (i = 0; (c = string[i]) != '\0'; i++)
//	{
//		if (c == ' ' && count != 1) 
//		{
//			printf("%c", c);
//			count = 1;
//			num++;
//		}
//		else if (c != ' ') 
//		{
//			printf("%c", c);
//			count = 0;
//			num++;
//		}
//	}
//	printf("\n%d\t%d", strlen(string),num);
//	//总结：出现第一个空格后把count标记为1，只有count满足不为1的时候才能输出空格
//	//在输出非字符后将count设为0，后续才能输出空格
//	//num用来统计输出后的字符串长度，只有输出的时候才+1，于是就是输出的字符串的长度
//}

// //不调用strcpy函数，把字符数组str2中的字符串复制到字符数组str1中
//int main()
//{
//	int i, j;
//	char str1[300], str2[300];
//	gets(str2);
//	for (i = 0; str2[i] != '\0'; i++)
//	{
//		str1[i] = str2[i];
//	}
//	str1[i] = '\0';
//	puts(str1);
//}

// //求几月几日
//int main()
//{
//	int b[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int x, i = 1,sum = 0;
//	scanf("%d", &x);
//	while (sum + b[i] < x)
//	{
//		sum += b[i];
//		i++;
//	}
//	printf("第%d天是%d月%d日", x, i, x - sum);
//}

// //统计数字0-9的出现次数-1.0
//int main()
//{
//	int b[10] = { 0 }, i, x, a[100] = { 0 };
//	for (i = 0; i < 100; i++)
//	{
//		a[i] = 10;
//	}
//	scanf("%d", &x);
//	int j = 0;
//	while (x)
//	{
//		a[j] = x % 10;
//		x /= 10;
//		j++;
//	}
//	for (i = 0; i <= j; i++)
//	{
//		int k;
//		for (k = 0; k < 10; k++)
//		{
//			(a[i] == k) ? (b[k]++) : (i = i);
//		}
//	}
//	for (i = 0; i < 100; i++)
//	{
//		(a[i] == 10) ? (a[i] = 0) : (i = i);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("数字%d出现:%d次\n", i, b[i]);
//	}
//	return 0;
//}
// //统计数字0-9的出现次数-2.0
//void main() 
//{
//    int num[10] = { 0 }, i;
//    char c;
//    while ((c = getchar()) != '\n') 
//    {
//        num[c - 48]++;
//    }
//    for (i = 0; i < 10; i++) 
//    {
//        printf("%d出现:%d\n", i, num[i]);
//    }
//}

// //车牌限行-中文版
//#include <stdio.h>
//int main()
//{
//	char lic[10] = { 0 };
//	//lic数组用来存储输入的字符
//	int flag = 0, i = 0, j, num = 0, odd = 0,temp = 0;
//	//flag 用来记录是否出现数字 
//	//当flag = 1时有数字
//	//num 用来记录没有出现其他字符的次数
//	//odd 用来记录最后一个出现的数字是否为奇数
//	//当odd = 1时最后一个数字为奇数
//	gets(lic);
//	if (lic[5] != 0&&lic[5]!=10)//ASCII码“10”代表回车，即'\n'
//	{
//		flag = 0;
//	}
//	else
//	{
//		for (j = 0; j < 5; j++)
//		{
//			if (lic[j] <= '9' && lic[j] >= '0')
//			{
//				flag = 1;
//				temp = lic[j];
//				num++;
//			}
//			if (lic[j] <= 'Z' && lic[j] >= 'A')
//			{
//				num++;
//			}
//		}
//		if ((temp <= '9' && temp >= '0') && (temp % 2))
//		{
//			odd = 1;
//		}
//	}
//	if (num == 5&& flag == 1)
//	{
//		(odd) ? (printf("限行\n")) : (printf("通行\n"));
//	}
//	else
//	{
//		printf("非法输入\n");
//	}
//	return 0;
//}
// //车牌限行-English
//int main()
//{
//    char lic[10] = { 0 };
//    //lic Array used to store the input character
//    int flag = 0, i = 0, j, num = 0, odd = 0, temp = 0;
//    //flag Used to record whether a number appears  
//    //There is a number when flag = 1
//    //num Used to record the number of times no other characters have appeared
//    //odd Used to record whether the last occurrence of the number is an odd number
//    //The last number is odd when odd = 1
//    gets(lic);
//    if (lic[5] != 0 && lic[5] != 10)//ASCII "10" on behalf of the carriage return, that is, '\ n'
//    {
//        flag = 0;
//    }
//    else
//    {
//        for (j = 0; j < 5; j++)
//        {
//            if (lic[j] <= '9' && lic[j] >= '0')
//            {
//                flag = 1;
//                temp = lic[j];
//                num++;
//            }
//            if (lic[j] <= 'Z' && lic[j] >= 'A')
//            {
//                num++;
//            }
//        }
//        if ((temp <= '9' && temp >= '0') && (temp % 2))
//        {
//            odd = 1;
//        }
//    }
//    if (num == 5 && flag == 1)
//    {
//        (odd) ? (printf("traffic limit\n")) : (printf("Pass\n"));
//    }
//    else
//    {
//        printf("illegal input\n");
//    }
//    return 0;
//}

// //统计单词的个数
//#include <stdio.h>
//void main()
//{
//	int i,count = 0;
//	char str[300] = { '\0' };
//	gets(str);
//	if (str[0] != ' ')
//	{
//		count++;
//	}
//	for (i = 1; i < 300; i++)
//	{
//		if ((str[i] == ' ') || (str[i] == '.') || (str[i] == ','))
//		{
//			if ((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
//			{
//				count++;
//			}
//		}
//	}
//	printf("%d", count);
//}

// //金字塔图形
//void draw(int n);
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	draw(n);
//}
//void draw(int n)
//{
//	int i,j,SpaceNumber,LetterNumber;
//	for (i = 1; i <= n; i++)
//	{
//		SpaceNumber = n - i;
//		LetterNumber = (2 * n - 1) - 2 * SpaceNumber;
//		for (j = 1;j<=SpaceNumber;j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= LetterNumber; j++)
//		{
//			printf("%c", 'A' + j - 1);
//		}
//		printf("\n");
//	}
//}

// //提取字符串中的数字
//int conv(char arr[]); //conv()函数提取数字并把数字变成一个整数返回主函数
//int main()
//{
//    int n; //一共有n个字符串
//    scanf("%d", &n);
//    char arr[21];
//    for (int i = 0; i < n; i++) 
//    {
//        scanf("%s", &arr); //%s是字符串型格式符
//        printf("%d  ", conv(arr)); //数组名的值是数组首元素的指针常量
//    }
//}
//int conv(char arr[])
//{
//    int sum = 0;
//    for (int i = 0; arr[i] != '\0'; i++) //字符串以'\0'结尾
//    {
//        if (arr[i] >= '0' && arr[i] <= '9')
//        {
//            sum = sum * 10 + arr[i] - '0'; //arr[]中存储的是数字的ASCII码，要转换成数字
//        }
//    }
//    return sum;
//}

// //求所有字符串中包含了多少个不同的英文字母（同一个字母的大小写视为不同字母），以end结束程序并且end不计入字母个数
//int main() 
//{
//    char att[129];
//    int ascii[128] = { 0 }; //用ASCII来标记不同的字母，没有的为0，有的为1
//    scanf("%s", &att);
//    int len = 0, flag = 0; //len计算第1个字符串的长度，flag判断字符串是否为end，是的话flag=0，否则flag=1
//    while (att[len] != '\0') 
//    {
//        len++;
//    }
//    if (len != 3) //判断字符串是不是end
//    {
//        flag = 1;
//    }
//    else if (att[0] != 'e' || att[1] != 'n' || att[2] != 'd') 
//    {
//        flag = 1;
//    }
//    else 
//    {
//        flag = 0;
//    }
//    while (flag) //用循环和scanf()函数来获取第2个到第n个字符串，用回车隔开不同的字符串
//    {
//        for (int i = 0; i < len; i++) //第1次循环先判断第1个字符串中的不同字母，接下来的循环判断后面的字符串中不同的字母
//        {
//            if ((att[i] >= 'a' && att[i] <= 'z') || (att[i] >= 'A' && att[i] <= 'Z'))
//            {
//                ascii[att[i] - '\0'] = 1; //用att[i]-'\n'来获取字母在ASCII中的编号
//            }
//        }
//        scanf("%s", &att);
//        len = 0; //每次循环结束要重新计算字符串的长度
//        while (att[len] != '\0') 
//        {
//            len++;
//        }
//        flag = 0; //每次循环结束要重新判断该字符串是不是end
//        if (len != 3) 
//        {
//            flag = 1;
//        }
//        else if (att[0] != 'e' || att[1] != 'n' || att[2] != 'd') 
//        {
//            flag = 1;
//        }
//        else 
//        {
//            flag = 0;
//        }
//    }
//    int count = 0; //count计算不同字母的个数
//    for (int i = 0; i < 128; i++) 
//    {
//        count += ascii[i]; 
//    }
//    printf("%d", count);
//    return 0;
//}

// //变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，比如1461 可以拆分成（1和461）, （14和61）, （146和1), 
// //如果所有拆分后的乘积之和等于自身，则是一个Lily Number。例如：655 = 6 * 55 + 65 * 5  1461 = 1 * 461 + 14 * 61 + 146 * 1
// //求出 5位数中的所有 Lily Number。
//int main() 
//{
//    int n = 0;
//    for (n = 10000; n <= 99999; n++) 
//    {
//        int i = 0;
//        int sum = 0;
//        for (i = 1; i <= 4; i++) //因为只有五位数所以循环四次
//        {
//            //很巧妙的转换，这个方法也能扩展到不止五位数，但是要注意记得给指数强制转换成int型，才能符合除法和取余法则
//            sum += (n / (int)pow(10.0, i)) * (n % (int)pow(10.0, i)); 
//        }
//        if (n == sum) 
//        {
//            printf("%d ", n);
//        }
//    }
//    return 0;
//}

// //从1开始按从小到大的顺序输出所有回文数
//int main() 
//{
//    int n, sum, b;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) 
//    {
//        b = i; //用b来存储i保证i不会在while循环中改变
//        sum = 0;
//        while (b) 
//        {
//            sum = sum * 10 + b % 10; //取出每一位数的同时将上一次取出的位数乘10
//            b /= 10;
//        }
//        if (sum == i) 
//        {
//            printf("%d\n", sum);
//        }
//    }
//    return 0;
//}

// //判断密码输入的合法性
// //要求如下：密码需在8-20位，且必须包含大写字母、小写字母和数字，至少有!、$、%其中一个特殊字符。
//int main()
//{
//	int n,i, count = 0; //n代表输入的密码个数
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int k, digit = 0, let1 = 0, let2 = 0, spe = 0, len = 0;
//		char str[100] = { 0 };
//		scanf("%s", str);
//		len = strlen(str); //用strlen()函数求字符串也就是密码的长度
//		if (len >= 8 && len <= 20) //判断密码长度是否在8-20位之间
//		{
//			for (k = 0; k <= len; k++)
//			{
//				if (str[k] <= 'Z' && str[k] >= 'A') //判断是否有大写字母
//				{
//					let1 = 1;
//				}
//				if (str[k] <= 'z' && str[k] >= 'a') //判断是否有小写字母
//				{
//					let2 = 1;
//				}
//				if (str[k] <= '9' && str[k] >= '0') //判断有无数字
//				{
//					digit = 1;
//				}
//				if (str[k] == '%' || str[k] == '!' || str[k] == '$') //判断是否有特殊字符
//				{
//					spe = 1;
//				}
//			}
//		}
//		if (spe + digit + let1 + let2 != 4)
//		{
//			count++; //计算不符合要求的密码个数
//		}
//	}
//	printf("%d", count);
//}

// //输入3个整数，按从小到大的顺序输出（用指针）
//void swap(int* p1, int* p2)
//{
//	int p;
//	p = *p1;
//	*p1 = *p2;
//	*p2 = p;
//}
//void main()
//{
//	int a, b, c;
//	int* p1, * p2, * p3;
//	scanf("%d,%d,%d", &a, &b, &c);
//	p1 = &a;
//	p2 = &b;
//	p3 = &c;
//	if (a > b)
//	{
//		swap(p1, p2);
//	}
//	if (a > c)
//	{
//		swap(p1, p3);
//	}
//	if (b > c)
//	{
//		swap(p2, p3);
//	}
//	printf("%d,%d,%d", a, b, c);
//}

// //用指针实现冒泡排序
// void sort(int *x, int a);
// void main()
// {
// 	int i, a[10] = { 9,8,7,6,5,4,3,2,1,0 };
// 	for (i = 0; i < 10; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	printf("\n");
// 	sort(a, 10);
// 	for (i = 0; i < 10; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// }
// void sort(int *x,int n)
// {
// 	int *i, *j, swap;
// 	for (i = x; i <= x + n - 1; i++)
// 	{
// 		for (j = i + 1; j <= x + n - 1; j++)
// 		{
// 			if (*i > *j)
// 			{
// 				swap = *i;
// 				*i = *j;
// 				*j = swap;
// 			}
// 		}
// 	}
// }

// //用指针实现复制字符串
//void main()
//{
//	char a[] = "I am a boy", b[20] = { 0 }, * p1, * p2;
//	p1 = a,p2 = b;
//	while (*p1 != '\0')
//	{
//		*p2 = *p1;
//		p1++, p2++;
//	}
//	*p2 = '\0';
//	printf("%s", b);
//}

// //用指针实现把10个数中最小的数与第一个对换，最大的数与最后一个对换，且不改变其他数的位置
//void swap(int* p);
//void main()
//{
//	int a[10], i, * p = a;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", p++);
//	}
//	p = a; //指针回指
//	swap(p);
//	p = a;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p++);
//	}
//}
//void swap(int* p)
//{
//	int* max = p, * min = p, i, swap, * temp = p + 9;
//	for (i = 0; i < 10; i++)
//	{
//		if (*p > *max)
//		{
//			max = p;
//		}
//		if (*p < *min)
//		{
//			min = p;
//		}
//		p++;
//	}
//	//交换最小的数
//	p -= 10;
//	swap = *min;
//	*min = *p;
//	*p = swap;
//	//交换最大的数
//	swap = *max;
//	*max = *temp;
//	*temp = swap;
//}

// //输入3个字符串，按由小到大的顺序输出
//void swap(char** p);//比较3个字符串的大小
//void swap_f(char** p1, char** p2);//交换字符串
//void main()
//{
//	//将字符串存储在数组中防止以下情况发生:
//	//如果用指针直接指向字符串（char* str = "AA"），会使得存储最小的字符串的大小固定，
//	//导致在使用strcpy(str,str_2)函数时str_2的字符串长度大于str字符串的长度造成str指向的字符串溢出，
//	//因此改用指针指向更长的字符串数组来防止字符串溢出
//	char str1[100], str2[100], str3[100];
//	//用指针数组来表示可以用for循环来控制输入、打印字符串，减少重复puts()函数引用
//	char* str[3] = { str1,str2,str3 };
//	char** str_1 = str;//用指向指针数组的指针来传递形参，减少传递的形参个数
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		gets(str[i]);
//	}
//	swap(str_1);
//	for (i = 0; i < 3; i++)
//	{
//		puts(str[i]);
//	}
//}
//void swap(char** p)//比较3个字符串的长度（有改进空间）- 可以尝试用冒泡算法
//{
//	if (strcmp(*p, *(p+1)) > 0)
//	{
//		swap_f(p, p + 1);
//	}
//	if (strcmp(*p, *(p + 2)) > 0)
//	{
//		swap_f(p, p + 2);
//	}
//	if (strcmp(*(p+1), *(p + 2)) > 0)
//	{
//		swap_f(p+1, p+2);
//	}
//}
//void swap_f(char** p1, char** p2)
//{
//	char swap[100];
//	strcpy(swap, *p1);
//	strcpy(*p1, *p2);
//	strcpy(*p2, swap);
//}

// //用指针求一个字符串的长度
//void main()
//{
//	char str[100];
//	char* p = str;
//	gets(p);
//	int count = 0;
//	while (*p++ != '\0') //指针先自增然后再取地址，++和*的运算顺序都是从右到左
//	{
//		count++;
//	}
//	// //相当于下面的程序
//	//while (*p != '\0')
//	//{
//	//	count++;
//	//	p++;
//	//}
//	printf("%d\n", count);
//}

// //将一个长度为n的字符串从第m个字符开始的全部字符复制成为另外一个字符串
//void copy(char *p,char *k,int m);
//void main()
//{
//	int m = 4;
//	char str1[100], str2[100];
//	char* p = str1, * k = str2;
//	gets(p);
//	scanf("%d", &m);
//	copy(p,k,m);
//}
//void copy(char* p,char *k,int m)
//{
//	if (m > strlen(p))
//	{
//		printf("Error\n");
//	}
//	else
//	{
//		strcpy(k, p + m - 1); //理解strcpy()函数的意义
//		puts(k);
//	}
//}

// //用指向指针的指针对10个不等长字符串进行排序
//void sort_select(char **p); //用选择排序法对10个字符串进行排序
//void sort_bubble(char** p); //用冒泡排序法对10个字符串进行排序
//void main()
//{	
//	int i;
//	char str[10][100];
//	char* arr[10];
//	char** p = arr;
//	for (i = 0; i < 10; i++)  //使用指针来指向字符串数组，避免一些gets()函数的问题，比如缓冲区溢出的问题
//	{
//		arr[i] = &str[i];
//		scanf("%s", &str[i]);
//	//	gets(p); //gets()函数仍然存在问题暂时未解决用字符串数组代替
//	//	p++;
//	}
//	p = arr;
//	printf("Using Select Sort\n");
//	sort_select(p);
//	for (i = 0; i < 10; i++)
//	{
//		puts(*p);
//		p++;
//	}
//	printf("Using Bubble Sort\n");
//	p = arr;
//	sort_bubble(p);
//	for (i = 0; i < 10; i++)
//	{
//		puts(*p);
//		p++;
//	}
//}
//void sort_select(char** p)
//{
//	char* temp = NULL;
//	int i,j;
//	for (i = 0; i < 9; i++)
//	{
//		for (j = i; j < 9; j++)
//		{
//			if (strcmp(*(p + i), *(p + j + 1)) > 0)
//			{
//				temp = *(p + i);
//				*(p + i) = *(p + j + 1);
//				*(p + j + 1) = temp;
//			}
//		}
//	}
//}
//void sort_bubble(char** p)
//{
//	char* temp = NULL;
//	int i, j;
//	for (i = 0; i < 9; i++)
//	{
//		for (j = 0; j < 9; j++)
//		{
//			if (strcmp(*(p + j), *(p + j + 1)) > 0)
//			{
//				temp = *(p + j);
//				*(p + j) = *(p + j + 1);
//				*(p + j + 1) = temp;
//			}
//		}
//	}
//}

// //计算三个选举人所获得的票数
//void main()
//{
//	int i, j;
//	char leader_name[20] = "Who", leader_people[3][20] = {"Li","Zhang","Fang"};
//	char* p = leader_name; //让指针指向一个字符串数组似乎能够解决gets()函数的读入问题
//	struct leader //定义一个结构体来存储每个候选人的名字及其票数
//	{
//		char name[20];
//		int count;
//	} leader[3] = { "Li",0,"Zhang",0,"Fang",0 }; //定义一个结构体变量不需要","来分隔结构体类型和结构体变量
//	for (i = 1; i <= 2; i++) //统计票数
//	{
//		gets(p);
//		for (j = 0; j < 3; j++) //可以用循环来代替下面的if else来对条件进行判断
//		{
//			if (strcmp(p, leader_people[j]) == 0)
//			{
//				leader[j].count++;
//			}
//		}
//		//if (strcmp(p, "Li") == 0)
//		//{
//		//	leader[0].count++;
//		//}
//		//else if (strcmp(p, "Zhang") == 0)
//		//{
//		//	leader[1].count++;
//		//}
//		//else if (strcmp(p, "Fang") == 0)
//		//{
//		//	leader[2].count++;
//		//}
//	}
//	printf("The number of votes:\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s = %d\n", leader[i].name, leader[i].count);
//	}
//}

// //给定一个集合s(s集合元素数量<=30)，求出此集合所有子集元素之和
//void main()
//{
//	int sum = 0, count = 0, i = 1, num[31];
//	while (scanf("%d", &num[i]) != EOF)
//	{
//		//if (getchar() != ' ') //取巧的方法，不同数据之间用空格来分隔，如果不是空格就结束
//		//{
//		//	break;
//		//}
//		i++;
//	}
//	int j;
//	for (j = 1; j <= i; j++)
//	{
//		sum += num[j] * pow(2, i-1);
//	}
//	printf("%d", sum);
//}

// //输入、输出学生的学号、姓名、平均分，并且按照学生的平均分大小进行排序
//struct student 
//{
//	int num;
//	float avg;
//	char name[20];
//	int score[3];
//} stu[5];
//void print(struct student* p)//调用函数输出学生的学号、姓名和平均分
//{
//	int i, j;
//	struct student* k = p, swap;
//	for (k = p; k < p + 5; k++) //分别计算每个学生的三个科目的平均分
//	{
//		for (i = 0; i < 3; i++)
//		{
//			k->avg += k->score[i];
//		}
//		k->avg /= 3; //记得平均分要除以3
//	}
//	for (j = 0; j < 5; j++) //用选择排序法，按照平均分从小到大重新排列学生的顺序
//	{
//		for (i = j + 1; i < 5; i++)
//		{
//			if (stu[j].avg > stu[i].avg)
//			{
//				swap = stu[j];
//				stu[j] = stu[i];
//				stu[i] = swap;
//			}
//		}
//	}
//	for (; p < stu + 5; p++) //输出学生的学号、姓名和平均分
//	{
//		printf("%d\t%s\t%.2f\n", p->num, p->name, p->avg);
//	}
//}
//void main()
//{
//	int i;
//	struct student* p = stu, * k = p;
//	for (; k < stu + 5; k++) //输入学生的学号、姓名以及成绩
//	{
//		scanf("%d%s", &k->num, &k->name);
//		for (i = 0; i < 3; i++)
//		{
//			scanf("%d", &k->score[i]);
//		}
//	}
//	print(p); //用指针作为参数
//}

// //链表相关
//#include <stdlib.h> //malloc()函数的头文件,malloc()函数用于开创一个空间用于存放所需要的数据,参数是所需空间的大小
//#define NULL 0
//#define NAME Linked_list //用于更改结构体类型名
//#define LEN sizeof(struct NAME) //结构体类型所需的内存长度
//int n = 0; //用全局变量n来计算链表的长度
//struct NAME
//{
//	int num;
//	char name[20];
//	struct NAME* next; //指向下一个链表结点首地址的指针
//};
//
//// //链表的创建
//struct NAME* creat() //定义一个指针函数(返回值是指针的函数)实现动态链表的创建
//{
//	struct NAME* p1, * p2, * head = NULL; //head用于存储链表头结点
//	p1 = p2 = (struct NAME*)malloc(LEN); //强制类型转换，因为malloc()函数的返回值的指针类型和结构体不同
//	//有些情况需要用p1 != NULL来检查malloc之后空间是不是不够,如果空间不够则malloc返回空指针NULL
//	scanf("%d%s", &p1->num, &p1->name);
//	while (p1->num != NULL) //num = 0标记链表结束位置
//	{
//		n++;
//		//把第一个结点地址赋给head指针，如果不是第一个结点就让next指针指向下一个结点的首地址
//		(n == 1) ? (head = p1) : (p2->next = p1);
//		p2 = p1; //p2指针移动到下一个结点的首地址(p1指针所存储的地址)
//		p1 = (struct NAME*)malloc(LEN); //新创建一个结点
//		scanf("%d%s", &p1->num, &p1->name);
//	}
//	p2->next = NULL; //链表结束使最后一个结点的next指针指向NULL(空指针)
//	return head; //返回值是一个指针，指向链表头结点的位置
//}
//
//// //链表的输出
//void print(struct NAME* head)
//{
//	struct NAME* p;
//	p = head;
//	if (head != NULL)
//	{
//		do
//		{
//			printf("%d\t%s\n", p->num, p->name);
//			p = p->next;
//		} while (p != NULL);
//	}
//}
//
//// //链表的删除
//struct NAME* del(struct NAME* head, long num) //返回值还是一个结构体类型的指针，便于删除之后还能对新链表进行打印等操作
//{
//	struct NAME* p1, * p2;
//	if (head == NULL)
//	{
//		printf("\nList null!\n");
//		return head; //注意返回值
//	}
//	p1 = head;
//	p2 = p1;
//	while (num != p1->num && p1->next != NULL)
//	{
//		p2 = p1;
//		p1 = p1->next;
//	}
//	if (num == p1->num)
//	{
//		if (p1 == head)
//		{
//			head = p1->next;
//		}
//		else
//		{
//			p2->next = p1->next;
//		}
//		printf("delete:%d\n", num);
//		n = n - 1; //注意全局变量用法
//	}
//	else
//	{
//		printf("%d not been found!\n", num);
//	}
//	return head; //注意返回值
//}
//
//// //链表的插入
//struct NAME* insert(struct NAME* head, struct NAME* stud) //注意返回值类型
//{
//	struct NAME* p0, * p1, * p2;
//	p1 = head;
//	p0 = stud;
//	p2 = p1;
//	if (head == NULL)
//	{
//		head = p0;
//		p0->next = NULL;
//	}
//	else
//	{
//		while ((p0->num > p1->num) && (p1->next != NULL))
//		{
//			p2 = p1;
//			p1 = p1->next;
//		}
//		if (p0->num <= p1->num)
//		{
//			if (head == p1)
//			{
//				head = p0;
//			}
//			else
//			{
//				p2->next = p0;
//			}
//			p0->next = p1;
//		}
//		else
//		{
//			p1->next = p0;
//			p0->next = NULL;
//		}
//	}
//	n = n + 1;
//	return head; //注意返回值
//}
//
//void main()
//{
//	struct NAME* head, stu;
//	int del_num;
//	printf("input records:\n");
//	head = creat();
//	print(head);
//	printf("\n input the deleted number:\n");
//	scanf("%d", &del_num);
//	head = del(head, del_num);
//	print(head);
//	printf("\n input the inserted record:\n");
//	scanf("%d%s", &stu.num, &stu.name);
//	head = insert(head, &stu);
//	print(head);
//}

// //删除链表中与要删除年龄值相等的学生结点，要注意可能存在多个相同的年龄值
//#define NAME Student_linked_list
//#define LEN sizeof(struct NAME)
//#define NULL 0
//int n = 0;
//
//struct NAME
//{
//	int num;
//	char name[20];
//	char sex[6];
//	int age;
//	struct NAME* next;
//};
//
//// //链表的创建
//struct NAME* create()
//{
//	struct NAME* p1, * p2, * head;
//	head = p2 = p1 = (struct NAME*)malloc(LEN);
//	scanf("%d%s%s%d", &p1->num, &p1->name, &p1->sex, &p1->age);
//	while (p1->num != NULL) //以0作为结束链表的标志
//	{
//		n++;
//		(n == 1) ? (head = p1) : (p2->next = p1);
//		p2 = p1;
//		p1 = (struct NAME*)malloc(LEN);
//		scanf("%d%s%s%d", &p1->num, &p1->name, &p1->sex, &p1->age);
//	}
//	p2->next = NULL;
//	return head;
//}
//
//// //链表的删除，可以删除多个含有某个相同值的链表
//struct NAME* del(struct NAME* head,int age)
//{
//	struct NAME* p1, * p2, * flag;
//	p1 = p2 =  flag = head;
//	if (head == NULL)
//	{
//		printf("\nNull list\n");
//	}
//	else
//	{
//		while (flag != NULL) //用flag控制链表的循环推进
//		{
//			if (p1->age == age) //判断是否为要删除的某个相同值
//			{
//				n--;
//				if (p1 == head) //判断p1是否为头结点
//				{
//					head = p1->next;
//					p2 = p1->next;
//				}
//				else
//				{
//					p2->next = p1->next;
//				}
//			}
//			else //让p2继续沿着链表移动
//			{
//				p2 = p1;
//			}
//			p1 = p1->next; //让p1继续沿着链表移动
//			flag = p1; //让flag跟着p1移动
//		}
//	}
//	return head;
//}
//
//// //链表的输出
//void print(struct NAME* head)
//{
//	struct NAME* p;
//	p = head;
//	if (head != NULL)
//	{
//		do
//		{
//			printf("\n%d\t%s\t%s\t%d\n", p->num, p->name, p->sex, p->age);
//			p = p->next;
//		} while (p != NULL);
//	}
//}
//
//void main()
//{
//	struct NAME* head;
//	int del_age;
//	printf("\nInput record:\n"); //获取输入的数据
//	head = create();
//	print(head);
//	printf("\nBefore delete:%d\n", n);
//	printf("\nInput the delete age:\n"); //获取要删除的某个相同值
//	scanf("%d", &del_age);
//	head = del(head, del_age);
//	print(head);
//	printf("\nAfter delete:%d\n", n);
//}

// //有两个链表a和b，从a链表中删去与b链表中有相同学号的那些结点
//#define NULL 0
//#define NAME Student_linked_list
//#define LEN sizeof(struct NAME)
//int n = 0, k = 0;
//
//struct NAME
//{
//	long long int num;
//	char name[20];
//	struct NAME* next;
//};
//
//// //链表的创建
//struct NAME* create()
//{
//	struct NAME* p1, * p2, * head;
//	head = p2 = p1 = (struct NAME*)malloc(LEN);
//	scanf("%lld%s", &p1->num, &p1->name);
//	while (p1->num != NULL) //用0作为链表结束的标志
//	{
//		n++; //n用于记录链表长度，要注意n是全局变量，只能记录第一个链表的长度，第二个链表创建时n!=0
//		(n == 1) ? (head = p1) : (p2->next = p1);
//		p2 = p1;
//		p1 = (struct NAME*)malloc(LEN);
//		scanf("%lld%s", &p1->num, &p1->name);
//	}
//	p2->next = NULL;
//	return head;
//}
//
//// //链表的输出
//void print(struct NAME* head)
//{
//	struct NAME* p = head;
//	if (head != NULL)
//	{
//		do
//		{
//			printf("\n%lld\t%s\n", p->num, p->name);
//			p = p->next;
//		} while (p != NULL);
//	}
//}
//
//// //提取b链表中不同的学号并返回一个指向不同学号数组的指针
//long long int* same_list(struct NAME*b_head)
//{ 
//	//same[]数组用于记录b链表中所有的学号，dif[]数组用于记录b链表中不重复的所有学号
//	long long int same[100] = { 0 }, dif[100] = { 0 };
//	long long int* list = same;
//	struct NAME* p1 = b_head;
//	int count = 0, i, j;
//	while (p1 != NULL)
//	{
//		*list = p1->num;
//		list++; //先用list指针控制数组的移动
//		count++; //count用来计算b链表中共有多少个学号，方便接下来的循环控制
//		p1 = p1->next;
//	}
//	for (i = 0; i < count; i++) //提取b链表中不同的学号
//	{
//		for (j = i + 1; j < count; j++)
//		{
//			if (same[i] == same[j])
//			{
//				same[j] = 0;
//			}
//		}
//		if (same[i] != 0)
//		{
//			dif[k] = same[i];
//			k++; //k用于记录b链表共有多少个不重复的学号
//		}
//	}
//	list = dif; //用list指向dif[]数组并作为返回值
//	return list;
//}
//
//// //链表a和链表b的比对并删除相同学号的信息
//struct NAME* del(struct NAME* a_head, long long int* list)
//{
//	struct NAME* p1, * p2, * flag;
//	long long int* same_list_b = list, table[100] = { 0 };
//	flag = p2 = p1 = a_head;
//	int i, equal = 0, head = 0;
//	for (i = 0; i < k; i++) //把b链表中不重复的学号存储在table[]数组，便于后续条件判断
//	{
//		table[i] = *same_list_b;
//		same_list_b++;
//	}
//	if (a_head == NULL)
//	{
//		printf("\nNull list\n");
//	}
//	else
//	{
//		while (flag != NULL)
//		{
//			for (i = 0; i < k; i++) //b链表一共有k个不重复的学号
//			{
//				if (table[i] == p1->num)
//				{
//					equal = 1; //equal用于判断是否有相同学号
//					if (p1 == a_head)
//					{
//						head = 1; //head用于判断相同学号的结点是否为头结点
//					}
//				}
//			}
//			if (equal == 1)
//			{
//				n--;
//				if (head == 1)
//				{
//					a_head = p1->next;
//					p2 = p1->next;
//				}
//				else
//				{
//					p2->next = p1->next;
//				}
//			}
//			else
//			{
//				p2 = p1;
//			}
//			p1 = p1->next;
//			flag = p1;
//			equal = head = 0; //每个结点判断结束要将equal和head重置为0
//		}
//	}
//	return a_head;
//}
//
//void main()
//{
//	struct NAME* a_head, * b_head;
//	long long int* del_num_list;
//	int len_a, len_b;
//	printf("\nInput record of a:\n");
//	a_head = create();
//	print(a_head);
//	len_a = n;
//	printf("\nThe length of a list before delete:%d\n", len_a);
//	n = 0; //使n重新开始计算链表b的长度
//	printf("\nInput record of b:\n");
//	b_head = create();
//	print(b_head);
//	len_b = n;
//	printf("\nThe length of b list:%d\n", len_b);
//	n = len_a; //让n表示链表a的长度并记录删除相同学号后链表a的长度
//	del_num_list = same_list(b_head);
//	a_head = del(a_head, del_num_list);
//	printf("\nThe linked list of a after delete:\n");
//	print(a_head);
//	printf("\nThe length of a list after delete:%d\n", n);
//}

// C++才能通过，C不能通过，问题在于文件的后缀是.c（C）还是.cpp（C++）
//void swap(int &x, int &y)
//{
//	int temp;
//	temp = x;
//	x = y;
//	y = temp;
//}
//void main()
//{
//	int a = 5, b = 9;
//	swap(a, b);
//	printf("a = %d, b = %d", a, b);
//}