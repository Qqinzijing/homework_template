# include <stdio.h>
# include <stdlib.h>

int countQ=0;
int countM=0;

int* input(int n,int s,int a,int c,int m){
    int *p;
    p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        if(s!=0){
            s=(a*s+c)%m;
        }
        p[i]=s;
        printf("%d ",p[i]);
    }
    printf("\n");
    return p;
}

int BubbleSort(int* list,int n){
    int numberOfPairs=n;
    int swappedElements=1;
    int count=0;
    while(swappedElements){
        numberOfPairs=numberOfPairs-1;
        swappedElements=0;
        for(int i=0;i<=numberOfPairs;i++){
            count++;
            if(list[i]>list[i+1]){
                int temp=list[i];
                list[i]=list[i+1];
                list[i+1]=temp;
                swappedElements=1;
            }
        }
        count--;
    }
    return count;
}

void MergeLists(int *list,int start1,int end1,int start2,int end2){
    int *result;
    result=(int *)malloc((end2-start1+1)*sizeof(int));
    int indexC=0;
    while(start1<=end1&&start2<=end2){
        countM++;
        if(list[start1]<list[start2]){
            result[indexC]=list[start1];
            start1=start1+1;
        }else{
            result[indexC]=list[start2];
            start2=start2;
        }
        indexC=indexC+1;
    }
    if(start1<=end1){
        for(int i=start1;i<=end1;i++){
            result[indexC]=list[i];
            indexC=indexC+1;
        }
    }else{
        for(int i=start2;i<=end2;i++){
            result[indexC]=list[i];
            indexC=indexC+1;
        }
    }
    indexC=0;
    for(int i=start1;i<=end2;i++){
        list[i]=result[indexC];
        indexC=indexC+1;
    }
}

void MergeSort(int *list,int first,int last){
    if(first<last){
        int middle=(first+last)/2;
        MergeSort(list,first,middle);
        MergeSort(list,middle+1,last);
        MergeLists(list,first,middle,middle+1,last);
    }
}

int PivotList(int *list,int first,int last){
    int PivotValue=list[first];
    int PivotPoint=first;
    for(int i=first+1;i<=last;i++){
        countQ++;
        if(list[i]<PivotValue){
            PivotPoint=PivotPoint+1;
            int temp=list[PivotPoint];
            list[PivotPoint]=list[i];
            list[i]=temp;
        }
    }
    int temp=list[first];
    list[first]=list[PivotPoint];
    list[PivotPoint]=temp;
    return PivotPoint;
}

void QuickSort(int *list,int first,int last){
    if(first<last){
        int pivot=PivotList(list,first,last);
        QuickSort(list,first,pivot-1);
        QuickSort(list,pivot+1,last);
    }
}

int main(){
    int n,s,a,c,m;
    printf("依次输入n,s,a,c,m:");
    scanf("%d%d%d%d%d",&n,&s,&a,&c,&m);
    int *p=input(n,s,a,c,m);
    int countB=BubbleSort(p,n);
    printf("冒泡次数：%d\n",countB);
    QuickSort(p,0,n-1);
    printf("快排比较次数:%d\n",countQ);
    MergeSort(p,0,n-1);
    printf("合并排序比较次数:%d\n",countM);
}