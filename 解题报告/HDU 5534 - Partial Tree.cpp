/*
	题意分析：
		给n个节点，告诉你树上节点不同度数时的一个数值，求怎么构造这个树能使这个数值最大。
	解题思路：
		树的性质和完全背包问题，这题告诉了你树的节点数为n，则就有n-1个边,共有2*(n-1)个度数，问题
	就转化为给n个节点分配2*(n-1)个度。
		这题有个小陷阱就是各节点的度必须是大于等于一的，所以对要默认所有树的度先都为一，所以问题又
	变成给n个节点分配n-2个度。
		同时输入要变化，变成相对于度数为1的节点数值的变化。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2018;
int a[maxn];
int dp[maxn * 3];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 2018 * 3; i++)
		{
			dp[i] = -0x3f3f3f3f;
		}
		dp[0] = 0;
		int n;
		cin >> n;
		for (int i = 1; i < n; i++)
		{
			cin >> a[i];
			if (i != 1)
			{
				a[i] -= a[1];
			}
		}
		int s = a[1] * n;
		for (int i = 2; i < n; i++)//这里度数为一已经在s中了。
		{
			for (int j = i - 1; j <= n - 2; j++)
			{
				dp[j] = max(dp[j], dp[j + 1 - i] + a[i]);
			}
		}
		cout << s + dp[n - 2] << endl;
	}
	return 0;
}
