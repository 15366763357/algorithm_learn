#include<iostream>
using namespace std;
int b_s(int a[], int t, int l,int&i,int&j)
{
	int left = 0, right = l - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == t)
        {
            i=j=mid;
            return 1;
        }
		else if (a[mid]>t)right = mid - 1;
		else left = mid + 1;
	}
	i=right;//С��f�����ֵ�±� 
	j=left;//����f����Сֵ�±� 
	return 0;
}
int main()
{
	int a[100];
	cout<<"���������鳤�ȣ�"<<endl;
	int l;cin>>l; 
	cout<<"���������飺"<<endl;
	for(int i=0;i<l;i++)cin>>a[i];
	cout<<"������Ҫ���ҵ����֣�"<<endl;
	int t;cin>>t;
    int i=0,j=0;
	b_s(a, t, l,i,j);
	cout<<"i��j������£�"<<endl;
	cout << i<<' '<<j << endl;
	return 0;
}
