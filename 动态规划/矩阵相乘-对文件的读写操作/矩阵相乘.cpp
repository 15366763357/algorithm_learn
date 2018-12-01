//30 35 15 5 10 20 25
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
ofstream fpw; 
void MatrixChain(int *p, int n,int(*m)[10],int(*s)[10])//�õ�����ֵ����m����¼���ŶϿ�λ������s
{//p�洢��������������nΪ�ܵľ�����Ŀ
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;//1���������˷�����Ϊ0
		s[i][i]=0;
	}
	for (int r = 2; r <= n; r++)//r���������
	{
		for (int i = 1; i <= n - r + 1; i++)//�ӵ�i������ʼ���
		{
			int j = i + r - 1;//һֱ�˵���j������
			m[i][j] = m[i][i]+m[i + 1][j] + p[i - 1] * p[i] * p[j]; s[i][j] = i;//����iΪ��ѷָ                                    
			for (int k = i + 1; k < j; k++)
			{
				int t= m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}//�ҵ���ѷָ��
		}
	}
}
/*void matrixMultiply(int **a, int **b,int **c, int ra, int ca, int rb, int cb)//������˽��
{
	if (ca != rb) { cout << "���󲻿ɳ�"; return; }
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
	/*printf("���������ĸ���:\n");
	cin>>n;
	printf("������p[]����:\n");
	for (int i = 0; i <= n; i++)cin >> p[i];*/
	MatrixChain(p, n,m,s);
	fpw.open("result.txt",ios::out);
	fpw<<"����˳������:\n";
	printf("����˳������:\n"); 
	Traceback(1, n,s);
	printf("m[i][j]��������:\n");
	fpw<<"m[i][j]��������:\n";
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
	
	
	printf("s[i][j]��������:\n");
	fpw<<"s[i][j]��������:\n";
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
