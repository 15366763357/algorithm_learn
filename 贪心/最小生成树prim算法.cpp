#include<bits/stdc++.h>
# define M 99999
using namespace std;
void prim(int n,int c[][100])
{
	bool s[100]={0};int lowcost[100],closest[100];//s[i]=1������s������
	s[1]=1;
	for(int i=2;i<=n;i++)
	{
		lowcost[i]=c[1][i];
		closest[i]=1;
	}
	for(int i=1;i<n;i++)//����n-1��ѭ�� ��ֱ�����н�����
	{
		int min=M,u=1;
		for(int j=2;j<=n;j++)//�ҵ���ǰ��Сlowcost[],����¼�±�,lowcost[j]��ʾ����ڵ�ǰs�����У��ⲿ���j��s���ϵ���̾��� 
		if(!s[j]&&lowcost[j]<min)
		{
			min=lowcost[j];
			u=j;
		}
		s[u]=1;//���ҵ�����С�ļ���
		cout<<u<<closest[u]<<endl;
		for(int j=2;j<=n;j++)//�жϼ���u�Ƿ�Ӱ��lowcost[]�ı仯������lowcost[]����
			if(!s[j]&&c[u][j]<lowcost[j])
			{
				lowcost[j]=c[u][j];
				closest[j]=u;//closest[j]��¼��������j��s�������ӵĽ�� 
			}
	}
 } 
 int main()
{
	int n, c[100][100];
	printf("�����������:\n");
	cin >> n;
	printf("������%d*%d�ڽӾ���:\n",n,n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if(c[i][j]<0)c[i][j]=M;
		}	
	printf("���μ���ߵ��������:\n");
	prim(n, c);
	system("Pause");
	return 0;
}
