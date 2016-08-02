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

template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p, m);p=mod(p*p, m);n>>=1;}return x;}

LL i,j,ans,n,p[10];
long double kk;
int t,k; 

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;
	

	p[0]=1;
	REP1(i,9)
		p[i]=p[i-1]*10;

	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		
		cout<<setprecision(9)
		<<(LL)pow(   10,    (modf((long double)n*log10l((long double)n), &kk)+k-1)   )<<" "
		<<setfill('0')<<setw(k)
		<<power(n,n,p[k])
		<<endl;
	}

	return 0;
}











