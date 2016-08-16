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

char s[10005]; 

LL decd()
{
	LL l = strlen(s);
	LL a[10005];
	LL i;
 	if(l==1 && s[0]!='0') return 1;
 	else if(s[0]=='0')return 0;

 	if(s[l-1]!='0')
 	{
 		a[l-1]=1;
 		if(s[l-1]-'0' + 10*(s[l-2]-'0') < 27 && s[l-2]>'0') a[l-2] = 2;
 		else a[l-2] = 1;
 	}
 	else
 	{
 		if(s[l-2]=='1' || s[l-2]=='2') a[l-2] =1;
 		else return 0;
 	}

 	for(i=l-3;i>=0;--i)
	{
		if(s[i]=='0' && s[i+1]!='0') a[i]=a[i+1];
		else if(s[i]=='0' && s[i+1]=='0') return 0;
		else if(s[i+1]-'0' + 10*(s[i]-'0') < 27 && s[i+1]!='0' && s[i+2]!='0') a[i]= a[i+1] + a[i+2];
		else if(s[i+1]-'0' + 10*(s[i]-'0') < 27 && s[i+1]!='0' && s[i+2]=='0') a[i]= a[i+1];
		else if(s[i+1]=='0' && s[i]=='1'||s[i]=='2') a[i] = a[i+1];
		else a[i] = a[i+1];
	}
 	return a[0];
}

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	fastio;

	while(scanf("%s",s)!=EOF)
	{
		printf("%lld\n", decd() );
	}
	
	return 0;
}











