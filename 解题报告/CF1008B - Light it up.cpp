/*
	题意分析：
		有一个灯，在0时间点打开，m时间关闭，在0到m的这段时间内有n个时间点会使灯的状态改变，现在要插入至多一个点使灯
	亮的时间最大。
	解题思路：
		最优的放置方法就是在左边亮右边暗的地方放置,所以剩下的只有遍历了，为了提高速度，我们可以将灯亮的时间和暗的时
	间一起记录下来，这样就省下了许多重复计算的步骤。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int inp[maxn];
int light[maxn][2];
int n;
int M;

int main()
{
	cin >> n >> M;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
	}
	inp[0] = 0;
	inp[n + 1] = M;
	int ans = 0;
	for (int i = n; i >= 0; i--)
	{
		light[i][0] = light[i + 1][0];
		light[i][1] = light[i + 1][1];
		if (i % 2 == 0)
		{
			light[i][0] += inp[i + 1] - inp[i];
			ans += inp[i + 1] - inp[i];
		}
		else
		{
			light[i][1] += inp[i + 1] - inp[i];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			int now1 = light[0][0] - light[i][0];//放右边的时候
			int now2 = light[0][0] - light[i - 1][0];//放左边的时候
			if (inp[i] - inp[i - 1] >= 2)
			{
				ans = max(ans, now2 + light[i][1] + inp[i] - inp[i - 1] - 1);
			}
			if (inp[i + 1] - inp[i] >= 2)
			{
				ans = max(ans, now1 + light[i + 1][1] + inp[i + 1] - inp[i] - 1);
			}
		}
	}
	cout << ans << endl;
}
