/*
	主要思路:
		线段树保存的是相应数字的个数。
		将序列按照顺序加入线段树，加入之前线查询比他的数字有多少个，之后就将每次查询的结果相加，就是我们想要的答案。
*/
//ps: 在用线段树求逆序对的时候往往先要将数据离散化，这样防止内存过度使用此题中由于数据的特殊性所以没有进行离散化。
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;

struct node {
	int l, r, s;
}T[maxn * 4];
int a[maxn];

void pullup(int i)
{
	T[i].s = T[i << 1].s + T[i << 1 | 1].s;
}

void build(int i, int l, int r)
{
	T[i].l = l;
	T[i].r = r;
	T[i].s = 0;
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	return;
}

void add(int i, int num)
{
	int L = T[i].l;
	int R = T[i].r;
	if (L == R && L == num)
	{
		T[i].s++;
		return;
	}
	int mid = L + R >> 1;
	if (num <= mid)
		add(i << 1, num);
	else add(i << 1 | 1, num);
	pullup(i);
	return;
}
int query(int i, int l, int r)
{
	int L = T[i].l;
	int R = T[i].r;
	if (l <= L && R <= r)
		return T[i].s;
	int mid = L + R >> 1;
	int an = 0;
	if (l <= mid)
		an = query(i << 1, l, r);
	if (r > mid)
		an += query(i << 1 | 1, l, r);
	return an;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		build(1, 0, n - 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += query(1, a[i], n - 1);
			add(1, a[i]);
		}
		int mins = ans;
		for (int i = 1; i <= n; i++)
		{
			ans -= a[i];
			ans += n - a[i] - 1;
			if (ans < mins) mins = ans;
		}
		printf("%d\n", mins);
	}
	return 0;
}
