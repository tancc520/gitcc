#include <stdio.h>
int main() {
	int num,a;
	scanf("%d",&num);
	do{
		a=num%10;
		printf("%d",a);
		num=num/10;
	}
	while(num!=0);
	printf("\n");
	return 0;


}