#include<bits/stdc++.h>
# define M 99999
using namespace std;
void dis(int n, int a[][100], int v[], int dist[],int prev[])
{
	v[1] = 1; dist[1] = 0;//v[i]=1������s�����У��Ѿ�ȷ�����·����С 
	for (int k = 1; k <= n - 1; k++)//����n-1��ѭ�� ��ֱ�����н����� 
	{
		int d = M, t;
		for (int i = 1; i <= n; i++)
			if (v[i] == 1)//����s�н�� 
			{
				for (int j = 1; j <= n; j++)
					if (v[j] == 0 && a[i][j] > 0&& dist[i] + a[i][j]<d)//����v-s�н�㣬�ҵ���С�ļ��� 
					{
							d = dist[i] + a[i][j];
							t = j;
							prev[j] = i;//��¼�������ǰ�� 
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
	printf("�����������:\n");
	cin >> n;
	printf("������%d*%d�ڽӾ���:\n",n,n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	printf("�ӽ��1�������������·������Ϊ:\n");
	dis(n, a, v, dist,prev);
	for (int i = 1; i <= n; i++)cout << dist[i] << ' ';
	cout << endl;
	printf("������ĳ������Ա�����ý������·��\n");
	int m; cin >> m;
	path(prev, m);
	cout << m << endl;
	system("Pause");
	return 0;
}
