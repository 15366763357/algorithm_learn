#include<bits/stdc++.h>
using namespace std;
int b[100] = { 0 };
void merge(int a[], int left, int right, int t)
{//小在前，t为中点位置，从k=left进行赋值，最终数组a,b均保留最终结果
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
	for (int i = left; i <= right; i++)a[i] = b[i];//相应下标进行赋值
}
void mergesort(int a[], int left, int right)
{
	if (left<right)//至少有两个元素
	{
		int i = (left + right)/2;//取中点
		mergesort(a, left, i);
		mergesort(a, i + 1, right);
		merge(a, left, right, i);//根据数组a内部数据大小合并到相应下标数组b
		copy(a,left,right);//复制回数组a，后续合并时使用最新的数组a数据排列
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