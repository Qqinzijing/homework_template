/*
  快速排序算法C语言实现
  学号：20201050470
  时间复杂度：O(nlog(n))
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// //生成随机数
// int * randlist(m,a,c,x0,n){
//     int *list = (int *)malloc(n*sizeof(int));
//     for(int i = 0;i < n;i++){
//         list[i] = (a*list[i]+c)%m;
//     }
//     printf("随机序列\n");
//     for(int i = 0;i < n;i++){
//         printf("%d ",list[i]);
//     }
//     printf("\n");
//     return list;
// }
int sum = 0;//记录比较次数
//快速排序
// void QuickSort(int *list,int left,int right){
//     //int sum = 0;
//     if(left < right){
//         int i = left,j = right,x = list[left];
//         while(i < j){
//             while(i < j && list[j] >= x){//从右向左找第一个小于x的数
//                 j--;                      //找到后，将其和x交换
//             }
//             list[i] = list[j];      //将找到的小于x的数放到左边
//             while(i < j && list[i] <= x){//从左向右找第一个大于x的数
//                 i++;                    //找到后将其放到右边
//             }
//             list[j] = list[i];//交换
//         }
//         list[i] = x;//将x放到最终位置

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

//生成随机数
void RandomLGC(int *list,int n,int l,int r)   //生成范围在l~r的随机数 
{
	srand(time(0));                     //设置时间种子
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //生成区间r~l的随机数 
	}
}

int main(){
    int n;   //数组元素的个数，即生成随机数的个数
    printf("请输入生成随机数的个数：");
    scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000);//生成随机数的通常范围为0~32767，这里通过取模控制取值为0~100000
    int len = (int) sizeof(list) / sizeof(*list);
    printf("随机生成的数组为：");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    QuickSort(list,0,len-1);  
    printf("\n快速排序后的数组为：");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    printf("\n快速排序次数为：%d\n",sum);
    printf("\n");
    return 0;
}









//快速排序
// void QuickSort(int res[], int low, int high)
// {
// 	int l = low;
// 	int h = high;
// 	if (l < h)
// 	{
// 		int key = res[l];//基准值
// 		int flag = 0;	//避免重复的copy
// 		while (l < h)
// 		{
// 			while (l < h && key <= res[h]) {		//从高位到低位,找比key小的数值
// 				--h;
// 				compare++;
// 			}
// 			if (l < h) {
// 				res[l] = res[h];
// 				swap += 1;
// 				flag = 1;	//如果进行了copy操作，设置flag为1
// 			}
// 			while (l < h && key >= res[l]) {	//从低位到高位，找比key大的数值
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
