#include <stdio.h>
#include <time.h>
clock_t start, end;
double cpt;
long fib(long x)
{
	if(x==1) return 0;
	if(x==2) return 1;
	else
	{
		long t=fib(x-1)+fib(x-2);
		t=t%2017;
		return t;
	}
}
int main(void) {
	long n,c;
	scanf("%ld",&n);
	start = clock();
	c=fib(n);
	end = clock();
	cpt = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%ld\n%lf",c,cpt);
	return 0;
}
