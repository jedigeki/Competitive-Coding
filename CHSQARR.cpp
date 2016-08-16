#include 				<bits/stdc++.h>
 
using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             100005LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)

 
template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
template <typename T> T signedMod(T a, T b){return a<0? (b+a%b) : a<b?a:a%b;}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((long double)a*(long double)b)/(long double)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p, m);p=mod(p*p, m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));} 

LL n,m,q, x,y,i,j,k,ii, jj;
LL mn, temp;
LL a[1005][1005];
LL cnt, prev;

void getTemp()
{
	k=1;
	cnt=0;
	prev=a[i][j];
	temp = 0;
	for(ii=i;ii<=i+x-1;++ii)
	{
		for(jj=j;jj<=j+y-1;++jj)
		{
			
			if(a[ii][jj]>prev)
			{
				temp+= (cnt*(a[ii][jj]-prev));
				prev = a[ii][jj];
				cnt++;
			}
			else
			{				
				temp+= (prev-a[ii][jj]);
				cnt++;
			}
			k++;
		}
	}	
	k--;
}
 
void ans()
{
	mn=1000000000009;
	if(x==1&&y==1) 
	{
		cout<<0<<endl;
		return;
	}
	for(i=1;i<=n-x+1;++i)
	{
		for(j=1;j<=m-y+1;++j)
		{
			getTemp(); 
			if(temp<mn) mn =temp;
			if(mn==0)break;
		}
		if(mn==0)break;
	}
	cout<<mn<<endl;
}

 
int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;
	
	cin>>n>>m;
	REP1(i,n)
	{
		REP1(j,m)
		{
			cin>>a[i][j];
		}
	}

	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		ans();
	}
 	return 0;
}









