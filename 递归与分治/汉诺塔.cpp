#include<bits/stdc++.h>
using namespace std;
void han(int n, char a, char b, char c)//n为从1到n圆盘由上到下排列 
{//函数表明把从1到n个圆盘以c为中介从a移动到b 
	if (n>0)
	{
		han(n - 1, a, c, b);//1~n-1号圆盘先经过b从a移动到c 
		printf("%d:%c->%c\n", n, a, b); //移动 
		han(n - 1, c, b, a);// 1~n-1号圆盘先经过a从c移动到b
	}
}
int main()
{
	han(3, 'A', 'B', 'C');
	return 0;
}
