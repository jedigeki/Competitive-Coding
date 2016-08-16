// Program to find Dijkstra's shortest path using STL set
#include        <bits/stdc++.h>
using           namespace std;
#define         INF 0x3f3f3f3f
 
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
int t,n,m,k1,k2,V,ans;
int i,j;
int arr[MAX][MAX];

class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex 
    // and weight pair for every edge
    list< pair<int, int> > *adj;
 
    public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // prints shortest path from s
    int shortestPath(int s);

};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest paths from src to all other vertices
int Graph::shortestPath(int src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, int> > setds;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till all shortest distance are finalized then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            // int weight = (*i).second;
            int weight = 1;
 
            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {

                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist[m-1];
}

// Driver program to test methods of graph class
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
        V=n*m;
        Graph g(V);

        REP(i,n)
        {
            REP(j,m)
            {
                cin>>arr[i][j];
            }
        }

        REP(i,n)
        {
            REP(j,m)
            {
                if(arr[i][j]==0)
                {
                    if(i!=n-1 && arr[i+1][j]==0)
                    {
                        g.addEdge(i*m+j, (i+1)*m +j, 1);
                    }
                    if(j!=m-1 && arr[i][j+1]==0)
                    {
                        g.addEdge(i*m+j,i*m+j+1,1);
                    }
                }   
            }
        }
        ans = g.shortestPath(0);
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

    }
 
    return 0;
}