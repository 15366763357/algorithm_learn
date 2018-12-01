#include<bits/stdc++.h>
using namespace std;
int mns(int n,int c[],int size[][100])
{
	for(int i=1;i<c[1];i++)size[1][i]=0;
	for(int i=c[1];i<=n;i++)size[1][i]=1;
	for(int i=2;i<n;i++)//不等于n原因是只用计算size[n][n]不需要第n行的值
	{
		for(int j=1;j<c[i];j++)size[i][j]=size[i-1][j];
		for(int j=c[i];j<=n;j++)size[i][j]=max(size[i-1][j],size[i-1][c[i]-1]+1); 
	}
	size[n][n]=max(size[n-1][n],size[n-1][c[n]-1]+1);  
 } 
int output(int n,int size[][100],int ans[],int c[])
 {//每次i的值减一，看size[i][j]与size[i-1][j]是否相等，
 //不相等说明(i,c[i])在mns中，继续i-1，j的值变为c[i]-1,继续查找， 
 // 最终当i=1时，如果j>=c[1],则把1加入 
  
 	int j=n,m=0;
 	for(int i=n;i>1;i--)
 	{
 		if(size[i][j]!=size[i-1][j])
		 {
		 	ans[m++]=i;
		 	j=c[i]-1;
		 }
	 }
	 if(c[1]<=j)ans[m++]=1;
	 return m;
 }
 int main()
 {
 	int n;int c[100]={0};int size[100][100];int ans[100];
 	ifstream fpr;
 	fpr.open("test.txt",ios::in); 
 	fpr>>n;
 	for(int i=1;i<=n;i++)fpr>>c[i];
 	mns(n,c,size);
 	int len=output(n,size,ans,c);
 	for(int i=0;i<len;i++)cout<<ans[i]<<' ';
 	cout<<endl;
 	return 0;
 }
 /*
 10
8 7 4 2 5 1 9 3 10 6
*/ 
