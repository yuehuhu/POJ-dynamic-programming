
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int dp[300][300];
char s1[300], s2[300];
int l1, l2;
int sum;

void solve()
{
	for (int i = 1; i <= l1; i++)
	{
		for (int j = 1; j <= l2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}
	}
	printf("%d\n", dp[l1][l2]);
	
}

int main()
{
	while (scanf("%s %s", &s1,&s2)!=EOF)
	{
		
			l1 = (int)strlen(s1);
			l2 = (int)strlen(s2);
			solve();
		

	}

	return 0;
}


