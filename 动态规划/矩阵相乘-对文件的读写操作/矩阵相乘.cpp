//30 35 15 5 10 20 25
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
ofstream fpw; 
void MatrixChain(int *p, int n,int(*m)[10],int(*s)[10])//得到最优值数组m，记录最优断开位置数组s
{//p存储各矩阵行列数，n为总的矩阵数目
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;//1个矩阵做乘法次数为0
		s[i][i]=0;
	}
	for (int r = 2; r <= n; r++)//r个矩阵相乘
	{
		for (int i = 1; i <= n - r + 1; i++)//从第i个矩阵开始相乘
		{
			int j = i + r - 1;//一直乘到第j个矩阵
			m[i][j] = m[i][i]+m[i + 1][j] + p[i - 1] * p[i] * p[j]; s[i][j] = i;//假设i为最佳分割处                                    
			for (int k = i + 1; k < j; k++)
			{
				int t= m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}//找到最佳分割处；
		}
	}
}
/*void matrixMultiply(int **a, int **b,int **c, int ra, int ca, int rb, int cb)//矩阵相乘结果
{
	if (ca != rb) { cout << "矩阵不可乘"; return; }
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			int sum = 0;
			for (int m = 0; m < ca; m++)
			{
				sum += a[i][m] * b[m][j];
			}
			c[i][j] = sum;
		}
	}
}*/
void Traceback(int i, int j,int (*s)[10])
{
	if (i == j)return;
	Traceback(i, s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	printf("Multiply A[%d,%d] and A[%d,%d]\n",i,s[i][j],s[i][j]+1,j);
	fpw<<"Multiply A["<<i<<","<<s[i][j]<<"] and A["<<s[i][j]+1<<j<<"]\n";
}
int main()
{
	ifstream fpr;
	int m[10][10], s[10][10];
	int p[200],n;
	fpr.open("test.txt",ios::in);
	fpr>>n;
	for(int i=0;i<=n;i++)fpr>>p[i];
	fpr.close();
	/*printf("请输入矩阵的个数:\n");
	cin>>n;
	printf("请输入p[]数组:\n");
	for (int i = 0; i <= n; i++)cin >> p[i];*/
	MatrixChain(p, n,m,s);
	fpw.open("result.txt",ios::out);
	fpw<<"计算顺序如下:\n";
	printf("计算顺序如下:\n"); 
	Traceback(1, n,s);
	printf("m[i][j]数组如下:\n");
	fpw<<"m[i][j]数组如下:\n";
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(j<i)cout<<' '<<' ';
		else cout<<m[i][j]<<(j==n?'\n':' '); 
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(j<i)fpw<<"a"<<" ";
		else fpw<<m[i][j]<<(j==n?'\n':' '); 
	}
	
	
	printf("s[i][j]数组如下:\n");
	fpw<<"s[i][j]数组如下:\n";
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(j<i)cout<<' '<<' ';
		else cout<<s[i][j]<<(j==n?'\n':' '); 
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(j<i)fpw<<"a"<<" ";
		else fpw<<s[i][j]<<(j==n?'\n':' '); 
	}
	return 0;
}
