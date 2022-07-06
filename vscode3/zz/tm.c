// 
#include<stdio.h>
#include<time.h>
#include<math.h>
clock_t start,stop;
//clock_t是clock()函数返回的变量类型
double duration;
//记录被测试函数运行时间，以秒为单位

#define MAXN 10 /*多项式最大项数，即多项式阶数+1*/ 

#define MAXK 1e7/*被测函数最大重复调用次数*/

double f1(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for(i=1;i<=n;i++)
	  p+=(a[i]*pow(x,i));
	return p;
}

double f2(int n,double a[],double x)
{
	int i;
	double p=a[n];
	for(i=1;i<=n;i++)
	  p=a[i-1]+x*p;
	return p;
}

void computationtime(double start,double stop,int i)
{
	duration = ((double)(stop-start))/CLK_TCK/MAXK;/*计算函数单次运行的时间*/
	//计算运行时间
	//其它不在测试范围的处理写在后面，例如输出duration的值
	printf("ticks%d = %f\n",i,(double)(stop - start));
	printf("duration%d = %6.2e\n",i,duration);
}

int main()
{
	int i;
	double a[MAXN];/*多项式的系数*/ 
	for( i=0; i<MAXN; i++)a[i]=(double)i;
	
	//不被测试函数内的准备工作写在clock()调用之前
	start = clock();//开始计时
	/*MyFunction();//把被测函数加在这里*/ 
	for(i=0;i<MAXK;i++)
	  f1(MAXN-1,a,1.1);
	stop = clock();//停止计时
	computationtime(start,stop,1);
	 
	start = clock();//开始计时
	/*MyFunction();把被测函数加在这里*/ 
	for(i=0;i<MAXK;i++)
	  f2(MAXN-1,a,1.1);
	stop = clock();//停止计时
	computationtime(start,stop,2);
	
	return 0; 
} 
/*
clock():捕捉从程序开始运行到clock()被调用时所耗费的时间。
这个时间单位是clock tick，即“时间打点”。
常数 CLK_TCK：机器时钟每秒所走的时钟打点数 
*/
