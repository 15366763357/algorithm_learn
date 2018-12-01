#include<bits/stdc++.h>
# define M 99999
using namespace std;
void dijkstra(int n,int start,int dist[],int c[][100],int prev[])
{
	bool s[100]={0};//s[i]=1代表在s集合中，已经确定最短路径大小 
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[start][i];
		if(dist[i]<M)prev[i]=start;
		else prev[i]=0;
	}
	s[start]=1;dist[start]=0;
	for(int i=1;i<=n-1;i++)//进行n-1次循环 ，直到所有结点加入
	{
		int temp=M,u=start;
		for(int j=1;j<=n;j++)if(!s[j]&&dist[j]<temp)//找到当前最小dist[] 
		{
			temp=dist[j];
			u=j;
		}
		s[u]=1;//将找到的最小的加入 
		for(int j=1;j<=n;j++)if(!s[j]&&c[u][j]<M&&dist[u]+c[u][j]<dist[j])//判断加入u是否影响dist[]的变化，更新dist[]数组 
		{
			dist[j]=dist[u]+c[u][j];
			prev[j]=u;//记录加入结点的前驱 
		}
	}
}
void path(int prev[],int i)
{
	if (i> 1)
	{
		path(prev, prev[i]);
		cout << prev[i] << ' ';
	}
}
int main()
{
	int n, c[100][100], dist[100] = { 0 },prev[100],start=1;
	printf("请输入结点个数:\n");
	cin >> n;
	printf("请输入%d*%d邻接矩阵:\n",n,n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if(c[i][j]<0)c[i][j]=M;
		}
			
	printf("从结点1到各个结点的最短路径长度为:\n");
	dijkstra(n, start, dist,c,prev);
	for (int i = 1; i <= n; i++)cout << dist[i] << ' ';
	cout << endl;
	printf("请输入某个结点以便输出该结点的最短路径\n");
	int m; cin >> m;
	path(prev, m);
	cout << m << endl;
	system("Pause");
	return 0;
}
