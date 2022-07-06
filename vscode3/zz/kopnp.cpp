#include<iostream> 
#include<algorithm>
using namespace std;

const int M = 10005;
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

void RandomWeight(int n,int l,int r)   //生成范围在l~r的随机物品重量 
{
    int seed=1;
    srand(seed);                   //设置时间种子
	for(int i=0;i<n;i++){
		s[i].w=(double)(rand()%(r-l+1)+l);          //生成区间r~l的随机数 
	}
  printf("随机生成的物品重量为：\n");
    for (int i = 0; i < n; i++){
        printf("%f ",s[i].w);
    }
}

void RandomValue(int n,int l,int r)   //生成范围在l~r的随机随机物品价值
{
    int seed=2;
	srand(seed);                     //设置时间种子
	for(int i=0;i<n;i++){
	   s[i].v=(double)(rand()%(r-l+1)+l);          //生成区间r~l的随机数
	}
  printf("\n随机生成的物品价值为：\n");
    for (int i = 0; i < n; i++){
        printf("%f ",s[i].v);
    }
}

int main()
{
	int n;  // 宝物数量 n
	double m;  //  背包的最大载重 m
	
	cout << "请输入宝物数量 n 及背包的最大载重 m " << endl;
	cin >> n >> m;
	

    RandomWeight(n,1,100);

    RandomValue(n,1,100);

	// cout << "请输入每个宝物的重量 w 及价值 v " << endl;
	// for(int i = 0;i < n;i++)
	// {
	// 	cin >> s[i].w >> s[i].v;
		
	// 	// 求性价比 
	// 	s[i].p = s[i].v / s[i].w;  
	// }
	 for(int i = 0;i < n;i++)
     {
     	//cin >> s[i].w >> s[i].v;
        
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
	
	cout << "\n装入的宝物的最大价值总和为" << sum << endl;
	return 0; 
}
