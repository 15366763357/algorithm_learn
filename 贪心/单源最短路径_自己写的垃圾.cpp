#include<bits/stdc++.h>
# define M 99999
using namespace std;
void dis(int n, int a[][100], int v[], int dist[],int prev[])
{
	v[1] = 1; dist[1] = 0;//v[i]=1代表在s集合中，已经确定最短路径大小 
	for (int k = 1; k <= n - 1; k++)//进行n-1次循环 ，直到所有结点加入 
	{
		int d = M, t;
		for (int i = 1; i <= n; i++)
			if (v[i] == 1)//遍历s中结点 
			{
				for (int j = 1; j <= n; j++)
					if (v[j] == 0 && a[i][j] > 0&& dist[i] + a[i][j]<d)//遍历v-s中结点，找到最小的加入 
					{
							d = dist[i] + a[i][j];
							t = j;
							prev[j] = i;//记录加入结点的前驱 
					}
			}
		dist[t] = d;
		v[t] = 1;
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
	int v[100] = { 0 }, n, a[100][100], dist[100] = { 0 },prev[100];
	printf("请输入结点个数:\n");
	cin >> n;
	printf("请输入%d*%d邻接矩阵:\n",n,n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	printf("从结点1到各个结点的最短路径长度为:\n");
	dis(n, a, v, dist,prev);
	for (int i = 1; i <= n; i++)cout << dist[i] << ' ';
	cout << endl;
	printf("请输入某个结点以便输出该结点的最短路径\n");
	int m; cin >> m;
	path(prev, m);
	cout << m << endl;
	system("Pause");
	return 0;
}
