#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             100001LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)

LL  t,n,i,mx;
LL 	sub;
LL  me[MAX];
LL 	ms2[MAX];
LL  a[MAX];

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	cin>>t;
	while(t--)
	{

		cin>>n;
		cin>>a[0];

		mx = a[0];
		sub = 0;
		me[0] = a [0];

		if(a[0]>0)
			ms2[0]  = a[0];
		else ms2[0] = 0;

		REP1(i,n-1)
		{
			cin>>a[i];
			if(a[i]>mx) mx = a[i];

			if(me[i-1]>0) me[i] = me[i-1] + a[i];
			else me[i] = a[i];


			if(a[i]<0)
			{
				ms2[i] = ms2[i-1] -sub;
				sub = ms2[i];
			}
			else
			{
				ms2[i] = ms2[i-1] + a[i];
			}

		}

		if(mx>0)
		{
			REP(i,n)
			{
				if(ms2[i] >  mx)  mx = ms2[i];
			}
		}
		cout<<mx<<endl;
	}

	return 0;
}











