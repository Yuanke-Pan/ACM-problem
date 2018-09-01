/*
	题意分析：
		给你若干个点，让你判断这些点能不能由两条线把他们都串起来。
	解题思路：
		在这题中用到了三个个点是否共线的条件，对三个点形成的两条线段进行叉乘
	如果叉乘为零则三点共线否则三点不共线，这题中任取三点，将任意两个点先连成
	一条直线，把这条直线上的所有点都删除，最后看剩下的点能不能连成一条直线如果
	可以则为YES, 否则NO。

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
bool used[maxn];
int n;
struct Point {
	long long x, y;
	Point() {};
	Point(long long __x, long long __y)
	{
		x = __x;
		y = __y;
	}
	friend Point operator- (const Point A, const Point B)
	{
		return Point(A.x - B.x, A.y - B.y);
	}
}P[maxn];
long long Cross(Point A, Point B)
{
	return A.x * B.y - B.x * A.y;
}
bool check()
{
	int Pa = -1;
	int Pb = -1;
	for (int i = 0; i < n; i++)
	{
		if (used[i] == true) continue;
		if (Pa == -1)
		{
			Pa = i;
		}
		else if (Pb == -1)
		{
			Pb = i;
		}
	}
	if (Pa == -1 && Pb == -1) return true;
	for (int i = 0; i < n; i++)
	{
		if (used[i] == true) continue;
		if (Cross(P[Pa] - P[Pb], P[Pa] - P[i]) != 0)
		{
			return false;
		}
	}
	return true;
}
bool judge(Point A, Point B)
{
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; i++)
	{
		if (Cross(A - B, A - P[i]) == 0)
		{
			used[i] = true;
		}
	}
	return check();
}
bool solve()
{
	if (n <= 3)
		return true;
	if (judge(P[0], P[1]) || judge(P[0], P[2]) || judge(P[1], P[2]))
		return true;
	else return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		P[i].x = a;
		P[i].y = b;
	}
	if (solve())
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
//ps:这题中的Point这个数据结构在计算几何中十分重要，但是往往作为向量来处理，所以要牢记。
