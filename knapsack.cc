#include <bits/stdc++.h>

using namespace std;
#define MAX 500
#define LL long long

int max(int a, int b){return a>b?a:b;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
	#endif
	
	int W,n;
	int v[MAX+1];
	int w[MAX+1];
	int mx2;

	cin>>W>>n;

	int dp[n+1][W+1];

	for (int i = 1; i <=n; ++i)
	{
		cin>>v[i]>>w[i];	
	}


	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=W; ++j)
		{
			mx2=0;
			if(i==0||j==0)
				dp[i][j]=0;
			else if(w[i]<=j)
			{	
				mx2=v[i]+dp[i-1][j-w[i]];
				dp[i][j]=max(dp[i-1][j],mx2);
			}
			else
				dp[i][j]=dp[i-1][j];	
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	cout<<dp[n][W];
	return 0;
}