//坐标轴压缩

/*
	题意分析：
		给定若干个区间，每次给一个区间，最后求根据被覆盖的次数从小到大输出个数。
	解题思路：
		对于数据量小的题目可以这样做：
		维护一个数组cnt,对于每次给出的l和r，cnt[l]++,cnt[r+1]--,求前缀和这样每个cnt[i]
	代表的是这个区间被覆盖的区间数。
		但是这题中不能这样写： 
		这题的数据量极大所以不能将整个cnt数组放进程序进行计算，但是我们的思路依旧可以延续，
	利用坐标压缩的技术来维护cnt。
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<long long, long long> > a(n);
	vector<long long> point;
	for (int i = 0; i<n; i++)
	{
		cin >> a[i].first >> a[i].second;
		point.push_back(a[i].first);
		point.push_back(a[i].second + 1);
	}
	sort(point.begin(), point.end());
	point.resize(unique(point.begin(), point.end()) - point.begin());//坐标轴压缩

	vector<int> cnt(2 * n);
	for (int i = 0; i<n; i++)
	{
		int posl = lower_bound(point.begin(), point.end(), a[i].first) - point.begin();
		int posr = lower_bound(point.begin(), point.end(), a[i].second + 1) - point.begin();
		cnt[posl]++;
		cnt[posr]--;
	}
	for (int i = 1; i< 2 * n; i++)
	{
		cnt[i] += cnt[i - 1];
	}
	vector<long long> ans(n + 1);
	for (int i = 1; i<2 * n; i++)
	{
		ans[cnt[i - 1]] += (point[i] - point[i - 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
