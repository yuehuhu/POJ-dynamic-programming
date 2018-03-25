//使用动态规划的一维数组，emmmmm，终于accept了，超级开心
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int N, M;
int w[3500], d[3500];
int dp[12888];
int S = 0;

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = M; j >= 0; j--)
		{
			if (w[i] <= j)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
			}

		}
	}


}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &w[i], &d[i]);
	}
	solve();
	S = dp[M];
	printf("%d", S);
	return 0;

}