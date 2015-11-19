#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int f(int a);
int g(int b);
int main(){
	int i,j,k;
	i=5;
	j=9;
	k=f(i)*g(j);
	printf("%d",k);
	return 0;
	}
