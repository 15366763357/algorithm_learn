#include<bits\stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void pailie(int list[], int k, int m)//kΪ�Ѿ��ᵽǰ���Ԫ�أ�mΪ�ܵ�Ԫ�ظ�����һ
{
	if (k == m) {
		for (int i = 0; i <= m; i++)
			printf("%d ", list[i]);
		printf("\n");
	}
	else {
		for (int i = k; i <= m; i++)
		{
			swap(list[i], list[k]);
			pailie(list, k + 1, m);
			swap(list[i], list[k]);
		}
	}
}
int main()
{
	int list[4] = { 1,2,3,4 };
	pailie(list, 0, 3);
	system("Pause");
	return 0;
}