#include<bits/stdc++.h>
#define nx x+dir[i][0]
#define ny y+dir[i][1]
using namespace std;
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int des[1001][1001] = { 0 };
bool org[1001][1001] = { 0 };
int ans[10000000] = { 0 };
int tempans = 0;
int n;
int t = 1;
queue<int> a;
void dfs(int x, int y)
{
	if (x >= n || y >= n || x < 0 || y < 0) return;
	tempans++;
	des[x][y] = t;
	for (int i = 0; i < 4; i++)
	{
		if (!des[nx][ny] && org[x][y] ^ org[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &(org[i][j]));
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!des[i][j])
			{
				tempans = 0;
				dfs(i, j);
				ans[t] = tempans;
				t++;
			}
		}
	for (int i = 0; i < m; i++)
	{
		int tx, ty;
		cin >> tx >> ty;
		a.push(ans[des[tx - 1][ty - 1]]);
	}
	while (!a.empty())
	{
		cout << a.front() << endl;
		a.pop();
	}
	return 0;
}
