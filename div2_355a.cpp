#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}

LL n, i, h,k;
LL temp, ans, rem;

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	cin>>n>>h>>k;
	REP(i,n)
	{ 
		cin>>temp;
		if(rem+temp>h)
		{
			ans += rem / k;
			rem = mod(rem,k);
			if(rem+temp > h)	
			{
				ans+=1;
				rem = temp;
			}		
			else
			{
				rem = rem + temp;
			}
 		}
		else if(rem + temp == h)
		{
			ans+= (rem+temp) / k;
			rem = mod(rem+temp,k);
		}
		else
		{
			rem = rem + temp;
		}
		
	}
	
	ans+=rem/k;
	rem = mod(rem,k);
	if(rem!=0) ans+=1;

	cout<<ans;
	return 0;

}











