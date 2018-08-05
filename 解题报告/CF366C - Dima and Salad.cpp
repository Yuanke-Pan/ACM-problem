/*
	题意分析：
		每种水果有两种属性a[i],b[i]计算当a[i],b[i]满足sigma(a[i])/sigma(b[i]) = k 时 sigma(a[i])的最大值。
	解题思路：
		将上式移项转换后发现如果把背包问题重量用 a[i]-k*b[i]替换后问题就转化为求n个水果当重量为零的时候，sigma(a[i])的最大值。
		要注意的是这里的水果的重量会产生负值，所以要找一个偏移量。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f;
int dp[105][maxn*maxn * 10 * 4];
int N;
int a[maxn];
int b[maxn];
int c[maxn];
int main()
{
	int n, k;
	cin >> n >> k;
	N = 1000 * n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		c[i] = a[i] - k * b[i];
	}
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j <= maxn * maxn * 20; j++)
		{
			dp[i][j] = -INT_MAX;
		}
	}
	dp[0][N] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2 * N; j >= c[i]; j--)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + a[i]);
		}
	}
	if (dp[n][N] <= 0)
	{
		cout << -1;
	}
	else
	{
		cout << dp[n][N] << endl;
	}
	return 0;
}