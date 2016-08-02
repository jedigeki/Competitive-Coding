#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             1000000
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define CREP1(i,n)      for(__typeof(n) i=n; i>=1; --i)
#define CREP2(i,n)      for(__typeof(n) i=n-1; i>=1; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)


int temp, cnt, cnt2;
int sv[MAX+1]; 
int cf[1000001];
int j;

void pre()
{
	cnt2 = 2;
	MYREP(i,1,MAX)
		sv[i]=0;

	sv[1] = -1; //code for !prime and cube free
	cf[1] = 1;
	MYREP(i,2,MAX)
	{
		if(sv[i]==0)
		{
			for (j = 2*i; j>0 && j<=MAX; j+=i)
			{
					if(sv[j]!=-3)
					{
						sv[j]=-1;//code for not prime
						cnt = 0;
						temp = j;
						while(temp % i==0)
						{
							temp/=i;
							cnt++;
						}
						if(cnt>=3)
						{
							sv[j]=-3;//code for non-cube free
						}
						else 
							sv[j]=-1;
					}
			}
		}
		if(sv[i]==0||sv[i]==-1)
		{	
			cf[i] = cnt2++; 
	 	}
	 	else
	 	{
	 		cf[i] = 0;
	 	}

	}

} 

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;
	
	pre();

	int t;
	int n;

	cin>>t;
	REP1(i,t)
	{
		cin>>n;
		if(cf[n])
			cout<<"Case "<<i<<": "<< cf[n]<<endl;
		else
			cout<<"Case "<<i<<": "<< "Not Cube Free"<<endl;
	}
}











