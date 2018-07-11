#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;

string inp[maxn];
int dp[maxn][maxn];
int equals[maxn][maxn];
int n;

int main()
{
	cin >> n;
	int allsum = n - 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
		allsum += inp[i].length();
	}
	for (int i = 1; i <= n; i++)
	{
		equals[i][i] = true;
		for (int j = 1; j<i; j++)
			equals[i][j] = equals[j][i] = inp[i] == inp[j];
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = n; j >= 1; j--)
			if (equals[i][j])
			{
				if (i + 1 <= n && j + 1 <= n)
					dp[i][j] = dp[i + 1][j + 1] + 1;
				else dp[i][j] = 1;
			}
	}
	int ans = allsum;
	// Then iterate over all starting positions of the possible abbreviation and all its possible lengths. 
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 0; i + j <= n; j++)//j表示的是j的长度
		{
			sum += inp[i + j].length();
			int cnt = 1;
			for (int pos = i + j+1; pos <= n; pos++) //从他本身的下一个位置开始找
			{
				if (dp[i][pos]>j)
				{
					cnt++;
					pos += j;
				}
			}
			int cur = allsum - sum * cnt + (j + 1)*cnt - j * cnt;
			if (cnt>1 && ans>cur)
				ans = cur;
		}
	}
	cout << ans << endl;
	return 0;
}