#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long

LL t,mn,mx;
int n,q;
int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	cin>>n>>q;
	mx=0;
	mn=1000000009;

	while(n--)
	{
		cin>>t;
		if(mx<t)mx=t;
		if(mn>t)mn=t;
	}
	while(q--)
	{
		cin>>t;
		if(t>=mn && t<=mx)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}











