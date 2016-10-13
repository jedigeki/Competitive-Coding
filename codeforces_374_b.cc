#include 				<bits/stdc++.h>
using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             1237LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)


int n,k,m,p_len,c,i;
int v[107];
int a[107];
int b[107];
char str[107];
int b_time,w_time,tries_before_halt;
int main()
{
  	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	cin>>n>>k;

	REP(i,107)
	{
		v[i]=9999;
		a[i]=999;
		b[i]=999;
	}

	REP(i,n)
	{
		cin>>str;
		m = strlen(str);
		if(v[m]==9999)
		{
			v[m]=0;
		}
		v[m]++;
	}
	cin>>str;
	p_len=strlen(str);

	c=0;
	m=101;
	REP(i,m)
	{
		if(v[i]!=9999)
		{
			a[c]=i;
			b[c]=v[i];
			c++;
		}
	}

	i=0;
	while(a[i]<=p_len)
	{
		if(a[i]!=p_len)
		{
			while(b[i]!=0)
			{
				if(tries_before_halt<k)
				{
					b_time+=1;
					tries_before_halt++;
				    b[i]--;
				}
				else
				{
					b_time+=5;
					tries_before_halt=0;
				}
			}
		}
		else
		{
			if(tries_before_halt==k)
				b_time+=k;
			w_time=b_time;
			b_time+=1;
			// cout<<tries_before_halt<<" ";
			while(b[i]!=0)
			{
				if(tries_before_halt<k)
				{
					w_time+=1;
					tries_before_halt++;
					b[i]--;
				}
				else
				{
					w_time+=5;
					tries_before_halt=0;
				}
			}
		}
		i++;
	}
	cout<<b_time<<" "<<w_time;
	return 0;
}










