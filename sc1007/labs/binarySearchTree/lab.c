//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);
	printf("\n");

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
    if (*node == NULL) {
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
    }

    if (value < (*node)->item) {
        insertBSTNode(&((*node)->left), value);
    } else if (value > (*node)->item) {
        insertBSTNode(&((*node)->right), value);
    } else {
		printf("Node already exists.\n");
		return;
	}
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	if (node == NULL)
        return;

    printBSTInOrder(node->left);
    printf("%d ", node->item);
    printBSTInOrder(node->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	if (node == NULL) 
		return 1;
	
	if (node->item >= max || node->item <= min)
		return 0;

	return isBST(node->left, min, node->item) && isBST(node->right, node->item, max);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	if (node == NULL) {
		printf("Node not found.\n");
		return NULL;
	}
	
	if (value < node->item) {
		// search left subtree
		node->left = removeBSTNode(node->left, value); 	

	} else if (value > node->item) {
		// search right subtree
		node->right = removeBSTNode(node->right, value);

	} else {
		// node has two children
		if (node->left != NULL && node->right != NULL) {
			// successor is minimum (leftmost) node in right subtree		
			BTNode *successor = findMin(node->right);	
			node->item = successor->item;
			node->right = removeBSTNode(node->right, successor->item);

		} else if (node->left == NULL && node->right == NULL) {	
			// node has no children
			free(node);
			node = NULL;

		} else {												
			BTNode *temp = node;
			if (node->left != NULL) {
				// node has a left child
				node = node->left;			
			} else {
				// node has a right child
				node = node->right;			
			}
			free(temp);
		}						
	}

	return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	while (p->left != NULL) {
		p = p->left;
	}
	return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////