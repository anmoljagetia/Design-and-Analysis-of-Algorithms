#include <stdio.h>
#include <malloc.h>

struct node
{
	int n;
	struct node *next;
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int n;
	printf("HELLO WORLD!\n");
	printf("HELLO WORLD!\n");
	scanf("%d",&n);
	scanf("%d",&n);
	scanf("%d",&n);
	scanf("%d",&n);
	printf("Entered number : %d\n", n);
	struct node *p;
	p = (struct node *) malloc(sizeof(struct node *));
	
	return 0;

}

