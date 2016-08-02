/*Author PRANAV MISRA*/

#include <bits/stdc++.h>
 
using                   namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             100005LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)

char a[100001];
LL i,j,k,s=0,val, ofs, ans, minn;
LL b[26];
int t,d;

LL calc(LL st)
{
    val = 0;
    for(j=st;j<s;++j)
    {
        if(b[j] - b[st] > k)
            val+= b[j] - (b[st]+ k);
    }
    return val;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
    fastio;

    cin>>t;

    while (t--)
    {   
      
        cin>>a;
        cin>>k;
        d = strlen(a);
        for(i=0;i<26;i++)
            b[i]=0;
        for(i=0;i<d;i++)
            b[a[i]-'a']++;
        for(i=0;i<26;i++)
            if(b[i]==0)b[i] = MOD;
        
        sort(b,b+26);
        s=26;
        while(b[--s]==MOD);
        // cout<<s<<endl;
        // REP(i,s+1)
        //     cout<<b[i]<< " "; 
        // cout<<endl;  
        s++;
        ans=ofs=0;
        minn = MOD;      

        REP(i,s)
        {
            ans = calc(i);
            // cout<<minn<<" "<<ofs<<" "<<ans<<" ";   
            if(ans + ofs < minn)
            {
                minn = ans+ofs;
            }
            ofs+= b[i];

        }
        cout<<minn<<endl;       
    }
    return 0;
}   