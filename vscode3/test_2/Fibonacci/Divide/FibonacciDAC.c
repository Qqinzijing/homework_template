/*
   쳲����������η�C����ʵ��
   ѧ�ţ�20201050470
*/

#include<stdio.h>

/*���η�*/ 
int DAC_f(int n){ 

	if(n==1||n==2){
		return 1;}
	else{
		return DAC_f(n-1)+DAC_f(n-2);
	}
}
int main(){
	int n;
	printf("������쳲��������е�����: ");
	scanf("%d",&n);
	printf("DAC_f(%d)=%d",n,DAC_f(n));
	n=0;
	return 0;
}
