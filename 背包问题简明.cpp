/*
	0-1背包问题：
		for(int i = 0 ;i < n; i++)
		{
			for(int j = sum; j >= cost; j--)
			{
				dp[j] = max(dp[j],dp[j-cost]+val);
			}
		}
		0-1背包问题，解决问题的思路主要是每一件商品的状态无非是放和不放这两种，因此对于每一种商品，只要判断放和不放的最大值就好了。
	完全背包问题：
		for(int i = 1; i <= n; i++)
		{
			for(int j = cost; j <= sum;j++)
			{
				dp[j] = max(dp[j],dp[j-cost]+val);
			}
		}
		这个问题的解决思路是每种商品都有放和不放两种状态，如果放就有放几个的问题。
		注：0-1背包问题的代码和完全背包问题的代码相似主要差在0-1背包是逆序找的而完全背包问题是顺序找的。
	多重背包问题：
		for(int i = 0; i < n; i++)
		{
			int num = min(num, w / c[i]);
			for(int k = 1; num > 0; k *= 2)
			{
				if(k > num) k = num;
				num -= k;
				for(int j = m; j > k*c[i]; j--)
				{
					dp[j] = max(dp[j],dp[j-k*c[i]]+a[i]);
				}
			}
		}
*/