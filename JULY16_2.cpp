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
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define CREP1(i,n)      for(__typeof(n) i=n; i>=1; --i)
#define CREP2(i,n)      for(__typeof(n) i=n-1; i>=1; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define sz(a)           int((a).size())
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define reset(c)        (c).clear()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
 
template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((long double)a*(long double)b)/(long double)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p, m);p=mod(p*p, m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return (!b)? a:__gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template <typename T> T bitpop(T x){return __builtin_popcount (x);} 

LL sum, next,n,i,j,temp, prev, maxDiff;
char e[100005];
LL x[100005];

LL diffSum(LL l, LL r)
{
	maxDiff = 0;
	MYREP(j,l,r-1)
	{
		if(x[j+1]-x[j]>maxDiff) maxDiff = x[j+1]-x[j];
	}
	return temp- maxDiff;
}

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%lld",&n);
		scanf("%s",&e[1]);
		sum = temp = prev = 0;
		REP1(i,n)
		{
			scanf("%lld",&x[i]);
			if(e[i]=='1')
			{	
				if(prev==0)
				{
					if(i!=1)temp+= x[i] - x[i-1];
					sum+=temp;
				}
				else if(prev!=i-1)
				{
					temp+= x[i] - x[i-1];
					sum+= diffSum(prev,i);	
				}
				prev = i;
				temp = 0;
			}
			else if(e[i]=='0'&& i!=1)
				temp+= x[i] - x[i-1];
			if(e[i]=='0' && i==n)
				sum+= temp;
		}
		printf("%lld\n",sum );
	}
}








