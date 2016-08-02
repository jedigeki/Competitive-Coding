#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             100005LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)


template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}

LL arr[MAX], E[MAX], S[MAX];
LL i,curr,ans, max_neg;
int t,n; 
bool flag;

void calc()
{
	REP(i,n)
	{
		curr = max(arr[i], curr + arr[i]);
		ans  = max(ans, curr);
		E[i] = curr;
	}

	curr=ans=0;

	CREP(i,n)
	{
		curr = max(arr[i], curr + arr[i]);
		ans  = max(ans, curr);
		S[i] = curr;
	} 

	REP1(i,n-2)
    	ans = max(ans, E[i-1] + S[i+1]);
}

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	scanf("%d",&t);
	while(t--)
	{
		flag = false;
		max_neg = -MOD;
		ans=curr=0;

		scanf("%d",&n);
		REP(i,n)
		{
			scanf("%lld",&arr[i]);

			max_neg = max(arr[i], max_neg);
			if(arr[i]>=0)
				flag = true;			
		}

		
		if(flag)
		{
			calc();
			cout<<ans<<endl;
		}
		else
			cout<<max_neg<<endl;
	}

	return 0;
}











