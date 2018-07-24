//并查集简化应用
/*
	题意分析：
		给定一个树，有这样一个数组，Dx,i代表祖先是x，到达祖先要经历i条边的顶点个数，在这样一个数组中如果存在这样一个数下标为i，其前边的数都比这个数小，后面的
	数不大于这个数，那么就称这个数为主下标。现在求每个节点的主下标为多少？
	解题思路：
		初步想法:由于每一个节点都要有一个数组来记录Dx,i，每次并入一个节点，其祖先节点的数组所对应的元素都要加上1，最后遍历每个节点找到主下标,这样的话时间复杂
	度为O(n^2),空间复杂度为O(n^2)
		进一步优化：如果树从底向上构建那么每个节点的父节点的信息，是父节点的所有子节点的信息之和，那么在构建树的时候将信息自底向上传递同时记录每个节点的主下标，
	那么这样的话就可以将时间复杂度转化为O(n)。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000043;

struct node
{
	vector<int> *d;//这里的vector只用设置指针,全靠孩子往上传
	int cur_max;//这里记录的主下标的值
	int sz()
	{
		return d->size();
	}
	void add(int i, int val)
	{
		(*d)[i] += val;
		if (make_pair((*d)[i], i)>make_pair((*d)[cur_max], cur_max))//由于是从底向上所以新的元素是以压入的形式，所以坐标越靠后越小
			cur_max = i;
	}
};

node pull(node z)//这个函数的目的是在merge完了以后，再加上Dx,0
{
	if (z.sz() == 0)
	{
		node c;
		c.d = new vector<int>(1, 1);
		c.cur_max = 0;
		return c;
	}
	else
	{
		node c;
		c.d = z.d;
		c.cur_max = z.cur_max;
		c.d->push_back(0);
		c.add(c.sz() - 1, 1);
		return c;
	}

}

node merge(node a, node b)//merge函数用来合并父子
{
	if (a.sz()<b.sz())
		swap(a, b);
	//node c;
	//c.d = a.d;
	//c.cur_max = a.cur_max;
	int as = a.sz();
	int bs = b.sz();
	for (int i = 0; i < bs; i++)
		a.add(as - i - 1, (*(b.d))[bs - i - 1]);//从末尾加到最后保证表达的意思是一致的
	return a;
}

node s[maxn];
int ans[maxn];
vector<int> g[maxn];

void dfs(int x, int p = -1)
{
	s[x].d = new vector<int>(0);
	s[x].cur_max = 0;
	for (auto y : g[x])
	{
		if (y != p)//防止成环
		{
			dfs(y, x);
			s[x] = merge(s[x], s[y]);
		}
	}
	s[x] = pull(s[x]);
	ans[x] = s[x].sz() - 1 - s[x].cur_max;
	return;
}
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}