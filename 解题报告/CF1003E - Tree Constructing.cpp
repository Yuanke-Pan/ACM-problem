/*
	题意分析：
		给定n个节点，要求构造一棵，最长的简单路长度不得超过d，每个节点的最大度数不得超过k。
	解题思路：
		这个题目已经告诉我们最长的简单路的长度，所以我们要做的是先构造一条最长简单路，同时维护一个set来保存每个节点的路的
	长度，和一个数组用来记录每个节点的度数，每次添加一个节点其最大简单路的长度是上一个节点加一。
		判断不可能构造出来的几个条件：1、d>=n 2、在构造的时候所有节点的度都已经到达k 3、在构造的时候已经有节点的最长简单路的长度到达d
		如果一个节点符合上述条件则可以直接跳出。
*/
#include<bits/stdc++.h>
using namespace std;

int n, d, k;
int main()
{
	cin >> n >> d >> k;
	vector<int> deg(n, 0);
	set<pair<int, int> > pa;
	vector<pair<int, int> > ans;
	if (d >= n)
	{
		cout << "NO";
		return 0;
	}
	for (int i = 0; i<d; i++)
	{
		deg[i]++;
		deg[i + 1]++;
		if (deg[i]>k || deg[i + 1]>k)
		{
			cout << "NO";
			return 0;
		}
		ans.push_back(make_pair(i, i + 1));
	}
	for (int i = 1; i<d; i++)//因为两头的最短路径都是d,所以i从1开始到d-1
	{
		pa.insert(make_pair(max(i, d - i), i));
	}
	for (int i = d + 1; i<n; i++)
	{
		while (!pa.empty() && deg[pa.begin()->second] == k)//首先保证这个点的度没有被用完
			pa.erase(pa.begin());
		if (pa.empty() || pa.begin()->first == d)//如果这个点的最长简单路长度已经到达d，那么无论往那个地方加点都会使他的长度加1，所以可以直接判断不可能
		{
			cout << "NO";
			return 0;
		}
		deg[i]++;
		deg[pa.begin()->second]++;
		ans.push_back(make_pair(i, pa.begin()->second));
		pa.insert(make_pair(pa.begin()->first + 1, i));
	}
	cout << "YES" << endl;
	for (int i = 0; i<n - 1; i++)
	{
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}
