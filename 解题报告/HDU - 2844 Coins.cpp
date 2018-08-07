/*
	题意分析：
		有一个人想买一个手表，只知道这个手表的售价不超过m，已知每一个硬币的价格，和数量，问能组合出多少种价格不超过m.
	解题思路：
		完全背包问题：
			将物品的数量转化成二进制，在用0-1背包问题来解决问题，如果dp[i]有问询则这个价格就可以组合。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int maxd = 1e6 + 5;

int a[maxn];
int c[maxn];
int dp[maxd];
int main()
{
	int n, m;
	while (1)
	{
		bool vis[maxd] = { 0 };
		for (int i = 0; i < maxd; i++)
		{
			dp[i] = -INT_MAX;
		}
		dp[0] = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int num = min(c[i], m / a[i]);
			for (int k = 1; num > 0; k *= 2)
			{
				if (k>num) k = num;
				num -= k;
				for (int j = m; j >= k * a[i]; j--)
				{
					dp[j] = max(dp[j], dp[j - k * a[i]] + k * a[i]);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			if (dp[i]>0) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
