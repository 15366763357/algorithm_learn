#include<iostream>
#include<algorithm>
using namespace std;
struct value_per_weight {
	int id;
	double v;
};
bool cmp(value_per_weight a, value_per_weight b)
{
	return a.v > b.v;
}

class Knap {
	int c;//��������
	int n;//��Ʒ��
	int w[100];//��Ʒ��������
	int p[100];//��Ʒ��ֵ����
	int cw;//��ǰ����
	int cp;//��ǰ��ֵ
	int bestp;//��ǰ���ż�ֵ

public:
	Knap(int cc, int nn, int ww[100], int pp[100]);
	int Bound(int i);
	void Backtrack(int i);
	void getbestp();
};
Knap::Knap(int cc, int nn, int ww[100], int pp[100])
{
	c = cc;
	n = nn;
	for (int i = 0; i<n; i++)
	{
		w[i] = ww[i];
		p[i] = pp[i];
	}
	cw = 0;
	cp = 0;
	bestp = 0;
}
void Knap::getbestp()
{
	cout << bestp << endl;
}
void Knap::Backtrack(int i)
{
	if (i>=n)
	{
		if (cp>bestp)
		{
			bestp = cp;
			return;
		}
	}
	if (cw + w[i] <= c)
	{
		cp += p[i];
		cw += w[i];
		Backtrack(i + 1);
		cw -= w[i];
		cp -= p[i];
	}
	if (Bound(i + 1)>bestp)
	{
		Backtrack(i + 1);
	}
}
int Knap::Bound(int i)
{
	int cleft = c - cw;
	int b = cp;
	while (i < n&&w[i] <= cleft)
	{
		cleft -= w[i];
		b += p[i];
		i++;
	}
	if (i < n)
	{
		b += p[i] * cleft / w[i];
	}
	return b;
}
int main()
{
	int n, c;
	int p[100] ;
	int w[100] ;
	int np[100] = { 0 };
	int nw[100] = {0};
	cout << "�밴˳��������Ʒ�����ͱ�������" << endl;
	cin>>n>>c;
	cout << "���������������Ʒ�ļ�ֵ" << endl;
	for(int i=0;i<n;i++)cin>>p[i];
	cout << "�������Ӧ��ֵ˳��ı���������" << endl;
	for(int i=0;i<n;i++)cin>>w[i];
	value_per_weight oa[100];
	for (int i = 0; i<n; i++)
	{
		oa[i].id = i;
		oa[i].v = 1.0*p[i] / w[i];
	}
	sort(oa, oa + n, cmp);
	for (int i = 0; i<n; i++)
	{
		np[i] = p[oa[i].id];
		nw[i] = w[oa[i].id];
	}
	Knap A(c, n, nw, np);
	A.Backtrack(0);
	A.getbestp();
	system("Pause");
	return 0;
}
