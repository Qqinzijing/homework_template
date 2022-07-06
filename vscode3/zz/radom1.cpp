#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

void Random(int *a,int n,int l,int r)   //生成范围在l~r的随机数 
{
	srand(time(0));                     //设置时间种子
	for(int i=0;i<n;i++){
		a[i]=rand()%(r-l+1)+l;          //生成区间r~l的随机数 
	}
}

void BubbleSort(int list[], int n) {//冒泡排序算法
        int i, j, temp;
        for (i = 0; i < n - 1; i++)
                for (j = 0; j < n - 1 - i; j++)
                        if (list[j] > list[j + 1]) {
                                temp = list[j];
                                list[j] = list[j + 1];
                                list[j + 1] = temp;
                        }
}


int main()
{
	int n;                 //数组元素的个数，即生成随机数的个数
    printf("请输入生成随机数的个数：");
    scanf("%d",&n);
	int list[n];
	Random(list,n,1,1000000);     //生成随机数的通常范围为0~32767，这里通过取模控制取值为0~100 
    int len = (int) sizeof(list) / sizeof(*list);
    printf("生成的随机数组：\n");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    BubbleSort(list, len);
    printf("\n采用冒泡排序后的随机数组：\n");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
        return 0;
}