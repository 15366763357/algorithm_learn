#include<bits\stdc++.h>
using namespace std;
void print(int a[],int len)
{
	for(int i=0;i<len;i++)
	cout<<a[i]<<' ';
	cout<<endl;
 } 
int integer_partition(int a[],int len,int n, int m)
{
	if (n == 1) 
	{
		a[len]=1;
		print(a,len+1); //满足一种情况，需要输出 
		return 1;
	}
	else if(m==1)
	{
		a[len]=1;
		integer_partition(a,len+1,n-1,m);//只是得出一种情况中的部分值，len+1数组长度增加，此时n的值减一，继续以m=1进行递归求解 
		return 1;
	}
	if (m > n)return integer_partition(a,len,n, n);
	if (m == n)
	{
		a[len]=m;
		print(a,len+1);//自身是一种情况，需要输出 
		return integer_partition(a,len,n, m - 1) + 1;
	}
	if (m < n)
	{
		a[len]=m;//一种情况中的第一个值 
		return (integer_partition(a,len+1,n-m, m) + integer_partition(a,len,n, m - 1));//第一个递归是这种情况的继续求解需要len+1,第二个递归是一种新的情况 
		
	}
}
int main()
{
	int a[100] = {0};
	int ans = integer_partition(a,0,6,6);
	printf("共有%d种划分\n", ans);
	system("Pause");
	return 0;
}
