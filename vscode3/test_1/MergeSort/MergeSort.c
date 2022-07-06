/*
   �鲢����Cʵ��
   ѧ�ţ�20201050470
   ʱ�临�Ӷȣ�O(n*logn)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sum=0;//��¼�Ƚϴ���
//�ϲ�������������
void Merge(int Array[], int first, int middle, int last){//�ϲ�����
	int n1 = middle - first;//�������鳤��
	int n2 = last - middle;//�Ұ�����鳤��
	
	int left[n1];
	int right[n2];
	
	for(int i = 0; i < n1; i++){
		left[i] = Array[first + i];    //����벿�����鿽����left������
	}
	for(int i = 0; i < n2; i++){
		right[i] = Array[middle + i];  //���Ұ벿�����鿽����right������
	}
	int i = 0, j = 0, key;
	for(key = first; key < last; key++){
		if(i < n1 && left[i] <= right[j]){  //�����벿�������е�Ԫ��С�ڵ����Ұ벿�������е�Ԫ��
			Array[key] = left[i++];  //����벿�������е�Ԫ�ؿ�����Array������
		}
		else if(j < n2 && left[i] >= right[j]){  //�����벿�������е�Ԫ�ش����Ұ벿�������е�Ԫ��
			Array[key] = right[j++];  //���Ұ벿�������е�Ԫ�ؿ�����Array������
			}
		else if(i == n1 && j < n2){   //��벿�������е�Ԫ���Ѿ�ȫ��������Array��
			Array[key] = right[j++];//���Ұ벿�������е�Ԫ�ؿ�����Array������
		}
			
		else if(j == n2 && i < n1){
			Array[key] = left[i++];//����벿�������е�Ԫ�ؿ�����Array������
		}	
			
	}
	sum=sum+n1+n2;
}
//�鲢������
void MergeSort(int list[], int first, int last){
	
	if(first + 1 < last){     		 
		int middle = (last + first) / 2;  //�����м�λ��
		MergeSort(list, first, middle);  //�鲢ǰ�������
		MergeSort(list, middle, last);  //�鲢��������
		Merge(list, first, middle, last);  //����������ϲ�
	}
}

// void Merge(int r[],int r1,int s,int m,int t){
// 	int i=s,j=m+1,k=s;
// 	while(i<=m&&j<=t){
// 		if(r[i]<=r[j]){
// 			r1[k++]=r[i++];
// 		}
// 		else{
// 			r1[k++]=r[j++];
// 		}
// 		while(i<=m){
// 			r1[k++]=r[i++];
// 		}
// 		while(j<=t){
// 			r1[k++]=r[j++];
// 		}
// 	}
// }

// void MergeSort(int r[],int s,int t){
// 	int m;
// 	int *r1=(int*)malloc((t-s+1)*sizeof(int));
// 	if(s==t){
// 		return;
// 	}
// 	else{
// 		m=(s+t)/2;
// 		MergeSort(r,s,m);
// 		MergeSort(r,m+1,t);
// 		Merge(r,s,m,t);
// 		r[i]=r1[i];
// 	}
// }

// void Merge(int r[],int r1[],int s,int m,int t){
// 	int i=s,j=m+1,k=s;
// 	while(i<=m&&j<=t){
// 		if(r[i]<=r[j]){
// 			r1[k]=r[i];
// 			i++;
// 		}
// 		else{
// 			r1[k]=r[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	while(i<=m){
// 		r1[k]=r[i];
// 		i++;
// 	}
// 	while(j<=t){
// 		r1[k]=r[j];
// 		j++;
// 	}
// 	sum=sum+t-s+1;
// }

// void MergeSort(int r[],int s,int t){
// 	int m;
// 	int *r1=(int*)malloc((t-s+1)*sizeof(int));
// 	if(s==t){
// 		return;
// 	}
// 	else{
// 		m=(s+t)/2;
// 		MergeSort(r,s,m);
// 		MergeSort(r,m+1,t);
// 		Merge(r,r1,s,m,t);
// 		for(int i=s;i<=t;i++){
// 			r[i]=r1[i];
// 		}
// 	}
// }

void RandomLGC(int *list,int n,int l,int r)   //���ɷ�Χ��l~r������� 
{
	srand(time(0));                     //����ʱ������
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //��������r~l������� 
	}
}

int main()
{
	int n;   //����Ԫ�صĸ�����������������ĸ���
    printf("����������������ĸ�����");
    scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000000);//�����������ͨ����ΧΪ0~32767������ͨ��ȡģ����ȡֵΪ0~100000
    int len = (int) sizeof(list) / sizeof(*list);
	// printf("������ɵ�����Ϊ:\n");
	// for (int i = 0; i < len; i++){
    //     printf("%d ",list[i]);
    // }
       MergeSort(list, 0, n);
	// printf("\n�ϲ�����������Ϊ:\n");
    // for (int i = 0; i < len; i++){
    //     printf("%d ",list[i]);
    // }
	printf("\n�Ƚϴ���Ϊ��%d\n",sum);
    return 0;
}
