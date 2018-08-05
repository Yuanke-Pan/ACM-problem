/*
	题意分析：
		给你存储罐的大小，和各种硬币的价值和大小，告知当装满这个存储罐的时候，其中的最小价值是多少。
	解题思路：
		这是一个完全背包问题的模板题。就是把模板中的max,,换成min就好了。

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct coin
{
	int val;
	int weight;
};
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int e, f;

	while (T--)
	{
		int n;
		coin a[505];
		cin >> e >> f;
		int vol = f - e;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int c, b;
			cin >> c >> b;
			if (b <= vol)
			{
				a[i].val = c;
				a[i].weight = b;
			}
		}
		int dp[maxn];
		for (int i = 0; i < maxn; i++)
		{
			dp[i] = 0x3f3f3f3f;
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = a[i].weight; j <= vol; j++)
			{
				dp[j] = min(dp[j], dp[j - a[i].weight] + a[i].val);
			}
		}
		if (dp[vol] == 0x3f3f3f3f)
		{
			cout << "This is impossible." << endl;
		}
		else
			cout << "The minimum amount of money in the piggy-bank is " << dp[vol] << '.' << endl;
	}

	return 0;
}
