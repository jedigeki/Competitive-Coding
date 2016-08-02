#include <bits/stdc++.h>
using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)

#define LL long long

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	int t;
	cin>>t;
	int marks[100005];
	int n,tt,sum;
	bool flag1;
	bool flag2;

	while(t--)
	{
		cin>>tt;
		sum=0;
		flag1=true;
		flag2=false;

		for(n=0;n<tt;++n)
		{
			cin>>marks[n];
			if(marks[n]<=2)
			{
				flag1=false;
			}
			else
			{
				sum+=marks[n];
			}
			if(marks[n]==5) flag2 = true;
		}
		if(flag1 && flag2 && (sum/tt)>=4 )cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
	return 0;
}
