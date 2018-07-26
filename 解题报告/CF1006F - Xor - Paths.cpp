/*
	题意分析：
		跟取数类似，把每次取数的过程替换成数与数之间做异或，最后走到终点时异或的数为k，则ans++,否则不计数；
	解题思路：
		初步的思路就是深搜，但是深搜太慢了，算法复杂度为O(2^(n+m-2)),所以就想着根据已有的信息对过程进行优化，
		有两个性质我们可以利用：
			1、异或满足交换律
			2、每一次取数都要经过中间（主对角线）
		先从左算到中间，再从右算到中间，得出结果，具体看代码。
		这种思想被叫做Meet-in-Middle;
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 20 + 5;
long long k;
int n, m;
long long inp[maxn][maxn];
long long ans;
int mid;
map<long long, int> N[maxn][maxn]; // map的灵活应用用来计数很方便
void calleft(int x, int y, long long val, int cnt)
{
	val ^= inp[x][y];
	if (mid == cnt)
	{
		N[x][y][val]++;
		return;
	}
	if (x + 1 <= n)
		calleft(x + 1, y, val, cnt + 1);
	if (y + 1 <= m)
		calleft(x, y + 1, val, cnt + 1);
	return;
}

void calright(int x, int y, long long val, int cnt)
{
	if (cnt == n + m - 2 - mid)
	{
		if (N[x][y].count(k ^ val))
		{
			ans += N[x][y][k ^ val];
		}
		return;
	}
	if (x - 1 >= 1)
		calright(x - 1, y, val^inp[x][y], cnt + 1);
	if (y - 1 >= 1)
		calright(x, y - 1, val^inp[x][y], cnt + 1);
	return;
}
int main()
{
	cin >> n >> m >> k;
	mid = (n + m - 2) / 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> inp[i][j];
	calleft(1, 1, 0, 0);
	calright(n, m, 0, 0);
	cout << ans;
	return 0;
}