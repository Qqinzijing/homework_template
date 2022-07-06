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
  // double w[] = {15,10,18};//已经按照单位价值降序排列

  int n;   //物品数量
  double C; //背包最大容量

  printf("请输入背包的最大容量:");
  scanf("%f", &C);

  printf("输入物品数:");
  scanf("%d", &n);

  double weight[n]; //物品重量
  double value[n];  //物品价值
  RandomWeight(weight, n, 1, 100);

  RandomValue(value, n, 1, 100);
  double *x;
  x = (double *)malloc(sizeof(double) * n);
  printf("\n******背包*******\n");
  package(n, C, value, weight, x);
  printf("\n*******0-1背包******\n");
  package0_1(n, C, value, weight, x);
  system("pause");
  return 0;
}

/*
 *  背包问题
 *  n:物品个数
 *  c：背包容量
 *  v[]:每个物品的价值
 *  w[]:每个物品的重量（这里已经按照单位价值降序排列 ）
 *  x[]:物品是否放入背包（0表示不放，1表示全部放入，0-1放入一部分）
 */
void package(int n, double c, double v[], double w[], double x[])
{
  int i;
  for (i = 0; i < n; i++)
  {
    x[i] = 0; //初始状态，所有物品都没有被放入背包
  }

  for (i = 0; i < n; i++)
  {
    if (w[i] > c)
    {
      break;
    }

    x[i] = 1;
    c = c - w[i];
    printf("放入第%d件物品，背包剩余容量%f.\n", (i + 1), c);
  }

  if (i <= n) //还可以放入一个物品的一部分
  {
    x[i] = c / w[i];

    printf("放入第%d件物品的%f部分.背包剩余容量为0.\n", (i + 1), w[i] * x[i]);
  }
}

void RandomWeight(double *list, int n, int l, int r) //生成范围在l~r的随机物品重量
{
  int seed = time(NULL);
  srand(seed); //设置时间种子
  for (int i = 0; i < n; i++)
  {
    list[i] = (double)(rand() % (r - l + 1) + l); //生成区间r~l的随机数
  }
  printf("随机生成的物品重量为：\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}

void RandomValue(double *list, int n, int l, int r) //生成范围在l~r的随机随机物品价值
{
  int seed = 1;
  srand(seed); //设置时间种子
  for (int i = 0; i < n; i++)
  {
    list[i] = (double)(rand() % (r - l + 1) + l); //生成区间r~l的随机数
  }
  printf("\n随机生成的物品价值为：\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}

/*
 *  0-1背包问题
 *  n:物品个数
 *  c：背包容量
 *  v[]:每个物品的价值
 *  w[]:每个物品的重量（这里已经按照单位价值降序排列 ）
 *  x[]:物品是否放入背包（0表示不放，1表示全部放入）
 */
void package0_1(int n, double c, double v[], double w[], double x[])
{
  int i;
  for (i = 0; i < n; i++)
  {
    x[i] = 0; //初始状态，所有物品都没有被放入背包
  }

  for (i = 0; i < n; i++)
  {
    if (w[i] > c)
    {
      break;
    }

    x[i] = 1;
    c = c - w[i];
    printf("放入第%d件物品，背包剩余容量%f.\n", (i + 1), c);
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
      if (PW[i] < PW[j]) //对效益/重量数组按递增进行排序
      {
        temp = PW[i];
        PW[i] = PW[j];
        PW[j] = temp;
        int x = index[i]; //交换相应的数组下标
        index[i] = index[j];
        index[j] = x;
      }
    }
  }

  double w1[n];
  double p1[n];
  for (int i = 0; i < n; i++)
  {
    w1[i] = W[index[i]]; //将排序后的重量和价值数组分别赋给w1[]和p1[]
    p1[i] = P[index[i]];
  }

  printf("\n各物品效益/重量的值为：");

  for (int i = 0; i < n; i++)
  {
    printf("%f ", PW[i]);
  }
  printf("\n\t\tv[1..n]和 w[1..n]分别含有按 vi/wi>v(i+1)/v(i+1)排序的n 件物品的价值和重量。\n");
  for (int i = 0; i < n; i++)
  {
    printf("\t\t%d\t%f\t%f\n", i + 1, p1[i], w1[i]);
  }
  // printf("\n\t\t按 vi/wi>v(i+1)/v(i+1)排序后的物品序号为：");
  // for (int i = 0; i < n; i++) {
  //     print(index[i] + " ");
  // }
  // printf("\n");
}
// printf("相应的重量数组为：" + Arrays.toString(w1));
// printlf("相应的效益数组为：" + Arrays.toString(p1));
//}
