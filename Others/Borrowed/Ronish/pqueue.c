#include <stdio.h>

struct pqueue {
	int a[20];
	void (*insert)(struct pqueue*, int);
	void (*update)(struct pqueue*, int, int);
	void (*heapitdown)(struct pqueue*, int); 
	int size;
};

void heapit(struct pqueue* q, int size) {
	if (size == 0) return;
	else {
		if (q->a[size] > q->a[(size - 1) / 2]) {
			int temp = q->a[size];
			q->a[size] = q->a[(size - 1) / 2];
			q->a[(size - 1) / 2] = temp;
			heapit(q, (size - 1) / 2);
		}
	}
	return;
}

void insert (struct pqueue* q, int n) {
	q->a[q->size] = n;
	q->size++;
	heapit(q, q->size - 1);	
}

void heapitdown(struct pqueue* q, int size) {
	int l = 2 * size - 1;
	int r = 2 * size;
	if (l > q->size - 1) return;
	else if (r > q->size - 1) { 
		if (q->a[r] > q->a[size]) {
			int temp = q->a[r];
			q->a[size] = q->a[r];
			q->a[r] = temp;
			return;
		}
	}
	
	if (q->a[l] > q->a[size]) {
		int temp = q->a[l];
		q->a[size] = q->a[l];
		q->a[l] = temp;
		heapitdown(q, l);
	}
	else if (q->a[r] > q->a[size]) {
		int temp = q->a[r];
		q->a[size] = q->a[r];
		q->a[r] = temp;
		heapitdown(q, r);
	}
	return;
}

void update (struct pqueue* q, int i, int key) {
	if (q->a[i] < key) {
		q->a[i] = key;
		heapit(q, i);
	}
}

int main() {
	
	struct pqueue q;
	q.size = 0;
	q.insert = &insert;
	q.update = &update;
	q.heapitdown = &heapitdown;
	char c = 'a';
	int n;
	
	printf ("Press i to insert followed by your number\n");
	printf ("Press u to update followed by index followed by number\n");
	printf ("Press m to get max\n");
	printf ("Press e to extract max\n");
	printf ("Press o to exit\n");
	
	while (c != 'o') {
	scanf("%c", &c);
	
		if (c == 'i') {
		
			scanf("%d", &n);
			q.insert(&q, n);
		
		} else if (c == 'u') {
			
			int i, j;
			scanf("%d%d",&i, &j);
			q.update(&q, i, j);
			
		} else if (c == 'm') {
		
			printf ("%d\n", q.a[0]);
	
		} else if (c == 'e') {
		
			printf("%d\n", q.a[0]);
			q.a[0] = q.a[q.size - 1];
			q.size--;
			q.heapitdown(&q, 0);
			
		}
	
	}
	
	return 0;
	
}
