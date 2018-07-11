/*
	题意分析：
		将一个数字分解程好几个部分，如果要使能被3整除的部分尽量多，请问这种情况下
	最多有几个部分能被3整除。
	解题思路：
		这个题目的解法很多，但是用dp的方法可以的到O(n)的算法。
		设s[i]为第i个数，z[i]用来记录在第i个字符时可以被3整除的部分个数，假设s[i]
	和其前缀可以被3整除，那么z[i]=z[i-1]+1否则z[i]=z[i-1]
		关于数字3有一个定理那就是只要是3的倍数其每一位数字之和等于3的倍数，那么任务
	就被转化为找数字之和等于3的倍数，我们要找的其实就是最短后缀能被3整除的数，由于
	我们在之前一直求的是前缀和，所以只要前缀同余那么在他们之间的后缀一定是3的倍数。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
string inp;
vector<int> rem(3, -1);
int dp[maxn];
int main()
{
	cin >> inp;
	inp = '0' + inp;
	int r = 0;
	rem[0] = 0;
	for (int i = 1; i<inp.length(); i++)
	{
		r = (r + inp[i] - '0') % 3;
		dp[i] = dp[i - 1];
		if (rem[r] != -1)
			dp[i] = max(dp[i], dp[rem[r]] + 1);
		rem[r] = i;
	}
	cout << dp[inp.length() - 1];
	return 0;
}
