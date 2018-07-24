//线段树
#include<bits/stdc++.h>
using namespace std;
const int maxn = 200001;

struct node
{
	long long l;
	long long r;
	long long maxs;
	long long lazy;
	void update(long long x)
	{
		maxs = max(maxs, x);
		lazy = x;
	}
}tree[maxn * 4];
int M;
long long D;
void push_up(int x)
{
	tree[x].maxs = max(tree[x << 1].maxs, tree[x << 1 | 1].maxs);
}
void push_down(int x)
{
	long long lazyval = tree[x].lazy;
	if (lazyval)
	{
		tree[x << 1].update(lazyval);
		tree[x << 1 | 1].update(lazyval);
		tree[x].lazy = 0;
	}
}
void build(int x, int l, int r)
{
	tree[x].l = l, tree[x].r = r;
	tree[x].maxs = tree[x].lazy = 0;
	if (l == r)
	{
		tree[x].maxs = 0;
	}
	else
	{
		int mid = (l + r) / 2;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		push_up(x);
	}
}
long long query(int x, int l, int r)
{
	long long ans = 0;
	int R = tree[x].r, L = tree[x].l;
	if (l <= L && R <= r) return tree[x].maxs;
	else
	{
		int mid = (L + R) / 2;
		if (l <= mid) ans = max(ans, query(x << 1, l, r));//更新的时候要注意信息的修改要根据题意来
		if (r>mid) ans = max(ans, query(x << 1 | 1, l, r));
	}
	return ans;
}
void add(int x, int p, long long val)
{
	int R = tree[x].r, L = tree[x].l;
	if (L == R && L == p) tree[x].update(val);
	else
	{
		int mid = (L + R) / 2;
		if (p <= mid) add(x << 1, p, val);
		else if (p>mid) add(x << 1 | 1, p, val);
		push_up(x);
	}
}
int top = 0;

int main()
{
	cin >> M >> D;
	long long t = 0;
	build(1, 1, M);//在树的大小不清楚的情况下，可以先建一个大的树，具体大小根据题意来建
	while (M--)
	{
		char c;
		long long b;
		cin >> c >> b;
		if (c == 'A')
		{
			add(1, ++top, (b + t) % D);
		}
		if (c == 'Q')
		{
			t = query(1, top - b + 1, top);
			cout << t << endl;
		}
	}
}
