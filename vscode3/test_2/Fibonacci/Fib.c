#include<stdio.h>
#include<stdlib.h>
/*���η�*/ 
int psum=0;//
int DAC_f(int n){ 
    //int sum=0;
	if(n==1||n==2){
		return 1;}
	else{
        psum++;
		return DAC_f(n-1)+DAC_f(n-2);
        
	}
    return psum;
    //printf("\n��̬�滮�ӷ�������%d",sum);
}

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
			f[i]=f[i-1]+f[i-2];
            sum++;
		}
	}
    printf("\n��̬�滮������%d\n",sum);
	return f;//����fibonacci����
}


int main(){
	int n;
	printf("������쳲��������е�����: ");
	scanf("%d",&n);
	printf("���η���\nDAC_f(%d)=%d",n,DAC_f(n));
	printf("\n���η��ӷ�������%d",psum);
    int *f=DP_f(n);
    printf("\n��̬�滮����");
	for(int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	n=0;
	return 0;
}
