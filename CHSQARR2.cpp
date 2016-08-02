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
 
template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
 
LL n,m,q, x,y,i,j,k,l,an,aa,bb;
LL mn, temp;
LL a[1005][1005];
LL M[10][10][1005][1005];
LL sum[1005][1005];

void SparseMatrix()
{
    for (int i = 0 ; (1<<i) < n+1; i += 1){
        for(int j = 0 ; (1<<j) < m+1; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)
                        M[i][j][x][y] = a[x][y]; // store x, y
                    else if (i == 0)
                        M[i][j][x][y]= max(M[i][j-1][x][y], M[i][j-1][x][y+(1<<(j-1))]);
                    else if (j == 0)
                        M[i][j][x][y]= max(M[i-1][j][x][y], M[i-1][j][x+ (1<<(i-1))][y]);
                    else 
                       M[i][j][x][y] = max(max(M[i-1][j-1][x][y], M[i-1][j-1][x + (1<<(i-1))][y]),max(M[i-1][j-1][x][y+(1<<(j-1))], M[i-1][j-1][x + (1<<(i-1))][y+(1<<(j-1))]));
                }
            }
        }
    }
}

LL RMQ(int x, int y){
     // k = log2(x1 - x + 1);
     // l = log2(y1 - y + 1);
    // cout << "Value of k="<<k<<" l="<<l<<endl;
    an = max(max(M[k][l][x][y], M[k][l][x+aa-(1<<k)][y]), max(M[k][l][x][y+bb-(1<<l)], M[k][l][x+aa-(1<<k)][y+bb- (1<<l)]));
    return an;
}                  

void ans()
{
	mn=1000000000009;
	if(x==1&&y==1) 
	{
		cout<<0<<endl;
		return;
	}
	REP(i,n-x+1)
	{
		REP(j,m-y+1)
		{
			temp =  x*y*RMQ(i,j)- sum[i+x-1][j+y-1]; 

			if(i-1>=0&&j-1>=0)temp-=sum[i-1][j-1];
			if(j-1>=0)temp+=sum[i+x-1][j-1];
			if(i-1>=0)temp+=sum[i-1][j+y-1];
			mn = min(temp,mn);
			temp = 0;
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
	REP(i,n)
	{
		REP(j,m)
		{
			cin>>a[i][j];
			sum[i][j] = a[i][j];
			if(i-1>=0&&j-1>=0)sum[i][j]-=sum[i-1][j-1];
			if(j-1>=0)sum[i][j]+=sum[i][j-1];
			if(i-1>=0)sum[i][j]+=sum[i-1][j];
		}
	}
 	
 	SparseMatrix();

	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		k=log2(x);
		l=log2(y);
		aa=x;
		bb=y;
		ans();
	}

 	return 0;
} 