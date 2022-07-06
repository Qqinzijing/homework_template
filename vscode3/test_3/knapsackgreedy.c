/*
    �������⣬̰���㷨Cʵ��
    ѧ�ţ�20201050470
    ʱ�临�Ӷȣ�O(n^2)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void package(float P[], float w[], int M,int n);//̰���㷨
//void package(int n,float c,float v[],float w[],int x[]);
void RandomWeight(float *list, int n, int l, int r);//�������n������ÿ�����ķ�Χ��[l,r]֮��
void RandomValue(float *list, int n, int l, int r);//�������n������ÿ�����ķ�Χ��[l,r]֮��
void sortkp(float pw[],int index[], float w[],float v[],int M,int n);//���ռ�ֵ����
void initpackage();//��ʼ������


int main(){
  initpackage();
  return 0;
}

void package(float P[], float w[], int M,int n)
{
  //printf("%d\n",M);
  int i;
  float x[n];
  for (i = 0; i < n; i++)
  {
    x[i] = 0; //��ʼ״̬��������Ʒ��û�б����뱳��
  }
  float cu=M;   //cu�Ǳ���ʣ������
  for (i = 0; i < n; i++)
  {
    if (w[i] > cu)
    {
      break;
    }
    x[i] = 1;
    cu = cu - w[i];
    //printf("�����%d����Ʒ������ʣ������%f.\n", (i + 1), cu);
  }

  if (i < n) //�����Է���һ����Ʒ��һ����
  {
    x[i] = cu / w[i];
    //printf("\n�����%d����Ʒ��%f����.����ʣ������Ϊ0.\n", (i + 1), w[i] * x[i]);
  }
  printf("\n��������Ž�Ϊ��\n");
  for (i = 0; i < n; i++)
  {
   printf("%f ", x[i]);
  }
  float sum=0;
  for (i = 0; i < n; i++)
  {
    sum=sum+x[i]*P[i];
  }
  printf("\n���Ž�ļ�ֵΪ��%f\n",sum);
}

void RandomWeight(float *list, int n, int l, int r) //���ɷ�Χ��l~r�������Ʒ����
{
  int seed = time(NULL);
  srand(seed); //����ʱ������
  for (int i = 0; i < n; i++)
  {
    list[i] = (float)(rand() % (r - l + 1) + l); //��������r~l�������
  }
  printf("������ɵ���Ʒ����Ϊ��\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}

void RandomValue(float *list, int n, int l, int r) //���ɷ�Χ��l~r����������Ʒ��ֵ
{
  int seed = 1;
  srand(seed); //����ʱ������
  for (int i = 0; i < n; i++)
  {
    list[i] = (float)(rand() % (r - l + 1) + l); //��������r~l�������
  }
  printf("\n������ɵ���Ʒ��ֵΪ��\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}


//����
void sortkp(float pw[],int index[], float w[],float v[],int M,int n)
{
  for(int i=0;i<n;i++)
  {
   pw[i]=v[i]/w[i];
   index[i]=i;
  }
  float temp=0;
  for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pw[i] < pw[j])   //�Լ�ֵ/�������鰴������������    
                {
                    temp = pw[i];
                    pw[i] = pw[j];
                    pw[j] = temp;
                    int x = index[i];       //������Ӧ�������±�
                    index[i] = index[j];
                    index[j] = x;
                }
            }
        }
        float w1[n];
        float v1[n];
        for(int i=0;i<n;i++)
        {
          w1[i]=w[index[i]];
          v1[i]=v[index[i]];
        }
        printf("\n����Ʒ��ֵ/������ֵ��\n");
        for(int i=0;i<n;i++)
        {
          printf("%f ",pw[i]);
        }
        printf("\n��Ӧ��������Ϊ��\n");
        for(int i=0;i<n;i++)
        {
          printf("%f ",w1[i]);
        }
        printf("\n��Ӧ��ֵ����Ϊ��\n");
        for(int i=0;i<n;i++)
        {
          printf("%f ",v1[i]);
        }
        //printf("%d\n",M);
        package(v1,w1,M,n);
}

void initpackage(){
  int n;
  int M;

  clock_t begin, end;
  double cost;

  printf("��������Ʒ������");
  scanf("%d",&n);
  printf("�����뱳�����������");
  scanf("%d",&M);
  float v[n];
  float w[n];

  RandomWeight(w,n,1,100);
  RandomValue(v,n,1,100);

  float pw[n];
  int x[n];
  begin = clock();//��ʼ��ʱ
  sortkp(pw,x,w,v,M,n);
  //package(v,w,c,n);
  end = clock();//������ʱ
  cost = (double)(end - begin)*1000/CLOCKS_PER_SEC;
  //CLOCKS_PER_SEC=1000,��������ʾһ���ӻ��ж��ٸ�ʱ�Ӽ�ʱ��Ԫ��
  //ʱ�Ӽ�ʱ��Ԫ�ĳ���Ϊ1���룬clock()/CLOCKS_PER_SEC���ǽ�����ת��Ϊ�롣

  printf("\n����ʱ��: %lf ms",cost);
  printf("\n");
}












// void Merge(float Array[], int first, int middle, int last){//�ϲ�����
// 	int n1 = middle - first;//�������鳤��
// 	int n2 = last - middle;//�Ұ�����鳤��
	
// 	float left[n1];
// 	float right[n2];
	
// 	for(int i = 0; i < n1; i++){
// 		left[i] = Array[first + i];    //����벿�����鿽����left������
// 	}
// 	for(int i = 0; i < n2; i++){
// 		right[i] = Array[middle + i];  //���Ұ벿�����鿽����right������
// 	}
// 	int i = 0, j = 0, key;
// 	for(key = first; key < last; key++){
// 		if(i < n1 && left[i] <= right[j]){  //�����벿�������е�Ԫ��С�ڵ����Ұ벿�������е�Ԫ��
// 			Array[key] = left[i++];  //����벿�������е�Ԫ�ؿ�����Array������
// 		}
// 		else if(j < n2 && left[i] >= right[j]){  //�����벿�������е�Ԫ�ش����Ұ벿�������е�Ԫ��
// 			Array[key] = right[j++];  //���Ұ벿�������е�Ԫ�ؿ�����Array������
// 			}
// 		else if(i == n1 && j < n2){   //��벿�������е�Ԫ���Ѿ�ȫ��������Array��
// 			Array[key] = right[j++];//���Ұ벿�������е�Ԫ�ؿ�����Array������
// 		}
			
// 		else if(j == n2 && i < n1){
// 			Array[key] = left[i++];//����벿�������е�Ԫ�ؿ�����Array������
// 		}	
			
// 	}
// }
// void MergeSort(float list[], int first, int last){
	
// 	if(first + 1 < last){     		 
// 		int middle = (last + first) / 2;  //�����м�λ��
// 		MergeSort(list, first, middle);  //�鲢ǰ�������
// 		MergeSort(list, middle, last);  //�鲢��������
// 		Merge(list, first, middle, last);  //����������ϲ�
// 	}
// }


// //����
// void sortkp(float pw[],int index[], float w[],float v[],int n)
// {
//   for(int i=0;i<n;i++)
//   {
//    pw[i]=v[i]/w[i];
//    index[i]=i;
//   }
//   //Merge(pw,0,n/2,n);
//   MergeSort(pw,0,n);

//   // float temp=0;
//   // for (int i = 0; i < n - 1; i++) {
//   //           for (int j = i + 1; j < n; j++) {
//   //               if (pw[i] > pw[j])       //��ֵ/�����ݼ�����
//   //               {
//   //                   temp = pw[i];
//   //                   pw[i] = pw[j];
//   //                   pw[j] = temp;
//   //                   temp = index[i];
//   //                   index[i] = index[j];
//   //                   index[j] = temp;
//   //               }
//   //               {
//   //                   temp = pw[i];
//   //                   pw[i] = pw[j];
//   //                   pw[j] = temp;
//   //                   temp = index[i];
//   //                   index[i] = index[j];
//   //                   index[j] = temp;
//   //               }
//   //               {
//   //                   temp = pw[i];
//   //                   pw[i] = pw[j];
//   //                   pw[j] = temp;
//   //                   int x = index[i];       //������Ӧ�������±�
//   //                   index[i] = index[j];
//   //                   index[j] = x;
//   //               }
//   //           }
//   //       }
//   //       float w1[n];
//   //       float v1[n];
//   //       for(int i=0;i<n;i++)
//   //       {
//   //         w1[i]=w[index[i]];
//   //         v1[i]=v[index[i]];
//   //       }
//   //       printf("\n����Ʒ��ֵ/������ֵ��\n");
//   //       for(int i=0;i<n;i++)
//   //       {
//   //         printf("%f ",pw[i]);
//   //       }
//   //       printf("\n��Ӧ��������Ϊ��\n");
//   //       for(int i=0;i<n;i++)
//   //       {
//   //         printf("%f ",v1[i]);
//   //       }
//   //       printf("\n��Ӧ��ֵ����Ϊ��\n");
//   //       for(int i=0;i<n;i++)
//   //       {
//   //         printf("%f ",w1[i]);
//   //       }
        
// }