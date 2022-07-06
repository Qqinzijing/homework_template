#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void package(int n, double c, double v[], double w[], double x[]);
void package0_1(int n, double c, double v[], double w[], double x[]);
void RandomWeight(double *list, int n, int l, int r);
void RandomValue(double *list, int n, int l, int r);
void sortkp(double PW[], int index[], int n,double P[], double W[]);

int main(void){
  // int n = 3;
  // double c = 20;
  // double v[] = {24,15,25};
  // double w[] = {15,10,18};//�Ѿ����յ�λ��ֵ��������

  int n;   //��Ʒ����
  double C; //�����������

  printf("�����뱳�����������:");
  scanf("%f", &C);

  printf("������Ʒ��:");
  scanf("%d", &n);

  double weight[n]; //��Ʒ����
  double value[n];  //��Ʒ��ֵ
  RandomWeight(weight, n, 1, 100);

  RandomValue(value, n, 1, 100);
  double *x;
  x = (double *)malloc(sizeof(double) * n);
  printf("\n******����*******\n");
  package(n, C, value, weight, x);
  printf("\n*******0-1����******\n");
  package0_1(n, C, value, weight, x);
  system("pause");
  return 0;
}

/*
 *  ��������
 *  n:��Ʒ����
 *  c����������
 *  v[]:ÿ����Ʒ�ļ�ֵ
 *  w[]:ÿ����Ʒ�������������Ѿ����յ�λ��ֵ�������� ��
 *  x[]:��Ʒ�Ƿ���뱳����0��ʾ���ţ�1��ʾȫ�����룬0-1����һ���֣�
 */
void package(int n, double c, double v[], double w[], double x[])
{
  int i;
  for (i = 0; i < n; i++)
  {
    x[i] = 0; //��ʼ״̬��������Ʒ��û�б����뱳��
  }

  for (i = 0; i < n; i++)
  {
    if (w[i] > c)
    {
      break;
    }

    x[i] = 1;
    c = c - w[i];
    printf("�����%d����Ʒ������ʣ������%f.\n", (i + 1), c);
  }

  if (i <= n) //�����Է���һ����Ʒ��һ����
  {
    x[i] = c / w[i];

    printf("�����%d����Ʒ��%f����.����ʣ������Ϊ0.\n", (i + 1), w[i] * x[i]);
  }
}

void RandomWeight(double *list, int n, int l, int r) //���ɷ�Χ��l~r�������Ʒ����
{
  int seed = time(NULL);
  srand(seed); //����ʱ������
  for (int i = 0; i < n; i++)
  {
    list[i] = (double)(rand() % (r - l + 1) + l); //��������r~l�������
  }
  printf("������ɵ���Ʒ����Ϊ��\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}

void RandomValue(double *list, int n, int l, int r) //���ɷ�Χ��l~r����������Ʒ��ֵ
{
  int seed = 1;
  srand(seed); //����ʱ������
  for (int i = 0; i < n; i++)
  {
    list[i] = (double)(rand() % (r - l + 1) + l); //��������r~l�������
  }
  printf("\n������ɵ���Ʒ��ֵΪ��\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}

/*
 *  0-1��������
 *  n:��Ʒ����
 *  c����������
 *  v[]:ÿ����Ʒ�ļ�ֵ
 *  w[]:ÿ����Ʒ�������������Ѿ����յ�λ��ֵ�������� ��
 *  x[]:��Ʒ�Ƿ���뱳����0��ʾ���ţ�1��ʾȫ�����룩
 */
void package0_1(int n, double c, double v[], double w[], double x[])
{
  int i;
  for (i = 0; i < n; i++)
  {
    x[i] = 0; //��ʼ״̬��������Ʒ��û�б����뱳��
  }

  for (i = 0; i < n; i++)
  {
    if (w[i] > c)
    {
      break;
    }

    x[i] = 1;
    c = c - w[i];
    printf("�����%d����Ʒ������ʣ������%f.\n", (i + 1), c);
  }
}

void sortkp(double PW[], int index[], int n, double P[], double W[])
{

  for (int i = 0; i < n; i++)
  {
    PW[i] = P[i] / W[i];
    index[i] = i;
  }

  double temp = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (PW[i] < PW[j]) //��Ч��/�������鰴������������
      {
        temp = PW[i];
        PW[i] = PW[j];
        PW[j] = temp;
        int x = index[i]; //������Ӧ�������±�
        index[i] = index[j];
        index[j] = x;
      }
    }
  }

  double w1[n];
  double p1[n];
  for (int i = 0; i < n; i++)
  {
    w1[i] = W[index[i]]; //�������������ͼ�ֵ����ֱ𸳸�w1[]��p1[]
    p1[i] = P[index[i]];
  }

  printf("\n����ƷЧ��/������ֵΪ��");

  for (int i = 0; i < n; i++)
  {
    printf("%f ", PW[i]);
  }
  printf("\n\t\tv[1..n]�� w[1..n]�ֱ��а� vi/wi>v(i+1)/v(i+1)�����n ����Ʒ�ļ�ֵ��������\n");
  for (int i = 0; i < n; i++)
  {
    printf("\t\t%d\t%f\t%f\n", i + 1, p1[i], w1[i]);
  }
  // printf("\n\t\t�� vi/wi>v(i+1)/v(i+1)��������Ʒ���Ϊ��");
  // for (int i = 0; i < n; i++) {
  //     print(index[i] + " ");
  // }
  // printf("\n");
}
// printf("��Ӧ����������Ϊ��" + Arrays.toString(w1));
// printlf("��Ӧ��Ч������Ϊ��" + Arrays.toString(p1));
//}
