/*
    쳲���������̬�滮��(Dynamic Programming)
	ѧ�ţ�20201050470
	ʱ�临�Ӷȣ�O(n)

*/
#include<stdio.h>
#include<stdlib.h>
/*��̬�滮��*/ 
int *DP_f(int n){//��̬�滮��
	int sum=0;
	int *f=(int*)malloc(sizeof(int)*n);
	f[0]=0;
	for(int i=1;i<=n;i++){
		if(i==1||i==2){
			f[i]=1;
		}
		else{
			sum++;
			f[i]=f[i-1]+f[i-2];
		}
	}
	printf("%d\n",sum);
	return f;//����fibonacci����
}

int main(){
	int n;
	printf("�����������: ");
	scanf("%d",&n);
	printf("������Ϊ��");
	int *f=DP_f(n);
	for(int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	return 0;
}
