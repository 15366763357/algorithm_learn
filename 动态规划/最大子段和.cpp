#include<bits/stdc++.h>
using namespace std;
int f(int a[],int n,int&l,int&r)
{
	int sum=0,b=0;
	for(int i=0;i<n;i++)
	{
		if(b<=0)
		{
			b=a[i];
			l=i+1;
		}//此种情况下更新左边界 
		else b+=a[i];
		if(b>sum)
		{
			sum=b;
			r=i+1;
		}
	}
	return sum;
}
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int l=0;int r=0;
	int ans=f(a,6,l,r);
	printf("%d~%d:%d\n",l,r,ans);
	return 0; 
 } 
