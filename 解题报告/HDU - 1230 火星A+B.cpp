#include<bits/stdc++.h>
using namespace std;

int mars[] = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113 };
int a[30];
int b[30];
int main()
{
	int tem;
	while (1)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		bool flaga = false;
		bool flagb = false;
		while (1)
		{
			cin >> a[++a[0]];
			char ch;
			ch = getchar();
			if (ch != ',')
				break;
		}
		while (1)
		{
			cin >> b[++b[0]];
			char ch;
			ch = getchar();
			if (ch != ',')
				break;
		}
		if (a[0] == 1 && a[1] == 0 && b[0] == 1 && b[1] == 0)
		{
			return 0;
		}
		int ans[30] = { 0 };
		for (int i = a[0], j = b[0], t = 1; i > 0 || j > 0; i--, j--, t++)
		{
			if (i == 0)
			{
				ans[t] = b[j];
			}
			else if (j == 0)
			{
				ans[t] = a[i];
			}
			else
			{
				ans[t] = a[i] + b[j];
			}
		}
		ans[0] = max(a[0], b[0]);
		for (int i = 1; i <= ans[0]; i++)
		{
			ans[i + 1] += ans[i] / mars[i];
			ans[i] %= mars[i];
		}
		if (ans[ans[0] + 1] != 0)
		{
			ans[0]++;
		}
		for (int i = ans[0]; i > 0; i--)
		{
			cout << ans[i];
			if (i - 1 > 0)
				cout << ',';
		}
		cout << endl;
	}
	return 0;
}
//不知道为什么会WA, 有毒