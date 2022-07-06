#include<iostream> 
#include<algorithm>
using namespace std;
const int M = 10000000;
struct three
{
	double w;  // 宝物重量
	double v;  // 宝物价值
	double p;  // 宝物性价比
}s[M];

bool cmp(three a,three b)
{
	// 按照宝物的性价比排序 
	return a.p > b.p; 
}

int main()
{
	int n;  // 宝物数量 n
	double m;  //  背包的最大载重 m
	
	cout << "请输入宝物数量 n 及背包的最大载重 m " << endl;
	cin >> n >> m;
	
	cout << "请输入每个宝物的重量 w 及价值 v " << endl;
	for(int i = 0;i < n;i++)
	{
		cin >> s[i].w >> s[i].v;
		
		// 求性价比 
		s[i].p = s[i].v / s[i].w;  
	}
	 
	// 按性价比排序 
	sort(s, s+n,cmp);

	// 装入的宝物的最大价值总和 
	double sum = 0.0;
	
	// 将宝物装入背包 
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
	
	cout << "装入的宝物的最大价值总和为" << sum << endl;
	return 0; 
}
