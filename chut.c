#include <stdio.h>
int fact(int n){
	return n<=1?1:n*fact(n-1);
}
int main(){
	int i = fact(10);
	printf("%d\n", i);
	return 0;
}