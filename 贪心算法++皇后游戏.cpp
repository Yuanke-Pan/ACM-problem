#include<iostream>
#include<algorithm>
using namespace std;
struct employee{
	long long a;
	long long b;
} em[50001] = {0};
int T,n;
long long dd[50005];
bool cmp(employee x,employee y)
{
	return min(x.a, y.b) < min(y.a, x.b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	long long sum = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> em[j].a >> em[j].b;
		}
		sort(em+1, em + n+1, cmp);
		dd[0] = 0;
		sum = 0;
		for (int j = 1; j<= n; j++)
		{
			sum += em[j].a;
			dd[j] = max(dd[j - 1], sum) + em[j].b;
		}
		cout << dd[n];
	}
	return 0;
}