
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
	cout << "���������鳤�ȣ�" << endl;
	int len; cin >> len;
	cout << "����������飺" << endl;
	for (int i = 0; i < len; i++)cin >> a[i];
	cout << "������£�" << endl;
	int ans = search_tag(a, len);
	cout << ans << endl;
	system("Pause");
	return 0;
}
