#include<iostream> 
#include<algorithm>
using namespace std;
const int M = 10000000;
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

int main()
{
	int n;  // �������� n
	double m;  //  ������������� m
	
	cout << "�����뱦������ n ��������������� m " << endl;
	cin >> n >> m;
	
	cout << "������ÿ����������� w ����ֵ v " << endl;
	for(int i = 0;i < n;i++)
	{
		cin >> s[i].w >> s[i].v;
		
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
	
	cout << "װ��ı��������ֵ�ܺ�Ϊ" << sum << endl;
	return 0; 
}
