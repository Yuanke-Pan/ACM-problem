/*
	题意分析：
		在这题中Tom向要逃课，并且让他在学校的时间最小，他能逃k节课，他在学校的时间为他的第一节课到最后一节
	课的时间间隔，他总共要上n天的课，求他在n天内上课的最短时间为多少。
	解题思路：
		先对上课时间进行预处理，处理出每天上课翘i节课要上的最小时间，最后就是一个分组背包问题了。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
int cla[maxn];
int mt[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '1')
			{
				cla[++num] = j;
			}
		}
		for (int j = 0; j < num; j++)//这里不能是k因为有可能一天没有k节课；
		{
			mt[i][j] = cla[num] - cla[1] + 1;
			for (int l = 0; l <= j; l++)
			{
				mt[i][j] = min(mt[i][j], cla[num - j + l] - cla[l + 1] + 1);
			}
		}
		mt[i][num] = 0;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + mt[i][l]);
			}
		}
	}
	cout << dp[n][k];
	return 0;
}