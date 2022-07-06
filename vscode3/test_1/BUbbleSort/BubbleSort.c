/*
   冒泡排序C实现
   学号：20201050416
   姓名：翁静铭
   时间复杂度：O(n^2)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void RandomLGC(int *list,int n,int l,int r)   //生成范围为1-r的随机数
{
	srand(time(0));                   
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //生成区间r~l的随机数 
	}
}
// 冒泡排序算法
void BubbleSort(int list[], int n) {
        int i, j, temp,sum=0;
        for (i = 0; i < n - 1; i++){//一趟排序
                for (j = 0; j < n - 1 - i; j++){//每趟比较次数
                        if (list[j] > list[j + 1]) {//交换两个数的位置
                                temp = list[j];
                                list[j] = list[j + 1];
                                list[j + 1] = temp;
                        }
                }
                sum=sum+n-1-i;//比较次数
        }
        printf("\n冒泡排序后的数组为：");
        for (int i = 0; i < n; i++){
            printf("%d ",list[i]);
        }
        printf("\n冒泡排序比较次数为：%d\n",sum);
}


int main(){
        int n;  //数组元素的个数，即生成随机数的个数
        printf("请输入生成随机数的个数：");
        scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000);
        int len = (int) sizeof(list) / sizeof(*list);
        printf("随机生成的数组为：");
        for (int i = 0; i < len; i++){
                 printf("%d ",list[i]);
        }
        BubbleSort(list, len);

        return 0;
}