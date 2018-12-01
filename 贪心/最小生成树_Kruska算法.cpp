#include<bits/stdc++.h>
# define M 200
using namespace std;
struct gra {
	int x, y;
	double cost;
};
bool cmp(gra&a, gra&b)
{
	return a.cost<b.cost;
}
int find(int x,int r[])
{
	if (x != r[x])find(r[x],r);
	return r[x];
}
int Kruskal(int n, int m, gra a[M])
{
	int res = 0; int r[M];
	for (int i = 0; i<M; i++)r[i] = i;
	sort(a, a + m, cmp);
	int k = 0, i = 0;
	while (k<n - 1 && i<m)
	{
		int rx = find(a[i].x,r);
		int ry = find(a[i].y,r);
		if (rx != ry)
		{
			k++;
			r[rx] = ry;
			res += a[i].cost;
		}
		i++;
	}
	return res;
}
int main()
{
	gra a[M];
	int n, m; cin >> n >> m;
	for (int i = 0; i<m; i++)cin >> a[i].x >> a[i].y >> a[i].cost;
	int ans = Kruskal(n, m, a);
	cout << ans << endl;
	system("Pause");
	return 0;
}
/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
3 4 5
2 5 3
5 6 6
6 4 2
3 5 6
3 6 4*/
