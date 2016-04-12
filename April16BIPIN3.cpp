#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MOD				1000000007LL

template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}

template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p, m);p=mod(p*p, m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}

LL n,t,k,ans;

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>t;
	
	while(t--)
	{
		cin>>n>>k;
			
		ans = mod(k*power(k-1,n-1,MOD),MOD) ;
		
		cout<<ans<<endl;		
	}
	return 0;
}











