#include<bits/stdc++.h>
using namespace std;
int b[100] = { 0 };
void merge(int a[], int left, int right, int t)
{//С��ǰ��tΪ�е�λ�ã���k=left���и�ֵ����������a,b���������ս��
	int i = left; int j = t+ 1; int k = left;
	while (i <= t&&j <= right)
	{
		if (a[i]>a[j])b[k++] = a[j++];
		else b[k++] = a[i++];
	}
	if (i >t)while (j <= right)b[k++] = a[j++];
	else while (i <= t)b[k++] = a[i++];
}
void copy(int a[],int left,int right)
{
	for (int i = left; i <= right; i++)a[i] = b[i];//��Ӧ�±���и�ֵ
}
void mergesort(int a[], int left, int right)
{
	if (left<right)//����������Ԫ��
	{
		int i = (left + right)/2;//ȡ�е�
		mergesort(a, left, i);
		mergesort(a, i + 1, right);
		merge(a, left, right, i);//��������a�ڲ����ݴ�С�ϲ�����Ӧ�±�����b
		copy(a,left,right);//���ƻ�����a�������ϲ�ʱʹ�����µ�����a��������
	}
}

int main()
{
	int a[8] = { 9,4,5,2,1,7,4,6 };
		mergesort(a, 0, 7);
	for (int i = 0; i<8; i++)cout << a[i] << ' ';
	system("Pause");
	return 0;
}