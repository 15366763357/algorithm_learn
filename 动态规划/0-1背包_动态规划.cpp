#include<bits/stdc++.h>
using namespace std;
void knapsack(int w[], int v[], int n, int c, int m[][100])
{
	for (int j = 0; j <= c; j++)
	{
		if (j<w[n])m[n][j] = 0;
		else m[n][j] = v[n];
	}
	for (int i = n - 1; i>1; i--)
	{
		for (int j = 0; j <= c; j++)
		{
			if (j<w[i])m[i][j] = m[i + 1][j];
			else m[i][j] = max(m[i + 1][j], v[i] + m[i + 1][j - w[i]]);
		}
	}
	if (c<w[1])m[1][c] = m[2][c];
	else m[1][c] = max(m[2][c], v[1] + m[2][c - w[1]]);

}
void output(int w[],int m[][100],int n,int c)
{
	int t = 1;
	while (t <n) 
	{
		if (m[t][c] != m[t + 1][c])
		{
			cout << t << ' ';
			c -= w[t];
		}
		t++;
	}
	if (c >= w[n])cout << n << endl;
}
int main()
{//依次输入物品数量，背包容量，各个物品质量，各个物品价值 
	int n, c;
	int w[100] = { 0 }, v[100] = { 0 };
	int m[100][100];
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> w[i];
	for (int j = 1; j <= n; j++)cin >> v[j];
	knapsack(w, v, n, c, m);
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= c; j++)
			cout << m[i][j] << (j == c ? '\n' : ' ');
	cout << m[1][c] << endl;
	output(w, m, n, c);
	system("Pause");
	return 0;
}
