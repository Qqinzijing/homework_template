/*
   ð������Cʵ��
   ѧ�ţ�20201050416
   �������̾���
   ʱ�临�Ӷȣ�O(n^2)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void RandomLGC(int *list,int n,int l,int r)   //���ɷ�ΧΪ1-r�������
{
	srand(time(0));                   
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //��������r~l������� 
	}
}
// ð�������㷨
void BubbleSort(int list[], int n) {
        int i, j, temp,sum=0;
        for (i = 0; i < n - 1; i++){//һ������
                for (j = 0; j < n - 1 - i; j++){//ÿ�˱Ƚϴ���
                        if (list[j] > list[j + 1]) {//������������λ��
                                temp = list[j];
                                list[j] = list[j + 1];
                                list[j + 1] = temp;
                        }
                }
                sum=sum+n-1-i;//�Ƚϴ���
        }
        printf("\nð������������Ϊ��");
        for (int i = 0; i < n; i++){
            printf("%d ",list[i]);
        }
        printf("\nð������Ƚϴ���Ϊ��%d\n",sum);
}


int main(){
        int n;  //����Ԫ�صĸ�����������������ĸ���
        printf("����������������ĸ�����");
        scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000);
        int len = (int) sizeof(list) / sizeof(*list);
        printf("������ɵ�����Ϊ��");
        for (int i = 0; i < len; i++){
                 printf("%d ",list[i]);
        }
        BubbleSort(list, len);

        return 0;
}