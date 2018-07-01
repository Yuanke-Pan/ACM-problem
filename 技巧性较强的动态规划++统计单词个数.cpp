#include<bits/stdc++.h>
using namespace std;
string s = "", inp[7];
int sum[210][210] = { 0 };
int dp[210][50] = { 0 };
int p, k, n;
bool find(int l, int r)
{
	string x = s.substr(l, r - l + 1);
	for (int i = 1; i <= n; i++)
	{
		if (x.find(inp[i]) == 0) return true;
	}
	return false;
}
int main()
{
	cin >> p >> k;
	s += '0';
	for (int i = 0; i < p; i++)
	{
		string a;
		cin >> a;
		s += a;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
	}
	for (int i = s.length() - 1; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			sum[j][i] = sum[j + 1][i];
			if (find(j, i))
				sum[j][i]++;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++) dp[i][i] = dp[i - 1][i - 1] + sum[i - 1][i - 1];
	for (int i = 1; i < s.length(); i++)
	{
		dp[i][1] = sum[1][i];
	}
	for (int i = 1; i < s.length(); i++)
	{
		for (int K = 1; K <= k && K < i; K++)
			for (int j = K; j < i; j++)//Attention,这里的j要从K开始取因为把j个字符分成k份当j<k时这件事是没有定义的所以要避开这个事件，如果不加约束的话会出问题
			{
				dp[i][K] = max(dp[i][K], dp[j][K - 1] + sum[j + 1][i]);
			}
	}
	cout << dp[s.length() - 1][k];
	return 0;
}