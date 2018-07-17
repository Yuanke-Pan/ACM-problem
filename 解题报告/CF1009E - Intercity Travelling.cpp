/*
	题意分析：
		leha从数轴的0到n，中间的整数点有可能有休息点也可能没有休息点。当你连续开k站，每两站的
	疲劳值为a1,a2,a3...ak，如果第k站有休息点，那么你可以在此处休息，然后接下来的站点的疲劳值从
	a1开始,否则继续为ak+1。题目中给出n和ai,每个站点有休息站的概率为1/2，问期望值*2^(n-1)的值。
	解题思路：
		根据站点的不同列出a前面的系数，找出规律，列出方程，转化为线性，开始求解。
		方程大概：

		*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
	x += y;
	while (x >= MOD)
		x -= MOD;
	while (x<0)
		x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1LL * y) % MOD;
}
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i<n; i++)
		cin >> a[i];
	long long ans = 0;
	vector<int> pw2(1, 1);
	while (pw2.size()<n)
	{
		pw2.push_back(mul(pw2.back(), 2));
	}
	//预先处理系数
	long long cur = mul(pw2[n - 1], a[0]);
	for (int i = 0; i<n; i++)
	{
		ans = add(ans, cur);
		if (i<n - 1)
		{
			cur = add(cur, -mul(pw2[n - 2 - i], a[i]));
			cur = add(cur, mul(pw2[n - 2 - i], a[i + 1]));
		}
	}
	cout << ans;
}
