#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)

template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}

LL r[3],t,ans,small,middle,large,k;

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>t;
	
	REP1(j,t)
	{
		cin>>r[0]>>r[1]>>r[2];
		cin>>k;
	 	sort(r,r+3);
	 	small=r[0];
	 	middle=r[1];
	 	large=r[2];

		if(k<=small)
			ans = 3*(k-1)+1; 
		else if (k>small && k<=middle)
			ans = 3*small + 2*(k-small-1) +1;
		else ans = 3*small + 2*(middle-small) + (k-middle); 	
		
		cout<<ans<<endl;		
	}
	return 0;
}











