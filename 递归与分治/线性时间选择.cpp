#include<bits/stdc++.h>
using namespace std;
void Swap(int &a,int&b)//必须是使用引用才能达到交换的效果
{
    int tmp=a;
    a=b;
    b=tmp;
}
int random(int p,int r)//返回[p,r)中的随机值
{
    srand((unsigned)time(NULL));
    return rand()%(r-p)+p;
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
int random_mized_select(int a[],int p, int r,int k)//分组后，找到中间位置，对其左右两边递归排序
{
    if(p==r)return a[p];
    int i=randommizedPartition(a,p,r);
    int j=i-p+1;
    if(k<=j)return random_mized_select(a,p,i,k);
    else return random_mized_select(a,i+1,r,k-j);
}
int main()
{
	int a[101];
	for(int i=1;i<=101;i++)a[i-1]=i;
	int k;
	cout<<"本例中已输入从1开始到101结束101个整数"<<endl;
	printf("请依次输入k=1、k=n和k=中位数进行验证\n"); 
	while(1)
    {
        cin>>k;
        int ans=random_mized_select(a,0,100,k);
        cout<<ans<<endl;
    }
	return 0;
}
