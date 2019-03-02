/*pat top level 1005 后缀数组，听说hash 也能过
	后缀数组的基本思想：倍增和基数排序
	LCP（最长公共子串）：有一个原理和推论，以及最后关键的 height[i] >= height[i-1]-1
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;

const int maxn = 100005;

char s[maxn];
int rk[maxn], sa[maxn], y[maxn], x[maxn], height[maxn];
int c[maxn];
int n, m;

void get_sa()
{
	for (int i = 1; i <= n; i++)
		++c[x[i] = s[i]];
	for (int i = 2; i <= m; i++)
		c[i] += c[i - 1];
	for (int i = n; i >= 1; i--)
		sa[c[x[i]]--] = i;
	for (int k = 1; k <= n; k <<= 1)
	{
		int num = 0;
		for (int i = n - k + 1; i <= n; i++)
			y[++num] = i;
		for (int i = 1; i <= n; i++)
			if (sa[i] > k) y[++num] = sa[i] - k;
		for (int i = 1; i <= m; i++)
			c[i] = 0;
		for (int i = 1; i <= n; i++)
			++c[x[i]];
		for (int i = 2; i <= m; i++)
			c[i] += c[i - 1];
		for (int i = n; i >= 1; i--)
			sa[c[x[y[i]]]--] = y[i], y[i] = 0;
		swap(x, y);
		x[sa[1]] = 1;
		num = 1;
		for (int i = 2; i <= n; i++)
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
		if (n == num) break;
		m = num;
	}
}
void get_height()
{
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		rk[sa[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (rk[i] == 1) continue;
		if (k) --k;
		int j = sa[rk[i] - 1];
		while (j + k <= n && i + k <= n && s[j + k] == s[i + k])
			k++;
		height[rk[i]] = k;
	}

}
int main()
{
	int tn;
	m = 127;
	cin >> tn;
	getchar();
	fgets(s + 1, maxn, stdin);
	n = strlen(s + 1);
	get_sa();
	get_height();
	int tr = 1, th = sa[1];
	int resunum = 0;
	int reindex = 1;
	for (int i = 1; i <= n; i++)
	{
		if (height[i] >= tn)
			tr++;
		else
		{
			if (tr > resunum || (tr == resunum && s[th] < s[reindex]))
				resunum = tr, reindex = th;
			tr = 1, th = sa[i];
		}
	}
	if (tr > resunum || (tr == resunum && s[th] < s[reindex]))
		resunum = tr, reindex = th;
	for (int i = 0; i < tn; i++)
		cout << s[reindex + i];
	cout << " " << resunum << endl;
	return 0;
}
