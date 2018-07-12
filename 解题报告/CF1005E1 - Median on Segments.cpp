/*
	题意分析：
		在一个给定的序列上找一个范围使另一个给定的数在这个范围内为中位数，
	解题思路：
		在这个题中要求的是中位数，中位数有一个性质那就是在一个序列中如果一个数为中位数，那么比他大的数要等于比他小的数或者
	比他小的数-1（+1）这个根据题目要求来定，那么我们就可以定义一个数组来记录下比他大的数减去比他小的数等于x的个数，根据前缀
	的性质，在包括m后找其前缀和相同的和前缀和-1的数在数组中的出现次数就好了。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int offset = 2e5 + 2;//这里使用的是数组，因此有可能会有数组下标越界的情况所以要设置偏移量。如果用map则可以不用设置。
int c[maxn];
int inp[maxn];
int n, m;

int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
	}
	c[offset] = 1;
	int sum = 0;
	bool inclu = false;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (inp[i]>m)
			sum++;
		else if (inp[i]<m)
			sum--;

		if (inp[i] == m)
			inclu = true;
		if (inclu)
			ans += c[sum - 1 + offset] + c[sum + offset];
		else c[sum + offset]++;
	}
	cout << ans << endl;
	return 0;
}
