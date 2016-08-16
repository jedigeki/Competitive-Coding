#include <bits/stdc++.h>

using           		namespace std;
#define         		INF 0x3f3f3f3f
 
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
// This class represents a directed graph using 
// adjacency list representation
#define MAX2            10009

int t,n,m,k1,k2,ans;
int i,j;
int arr[MAX][MAX];
int ch[MAX][MAX];

typedef struct info
{
	int x;
	int y;
	int lev;	
}info ;

int BFS()
{
	list<info> que;
	info a;
	a.x=a.y=a.lev=0;
	que.push_back(a);
	int lev=0;
	info temp;
	ch[0][0]=1;
	while(!que.empty())
	{
		temp = que.front();
		if(temp.y!=m-1 && arr[temp.x][temp.y+1]!=1 && ch[temp.x][temp.y+1]==0)
		{	
			a.x= temp.x;
			a.y= temp.y+1;
			a.lev=  temp.lev+1;
			ch[temp.x][temp.y+1]=1;
			que.push_back(a);
		}
		if(temp.x!=0 && arr[temp.x-1][temp.y]!=1 && ch[temp.x-1][temp.y]==0)
		{	
			a.x= temp.x-1;
			a.y= temp.y;
			a.lev= temp.lev+1;
			ch[temp.x-1][temp.y]=1;
			que.push_back(a);
		}
		if(temp.y!=0 && arr[temp.x][temp.y-1]!=1 && ch[temp.x][temp.y-1]==0)
		{	
			a.x= temp.x;
			a.y= temp.y-1;
			a.lev= temp.lev+1;
			ch[temp.x][temp.y-1]=1;
			que.push_back(a);
		}
		if(temp.x!=n-1 && arr[temp.x+1][temp.y]!=1 && ch[temp.x+1][temp.y]==0)
		{	
			a.x= temp.x+1;
			a.y= temp.y;
			a.lev= temp.lev+1;
			ch[temp.x+1][temp.y]=1;
			que.push_back(a);
		}
		if(temp.y==m-1 && temp.x==0) return temp.lev;
		que.pop_front();
	}
	return INF;
};

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
    fastio;

    // create the graph given in above fugure
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;

        REP(i,n)
        {
            REP(j,m)
            {
                cin>>arr[i][j];
                ch[i][j]=0;
            }
        }

        // cout<<t+1<<endl;
        ans = BFS();
        // cout<<"ans: "<<ans<<endl;
        if(ans!=INF) 
        {
            if((k1+k2)!=0 && ans%(k1+k2)==0)
                cout<<(ans/(k1+k2))<<endl;
            else if((k1+k2)!=0)
                cout<<(ans/(k1+k2)+1)<<endl;
            else 
                cout<<-1<<endl;
        }
        else
            cout<<-1<<endl;
        // REP(i,n)
        // {
        // 	REP(j,m)
        // 	{
        // 		cout<<ch[i][j]<<" ";
        // 	}
        // 	cout<<endl;
        // }
    }
    // cout<<INF/2;
    return 0;
}
