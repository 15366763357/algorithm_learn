#include<bits\stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void pailie(int list[], int k, int m)//k为已经提到前面的元素，m为总的元素个数减一
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