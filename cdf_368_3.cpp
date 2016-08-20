#include <bits/stdc++.h>
using namespace std;
int x,m;
int main()
{

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif

	cin>>x;
	if(x==1||x==2){cout<<-1;return 0;}
	if(x&1)
	{
		m = (x*x-1)/2;
		cout<<m<<" "<<m+1;

	}
	else
	{	
		m = (x*x)/2;
		cout<<m-1<<" "<<m+1;
	}
}