#include<bits/stdc++.h>
using namespace std;
void han(int n, char a, char b, char c)//nΪ��1��nԲ�����ϵ������� 
{//���������Ѵ�1��n��Բ����cΪ�н��a�ƶ���b 
	if (n>0)
	{
		han(n - 1, a, c, b);//1~n-1��Բ���Ⱦ���b��a�ƶ���c 
		printf("%d:%c->%c\n", n, a, b); //�ƶ� 
		han(n - 1, c, b, a);// 1~n-1��Բ���Ⱦ���a��c�ƶ���b
	}
}
int main()
{
	han(3, 'A', 'B', 'C');
	return 0;
}
