/*
	?�}�Ƨ�Python??
    ??�G20201050416
    �m�W�G��??
    ??�`?�סGO(nlog(n))

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sum=0;

void Merge(int Array[], int first, int middle, int last){
	int n1 = middle - first;
	int n2 = last - middle;
	
	int left[n1];
	int right[n2];
	
	for(int i = 0; i < n1; i++){
		left[i] = Array[first + i];   
	}
	for(int i = 0; i < n2; i++){
		right[i] = Array[middle + i];  
	}
	int i = 0, j = 0, key;
	for(key = first; key < last; key++){
		if(i < n1 && left[i] <= right[j]){ 
			Array[key] = left[i++];  
		}
		else if(j < n2 && left[i] >= right[j]){  
			Array[key] = right[j++];  
			}
		else if(i == n1 && j < n2){  
			Array[key] = right[j++];
		}
			
		else if(j == n2 && i < n1){
			Array[key] = left[i++];
		}	
			
	}
	sum=sum+n1+n2;
}

void MergeSort(int list[], int first, int last){
	
	if(first + 1 < last){     		 
		int middle = (last + first) / 2; 
		MergeSort(list, first, middle);  
		MergeSort(list, middle, last);  
		Merge(list, first, middle, last);  
	}
}


void RandomLGC(int *list,int n,int l,int r)   
{
	srand(time(0));                    
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;       
	}
}

int main()
{
	int n;  
    printf("请输入生成随机数的个数：");
    scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000);
    int len = (int) sizeof(list) / sizeof(*list);
	printf("随机生成的数组为:\n");
	for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    MergeSort(list, 0, n);
	printf("\n合并排序后的数组为:\n");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
	printf("\n比较次数为：%d\n",sum);
    return 0;
}