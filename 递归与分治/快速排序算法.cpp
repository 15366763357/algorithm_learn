#include<bits/stdc++.h>
using namespace std;
void Swap(int &a,int&b)//������ʹ�����ò��ܴﵽ������Ч��
{
    int tmp=a;
    a=b;
    b=tmp;
}
int random(int p,int r)//����[p,r]�е����ֵ
{
    srand((unsigned)time(NULL));
    return rand()%(r-p+1)+p;
}

int Partition(int a[],int p,int r)//��������з��飬����a[p]������С�ڵ����ң�����a[p]��ֵ�����м�λ�ã��������м�λ���±�
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
int randommizedPartition(int a[],int p,int r)//����������е����������鿪ͷλ�ã��ﵽ��Partition()������ʵ���������
{
    int i=random(p,r);
    Swap(a[i],a[p]);
    return Partition(a,p,r);
}
void quick_sort(int a[],int p, int r)//������ҵ��м�λ�ã������������ߵݹ�����
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

