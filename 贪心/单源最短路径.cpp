#include<bits/stdc++.h>
# define M 99999
using namespace std;
void dijkstra(int n,int start,int dist[],int c[][100],int prev[])
{
	bool s[100]={0};//s[i]=1������s�����У��Ѿ�ȷ�����·����С 
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[start][i];
		if(dist[i]<M)prev[i]=start;
		else prev[i]=0;
	}
	s[start]=1;dist[start]=0;
	for(int i=1;i<=n-1;i++)//����n-1��ѭ�� ��ֱ�����н�����
	{
		int temp=M,u=start;
		for(int j=1;j<=n;j++)if(!s[j]&&dist[j]<temp)//�ҵ���ǰ��Сdist[] 
		{
			temp=dist[j];
			u=j;
		}
		s[u]=1;//���ҵ�����С�ļ��� 
		for(int j=1;j<=n;j++)if(!s[j]&&c[u][j]<M&&dist[u]+c[u][j]<dist[j])//�жϼ���u�Ƿ�Ӱ��dist[]�ı仯������dist[]���� 
		{
			dist[j]=dist[u]+c[u][j];
			prev[j]=u;//��¼�������ǰ�� 
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
	printf("�����������:\n");
	cin >> n;
	printf("������%d*%d�ڽӾ���:\n",n,n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if(c[i][j]<0)c[i][j]=M;
		}
			
	printf("�ӽ��1�������������·������Ϊ:\n");
	dijkstra(n, start, dist,c,prev);
	for (int i = 1; i <= n; i++)cout << dist[i] << ' ';
	cout << endl;
	printf("������ĳ������Ա�����ý������·��\n");
	int m; cin >> m;
	path(prev, m);
	cout << m << endl;
	system("Pause");
	return 0;
}
