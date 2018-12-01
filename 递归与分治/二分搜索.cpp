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
	i=right;//小于f的最大值下标 
	j=left;//大于f的最小值下标 
	return 0;
}
int main()
{
	int a[100];
	cout<<"请输入数组长度："<<endl;
	int l;cin>>l; 
	cout<<"请输入数组："<<endl;
	for(int i=0;i<l;i++)cin>>a[i];
	cout<<"请输入要查找的数字："<<endl;
	int t;cin>>t;
    int i=0,j=0;
	b_s(a, t, l,i,j);
	cout<<"i和j结果如下："<<endl;
	cout << i<<' '<<j << endl;
	return 0;
}
