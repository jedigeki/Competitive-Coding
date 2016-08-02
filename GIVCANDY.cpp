/*Author:Shubham Nagaria*/
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define LL              long long
#define LD              long double
#define MAX             100005
#define INF             1000000000000000LL
#define MOD             1000000007LL
#define FOR(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CFOR(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYFOR(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCFOR(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define count_one(a)    __builtin_popcountll(a)
#define power_2(a)      (a)&(a-1)==0
#define sz(a)           int((a).size())
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define loopr(c,i)      for(typeof(c.end()) i = c.end(); i != c.begin(); )
#define UNIQUE(a)       sort(all(a)), (a).erase(unique(all(a)),(a).end())
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
 
 
template <typename T> T mod(T a, T b) {return (a < b) ? (b-a) : (a-b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
 
 
 
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
    
    int t;
    cin>>t;
    while (t--)
    {   LL a,b,c,d,gd,diff,mn;
        cin>>a>>b>>c>>d;
        if(a==b)
        {cout<<"0\n";continue;}
        if(c==d)
        {cout<<mod(a,b)<<"\n";continue;}
        diff = mod(a,b);
         LL m = c;
       LL n = d;
      
      while (n) {
          m = m % n;
          m ^= n ^= m ^= n;}
      
        gd = m;
        
        
          LL temp = diff/gd;
           LL temp2 = mod(diff,(gd*temp));
           LL temp3 = mod(diff,gd*(temp+1));
          if(temp2>temp3)
            cout<<temp3<<"\n";
          else cout<<temp2<<"\n";
    }
    return 0;
} 