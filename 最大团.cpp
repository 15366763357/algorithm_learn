#include<bits/stdc++.h>
using namespace std;
int n = 5;//������
int a[100][100];//�ڽӾ���
int x[100];//��ǰ��
int bestx[100];//��ǰ���Ž�
int cn;//��ǰ������
int bestn;//��ǰ��󶥵���
void Backtrack(int i)
{
	if (i > n) {
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = x[j];
			//cout << bestx[j]<<' ';
		}
		bestn = cn;
		//cout << endl;
		return;

	}
	int OK = 1;
	for (int j = 1; j < i; j++)
	{
		if (x[j] && a[i][j] == 0)
		{
			OK = 0;
			break;
		}
	}
	if (OK)
	{
		x[i] = 1;
		cn++;
		Backtrack(i + 1);
		x[i] = 0;
		cn--;
	}
	if (cn + n - i >= bestn)
	{
		x[i] = 0;
		Backtrack(i + 1);
	}

}
int main()
{
	cout << "������ͼ���ڽӾ���" << endl;
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=n; j++)cin >> a[i][j];
	cn = 0;
	bestn = 0;
	bestx[100] = { 0 };
	Backtrack(1);
	cout << "������нڵ�������£�" << bestn<<endl;
	//cout << bestn << endl;
	cout << "����һ������Ҫ�������Žڵ�����������(0����û�иýڵ�,1�����иýڵ�):" << endl;
	for (int j = 1; j <= n; j++)
	{
		//bestx[j] = x[j];
		cout << bestx[j]<<' ';
	}
	cout << endl;
	system("Pause");
	return 0;
}