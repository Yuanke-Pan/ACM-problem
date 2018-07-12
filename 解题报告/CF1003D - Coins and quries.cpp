/*
	题意分析：
		给定n个硬币，每个硬币都是2的x次方，每次查询给定一个数，求最少要多少枚硬币。
	解题思路：
		优先使用最大的硬币（很简单的一个贪心），在写法上有些技巧。
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> deg(33);
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++)
	{
		int a;
		cin >> a;
		deg[__builtin_ctz(a)]++;//这个内建函数表示最低位的1的位数
	}
	for (int i = 0; i<m; i++)
	{
		int a;
		cin >> a;
		int ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			int needs = min(a >> i, deg[i]);//判断供需的最小值
			ans += needs;
			a -= (1 << i)*needs;
		}
		if (a == 0) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}