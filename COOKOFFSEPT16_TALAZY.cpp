#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long

LL t,n,b,m;
LL break_minutes, work_minutes;

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
		cin>>n>>b>>m;
		while(n!=1 )
		{
			if(n&1)
			{
				work_minutes+=(n+1)/2*m + b;
				n=n-(n+1)/2;
			}
			else
			{
				n= (n/2);
				work_minutes+=(n*m + b);
			}			
			m*=2;			
		}
		work_minutes+=m;
		cout<<work_minutes<<endl;
		work_minutes=0;
	}
	return 0;
}











