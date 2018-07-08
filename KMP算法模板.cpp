#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 7;

int next[maxn];
string a, b;

void getnext(string& a)
{
	int plen = a.length();
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j<plen - 1)
	{
		if (k == -1 || a[k] == a[j])
		{
			k++; j++;
			next[j] = k;
		}
		else { k = next[k]; }
	}
}
int kmp(string &b)
{
	int j = 0, i = 0;
	int plen = a.length();
	int tlen = b.length();
	while (j<plen&&i<tlen)
	{
		if (j == -1 || a[j] == b[i])
		{
			j++;
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == plen)
		return i - j;
	else return -1;
}
int main()
{
	cin >> a >> b;
	getnext(a);
	cout << kmp(b);
	return 0;
}
