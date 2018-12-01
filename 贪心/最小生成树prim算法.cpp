#include<bits/stdc++.h>
# define M 99999
using namespace std;
void prim(int n,int c[][100])
{
	bool s[100]={0};int lowcost[100],closest[100];//s[i]=1代表在s集合中
	s[1]=1;
	for(int i=2;i<=n;i++)
	{
		lowcost[i]=c[1][i];
		closest[i]=1;
	}
	for(int i=1;i<n;i++)//进行n-1次循环 ，直到所有结点加入
	{
		int min=M,u=1;
		for(int j=2;j<=n;j++)//找到当前最小lowcost[],并记录下标,lowcost[j]表示相对于当前s集合中，外部结点j与s集合的最短距离 
		if(!s[j]&&lowcost[j]<min)
		{
			min=lowcost[j];
			u=j;
		}
		s[u]=1;//将找到的最小的加入
		cout<<u<<closest[u]<<endl;
		for(int j=2;j<=n;j++)//判断加入u是否影响lowcost[]的变化，更新lowcost[]数组
			if(!s[j]&&c[u][j]<lowcost[j])
			{
				lowcost[j]=c[u][j];
				closest[j]=u;//closest[j]记录所加入结点j与s中相连接的结点 
			}
	}
 } 
 int main()
{
	int n, c[100][100];
	printf("请输入结点个数:\n");
	cin >> n;
	printf("请输入%d*%d邻接矩阵:\n",n,n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if(c[i][j]<0)c[i][j]=M;
		}	
	printf("依次加入边的情况如下:\n");
	prim(n, c);
	system("Pause");
	return 0;
}
