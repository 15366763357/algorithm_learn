#include<bits/stdc++.h>
using namespace std;
void Swap(int &a,int&b)//必须是使用引用才能达到交换的效果
{
    int tmp=a;
    a=b;
    b=tmp;
}
int random(int p,int r)//返回[p,r]中的随机值
{
    srand((unsigned)time(NULL));
    return rand()%(r-p+1)+p;
}

int Partition(int a[],int p,int r)//对数组进行分组，大于a[p]的在左，小于的在右，并把a[p]的值放在中间位置，并返回中间位置下标
{
    int i=p,j=r+1;
    int x=a[p];
    while(1)
    {
        while(a[++i]<x&&i<r);
        while(a[--j]>x);
        if(i>=j)break;
        Swap(a[i],a[j]);
    }
    a[p]=a[j];
    a[j]=x;
    return j;
}
int randommizedPartition(int a[],int p,int r)//随机把数组中的数放在数组开头位置，达到在Partition()函数中实现随机划分
{
    int i=random(p,r);
    Swap(a[i],a[p]);
    return Partition(a,p,r);
}
void quick_sort(int a[],int p, int r)//分组后，找到中间位置，对其左右两边递归排序
{
    if(p<r)
    {
        int q=randommizedPartition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}
int main()
{
	int a[10] = {-1,-1,3,4,5,7,8,9,10,11};
	quick_sort(a,0,9);
	for(int i=0;i<10;i++)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}

