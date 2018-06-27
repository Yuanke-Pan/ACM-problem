#include<bits/stdc++.h>
using namespace std;
string org, tra;
vector<pair<string, string>> rule;
set<string> repeat;
struct node
{
	int time;
	string nows;
	node(string a, int t) :nows(a), time(t) {}
};
bool bfs()
{
	queue<node> que;
	que.push(node(org, 0));
	while (!que.empty())
	{
		node n = que.front();
		que.pop();
		if (n.time > 10) { cout << "NO ANSWER!"; return false; }
		for (int i = 0; i < rule.size(); i++)
		{
			if (n.nows.find(rule[i].first) != -1)
			{
				for (int j = n.nows.find(rule[i].first); j < n.nows.length(); j = n.nows.find(rule[i].first, j + 1))
				{
					string t = n.nows;
					t.replace(j, rule[i].first.length(), rule[i].second);
					if (t == tra) { cout << n.time + 1; return true; }
					if (!repeat.count(t))
					{
						que.push(node(t, n.time + 1));
						repeat.insert(t);
					}
				}

			}
		}
	}
	cout << "NO ANSWER!";
	return false;
}
int main()
{
	cin >> org >> tra;
	string ra, rb;
	while (cin >> ra >> rb)
		rule.push_back(make_pair(ra, rb));
	bfs();
	return 0;
}