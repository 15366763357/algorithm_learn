#include<bits/stdc++.h>
using namespace std;
int length(int x)//xΪ4ʱ���Ϊ3����0��������� 
{
	int i = 1;x/=2; 
	while (x)
	{
		x /= 2;
		i++;
	}
	return i;
}
void output(int a[],int l[],int n)
{
	if(n>0)
	{
		int t=l[n];
		output(a,l,n-t);
		for(int i=n-t+1;i<=n;i++)cout<<a[i]<<' ';
		cout<<endl;
	}
}
void compress(int a[], int n, int bb[], int b[], int l[], int s[])
{/*b����洢s[i]���һ�����ֵĴ洢λ��
l����洢s[i]���һ�����ֵĳ���
bb����洢��Ӧ�Ĵ洢λ��
bmaxΪ���һ��������Ԫ�����洢λ��
s���������յĽ��*/ 
	int bmax;
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		bb[i] = length(a[i]);
		bmax = bb[i];
		s[i] = s[i - 1] + bmax;
		l[i] = 1;
		b[i] = bmax;//�ȴ����ֻ��һ��Ԫ��Ϊһ�����ֿ�ʼ���г�ʼ���� 
		for (int j = 2; j <= i&&j <= 256; j++)//���j��Ԫ��Ϊһ��   ���ֳ������Ϊ256 
		{
			if (bb[i - j + 1]>bmax)bmax = bb[i - j + 1];
			if (s[i]>s[i - j] + j*bmax)
			{
				s[i] = s[i - j] + j*bmax;
				l[i] = j;
				b[i] = bmax;
			}
		}
		s[i] += 11;
	}
}
int main()
{
	int a[100]={0};
	int bb[100] = { 0 }, b[100] = { 0 }, l[100] = {0}, s[100] = { 0 }, n;
	ifstream fpr;
	fpr.open("test.txt",ios::in);
	fpr>>n;
	for(int i=1;i<=n;i++)fpr>>a[i];
	/*int a[8] = { 0,4,6,5,7,129,138,1 };
	int bb[8] = { 0 }, b[8] = { 0 }, l[8] = {0}, s[8] = { 0 }, n = 7;*/
	compress(a, n, bb, b, l, s);
	printf("s[i]�������£�\n"); 
	for (int i = 1; i <= n; i++)cout << s[i] << ' ';
	printf("\nl[i]�������£�\n");
	for (int i = 1; i <= n; i++)cout << l[i] << ' ';
	printf("\nb[i]�������£�\n");
	for (int i = 1; i <= n; i++)cout << b[i] << ' ';
	cout<<endl<<"���ֽ������:"<<endl; 
	output(a,l,n);
	system("Pause");
	return 0;
}
