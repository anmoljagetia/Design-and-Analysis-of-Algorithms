#include <iostream>
using namespace std;

// A generic tree node class
class Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node() { key=-1; left=NULL; right=NULL; parent = NULL;};
    void setKey(int aKey) { key = aKey; };
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    void setParent(Node* aParent) { parent = aParent; };
    int Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
    Node* Parent() { return parent; };
};

// Binary Search Tree class
class Tree {
    Node* root;
public:
    Tree();
    ~Tree();
    Node* Root() { return root; };
    void addNode(int key);
    Node* findNode(int key, Node* parent);
    void walk(Node* node);
    void deleteNode(int key);
    Node* min(Node* node);
    Node* max(Node* node);
    Node* successor(int key, Node* parent);
    Node* predecessor(int key, Node* parent);
private:
    void addNode(int key, Node* leaf);
    void freeNode(Node* leaf);
};

// Constructor
Tree::Tree() {
    root = NULL;
}

// Destructor
Tree::~Tree() {
    freeNode(root);
}

// Free the node
void Tree::freeNode(Node* leaf)
{
    if ( leaf != NULL ) 
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
    }
}

// Add a node [O(height of tree) on average]
void Tree::addNode(int key)
{
    // No elements. Add the root
    if ( root == NULL ) {
        cout << "add root node ... " << key << endl;
        Node* n = new Node();
        n->setKey(key);
    root = n;
    }
    else {
    cout << "add other node ... " << key << endl;
    addNode(key, root);
    }
}

// Add a node (private)
void Tree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() )
    {
        if ( leaf->Left() != NULL )
            addNode(key, leaf->Left());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != NULL )
            addNode(key, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Find a node [O(height of tree) on average]
Node* Tree::findNode(int key, Node* node)
{
    if ( node == NULL )
        return NULL;
    else if ( node->Key() == key )
        return node;
    else if ( key <= node->Key() )
        findNode(key, node->Left());
    else if ( key > node->Key() )
        findNode(key, node->Right());
    else
        return NULL;
}

// Print the tree
void Tree::walk(Node* node)
{
    if ( node )
    {
        cout << node->Key() << " ";
        walk(node->Left());
        walk(node->Right());
    }
}

// Find the node with min key
// Traverse the left sub-tree recursively
// till left sub-tree is empty to get min
Node* Tree::min(Node* node)
{
    if ( node == NULL )
        return NULL;

    if ( node->Left() )
        min(node->Left());
    else
        return node;
}

// Find the node with max key
// Traverse the right sub-tree recursively
// till right sub-tree is empty to get max
Node* Tree::max(Node* node)
{
    if ( node == NULL )
        return NULL;

    if ( node->Right() )
        max(node->Right());
    else
        return node;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-tree to get the successor
Node* Tree::successor(int key, Node *node)
{
    Node* thisKey = findNode(key, node);
    if ( thisKey )
        return min(thisKey->Right());
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-tree to get the predecessor
Node* Tree::predecessor(int key, Node *node)
{
    Node* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Left());
}

// Delete a node
// (1) If leaf just delete
// (2) If only one child delete this node and replace
// with the child
// (3) If 2 children. Find the predecessor (or successor).
// Delete the predecessor (or successor). Replace the
// node to be deleted with the predecessor (or successor).
void Tree::deleteNode(int key)
{
    // Find the node.
    Node* thisKey = findNode(key, root);

    // (1)
    if ( thisKey->Left() == NULL && thisKey->Right() == NULL )
    {
        if ( thisKey->Key() > thisKey->Parent()->Key() )
            thisKey->Parent()->setRight(NULL);
        else
            thisKey->Parent()->setLeft(NULL);

        delete thisKey;
    }

    // (2)
    if ( thisKey->Left() == NULL && thisKey->Right() != NULL )
    {
        if ( thisKey->Key() > thisKey->Parent()->Key() )
            thisKey->Parent()->setRight(thisKey->Right());
        else
            thisKey->Parent()->setLeft(thisKey->Right());

        delete thisKey;
    }
    if ( thisKey->Left() != NULL && thisKey->Right() == NULL )
    {
        if ( thisKey->Key() > thisKey->Parent()->Key() )
            thisKey->Parent()->setRight(thisKey->Left());
        else
            thisKey->Parent()->setLeft(thisKey->Left());

        delete thisKey;
    }

    // (3)
    if ( thisKey->Left() != NULL && thisKey->Right() != NULL )
    {
        Node* sub = predecessor(thisKey->Key(), thisKey);
        if ( sub == NULL )
            sub = successor(thisKey->Key(), thisKey);        

        if ( sub->Parent()->Key() <= sub->Key() )
            sub->Parent()->setRight(sub->Right());
        else
            sub->Parent()->setLeft(sub->Left());

        thisKey->setKey(sub->Key());
        delete sub;
    }
}

// Test main program
int main() {
    Tree* tree = new Tree();

    // Add nodes
    tree->addNode(300);
    tree->addNode(100);
    tree->addNode(200);
    tree->addNode(400);
    tree->addNode(500);

    // Traverse the tree
    tree->walk(tree->Root());
    cout << endl;

    // Find nodes
    if ( tree->findNode(500, tree->Root()) )
        cout << "Node 500 found" << endl;
    else
        cout << "Node 500 not found" << endl;

    if ( tree->findNode(600, tree->Root()) )
        cout << "Node 600 found" << endl;
    else
        cout << "Node 600 not found" << endl;

    // Min & Max
    cout << "Min=" << tree->min(tree->Root())->Key() << endl;
    cout << "Max=" << tree->max(tree->Root())->Key() << endl;

    // Successor and Predecessor
    cout << "Successor to 300=" <<
            tree->successor(300, tree->Root())->Key() << endl;
    cout << "Predecessor to 300=" <<
            tree->predecessor(300, tree->Root())->Key() << endl;

    // Delete a node
    tree->deleteNode(300);

    // Traverse the tree
    tree->walk(tree->Root());
    cout << endl;

    delete tree;
    return 0;
}