#include<bits/stdc++.h> 
#pragma warning(disable : 4996)
using namespace std;
#define M 202
struct tr {
	int data;
	int lc, rc, pa;
};//哈夫曼树结构 
struct trc {
	int w;//每个字符的权重 
	char code[M];//存放对应字符的编码 
};
void select(tr hafftree[], int k, int*s1, int*s2)
{
	int i, t;
	for (i = 1; i <= k; i++)if (hafftree[i].pa == 0)break;//顺序找到一个未添加进树的结点
	*s1 = i;
	for (i = 1; i <= k; i++)
		if (hafftree[i].pa == 0 && hafftree[*s1].data>hafftree[i].data)*s1 = i;//找到未添加进树节点中最小的结点
	for (i = 1; i <= k; i++)if (hafftree[i].pa == 0 && i != *s1)break;
	*s2 = i;
	for (i = 1; i <= k; i++)
		if (hafftree[i].pa == 0 && i != *s1&&hafftree[*s2].data>hafftree[i].data)*s2 = i;//找到第二小结点
}
void Haffmancoding(int n, tr hafftree[], trc hc[])
{
	int m = 2 * n - 1, s1, s2, c, f, star; char cd[M];
	//n个叶子结点共有2n-1个结点,s1,s2为第1,2小权重值
	for (int i = 1; i <= m; i++)
	{
		if (i <= n)hafftree[i].data = hc[i].w;//n个叶子结点权重
		else hafftree[i].data = 0;
		hafftree[i].pa = 0; hafftree[i].lc = 0; hafftree[i].rc = 0;//所有结点初始化,0代表空
	}
	for (int i = n + 1; i <= m; i++)//构造剩余非叶子结点
	{
		select(hafftree, i - 1, &s1, &s2);
		hafftree[s1].pa = hafftree[s2].pa = i;
		hafftree[i].lc = s1;
		hafftree[i].rc = s2;
		hafftree[i].data = hafftree[s1].data + hafftree[s2].data;
	}
	cd[n - 1] = '\0';//编码最多有n位
	for (int i = 1; i <= n; i++)//自底向上对n个叶子节点进行编码
	{
		star = n - 1;//cd[n-2]为编码的最后一位
		for (c = i, f = hafftree[i].pa; f!=0; c = f, f = hafftree[f].pa)//c为当前结点, f为父节点
		{
			if (hafftree[f].lc == c)cd[--star] = '0';
			else cd[--star] = '1';
		}
		strcpy(hc[i].code, &cd[star]);
		cout << hc[i].code << endl;
	}
}
int main()
{
	int n;
	printf("请输入需要编码的字符个数:\n");
	cin >> n;
	trc hc[M];
	tr hafftree[M];
	printf("请输入需要编码字符的权重:\n");
	for (int i = 1; i <= n; i++)cin >> hc[i].w;
	printf("哈夫曼编码如下:\n");
	Haffmancoding(n, hafftree, hc);
	system("Pause");
	return 0;
}
