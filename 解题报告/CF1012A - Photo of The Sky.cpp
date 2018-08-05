/*
	题意分析：
		给你2n个随机数，求两个坐标，使所有数组成的坐标都留在这两个坐标组成的正方形中，求这个正方形的最小面积。
	解题思路：
		最终得到的两个坐标（x1,y1）（x2,y2）满足对于所有的坐标而言x1<=x<=x2,y1<=y<=y2,那么输入的数列属于两个集合X和Y,则我们的任务就是找到
	这两个集合的端点。
		那么最终就只有两种情况，一个集合在数列的中间，另一个在数列的两头，另一种情况是两个集合分别占据两头。就可以开始编程了。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int inp[maxn * 2];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &(inp[i]));
	sort(inp, inp + 2 * n);
	int now = INT_MAX;
	for (int i = 0; i < n; i++)
		now = min(now, inp[i + n - 1] - inp[i]);
	long long ans = (long long)min((long long)now*(long long)(inp[2 * n - 1] - inp[0]), (long long)(inp[n - 1] - inp[0])*(long long)(inp[2 * n - 1] - inp[n]));
	printf("%lld", ans);
	return 0;
}