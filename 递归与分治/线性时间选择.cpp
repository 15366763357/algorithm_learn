#include<bits/stdc++.h>
using namespace std;
void Swap(int &a,int&b)//������ʹ�����ò��ܴﵽ������Ч��
{
    int tmp=a;
    a=b;
    b=tmp;
}
int random(int p,int r)//����[p,r)�е����ֵ
{
    srand((unsigned)time(NULL));
    return rand()%(r-p)+p;
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
int random_mized_select(int a[],int p, int r,int k)//������ҵ��м�λ�ã������������ߵݹ�����
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
	cout<<"�������������1��ʼ��101����101������"<<endl;
	printf("����������k=1��k=n��k=��λ��������֤\n"); 
	while(1)
    {
        cin>>k;
        int ans=random_mized_select(a,0,100,k);
        cout<<ans<<endl;
    }
	return 0;
}
