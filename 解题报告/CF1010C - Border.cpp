/*
	题意分析：
		给出n个十进制数，求当以k为底时这些数的最后一位数，以及这些数组合后的最后
	一位数，有多少个，分别是什么？
	解题思路：
		这个题可以借助贝祖定理ax+by = （a,b最小公约数的倍数），由此我们可以先计算
	最小公因数，在枚举到他的k倍就行了，k倍之后就是循环了。
*/
#include<bits/stdc++.h>
using namespace std;

int gdc(int a, int b)
{
	if (a<b)
		swap(a, b);
	return b == 0 ? a : gdc(b, a%b);
}

int main()
{
	int n, k;
	cin >> n >> k;
	int m = 0;
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		g = gdc(g, t);
	}
	set<int> ans;
	long long s = 0;
	for (int i = 0; i < k; i++, s += g)
	{
		ans.insert(s%k);
	}
	cout << ans.size() << endl;
	for (set<int>::iterator i = ans.begin(); i != ans.end(); i++)
	{
		cout << *i << " ";
	}
	return 0;
}
