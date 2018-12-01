#include<bits/stdc++.h>
using namespace std;
void lcs_length(int m,int n,char x[10],char y[10],int c[][10],int b[][10])
{
	for(int i=0;i<=n;i++)
	{
		c[0][i]=0;
		b[0][i]=0;
	}
	for(int j=0;j<=m;j++)
	{
		c[j][0]=0;
		b[j][0]=0;
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(x[i]==y[j])
		{
			c[i][j]=c[i-1][j-1]+1;
			b[i][j]=1;
		}
		else if(c[i-1][j]>=c[i][j-1])
		{
			c[i][j]=c[i-1][j];
			b[i][j]=2;
		}
		else{
			c[i][j]=c[i][j-1];
			b[i][j]=3;
		}
	}
}
void lcs(int m,int n,int b[][10],char x[10])
{
	if(m==0||n==0)return;	
	if(b[m][n]==1)
	{
		lcs(m-1,n-1,b,x);
		cout<<x[m]<<' ';
	}
	if(b[m][n]==2)lcs(m-1,n,b,x);
	if(b[m][n]==3)lcs(m,n-1,b,x);
}
int main()
{
	ifstream fpr;
	int c[10][10];
	int b[10][10];
	char x[10],y[10];
	x[0]='#';y[0]='#';
	fpr.open("test.txt",ios::in);
	int m,n;
	fpr>>m>>n;
	for(int i=1;i<=m;i++)fpr>>x[i];
	for(int i=1;i<=n;i++)fpr>>y[i];
	lcs_length(m,n,x,y,c,b);
	cout<<"c[i][j]数组如下："<<endl; 
	for(int i=0;i<=m;i++)
	for(int j=0;j<=n;j++)
	cout<<c[i][j]<<(j==n?'\n':' ');
	cout<<endl;
	cout<<"b[i][j]数组如下："<<endl; 
	for(int i=0;i<=m;i++)
	for(int j=0;j<=n;j++) 
	cout<<b[i][j]<<(j==n?'\n':' ');
	cout<<endl;
	cout<<"最长公共子序列如下："<<endl;
	cout<<c[m][n]<<' ';
	lcs(m,n,b,x);
	return 0;
 } 
