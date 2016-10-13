#include 				<bits/stdc++.h>
#include    			<algorithm>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define LL				long long
#define MAX				10000009LL
#define	REP(i,n)		for(__typeof(n) i=0; i<n;++i)
#define	REP1(i,n)		for(__typeof(n) i=1; i<=n;++i)

template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}

LL n;
typedef struct dim{LL l,w;} dim;
typedef struct line{LL m, c, sp;}line;
vector<dim> v;
LL max_l,max_w;
LL area_i,j,cost,t_cost, tmax_l, tmax_w;
bool flag;
bool compareByLength(const dim &a, const dim &b){return a.l < b.l;}
class compareBySlope{ public: bool operator()(const line &a, const line &b){return a.sp < b.sp;}};
priority_queue<line,vector<line>,compareBySlope> E;

LL intersection_with_prev_line(LL m1, LL m2, LL c1, LL c2)
{
	return (c1-c2)/((m2-m1));
}

LL query(LL pt)
{
	
}

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>n;
	LL t = n;
	dim a;
	while(t--)
	{	
		cin>>a.l>>a.w;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), compareByLength);

	//removing redundant rectangles
	REP(i,v.size()-1)
	{
		if(v[i].w<v[i+1].w)
		{
			v.erase(v.begin()+i);
			i--;
		}
	}

	// // brute force solution
	// n=v.size();
	// LL cost[n+1];
	// cost[0]=0;
	// REP1(i,n)
	// {
	// 	cost[i]= 2147483647;
	// 	REP(j,i)
	// 	{
	// 		// cout<<cost[j]<<" ";
	// 		cost[i]=min(cost[i],cost[j]+v[i-1].l*v[j].w);
	// 	}
	// 	// cout<<endl<<cost[i]<<" kk "<<endl;
	// }

	// let E = empty lower envelope structure
	
	LL cost[n+1];
	cost[0]=0;

	line t_line;
	t_line.m=v[0].w;
	t_line.c=cost[0];
	t_line.sp=0;
	E.push(t_line);

	REP1(i,n)
	{
	    // cost[i] = query(rect[i-1].h);//what to do here????
		if(i<n-1)
		{
			t_line.m=v[i].w;
			t_line.c=cost[i];
			t_line.sp= intersection_with_prev_line(v[i-1].w, v[i].w, cost[i-1],cost[i]);
          	E.push(t_line);
		}
	}
	cout<<cost[n];
	return 0;
}













				
