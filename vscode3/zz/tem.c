#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()

{

clock_t begin, end;

double cost;

//��ʼ��¼

begin = clock();

/*�����Գ����*/

printf("hello world!\n");

//������¼

end = clock();

cost = (double)(end - begin)*1000/CLOCKS_PER_SEC;

printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf ms", CLOCKS_PER_SEC, cost);

}