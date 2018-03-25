//这个用的是递归的方法进行求解，虽然能计算出最后的结果，但是占用的内存很大
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int N, M, S;
int W[3402], D[3402];
int dp[3402][12880];

int solve(int i, int j)
{
	if (dp[i][j] > 0)
	{
		return dp[i][j];
	}

	int res;
	if (i == N)
	{
		res = 0;
	}
	else if (j < W[i])
	{
		res = solve(i + 1, j);
	}
	else
	{
		res = max(solve(i + 1, j), solve(i + 1, j - W[i]) + D[i]);
	}
	dp[i][j] = res;
	return res;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &W[i], &D[i]);
	}
	S = solve(0, M);
	printf("%d", S);
	return 0;

}