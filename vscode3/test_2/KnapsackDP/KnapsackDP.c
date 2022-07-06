/*
   0-1������̬�滮C����ʵ��
   ѧ�ţ�20201050470
   ʱ�临�Ӷȣ�O(n*w)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a,int b);  //�����ֵ
int F[10000][10000];  //ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ
int KnapSackDP(int n,int weight[],int value[],int C);  //nΪ��Ʒ������weightΪÿ����Ʒ��������valueΪÿ����Ʒ�ļ�ֵ��CΪ�������ܵ��������
void Judge(int C,int n,int weight[]);  //�жϱ����Ƿ���Գ���
void RandomLGCW(int *list,int n,int l,int r);   //���ɷ�Χ��l~r�������Ʒ���� 
void RandomLGCV(int *list,int n,int l,int r);  //���ɷ�Χ��l~r�������Ʒ��ֵ
void initpackage();

int main(){
    initpackage();
    return 0;

    // int n;         //��Ʒ���� 
    // int Capacity;  //�����������
    // printf("�����뱳�����������:");
    // scanf("%d",&Capacity);
    // printf("������Ʒ��:");
    // scanf("%d",&n);
    // int weight[n];//��Ʒ����
    // int value[n];//��Ʒ��ֵ
    // clock_t begin, end;//��ʼʱ��
    // double cost;//����ʱ��
    // //begin = clock();//��¼��ʼʱ��
    // printf("���������Ʒ������Ϊ��\n");
    // RandomLGCW(weight,n,1,100);
    // printf("\n���������Ʒ�ļ�ֵ:\n");
    // RandomLGCV(value,n,1,100);
    // begin = clock();//��¼��ʼʱ��
    // int reslut=KnapSackDP(n,weight,value,Capacity);  //��õ�����ֵ
    // Judge(Capacity,n,weight);  //�ж���Щ��Ʒ��ѡ�� 
    // printf("����ֵΪ:%d\n",reslut);
    // end = clock();//��¼����ʱ��
    // cost = (double)(end - begin)*1000/CLOCKS_PER_SEC;
    // printf("\n�㷨����ʱ��: %lf ms",cost);
    // return 0;
}

int max(int a,int b){
   if(a>=b)
       return a;
   else return b;
}
 
int KnapSackDP(int n,int weight[],int value[],int C){
    
	//���,���е�һ�к͵�һ��ȫΪ0,�� F(i,0)=F(0,j)=0�� 
    for(int i=0;i<=n;i++){
        F[i][0]=0;
    }
    for(int j=0;j<=C;j++){
        F[0][j]=0;
    }
    //�õ��ľ��󲿷�V[n][C] ,��������в������ ��1�к͵�1�� 
    
	// printf("\n��� ���� ��ֵ \n "); 
		    
    // for(int i=1;i<=n;i++){
	// 	printf("%2d   %2d   %2d    \n ",i,weight[i-1],value[i-1]);   // (weight��value���Ǵ�0��ʼ��ģ����Կ�ʼi=1ʱ��Ӧ0��λ��)
    // }
    // printf("\n0��1������̬�滮��:\n");
    // for(int i=1;i<=C;i++){
	// 	printf("%2d   ",i);
    // }
    printf("\n\n");
   
    for(int i=1;i<=n;i++){
       
        for(int j=1;j<=C;j++){
            if(j<weight[i-1]){                                  //���������ȸ���Ʒ���С��װ���£���ʱ�ļ�ֵ��ǰi-1���ļ�ֵ��һ����
				F[i][j]=F[i-1][j];
				//printf("%2d   ",F[i][j]);
			}
            else{                                             //�����㹻����������װ����Ʒ����װ��Ҳ��һ���ﵽ��ǰ���ż�ֵ��������װ�벻װ֮��ѡ�����ŵ�һ��
                F[i][j]=max(F[i-1][j],F[i-1][j-weight[i-1]]+value[i-1]);		
				//printf("%2d   ",F[i][j]);
			}
		}
		printf("\n");
	}
	
        return F[n][C];
        
}

void Judge(int C,int n,int weight[]){	//�ж���Щ��Ʒ��ѡ��		
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));
    
    for(int i=n;i>=1;i--){
	    if(F[i][j]>F[i-1][j]){  //���װ�˾ͱ�ǣ�Ȼ���ȥ��Ӧ���� 
				state[i]=1;
				j=j-weight[i-1];
	        }
	    else
	        state[i]=0;
    }
    printf("ѡ�е���Ʒ�����:");
    for(int i=1;i<=n;i++)
        if(state[i]==1)
        	printf("%d ",i);
    printf("\n");
}
//ʹ������������ɺ��������ò�ͬ��ʱ�����ӣ��Ա������ͬ�������
 void RandomLGCW(int *list,int n,int l,int r)   //���ɷ�Χ��l~r�������Ʒ���� 
{
    int seed=time(NULL);
	srand(seed);                     //����ʱ������
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //��������r~l������� 
	}
    // for (int i = 0; i < n; i++){
    //     printf("%d ",list[i]);
    // }
}

void RandomLGCV(int *list,int n,int l,int r)   //���ɷ�Χ��l~r����������Ʒ��ֵ
{
    int seed=1;
	srand(seed);                     //����ʱ������
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //��������r~l�������
	}
    // for (int i = 0; i < n; i++){
    //     printf("%d ",list[i]);
    // }
}


void initpackage(){
     int n;         //��Ʒ���� 
    int Capacity;  //�����������
    
    printf("�����뱳�����������:");
    scanf("%d",&Capacity);
    
    printf("������Ʒ��:");
    scanf("%d",&n);

    int weight[n];//��Ʒ����
    int value[n];//��Ʒ��ֵ

    clock_t begin, end;//��ʼʱ��
    double cost;//����ʱ��

    //begin = clock();//��¼��ʼʱ��

    printf("���������Ʒ������Ϊ��\n");
    RandomLGCW(weight,n,1,100);
    
    printf("\n���������Ʒ�ļ�ֵ:\n");
    RandomLGCV(value,n,1,100);
    begin = clock();//��¼��ʼʱ��
    int reslut=KnapSackDP(n,weight,value,Capacity);  //��õ�����ֵ

    Judge(Capacity,n,weight);  //�ж���Щ��Ʒ��ѡ�� 
    printf("����ֵΪ:%d\n",reslut);
    end = clock();//��¼����ʱ��
    cost = (double)(end - begin)*1000/CLOCKS_PER_SEC;
    printf("\n�㷨����ʱ��: %lf ms",cost);
    //return 0;
}