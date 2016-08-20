#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             100009LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define CREP1(i,n)      for(__typeof(n) i=n; i>=1; --i)
#define CREP2(i,n)      for(__typeof(n) i=n-1; i>=1; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)

int n,m,k;
LL u,v,ww;
LL fk[MAX];
LL ss[MAX];
LL ans=-1;
vector<LL> a[MAX];
vector<LL> w[MAX];


void doShit(int s)
{
	int sz= a[s].size();
	REP(i,sz)
	{
		if(ss[a[s][i]]==-1)
		{
			if(ans!=-1)
			{
				if(ans>w[s][i])ans=w[s][i];
			}
			else
				ans = w[s][i];
		}

	}
}

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>n>>m>>k;

	REP(i,m)
	{
		cin>>u;
		cin>>v;
		cin>>ww;
		a[u].push_back(v);
		a[v].push_back(u);
		w[u].push_back(ww);
		w[v].push_back(ww);
	}

	if(k==0||k==n)
	{
		cout<<-1;
		return 0;
	}

	REP(i,k)
	{
		cin>>fk[i];
		ss[fk[i]] = -1;
	}

	REP1(i,n)
	{
		if(ss[i]!=-1)
			doShit(i);
	}
	cout<<ans<<endl;
	
	return 0;
}










