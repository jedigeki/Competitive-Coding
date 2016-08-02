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
 
long double ans1, factor; 
LL n,i,q,r, qt, ans2;
LL a[MAX];
 
 
 
int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;
	
	cin>>n;
	REP(i,n)
	{
		cin>>a[i];
	}
 
	cin>>q;
 	if(n>10)
	{ 		
		while(q--)
		{
			ans2=1;
			ans1=0;
			cin>>qt;
			switch(qt)
			{
				case 1:
				cin>>i>>r;
				a[i-1]=r;
				break;
	 
				case 2:
				cin>>r;
				for(i=0;i<n;i+=r)
				{
					ans2=mod((ans2*a[i]),MOD);
					if(a[i]!=0)ans1+= log10l(a[i]);
				}
			    factor=  ans1-(long double)(LL)ans1;
				ans1 = pow(10,factor);
				cout<<(int)ans1<<" "<<ans2<<endl;
				break;
			}
		}
	}
	else
	{
		while(q--)
		{
			ans1=ans2=1;
			cin>>qt;
			switch(qt)
			{
				case 1:
				cin>>i>>r;
				a[i-1]=r;
				break;
	 
				case 2:
				cin>>r;
				for(i=0;i<n;i+=r)
				{
					ans2=mod((ans2*a[i]),MOD);
					if(ans1<=1000000000000)ans1*=a[i];
					if(ans1>1000000000000)ans1/=1000000;
				}
				while(ans1>=10)
				{
					ans1/=10;
				}
				cout<<(int)ans1<<" "<<ans2<<endl;
				break;
			}
		}
	}
 	return 0;
}
  