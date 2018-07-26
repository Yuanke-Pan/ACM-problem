#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int maxn = 1e5 + 7;

vector<int> a[2019];
bool in_turn[2019] = { 0 };
int inp[maxn];
struct node
{
	int l, r;
	int orig;
	int val;
	int cnt;
	node(int l = 0, int r = 0, int val = 0, int cnt = 0) :l(l), r(r), val(val), cnt(cnt) {}
	void update()
	{
		if (!in_turn)
		{
			val *= val;
			val %= 2018;
		}
		else
		{
			cnt++;
			cnt %= a[orig].size();
			val = a[cnt];
			return;
		}
		if (val == a[orig][0])
			in_turn[orig] = true;
	}
}tree[maxn << 2];

void pull_up(int x)
{
	tree[x].val = tree[x << 1 | 1].val + tree[x << 1].val;
}

void build(int x, int l, int r)
{
	tree[x].l = l, tree[x].r = r;
	tree[x].val = tree[x].orig = 0;
	if (l == r)
	{
		tree[x].val = inp[l];
		tree[x].orig = inp[l];
	}
	else
	{
		int mid = (l + r) / 2;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		pull_up();
	}
}

void update(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	if (L == R && l <= L && R <= r)
	{
		tree[x].update();
	}
	else
	{
		int mid = (L + R) / 2;
		if (l <= mid) update(x << 1, l, r);
		if (r > mid) update(x << 1 | 1, l, r);
		pull_up(x);
	}
}

int query(int x, int l, int r)
{
	int L = tree[x].l, R = tree[x].r;
	if (l <= L && R <= r)
		return tree[x].val;
	else
	{
		int mid = (L + R) / 2;
		int ans = 0;
		if (l <= mid)
		{
			ans += query(x << 1, l, r);
		}
		if (r > mid)
			ans += query(x << 1 | 1, l, r);
		return ans;
	}
}

void processor()
{
	a[1].push_back(1);
	for (int i = 2; i <= 2018; i++)
	{
		set<int> tem;
		int t = i;
		while (!tem.count(tem))
		{
			tem.insert(t);
			t *= t;
			t %= 2018;
		}
		set<int> tem2;
		while (!tem.count(t))
		{
			a[i].push_back(t);
			tem.insert(t);
			t *= t;
			t %= 2018;
		}
	}
}

int main()
{
	processor();
	int T;
	cin >> T;
	while (T--)
	{
		i
	}
}