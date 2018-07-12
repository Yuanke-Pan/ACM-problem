/*
	题意分析：
		此题和E1的题意相似只不过，上一题给的是不充分的序列，而这一题给的是一个可重复的数组（难度加大）。
	解题思路：
		在这题中可以将问题稍微转化，如果我们要求出中位数为m的序列,我们可以将问题的规模放大来简化问题，我们可以来求中位数大于等于m
	的序列个数和中位数大于等于m+1的序列的个数，两个相减就为中位数等于1的序列个数。
		中位数大于等于m的序列个数求法：
		中位数大于等于m的序列有一个特点，其中大于等于m的元素个数大于小于m的元素个数，统计的方法为如果元素小于m则sum--，否则sum++，
	之后用一个数组来统计之前每个sum出现的次数，就可以得到一个数形成中位数的序列有多少个，根据元素与中位数相比可以得到这个序列是对
	答案做了贡献，或者没做贡献。由此来对下一个要加的数进行加或者减，就可以得到想要的结果。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int inp[maxn];

long long getgreat(int m)
{
	vector<int> s(2 * n + 3, 0);
	s[n] = 1;
	long long add = 0;
	long long result = 0;
	int sum = n;
	for (int i = 1; i <= n; i++)
	{
		if (inp[i]<m)
		{
			sum--; add -= s[sum];
		}
		else
		{
			add += s[sum]; sum++;
		}
		result += add;
		s[sum]++;
	}
	return result;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> inp[i];
	cout << getgreat(m) - getgreat(m + 1) << endl;
	return 0;
}
