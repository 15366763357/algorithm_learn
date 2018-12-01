#include<bits/stdc++.h> 
#pragma warning(disable : 4996)
using namespace std;
#define M 202
struct tr {
	int data;
	int lc, rc, pa;
};//���������ṹ 
struct trc {
	int w;//ÿ���ַ���Ȩ�� 
	char code[M];//��Ŷ�Ӧ�ַ��ı��� 
};
void select(tr hafftree[], int k, int*s1, int*s2)
{
	int i, t;
	for (i = 1; i <= k; i++)if (hafftree[i].pa == 0)break;//˳���ҵ�һ��δ��ӽ����Ľ��
	*s1 = i;
	for (i = 1; i <= k; i++)
		if (hafftree[i].pa == 0 && hafftree[*s1].data>hafftree[i].data)*s1 = i;//�ҵ�δ��ӽ����ڵ�����С�Ľ��
	for (i = 1; i <= k; i++)if (hafftree[i].pa == 0 && i != *s1)break;
	*s2 = i;
	for (i = 1; i <= k; i++)
		if (hafftree[i].pa == 0 && i != *s1&&hafftree[*s2].data>hafftree[i].data)*s2 = i;//�ҵ��ڶ�С���
}
void Haffmancoding(int n, tr hafftree[], trc hc[])
{
	int m = 2 * n - 1, s1, s2, c, f, star; char cd[M];
	//n��Ҷ�ӽ�㹲��2n-1�����,s1,s2Ϊ��1,2СȨ��ֵ
	for (int i = 1; i <= m; i++)
	{
		if (i <= n)hafftree[i].data = hc[i].w;//n��Ҷ�ӽ��Ȩ��
		else hafftree[i].data = 0;
		hafftree[i].pa = 0; hafftree[i].lc = 0; hafftree[i].rc = 0;//���н���ʼ��,0�����
	}
	for (int i = n + 1; i <= m; i++)//����ʣ���Ҷ�ӽ��
	{
		select(hafftree, i - 1, &s1, &s2);
		hafftree[s1].pa = hafftree[s2].pa = i;
		hafftree[i].lc = s1;
		hafftree[i].rc = s2;
		hafftree[i].data = hafftree[s1].data + hafftree[s2].data;
	}
	cd[n - 1] = '\0';//���������nλ
	for (int i = 1; i <= n; i++)//�Ե����϶�n��Ҷ�ӽڵ���б���
	{
		star = n - 1;//cd[n-2]Ϊ��������һλ
		for (c = i, f = hafftree[i].pa; f!=0; c = f, f = hafftree[f].pa)//cΪ��ǰ���, fΪ���ڵ�
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
	printf("��������Ҫ������ַ�����:\n");
	cin >> n;
	trc hc[M];
	tr hafftree[M];
	printf("��������Ҫ�����ַ���Ȩ��:\n");
	for (int i = 1; i <= n; i++)cin >> hc[i].w;
	printf("��������������:\n");
	Haffmancoding(n, hafftree, hc);
	system("Pause");
	return 0;
}
