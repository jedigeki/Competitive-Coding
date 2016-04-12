#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define LL              long long

LL n,i, b ,p , n1, n2,tow, k=0,bt;

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	string s;
	getline(cin,s);
	n = s.length();
	k=0;
	for (i = 0; i < n; ++i)
	{
		if(s[i]=='0'||s[i]=='4'||s[i]=='8')++k;
		if(i>=1)
		{
			if(s[i]=='0') if(s[i-1]=='0'||s[i-1]=='2'||s[i-1]=='4'||s[i-1]=='6'||s[i-1]=='8')k+=i;
			if(s[i]=='2') if(s[i-1]=='1'||s[i-1]=='3'||s[i-1]=='5'||s[i-1]=='7'||s[i-1]=='9')k+=i;
			if(s[i]=='4') if(s[i-1]=='0'||s[i-1]=='2'||s[i-1]=='4'||s[i-1]=='6'||s[i-1]=='8')k+=i;
			if(s[i]=='6') if(s[i-1]=='1'||s[i-1]=='3'||s[i-1]=='5'||s[i-1]=='7'||s[i-1]=='9')k+=i;
			if(s[i]=='8') if(s[i-1]=='0'||s[i-1]=='2'||s[i-1]=='4'||s[i-1]=='6'||s[i-1]=='8')k+=i;
		}
	}
	cout<<k;
}











