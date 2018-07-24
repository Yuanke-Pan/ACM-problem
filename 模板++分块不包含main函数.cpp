//分块
/*
belong[i] 表示属于那一块
block表示块的大小
num表示块的个数
l[maxn]表示块的左边界
r[maxn]表示块的右边界
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 7;

int belong[maxn], block, num, l[maxn], r[maxn], n, q;
long long a[maxn], Max[maxn];
void build()
{
	block = sqrt(n);
	num = n / block; if (n%block) num++;
	for (int i = 1; i <= num; i++)
	{
		l[i] = (i - 1)*block + 1, r[i] = i * block;
	}
	r[num] = n;
	for (int i = 1; i <= n; i++)
		belong[i] = (i - 1) / block + 1;
	// 以上对于大部分分块的题目基本不变
	for (int i = 1; i <= num; i++)
		for (int j = l[i]; j <= r[i]; j++)
			Max[i] = max(Max[i], a[j]);
	//以上根据题意的不同进行不同的初始化
}

void update(int x, int y)
{
	a[x] += y;
	Max[belong[x]] = max(Max[belong[x]], a[x]);
}

long long ask(int x, int y)
{
	long long ans = 0;
	if (belong[x] == belong[y])
	{
		for (int i = x; i <= y; i++)
			ans = max(ans, a[i]);
		return ans;
	}
	for (int i = x; i <= r[belong[x]]; i++)
		ans = max(ans, a[i]);
	for (int i = belong[x] + 1; i<belong[y]; i++)
		ans = max(ans, Max[i]);
	for (int i = l[belong[y]]; i <= y; i++)
		ans = max(ans, a[i]);
	return ans;
}
