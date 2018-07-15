/*
	题意分析：
		给一个长宽高固定的立方体，问有多少种切法，可以使他变为等大的立方体(每块立方体的长宽高均相等)。
	解题思路：
		先算出每个数的因子个数，再求出两两和三个数一起的最大公约数，根据容斥定理算出三个数独自的因子个数，和两两组合的独自的因子个数，还有三个一起的因子个数
	，将这些数根据组合的方法全部相乘。
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5;
const int V = 1.2e5;
int cnt[MAX];

int p2(int n)//用来算p_n^2;
{
	return n * (n - 1);
}

int c2(int n)//用来算C_n^2
{
	return n * (n - 1) / 2;
}

int c3(int n)//用来算C_n^3
{
	return n * (n - 1)*(n - 2) / 6;
}

int g2(int n)
{
	return c2(n + 1);//这里的加一代表可以重复选的那个一
}

int g3(int n)
{
	return c3(n + 2);//这里的二代表可以重复选的一有两个
}

int query(int A, int B, int C)
{
	int AB = __gcd(A, B);
	int AC = __gcd(A, C);
	int BC = __gcd(B, C);
	int ABC = __gcd(AB, C);

	int cA = cnt[A] - cnt[AB] - cnt[AC] + cnt[ABC];
	int cB = cnt[B] - cnt[AB] - cnt[BC] + cnt[ABC];
	int cC = cnt[C] - cnt[AC] - cnt[BC] + cnt[ABC];
	int cAB = cnt[AB] - cnt[ABC];
	int cAC = cnt[AC] - cnt[ABC];
	int cBC = cnt[BC] - cnt[ABC];
	int cABC = cnt[ABC];
	int ans = 0;
	ans += cA * cB * cC;
	ans += cA * cB * cAC;
	ans += cA * cB * cBC;
	ans += cA * cB * cABC;
	ans += cA * cAB * cC;
	ans += cA * cAB * cAC;
	ans += cA * cAB * cBC;
	ans += cA * cAB * cABC;
	ans += cA * cBC * cC;
	ans += cA * cABC * cC;
	ans += cA * cAC * cBC;
	ans += cA * cAC * cABC;
	ans += cA * g2(cBC);
	ans += cA * cBC * cABC;
	ans += cA * g2(cABC);
	ans += cB * cAB * cC;
	ans += cB * cAB * cAC;
	ans += cB * cAB * cBC;
	ans += cB * cAB * cABC;
	ans += cB * cC * cAC;
	ans += cB * cC * cABC;
	ans += cB * g2(cAC);
	ans += cB * cAC * cBC;
	ans += cB * cAC * cABC;
	ans += cB * cBC * cABC;
	ans += cB * g2(cABC);
	ans += g2(cAB) * cC;
	ans += g2(cAB) * cAC;
	ans += g2(cAB) * cBC;
	ans += g2(cAB) * cABC;
	ans += cAB * cC * cAC;
	ans += cAB * cC * cBC;
	ans += cAB * cC * cABC;
	ans += cAB * g2(cAC);
	ans += cAB * cAC * cBC;
	ans += cAB * cAC * cABC;
	ans += cAB * g2(cBC);
	ans += cAB * cBC * cABC;
	ans += cAB * g2(cABC);
	ans += cC * cAC * cBC;
	ans += cC * cAC * cABC;
	ans += cC * cBC * cABC;
	ans += cC * g2(cABC);
	ans += g2(cAC) * cBC;
	ans += g2(cAC) * cABC;
	ans += cAC * g2(cBC);
	ans += cAC * cBC * cABC;
	ans += cAC * g2(cABC);
	ans += g2(cBC) * cABC;
	ans += cBC * g2(cABC);
	ans += g3(cABC);
	return ans;
}
int main()
{
	for (int i = 1; i <= V; i++)
		for (int j = i; j <= V; j += i)
			cnt[j]++;
	int T;
	cin >> T;
	while (T--)
	{
		int A, B, C;
		cin >> A >> B >> C;
		cout << query(A, B, C) << endl;
	}
	return 0;

}
