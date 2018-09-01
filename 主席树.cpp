//主席树（函数式线段树)此为更改版本由于本人认为这个更好理解
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct node
{
	int s;
	node *lc, *rc;
}T[maxn * 40], *root[maxn], *cnt;//cnt在主席树中十分重要，其用来记录当前更新的节点，防止节点被重复写入

int a[maxn], n;
long long ans;

node *update(node* u, int l, int r, int num)
{
	node *ret = ++cnt;//这里拿取一个新的节点
	*ret = *u;//复制上一个节点的内容到新的节点
	ret->s++;
	if (l == r) return  ret;
	int mid = (l + r) >> 1;
	if (num>mid)//这里就体现了部分更新的思想如果有变化则更新，否则保持原样
		ret->rc = update(ret->rc, mid + 1, r, num);
	else
		ret->lc = update(ret->lc, l, mid, num);
	return ret;
}

int query(node* u, node* v, int l, int r, int num)
{
	if (num <= l) return v->s - u->s;//这一步是根据题意来的。。。
	int mid = (l + r) >> 1, an = query(u->rc, v->rc, m id + 1, r, num);
	if (mid >= num) an += query(u->lc, v->lc, l, mid, num);
	return an;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i]>n) a[i] = n;
	}
	root[0] = T->lc = T->rc = cnt = T;
	T->s = 0;
	for (int i = 1; i <= n; i++)
	{
		root[i] = update(root[i - 1], 1, n, a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i]>i)
			ans += (long long)query(root[i], root[a[i]], 1, n, i);
	}
	printf("%lld\n", ans);
	return 0;
}
