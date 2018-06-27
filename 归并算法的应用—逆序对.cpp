#include<bits/stdc++.h>
using namespace std;
int tem[40001] = { 0 }, n, ans = 0, a[40001] = { 0 };
void mergesort(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) / 2;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r)
	{
		if (a[i] > a[j])
		{
			tem[p++] = a[j++];
			ans += mid - i + 1;
		}
		else
			tem[p++] = a[i++];
	}
	while (i <= mid)
		tem[p++] = a[i++];
	while (j <= r)
		tem[p++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = tem[i];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(0, n - 1);
	cout << ans;
	return 0;
}