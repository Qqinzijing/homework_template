#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// int Max=10000000000;
// typedef struct kp
// {
//     double weight;//物品重量
//     double value;//物品价值
//     double pw;//物品价值/重量
//     double x;//解向量
// }package[Max];

void KnapsackGreedy(int n,double c,double v[],double w[],double x[]);//背包问题贪心算法
void RandomWeight(double weight[],int n,int l,int r);//随机生成物品重量
void RandomValue(double weight[],int n,int l,int r);//随机生成物品价值

void main(){
    int n;//物品数量
    double C;//背包最大容量
    double PW[n];//物品价值/重量
    int index[n];//物品编号
    double P[n];//物品价值
    double W[n];//物品重量
    double x[n];//解向量
    printf("请输入背包的最大容量:");
    scanf("%lf",&C);
    printf("输入物品数:");
    scanf("%d",&n);
    RandomWeight(W,n,1,100);
    RandomValue(P,n,1,100);
    KnapsackGreedy(n,C,P[n],W[n],x);
    printf("\n******背包*******\n");
    // for(i=0;i<n;i++)
    // {
    //     printf("物品%d:",i+1);
    //     if(p[i].x==1)
    //     {
    //         printf("放入\n");
    //     }
    //     else
    //     {
    //         printf("不放入\n");
    //     }
    // }
    // system("pause");
}


void KnapsackGreedy(int n,double c,double v[],double w[],double x[]){
    int i;
     for(i=0;i<n;i++)
     {
        x[i] = 0;//初始状态，所有物品都没有被放入背包 
     } 
     
     for(i=0;i<n;i++)
     {
       if(w[i] > c)
       {
         break;
       }
       
       x[i] = 1;
       c = c - w[i];
       printf("放入第%d件物品，背包剩余容量%f.\n",(i+1),c);
     }
     
     if(i<=n)//还可以放入一个物品的一部分 
     {
        x[i] = c/w[i]; 
        
        printf("放入第%d件物品的%f部分.背包剩余容量为0.\n",(i+1),w[i]*x[i]);
     }     
}

void RandomWeight(double weight[],int n,int l,int r)   //生成范围在l~r的随机物品重量 
{
    int seed=1;
    srand(seed);                   //设置时间种子
	for(int i=0;i<n;i++){
		weight[i]=(double)(rand()%(r-l+1)+l);          //生成区间r~l的随机数 
	}
  printf("随机生成的物品重量为：\n");
    for (int i = 0; i < n; i++){
        printf("%f ",weight[i]);
    }
}

void RandomValue(double value[],int n,int l,int r)   //生成范围在l~r的随机随机物品价值
{
    int seed=2;
	srand(seed);                     //设置时间种子
	for(int i=0;i<n;i++){
	   value[i]=(double)(rand()%(r-l+1)+l);          //生成区间r~l的随机数
	}
  printf("\n随机生成的物品价值为：\n");
    for (int i = 0; i < n; i++){
        printf("%f ",value[i]);
    }
}
