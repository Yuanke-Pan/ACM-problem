#include<iostream>
#include<vector>
using namespace std;
vector<int> pri;
bool prim[10000001] = { 0 };
int m, n;
void list()
{
	for (int i = 2; i <= m; i++)
	{
		if (!prim[i]) pri.push_back(i);
		for (int j = 0; j < pri.size() && pri[j] * i <= m; j++)
		{
			prim[pri[j] * i] = true;
			if (i%pri[j] == 0)break;
		}
	}
	prim[1] = true;//这里要特别注意1不是质数
}
int main()
{
	cin >> m >> n;
	list();
	int z;
	for (int i = 0; i < n; i++)
	{
		cin >> z;
		if (!prim[z])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}