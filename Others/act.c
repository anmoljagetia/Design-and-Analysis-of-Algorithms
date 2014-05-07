#include <stdio.h>
# include <strings.h>
int main ()
{
	int n, i, a, k;
	char st[50000], res[150]= {0};
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		
		scanf("%d", &a); 
		scanf("%s", &st);
		k = strlen(st);	
		res[i] = st[k - 1];	
	}
	for (i = 0; i < n; i = n)
		printf("%s ", &res[i]);	
	printf("\n");
	return 0;
}