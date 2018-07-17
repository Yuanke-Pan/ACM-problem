#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 7;

int nexts[maxn];
int dp[maxn];

void getnext(string &a)
{
	int plen = a.length();
	int k = -1;
	int j = 0;
	nexts[0] = -1;
	while (j<plen - 1)
	{
		if (k == 1 || a[k] == a[j])
		{
			k++, j++;
			nexts[j] = k;
		}
		else k = nexts[k];
	}
}
int main()
{
	int n;
	string ba;
	cin >> n;
	cin >> ba;
	getnext(ba);
	int i, u, ans = 0;
	for (int i = n; i >= 1; i--)
	{
		u = i;
		dp[u - 1] += 1;
		if (nexts[u] != 0) dp[nexts[u] - 1] = (dp[nexts[u] - 1] + dp[u - 1]) % 10007;
	}
	for (int i = 0; i<n; i++)
	{
		ans += dp[i];
		ans %= 10007;
	}
	cout << ans - 1 << endl;
	return 0;
}

