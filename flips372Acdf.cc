#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define LL long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
	#endif

	LL n;
	LL a[MAX],b[MAX],c[MAX];
	cin>>n;
	for (LL i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	b[0]=a[0];
	c[n]=0;
	for(LL i = 1; i < n; ++i)
	{
		b[i] = b[i-1] + a[i];
		c[n-i] = c[n-i+1] + a[n-i];
	}
	c[0]=c[1]+a[0];

	for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;


	int i=0,j=n-1,cnt=0;
	while(i<j)
	{
		if(b[i]<c[j])
		{
			i++;
		}
		else if(c[j] < b[i])
		{
			j--;
		}
		else
		{
			cout<<i<<" "<<j<<endl;
			cnt++;
			j--;
		}
	}
	cout<<cnt;
	return 0;
}













