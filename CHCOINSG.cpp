#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long

LL t,n,i,j,k=0,ans;
LL p[100000],l[100000];
void pre()
{
	p[0]=1;
	p[1]=1;	
	for (i = 2; i <100000 ; ++i)
	{
		if(p[i]==0)
		{
			for(j=2*i; j<100000; j+=i)
			{
				p[j]=1;
			}
			k++;
			l[k]=i;
		}
	}

}
int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	pre();

	cin>>t;
	
	while(t--)
	{
		cin>>n;
		ans=0;
		l[100000]=n;
		for(i=1;i<=k && l[i]<=n;++i)
		{
			j=0;
			if(n%l[i]==0)
			{
				while(n%l[i]==0)
				{
					j++;
					n/=l[i];
				}
			}
			ans= ans^j; 
		}
		if(ans || l[100000]==1)cout<<"Chef"<<endl;
		else cout<<"Misha"<<endl;
	}
	return 0;
}











