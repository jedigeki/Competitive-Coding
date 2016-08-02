#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long

template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}


LL n,m,q,i;

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>n>>m>>q;
	LL arr[q][4];

	for(i=0;i<q;++i)
	{
		cin>>arr[i][0];
		if(arr[i][0] < 3 ) cin>>arr[i][1]>>arr[i][2];
		else cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
	}
	int arr[n][m] = 
	return 0;
}











