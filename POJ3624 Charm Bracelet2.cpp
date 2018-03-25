//emmmmmm,采用的是二维数组的动态规划，还是超内存了。。。。
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int N, M;
int w[3500], d[3500];
int dp[3500][12888];
int S = 0;

void solve()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (w[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + d[i]);
			}
		}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &w[i], &d[i]);
	}
	solve();
	S = dp[N][M];
	printf("%d", S);
	return 0;

}