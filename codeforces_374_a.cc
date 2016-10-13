#include 				<bits/stdc++.h>
using 					namespace std;
int n,c,ct;
char a[100];
int g[101];

int main()
{
  	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(i!=0)
		{
			if(a[i]=='B')
			{
				if(a[i-1]=='B')ct++;
				if(a[i-1]=='W')
				{
					c++;
					ct++;
				}
			}
			else if(a[i]=='W')
			{
				if(a[i-1]=='B')
				{
					g[c]=ct;
					ct=0;
				}
			}
		}
		else
		{
			if(a[i]=='B')
			{
				c++;
				ct++;
			}
			else if(a[i]=='W')
			{

			}
		}
	}
	if(a[n-1]=='B')g[c]=ct;
	cout<<c<<endl;
	for(int i=0;i<c;++i)
	{
		cout<<g[i+1]<<" ";
	}
	return 0;
}