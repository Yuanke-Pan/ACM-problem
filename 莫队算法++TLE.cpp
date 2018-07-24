//Äª¶ÓËã·¨
#include<bits/stdc++.h>
using namespace std;
const int maxns = 1e6 + 5;
const int maxq = 2e6 + 5;
const int maxn = 5e6 + 5;

struct query {
	int l, r;
	int id;
}node[maxq];

int flag[maxns];
int a[maxn];
int ans[maxq];
int pos[maxn];
int as = 0;

int N, M;

bool cmp(query a, query b)
{
	if (pos[a.l] == pos[b.l])
		return a.r>b.r;
	else return pos[a.l]>pos[b.l];
}

void add(int x)
{
	if (flag[a[x]] == 0)
	{
		as++;
	}
	flag[a[x]]++;
}

void del(int x)
{
	if (flag[a[x]] == 1)
	{
		as--;
	}
	flag[a[x]]--;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	int size = sqrt(N);
	for (int i = 1; i <= N; i++)
	{
		pos[i] = i / size;
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> node[i].l >> node[i].r;
		node[i].id = i;
	}
	sort(node + 1, node + 1 + M, cmp);
	int L = 1, R = 0;
	for (int i = 1; i <= M; i++)
	{
		while (L<node[i].l)
		{
			del(L);
			L++;
		}
		while (L>node[i].l)
		{
			L--;
			add(L);
		}
		while (R<node[i].r)
		{
			R++;
			add(R);
		}
		while (R>node[i].r)
		{
			del(R);
			R--;
		}
		ans[node[i].id] = as;
	}
	for (int i = 1; i <= M; i++)
		cout << ans[i] << endl;
}
