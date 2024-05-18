//Referred to: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ and https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
#include <stdio.h>
#include <stdlib.h>

struct nodeType{
	int key;
	struct nodeType* left; 
	struct nodeType* right;
};

typedef struct nodeType Node;

Node* createnode(int x){
    Node* root = malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->key = x;
 
    return root;
}

Node* insert(Node* root, int key){
	if(root==NULL){
        return createnode(key);
    }

    if (key < root->key){
        root->left = insert(root->left, key);
    }
	else if (key > root->key){
        root->right = insert(root->right, key);
    }

	return root;
}

//finding the node with minimum value
Node* minNode(Node* node)
{
    Node* current = node;
 
    //moving to the left side of the tree
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node* root, int key)
{
    //when there is only root
    if (root == NULL)
        return root;
 
    //if the deleted key is smaller than the root's key, then it traverse left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    //if the deleted key is greater than the root's key, then it traverse right subtree

    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    //if key is same as root's key, then node to be deleted is the root

    else {
        //node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children, using the inorder successor (smallest on the right subtree)
        Node* temp = minNode(root->right);
 
        //duplicate the inorder successor's content to this node
        root->key = temp->key;
 
        //delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

Node* arraytoBST(int *a, int n){
    int mid = n/2;
    
    Node *root = createnode(a[mid]);
 
    for(int i = 0; i < n; i++){
        if (root == NULL){
            return createnode(a[i]);
        }
        
        else if(a[i] < root->key) {
            root->left  = insert(root->left , a[i]);
        }
	
        else if (a[i] > root->key ){
            root->right = insert(root->right, a[i]);
        }
    }

    return root;
}

void Inorder(Node* root){
    if (root != NULL){
        Inorder(root->left);
        printf("%d  ", root->key);
        Inorder(root->right);
    }
}

void main(){
  
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    int *A;
    A = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &A[i]);
    }
//using selection sort to sort the array into descending order
    for (int  i = 0; i < n - 1; i++){
        int max = i;

        for (int j = i + 1; j < n; j++){
            if (A[j] < A[max]){
                int temp = A[max];    
                A[max] = A[j];          
                A[j] = temp;
            }
        }
    }
    
    printf("BST:\n");
    Inorder(arraytoBST(A, n));

    //if 3 is there, then delete it
    deleteNode(arraytoBST(A, n), 3);

    printf("BST after deleting:\n");
    Inorder(arraytoBST(A, n));
<<<<<<< HEAD
}
=======
}
>>>>>>> 905b323f5ecee4465fcb28c1ebdcbdd7d0d1e198
