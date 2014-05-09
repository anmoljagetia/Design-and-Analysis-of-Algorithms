#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//structure of a tree node
struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

//recursive in-order walk of the BST
//it is in the format L-N-R
//also known as tree sort
void inorderWalk (struct node * head)
{
	if (head != NULL) {
		inorderWalk(head->lchild);
		cout << head->data << "\t";
		inorderWalk(head->rchild);
	}
}

//recursive pre-order walk of the BST
//it is in the format N-L-R
void preorderWalk (struct node * head)
{
	if (head != NULL) {
		cout << head->data << "\t";
		preorderWalk(head->lchild);
		preorderWalk(head->rchild);
	}
}

//recursive post-order walk of the BST
//it is in the format l-R-N
void postorderWalk (struct node * head)
{
	if (head != NULL) {
		postorderWalk(head->lchild);
		postorderWalk(head->rchild);
		cout << head->data << "\t";
	}
}

//iterative way to find the minimum element in the BST
void min (struct node *head)
{
	while (head->lchild != NULL) {
		head = head->lchild;
	}
	cout << head->data << endl;
}

//recursive way to find the minimum element in the BST
struct node *minimum (struct node *head)
{
	if(head->lchild == NULL) {
		cout << head->data << endl;
		return head;
	}
	else {
		minimum (head->lchild);
	}
}

//iterative way of find the maximum element in the BST
void max (struct node *head)
{
	while (head->rchild != NULL) {
		head = head->rchild;
	}
	cout << head->data << endl;
}
//recursive way to find the maximum element in the BST
void maximum (struct node *head)
{
	if(head->rchild == NULL) {
		cout << head->data << endl;
	} else {
		maximum (head->rchild);
	}
}
//recursive approach to find an element in the BST
struct node *search (struct node *head, int key)
{
	if (head == NULL) {
		cout << "Not Found" << endl;
		return head;
	}	
	if (head->data == key) {
		cout << "Found" << endl;
		return head;
	}
	else if (key < head->data) {
		return search(head->lchild, key);
	}
	else {
		return search(head->rchild, key);
	}
}

//Generating a new node for the BST
struct node *newNode (int key)
{
	struct node *temp;
	temp = (struct node *) malloc (sizeof (struct node *));
	temp->lchild = NULL;
	temp->rchild = NULL;
	temp->data = key;
	return temp;
}

struct node *insert (struct node *head, int key)
{
	struct node *temp;
	if (key < head->data) {
		if(head->lchild == NULL) {
			temp = newNode(key);
			head->lchild = temp;
		} else {
			insert(head->lchild, key);
		}
	}

	if (key >= head->data) {
		if(head->rchild == NULL) {
			temp = newNode(key);
			head->rchild = temp;
		} else {
			insert(head->rchild, key);
		}
	}
	return head;
}

struct node *deleteNode (struct node *head, int key)
{
	if (head == NULL) {
		return head;
	}
	if (key < head->data) {
	 	head->lchild = deleteNode(head->lchild, key);
	 }
	else if (key > head->data) {
	 	head->rchild = deleteNode(head->rchild, key);
	 }
	 //when the key to be deleted is equal to the node we currently are on
	else {
		//case where the tree only has right subtree
		if(head->lchild == NULL) {
			struct node *temp;
			temp = head->rchild;
			free(head);
			return temp;
		}
		//case where the tree only has left subtree
		else if(head->rchild == NULL) {
			struct node *temp;
			temp = head->lchild;
			free(head);
			return temp;
		}
		// when there are both right and left subtrees
        // Copy the inorder successor's content to this node
        // Delete the inorder successor
        struct node* temp = minimum(head->rchild);
        head->data = temp->data;
        head->rchild = deleteNode(head->rchild, temp->data);
	}
	return head;
}


int main(int argc, char const *argv[])
{
	struct node *head;
	head = (struct node *) malloc (sizeof (struct node *));
	head->lchild = NULL;
	head->rchild = NULL;
	head->data = 4;
	head = insert(head, 2);
	head = insert(head, 6);
	head = insert(head, 1);
	head = insert(head, 3);
	/*	The Sample BST that we have created in this example
	*					4
	*			2				6
	*		1		3
	*/	
	search(head, 4);
	search(head, 9);
	
	inorderWalk(head);
	cout << endl;

	preorderWalk(head);
	cout << endl;
	
	postorderWalk(head);
	cout << endl;
	
	min(head);
	minimum(head);

	max(head);
	maximum(head);

	head = deleteNode(head, 2);
	inorderWalk(head);

	return 0;
}