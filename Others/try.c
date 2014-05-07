#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
 	int n = 5;
 	int i;
 	int a[5];
 	for (i = 0; i < n; i++) {
 		scanf("%d\t", &a[i]);
 	}
 	for (i = 0; i < n; i++) {
 		printf("%d", a[i]);
 	}
	return 0;
}
