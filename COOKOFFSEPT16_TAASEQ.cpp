#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX				100007LL
#define	REP(i,n)		for(__typeof(n)i=0;i<n;++i)
#define	REP1(i,n)		for(__typeof(n)i=0;i<n;++i)

template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
LL t,n;
LL a[MAX];
LL b[MAX];
LL ans,pt,d,i,lowest_num;
bool flag=true;
bool flag1=true;

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>t;
	while(t--)
	{
		cin>>n;
		REP(i,n)
		{
			cin>>a[i];	
		}
		if(n==2)
		{
			// cout<<"if1 "<<i<<" "<<i+2<<endl;
			cout<<min(a[0],a[1])<<endl;
		}
		else if(n==3)
		{
			// cout<<"if1 "<<i<<" "<<i+2<<endl;
			cout<<min(min(a[0],a[1]),min(a[2],a[1]))<<endl;
		}
		else
		{	

			lowest_num=a[0];
			REP(i,n-1)
			{
				lowest_num=min(lowest_num,a[i]);
				b[i]=a[i+1]-a[i];
			}
			// REP(i,n)cout<<b[i]<<" ";
			// cout<<endl;
			// cout<<"if1 "<<i<<" "<<i+2<<endl;
			REP(i,n-3)
			{
				// cout<<"if1 "<<i<<" "<<i+2<<endl;
				if(flag && b[i]==b[i+1]);
				else if(!flag && b[i+1]-b[i]==d);
				else if (flag)
				{

					flag=false;
					// cout<<"yahanx "<<i<<" "<<endl;
					d=b[i+1]+b[i+2];
					if(d==b[i]) 
					{
						// cout<<"if1 "<<i<<" "<<a[i+2]<<endl;
						ans=a[i+2];
						pt = i+2;
						i+=2;
					}
					else if(b[i+1]==b[i+2])
					{
						// cout<<"if1 "<<i<<" "<<a[i+1]<<endl;
						d=b[i+1];
						pt=i;
						ans=a[i];
						i+=1;
					}
					else
					{
						// cout<<"yahan "<<i<<" "<<endl;
						flag1 =false;
					}
				}
				else
				{
					// cout<<"yahan bhi ";
					flag1=false;
				}
			}
			// cout<<pt<<" ** "<<endl;
			if(pt!=n-3)
			{ 
				if(b[n-3]==b[n-2] && b[n-2]==b[n-4]);
				else if(b[n-2]+b[n-3]==b[n-4])
				{
					// cout<<"**"<<pt<<"**";
					d=b[n-2];
					pt=n-2;
					ans=a[n-2];
					if(flag)flag = false;
					else flag1 =false;
				}
				else if(b[n-4]==b[n-3] && b[n-1]!=b[n-2])
				{
					// cout<<pt<<" ** "<<endl;
					d=b[n-1];
					pt=n-1;
					ans=a[n-1];
					if(flag)flag = false;
					else flag1 =false;
				}
				else
				{	
					// cout<<pt<<" ** "<<endl;
					flag1=false;
				}
			}
			if(flag)
			{
				// cout<<pt<<" ** "<<endl;
				cout<<lowest_num<<endl;
			}
			else if((!flag) && flag1)
			{
				// cout<<pt<<" ** "<<endl;
				cout<<ans<<endl;
			}
			else
			{
				cout<< -1<<endl;
			}
			ans=0;
			pt=-1;
			flag1=true;
			flag=true;
		}
	}
	return 0;
}











