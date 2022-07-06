#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// int Max=10000000000;
// typedef struct kp
// {
//     double weight;//��Ʒ����
//     double value;//��Ʒ��ֵ
//     double pw;//��Ʒ��ֵ/����
//     double x;//������
// }package[Max];

void KnapsackGreedy(int n,double c,double v[],double w[],double x[]);//��������̰���㷨
void RandomWeight(double weight[],int n,int l,int r);//���������Ʒ����
void RandomValue(double weight[],int n,int l,int r);//���������Ʒ��ֵ

void main(){
    int n;//��Ʒ����
    double C;//�����������
    double PW[n];//��Ʒ��ֵ/����
    int index[n];//��Ʒ���
    double P[n];//��Ʒ��ֵ
    double W[n];//��Ʒ����
    double x[n];//������
    printf("�����뱳�����������:");
    scanf("%lf",&C);
    printf("������Ʒ��:");
    scanf("%d",&n);
    RandomWeight(W,n,1,100);
    RandomValue(P,n,1,100);
    KnapsackGreedy(n,C,P[n],W[n],x);
    printf("\n******����*******\n");
    // for(i=0;i<n;i++)
    // {
    //     printf("��Ʒ%d:",i+1);
    //     if(p[i].x==1)
    //     {
    //         printf("����\n");
    //     }
    //     else
    //     {
    //         printf("������\n");
    //     }
    // }
    // system("pause");
}


void KnapsackGreedy(int n,double c,double v[],double w[],double x[]){
    int i;
     for(i=0;i<n;i++)
     {
        x[i] = 0;//��ʼ״̬��������Ʒ��û�б����뱳�� 
     } 
     
     for(i=0;i<n;i++)
     {
       if(w[i] > c)
       {
         break;
       }
       
       x[i] = 1;
       c = c - w[i];
       printf("�����%d����Ʒ������ʣ������%f.\n",(i+1),c);
     }
     
     if(i<=n)//�����Է���һ����Ʒ��һ���� 
     {
        x[i] = c/w[i]; 
        
        printf("�����%d����Ʒ��%f����.����ʣ������Ϊ0.\n",(i+1),w[i]*x[i]);
     }     
}

void RandomWeight(double weight[],int n,int l,int r)   //���ɷ�Χ��l~r�������Ʒ���� 
{
    int seed=1;
    srand(seed);                   //����ʱ������
	for(int i=0;i<n;i++){
		weight[i]=(double)(rand()%(r-l+1)+l);          //��������r~l������� 
	}
  printf("������ɵ���Ʒ����Ϊ��\n");
    for (int i = 0; i < n; i++){
        printf("%f ",weight[i]);
    }
}

void RandomValue(double value[],int n,int l,int r)   //���ɷ�Χ��l~r����������Ʒ��ֵ
{
    int seed=2;
	srand(seed);                     //����ʱ������
	for(int i=0;i<n;i++){
	   value[i]=(double)(rand()%(r-l+1)+l);          //��������r~l�������
	}
  printf("\n������ɵ���Ʒ��ֵΪ��\n");
    for (int i = 0; i < n; i++){
        printf("%f ",value[i]);
    }
}
