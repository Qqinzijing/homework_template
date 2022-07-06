// 
#include<stdio.h>
#include<time.h>
#include<math.h>
clock_t start,stop;
//clock_t��clock()�������صı�������
double duration;
//��¼�����Ժ�������ʱ�䣬����Ϊ��λ

#define MAXN 10 /*����ʽ���������������ʽ����+1*/ 

#define MAXK 1e7/*���⺯������ظ����ô���*/

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
	duration = ((double)(stop-start))/CLK_TCK/MAXK;/*���㺯���������е�ʱ��*/
	//��������ʱ��
	//�������ڲ��Է�Χ�Ĵ���д�ں��棬�������duration��ֵ
	printf("ticks%d = %f\n",i,(double)(stop - start));
	printf("duration%d = %6.2e\n",i,duration);
}

int main()
{
	int i;
	double a[MAXN];/*����ʽ��ϵ��*/ 
	for( i=0; i<MAXN; i++)a[i]=(double)i;
	
	//�������Ժ����ڵ�׼������д��clock()����֮ǰ
	start = clock();//��ʼ��ʱ
	/*MyFunction();//�ѱ��⺯����������*/ 
	for(i=0;i<MAXK;i++)
	  f1(MAXN-1,a,1.1);
	stop = clock();//ֹͣ��ʱ
	computationtime(start,stop,1);
	 
	start = clock();//��ʼ��ʱ
	/*MyFunction();�ѱ��⺯����������*/ 
	for(i=0;i<MAXK;i++)
	  f2(MAXN-1,a,1.1);
	stop = clock();//ֹͣ��ʱ
	computationtime(start,stop,2);
	
	return 0; 
} 
/*
clock():��׽�ӳ���ʼ���е�clock()������ʱ���ķѵ�ʱ�䡣
���ʱ�䵥λ��clock tick������ʱ���㡱��
���� CLK_TCK������ʱ��ÿ�����ߵ�ʱ�Ӵ���� 
*/
