#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             10005LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define CREP1(i,n)      for(__typeof(n) i=n; i>=1; --i)


int curr,i,ans, n;
int a[MAX];
int b[MAX];
int temp[MAX];

int result()
{
	REP1(i,n-1)
	{	
		if(i!=n-1)
		{
			if(temp[i-1]==0)
			{
				if(a[i]>curr) break;
				else if(b[i-1]+a[i] == curr)
					{temp[i-1]=1;continue;}
				else if(b[i-1]+a[i] + b[i]== curr && temp[i]==0)
					{temp[i-1]=temp[i]=1;continue;}				
				else if(b[i-1]+a[i] +b[i+1]+ b[i]== curr && temp[i]==0)
					{temp[i-1]=temp[i]=temp[i+1]=1;continue;}
				else if(b[i-1]+a[i] +b[i+1]== curr)
					{temp[i-1]=temp[i+1]=1;continue;}
				else break;
			}
			else
			{
				if(a[i]>curr) break;
				else if(a[i] + b[i]== curr && temp[i]==0)
					{temp[i]=1;continue;}
				else if(a[i] + b[i+1]== curr)
					{temp[i+1]=1;continue;}
				else if(a[i] +b[i+1]+ b[i]== curr && temp[i]==0 )
					{temp[i]=temp[i+1]=1;continue;}
				else if(a[i]==curr)continue;
				else break;
			}	
		}	
		else 
		{
			if(temp[i-1]==0 && temp[i]==0 && a[i]+b[i-1]+b[i]==curr)
				{ return curr;}
			if(temp[i-1]==0 && temp[i]==1 && a[i]+b[i-1]==curr) 
				{ return curr;}
			if(temp[i-1]==1 && temp[i]==0 && a[i]+b[i]==curr) 
				{ return curr;}
			if(temp[i-1]==1 && temp[i]==1 && a[i]==curr) 
				{ return curr;}
		}		
	}
	return -1;
}
 
int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		REP(i,n)
		{
			cin>>b[i];
		}
		REP(i,n)
		{
			cin>>a[i];
		}
		if(n==1) cout<<a[0]+b[0]<<endl;
		else 
		{	
			REP(i,n+1)temp[i]=0;
			curr = a[0]; 
			ans = result();
			if(ans!=-1)
			{cout<<ans<<endl; continue;}

			REP(i,n+1)temp[i]=0;
			curr = a[0]+b[1]; 
			temp[1]=1;
			ans = result();
			if(ans!=-1)
			{cout<<ans<<endl; continue;}

			REP(i,n+1)temp[i]=0;
			curr = a[0]+b[0]; 
			temp[0]=1;
			ans = result();
			if(ans!=-1)
			{cout<<ans<<endl; continue;}

			REP(i,n+1)temp[i]=0;
			curr = a[0]+b[1]+ b[0]; 
			temp[1]=temp[0]=1;
			cout<<result()<<endl;
		}
	}
}








