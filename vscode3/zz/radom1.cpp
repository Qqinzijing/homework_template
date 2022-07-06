#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

void Random(int *a,int n,int l,int r)   //���ɷ�Χ��l~r������� 
{
	srand(time(0));                     //����ʱ������
	for(int i=0;i<n;i++){
		a[i]=rand()%(r-l+1)+l;          //��������r~l������� 
	}
}

void BubbleSort(int list[], int n) {//ð�������㷨
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
	int n;                 //����Ԫ�صĸ�����������������ĸ���
    printf("����������������ĸ�����");
    scanf("%d",&n);
	int list[n];
	Random(list,n,1,1000000);     //�����������ͨ����ΧΪ0~32767������ͨ��ȡģ����ȡֵΪ0~100 
    int len = (int) sizeof(list) / sizeof(*list);
    printf("���ɵ�������飺\n");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
    BubbleSort(list, len);
    printf("\n����ð��������������飺\n");
    for (int i = 0; i < len; i++){
        printf("%d ",list[i]);
    }
        return 0;
}