#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
	#endif

	int n;
	cin>>n;
	int b[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
	}

	int m;
	cin>>m;
	int g[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>g[i];
	}

	sort(b,b+n);
	sort(g,g+m);
	for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < m; ++i)
	{
		cout<<g[i]<<" ";
	}

	return 0;
}













