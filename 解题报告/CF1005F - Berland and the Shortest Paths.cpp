/*
	题意分析：
		给n个节点,m条边，求以0为中心构成最短路径树的k种方法（如果不足k种则输出k种）。
	解题思路：
		对于最小生成树而言，不同的情况每个点到中心的距离都是相同的，所以我们可以用一个数组来保存，每个点
	到原点的距离，那么根据树的性质可以非常轻易的得知，*一条边入度所在节点的距离等与出度所在点的距离加一，
	由以上两个性质我们再用BFS构建最短路径树，由打*号的性质我们可以得知最短路径树的多种情况。之后输出就完事了。
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > g(n);
	vector<int> a(m), b(m);
	for (int i = 0; i<m; i++)
	{
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	//以上为输入和作图
	queue<int> q;
	vector<int> d(n, INT_MAX);
	q.push(0);
	d[0] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i<g[u].size(); i++)
		{
			if (d[g[u][i]] == INT_MAX)
			{
				d[g[u][i]] = d[u] + 1;
				q.push(g[u][i]);
			}
		}
	}
	//以上为最短路径树的建立
	vector<vector<int> > inc(n);
	for (int i = 0; i<m; i++)
	{
		if (d[a[i]] + 1 == d[b[i]])
			inc[b[i]].push_back(i);
		if (d[b[i]] + 1 == d[a[i]])
			inc[a[i]].push_back(i);

	}
	//以上为多种情况的确立
	vector<int> f(n, 0);
	vector<string> ans;
	for (int i = 0; i<k; i++)
	{
		string tem(m, '0');
		for (int j = 1; j<n; j++)
		{
			tem[inc[j][f[j]]] = '1';
		}
		ans.push_back(tem);
		bool ok = false;
		for (int j = 1; j<n; j++)
		{
			if (f[j] + 1<inc[j].size())
			{
				ok = true;
				f[j]++;
				break;
			}
			else
				f[j] = 0;
		}
		if (!ok)
			break;
	}
	cout << ans.size() << endl;
	for (int i = 0; i<ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
