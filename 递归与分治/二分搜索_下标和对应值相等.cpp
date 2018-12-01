
#include<iostream>
using namespace std;
int search_tag(int a[], int l)
{
	int left = 0, right = l - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == mid)return mid;
		else if (a[mid]>mid)right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
int main()
{
	int a[100];
	cout << "请输入数组长度：" << endl;
	int len; cin >> len;
	cout << "请输入该数组：" << endl;
	for (int i = 0; i < len; i++)cin >> a[i];
	cout << "结果如下：" << endl;
	int ans = search_tag(a, len);
	cout << ans << endl;
	system("Pause");
	return 0;
}
