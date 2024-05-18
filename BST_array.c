//Referred to: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
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

<<<<<<< HEAD
}
=======
}
>>>>>>> 905b323f5ecee4465fcb28c1ebdcbdd7d0d1e198
