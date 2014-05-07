#include <stdio.h>
#include <stdlib.h>

struct list {
	float i;
	struct list* p;
};

void insert(struct list* a[], float n, int ind) {
	if (a[ind] == NULL) {
		struct list* temp = (struct list*) malloc (sizeof (struct list));
		temp->i = n;
		temp->p = NULL;
		a[ind] = temp;
		//printf ("%d", a[ind]);
		return;
	}
	struct list* root = a[ind];
	if (root->i > n) {
		struct list* temp = (struct list*) malloc (sizeof (struct list));
		temp->i = n;
		temp->p = root;
		a[ind] = temp;
		return;		
	}
	struct list* pre = NULL;
	while (root->p != NULL) {
		if (root->i > n) {
			struct list* temp = (struct list*) malloc (sizeof (struct list));
			temp->i = n;
			temp->p = root;
			pre->p = temp;
			return;
		}
		pre = root;
		root = root->p;
	}
	if (root->i > n) {
			struct list* temp = (struct list*) malloc (sizeof (struct list));
			temp->i = n;
			temp->p = root;
			pre->p = temp;
			return;	
	}
	struct list* temp = (struct list*) malloc (sizeof (struct list));
	temp->i = n;
	temp->p = NULL;
	root->p = temp;
	return;
}

int main() 
{	
	int n, i;
	scanf ("%d", &n);
	float arr[n];
	struct list* a[10];
	for (i = 0; i < 10; i++) {
		a[i] = NULL;
	}
	for (i = 0; i < n; i++) {
		
		scanf("%f", &arr[i]);
		int ind = arr[i] * 10;
		if (arr[i] == 1) ind = 9;
		insert (a, arr[i], ind);
 	}
 	
 	for (i = 0; i < 10; i++) {
 		if (a[i] != NULL) {
	 		struct list* root = a[i];
	 		while (root->p != NULL) {
	 			printf ("%.3f ", root->i);
	 			root = root->p;
	 		}
	 		printf ("%.3f ", root->i);
 		}
 	}
 	printf ("\n");
 	
	return 0;
}
