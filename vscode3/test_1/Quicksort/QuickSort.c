/*
  ���������㷨C����ʵ��
  ѧ�ţ�20201050470
  ʱ�临�Ӷȣ�O(nlog(n))
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// //���������
// int * randlist(m,a,c,x0,n){
//     int *list = (int *)malloc(n*sizeof(int));
//     for(int i = 0;i < n;i++){
//         list[i] = (a*list[i]+c)%m;
//     }
//     printf("�������\n");
//     for(int i = 0;i < n;i++){
//         printf("%d ",list[i]);
//     }
//     printf("\n");
//     return list;
// }
int sum = 0;//��¼�Ƚϴ���
//��������
// void QuickSort(int *list,int left,int right){
//     //int sum = 0;
//     if(left < right){
//         int i = left,j = right,x = list[left];
//         while(i < j){
//             while(i < j && list[j] >= x){//���������ҵ�һ��С��x����
//                 j--;                      //�ҵ��󣬽����x����
//             }
//             list[i] = list[j];      //���ҵ���С��x�����ŵ����
//             while(i < j && list[i] <= x){//���������ҵ�һ������x����
//                 i++;                    //�ҵ�����ŵ��ұ�
//             }
//             list[j] = list[i];//����
//         }
//         list[i] = x;//��x�ŵ�����λ��

//         QuickSort(list,left,i-1);
//         QuickSort(list,i+1,right);
//         sum=sum+i-left+right-i;
//     }
    
// }

// void QuickSort(int *list,int left,int right){
//     int pivot;
//     if(left<right){
//         pivot=Partition(list,left,right);
//         QuickSort(list,left,pivot-1);
//         QuickSort(list,pivot+1,right);
//     }
// }
int Partition(int *list,int left,int right){
    int i=left+1,j=right;
    //int sum = 0;
    while(i<j){
        while(i<=j&&list[i]<=list[j]){
            j--;
        }
        if(i<j){
            int temp=list[i];
            list[i]=list[j];
            list[j]=temp;
            i++;
        }
        while(i<=j&&list[i]>=list[j]){
            i++;
        }
        if(i<j){
            int temp=list[i];
            list[i]=list[j];
            list[j]=temp;
            j--;
        }

    }
    sum=sum+j-left+right-i;
    //printf("%d\n",sum);
    return i;
}

void QuickSort(int *list,int left,int right){
    int pivot;
    if(left<right){
        pivot=Partition(list,left,right);
        QuickSort(list,left,pivot-1);
        QuickSort(list,pivot+1,right);
    }
}

//���������
void RandomLGC(int *list,int n,int l,int r)   //���ɷ�Χ��l~r������� 
{
	srand(time(0));                     //����ʱ������
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //��������r~l������� 
	}
}

int main(){
    int n;   //����Ԫ�صĸ�����������������ĸ���
    printf("����������������ĸ�����");
    scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000);//�����������ͨ����ΧΪ0~32767������ͨ��ȡģ����ȡֵΪ0~100000
    int len = (int) sizeof(list) / sizeof(*list);
    printf("������ɵ�����Ϊ��");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    QuickSort(list,0,len-1);  
    printf("\n��������������Ϊ��");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    printf("\n�����������Ϊ��%d\n",sum);
    printf("\n");
    return 0;
}









//��������
// void QuickSort(int res[], int low, int high)
// {
// 	int l = low;
// 	int h = high;
// 	if (l < h)
// 	{
// 		int key = res[l];//��׼ֵ
// 		int flag = 0;	//�����ظ���copy
// 		while (l < h)
// 		{
// 			while (l < h && key <= res[h]) {		//�Ӹ�λ����λ,�ұ�keyС����ֵ
// 				--h;
// 				compare++;
// 			}
// 			if (l < h) {
// 				res[l] = res[h];
// 				swap += 1;
// 				flag = 1;	//���������copy����������flagΪ1
// 			}
// 			while (l < h && key >= res[l]) {	//�ӵ�λ����λ���ұ�key�����ֵ
// 				++l;
// 				compare++;
// 			}
// 			if (l < h) {
// 				res[h] = res[l];
// 				swap+=1;
// 				flag = 1;
// 			}
// 		}
// 		if (flag == 1) {
// 			res[l] = key;
// 			swap++;
// 		}
// 		QuickSort(res, low, l - 1);
// 		QuickSort(res, l + 1, high);
// 	}
// }
