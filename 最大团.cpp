#include<bits/stdc++.h>
using namespace std;
int n = 5;//顶点数
int a[100][100];//邻接矩阵
int x[100];//当前解
int bestx[100];//当前最优解
int cn;//当前顶点数
int bestn;//当前最大顶点数
void Backtrack(int i)
{
	if (i > n) {
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = x[j];
			//cout << bestx[j]<<' ';
		}
		bestn = cn;
		//cout << endl;
		return;

	}
	int OK = 1;
	for (int j = 1; j < i; j++)
	{
		if (x[j] && a[i][j] == 0)
		{
			OK = 0;
			break;
		}
	}
	if (OK)
	{
		x[i] = 1;
		cn++;
		Backtrack(i + 1);
		x[i] = 0;
		cn--;
	}
	if (cn + n - i >= bestn)
	{
		x[i] = 0;
		Backtrack(i + 1);
	}

}
int main()
{
	cout << "请输入图的邻接矩阵" << endl;
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=n; j++)cin >> a[i][j];
	cn = 0;
	bestn = 0;
	bestx[100] = { 0 };
	Backtrack(1);
	cout << "最大团中节点个数如下：" << bestn<<endl;
	//cout << bestn << endl;
	cout << "其中一个满足要求的最大团节点组成情况如下(0代表没有该节点,1代表有该节点):" << endl;
	for (int j = 1; j <= n; j++)
	{
		//bestx[j] = x[j];
		cout << bestx[j]<<' ';
	}
	cout << endl;
	system("Pause");
	return 0;
}