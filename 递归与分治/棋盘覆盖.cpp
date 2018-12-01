#include<bits/stdc++.h>
using namespace std;
int tile = 0;//表示L型骨牌的编号，其初始值为0；
int board[100][100];//表示棋盘的数组，初始化为-1
void chess(int tr, int tc, int dr, int dc, int size)
{//tr:棋盘左上角行数，tc:棋盘左上角列数，dr:特殊方格所在的行号，dc:特殊方格所在的列号，size:size=2^k,棋盘规格为2^k*2^k
	if (size == 1)return;
	int t = tile++;
	int s = size / 2;
	if (dr<tr + s&&dc<tc + s)chess(tr, tc, dr, dc, s);
	else {
		board[tr + s - 1][tc + s - 1] = t;
		chess(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr<tr + s&&dc >= tc + s)chess(tr, tc + s, dr, dc, s);
	else {
		board[tr + s - 1][tc + s] = t;
		chess(tr, tc + s, tr + s - 1, tc + s, s);
	}
	if (dr >= tr + s&&dc<tc + s)chess(tr + s, tc, dr, dc, s);
	else {
		board[tr + s][tc + s - 1] = t;
		chess(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s&&dc >= tc + s)chess(tr + s, tc + s, dr, dc, s);
	else {
		board[tr + s][tc + s] = t;
		chess(tr + s, tc + s, tr + s, tc + s, s);
	}
}
int main()
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)board[i][j] = -1;
	chess(0, 0, 0, 1, 4);
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			cout << board[i][j] << (j == 3 ? '\n' : ' ');
	system("Pause");
	return 0;
}