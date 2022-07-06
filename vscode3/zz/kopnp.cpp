#include<iostream> 
#include<algorithm>
using namespace std;

const int M = 10005;
struct three
{
	double w;  // ��������
	double v;  // �����ֵ
	double p;  // �����Լ۱�
}s[M];

bool cmp(three a,three b)
{
	// ���ձ�����Լ۱����� 
	return a.p > b.p; 
}

void RandomWeight(int n,int l,int r)   //���ɷ�Χ��l~r�������Ʒ���� 
{
    int seed=1;
    srand(seed);                   //����ʱ������
	for(int i=0;i<n;i++){
		s[i].w=(double)(rand()%(r-l+1)+l);          //��������r~l������� 
	}
  printf("������ɵ���Ʒ����Ϊ��\n");
    for (int i = 0; i < n; i++){
        printf("%f ",s[i].w);
    }
}

void RandomValue(int n,int l,int r)   //���ɷ�Χ��l~r����������Ʒ��ֵ
{
    int seed=2;
	srand(seed);                     //����ʱ������
	for(int i=0;i<n;i++){
	   s[i].v=(double)(rand()%(r-l+1)+l);          //��������r~l�������
	}
  printf("\n������ɵ���Ʒ��ֵΪ��\n");
    for (int i = 0; i < n; i++){
        printf("%f ",s[i].v);
    }
}

int main()
{
	int n;  // �������� n
	double m;  //  ������������� m
	
	cout << "�����뱦������ n ��������������� m " << endl;
	cin >> n >> m;
	

    RandomWeight(n,1,100);

    RandomValue(n,1,100);

	// cout << "������ÿ����������� w ����ֵ v " << endl;
	// for(int i = 0;i < n;i++)
	// {
	// 	cin >> s[i].w >> s[i].v;
		
	// 	// ���Լ۱� 
	// 	s[i].p = s[i].v / s[i].w;  
	// }
	 for(int i = 0;i < n;i++)
     {
     	//cin >> s[i].w >> s[i].v;
        
     	// ���Լ۱� 
     	s[i].p = s[i].v / s[i].w;  
     }

	// ���Լ۱����� 
	sort(s, s+n,cmp);
    
	// װ��ı��������ֵ�ܺ� 
	double sum = 0.0;
	
	// ������װ�뱳�� 
	for(int i=0;i<n;i++)
	{
		if(m > s[i].w)
		{
			m -= s[i].w;
			sum += s[i].v;
		}
		else
		{
			sum += (m*s[i].p);
			break;
		}
	}
	
	cout << "\nװ��ı��������ֵ�ܺ�Ϊ" << sum << endl;
	return 0; 
}
