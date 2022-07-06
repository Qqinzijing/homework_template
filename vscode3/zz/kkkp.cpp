
#include<stdio.h>
#define MAX 200

typedef struct Solution
{
    float x[MAX]; //表示该号物品放在多少背包里
    int order[MAX];//表示物品的序号，相当其名字

}Solution;

Solution X;
int m=15;//背包容量
int n=7;//物品数量
int p[]={10,5,15,7,6,18,3};
int w[]={2,3,5,7,1,4,1};


void GreedyKnapsack(int weight[]){
    float cu;
    int i;
    cu=float(m);
    
    for(i=0;i<n;i++){
        if(weight[i]>cu)
            break;
        X.x[i]=1;
        cu=cu-weight[i];
    }
    if(i<n){
        X.x[i]=cu/weight[i];
    }
}
//按价值排序
bool compare1(int i,int j){
    if((p[i]<p[j]))
        return true;
    else return false;
}
//按重量排序
bool compare2(int i,int j){
    if((w[i]>w[j]))
        return true;
    else return false;
}

// 按价值/重量排序
bool compare3(int i,int j){
    if((float)(p[i]/w[i]<p[i]/w[j]))
        return true;
    else return false;
}
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

void sort(int type){
    
    int i,j;
    for(i=0;i<n-1;i++){
        int k=i;
        for(j=i+1;j<n;j++){
            if(type==1){
                if(compare1(k,j))
                    k=j;
            }
            else if(type==2){
                if(compare2(k,j))
                    k=j;
            }
            else
            {
                if (compare3(k,j))
                    k=j;   
            }
            if(k!=i){
                swap(p[i],p[k]);
                swap(w[i],w[k]);
                swap(X.order[i],X.order[k]);
            }
            
        }
    }
}

void init(){
    for(int i=0;i<n;i++){
        X.order[i]=i;
        X.x[i]=0;
    }
}

void show()
{
    float total=0,weight=0;
    for(int i=0;i<n;i++)
    {
    total+=p[i]*X.x[i];
    weight+=w[i]*X.x[i];
    printf("装入的包的序号:%d 装入的份量%.6f\n",X.order[i],X.x[i]);
    printf("\n 背包的总价值 fp:%.2f,背包的总质量 fw:%.2f\n",total,weight);

    }
}
int main()
{
    for(int i=1;i<=3;i++)
    {
    printf("\t\t 策略%d:\n",i);
    printf("解向量 x%d:\n",i);
    init();
    sort(i);
    GreedyKnapsack(w);
    show();
    }
} 

