/*
	这题很关键，这是我不借助任何资料独立完成的一道背包题，算是入门了
	题意分析：
		给你n个事件集，每个事件有花费的时间和另外一个点数，每个事件集有不同的种类
	每个种类有不同的选择方法（具体请见题目），问在给定时间内使另一个属性最大。
	解题思路：
		只用明白每种操作的状态转移方程就可以解题了，思路还是分组背包。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int cost[maxn];
int val[maxn];
int dp[2][maxn];
int n, T;
int atlestone(int a, int b)
{
	for (int j = 0; j <= T; j++) dp[b][j] = -0x3f3f3f3f;
	for (int i = 0; i < a; i++)
	{
		for (int j = T; j >= cost[i]; j--)
		{
			dp[b][j] = max(dp[b][j], max(dp[b ^ 1][j - cost[i]] + val[i], dp[b][j - cost[i]] + val[i]));
		}
	}
}
int nomoreone(int a, int b)
{
	for (int j = 0; j <= T; j++) dp[b][j] = dp[b ^ 1][j];
	for (int i = 0; i < a; i++)
	{
		for (int j = T; j >= cost[i]; j--)
		{
			dp[b][j] = max(dp[b][j], dp[b ^ 1][j - cost[i]] + val[i]);
		}
	}
}
int free(int a, int b)
{
	for (int j = 0; j <= T; j++) dp[b][j] = dp[b ^ 1][j];
	for (int i = 0; i < a; i++)
	{
		for (int j = T; j >= cost[i]; j--)
		{
			dp[b][j] = max(dp[b][j], max(dp[b ^ 1][j - cost[i]] + val[i], max(dp[b][j - cost[i]] + val[i], dp[b ^ 1][j])));
		}
	}
}
int main()
{
	while (scanf("%d%d", &n, &T) != EOF)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j <= T; j++)
			{
				if (i == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = -INT_MAX;
			}
		}
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			for (int j = 0; j < a; j++)
			{
				scanf("%d%d", cost + j, val + j);
			}
			if (b == 0)
			{
				atlestone(a, i % 2);
			}
			if (b == 1)
			{
				nomoreone(a, i % 2);
			}
			if (b == 2)
			{
				free(a, i % 2);
			}
		}
		if (dp[(n - 1) % 2][T]<0)
			cout << -1 << endl;
		else
			cout << dp[(n - 1) % 2][T] << endl;
	}
	return 0;
}
