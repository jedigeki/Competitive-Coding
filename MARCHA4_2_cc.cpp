#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
 
 
long modexp( long a, long n, long k )
{
 
	unsigned long  long base = (long long)a;
	unsigned long  long  mod = (long long)k;
	unsigned long long   res = (long long)1;
	while ( n > 0 )
	{
		if ( n & 1 ) // n is odd
			res = (res * base) % mod;
		n /= 2;
		base = (base * base) % mod;
	}
	return (long)res;
}
long getfk(long N, long K)
{
	long double value,ipart;
	long ans;
	value=(long double)N*log10l((long double)N);
	ans=(long)powl(10.0,(modfl(value,&ipart)+K-1));
	return ans;
 
}
int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	
	long T,N,K,fk,lk,i,j,l,a,MOD;
	float value;
	char v[200],str[204];
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%ld %ld",&N,&K);


		fk=getfk(N,K);
		printf("%ld ",fk);


		MOD=1;
		for(i=0;i<K;i++)
			MOD=MOD*10;
		lk=modexp(N,N,MOD);
		i=0;
		j=lk;
		while(j>0)
		{
		  j=j/10;
			i++;
		}
		j=K-i;
		while(j>0)
		{
			printf("0");
			j--;
		}
		if(lk!=0)
			printf("%ld\n",lk);
		else
			printf("\n");
 
	}
	return 0;
}