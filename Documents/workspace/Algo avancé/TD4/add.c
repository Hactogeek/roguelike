#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
	return a+b;
	}
	
void main(void){
	int a,b,c=0;
	scanf("%i",&a);
	scanf("%i",&b);
	c=add(a,b);
	printf("%i",c);
	
}
