#include <stdio.h>
#include <time.h>
clock_t start, end;
double cpt;
int main(void) {
	long n,a,b,c,i;
	scanf("%ld",&n);
	start = clock();
	a=0;
	b=1;
	for(i=3;i<=n;i++)
	{
		c=a+b;
		c=c%2017;
		a=b;
		b=c;
	}
	end = clock();
	cpt = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%ld\n%lf",c,cpt);
	return 0;
}
