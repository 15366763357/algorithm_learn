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
		print(a,len+1); //����һ���������Ҫ��� 
		return 1;
	}
	else if(m==1)
	{
		a[len]=1;
		integer_partition(a,len+1,n-1,m);//ֻ�ǵó�һ������еĲ���ֵ��len+1���鳤�����ӣ���ʱn��ֵ��һ��������m=1���еݹ���� 
		return 1;
	}
	if (m > n)return integer_partition(a,len,n, n);
	if (m == n)
	{
		a[len]=m;
		print(a,len+1);//������һ���������Ҫ��� 
		return integer_partition(a,len,n, m - 1) + 1;
	}
	if (m < n)
	{
		a[len]=m;//һ������еĵ�һ��ֵ 
		return (integer_partition(a,len+1,n-m, m) + integer_partition(a,len,n, m - 1));//��һ���ݹ�����������ļ��������Ҫlen+1,�ڶ����ݹ���һ���µ���� 
		
	}
}
int main()
{
	int a[100] = {0};
	int ans = integer_partition(a,0,6,6);
	printf("����%d�ֻ���\n", ans);
	system("Pause");
	return 0;
}
