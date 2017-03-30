#include <bits/stdc++.h>
using namespace std;
#define MAX 100008
#define LL long long

int main(){

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	int t,n;
	cin>>t;
	LL a[MAX];
	while(t--)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}

		sort(a,a+n);

		if(!(a[n-1]==a[n-2]+1))
		{
			cout<<a[n-1]<<endl; 
		}
		else{
			for (int i = 0; i < n-1; ++i)
			{
				if(!(a[i]==a[i+1]-1))
				{
					cout<<a[i]<<endl;
					break;
				}
			}			
		}

	}


	return 0;
}