//referred from: https://www.sanfoundry.com/c-program-implement-avl-tree/ 
 
#include<stdio.h>
#include<stdlib.h>
 
// structure of the tree node
struct nodeType
{
    int data;
    struct nodeType* left;
    struct nodeType* right;
    int ht;
};

typedef struct nodeType Node;
 
// global initialization of root node
Node* root = NULL;
 
// function prototyping
Node* create(int);
Node* insert(Node*, int);
Node* delete(Node*, int);
Node* search(Node*, int);
Node* rotate_left(Node*);
Node* rotate_right(Node*);
int balance_factor(Node*);
int height(Node*);
void inorder(Node*);

 
int main()
{
    int user_choice, data;
    char user_continue = 'y';
    Node* result = NULL;
 
    while (user_continue == 'y' || user_continue == 'Y')
    {
        printf("\n\n------- AVL TREE --------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder");
        printf("\n5. EXIT");
 
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &user_choice);
 
        switch(user_choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
 
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
 
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL)
                {
                    printf("\nNode not found!");
                }
                else
                {
                    printf("\n Node found");
                }
                break;
            case 4:
                inorder(root);
                break;
 
            case 5:
                printf("\n\tProgram Terminated\n");
                return 1;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\n\nDo you want to continue? ");
        scanf(" %c", &user_continue);
    }
 
    return 0;
}
 
// creates a new tree node
Node* create(int data)
{
    Node* new_node = (Node*) malloc (sizeof(Node));
 
    // if a memory error has occurred
    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
 
//rotates to the left
Node* rotate_left(Node* root)
{
    Node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
 
    // update the heights of the nodes
    root->ht = height(root);
    right_child->ht = height(right_child);
 
    // return the new node after rotation
    return right_child;
}
 
// rotates to the right
Node* rotate_right(Node* root)
{
    Node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
 
    // update the heights of the nodes
    root->ht = height(root);
    left_child->ht = height(left_child);
 
    // return the new node after rotation
    return left_child;
}
 
// calculates the balance factor of a node
int balance_factor(Node* root)
{
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
 
// calculate the height of the node
int height(Node* root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
 
    if (lh > rh)
        return (lh);
    return (rh);
}
 
// inserts a new node in the AVL tree
Node* insert(Node* root, int data)
{
    if (root == NULL)
    {
        Node* new_node = create(data);
        if (new_node == NULL)
        {
            return NULL;
        }
        root = new_node;
    }
    else if (data > root->data)
    {
        // insert the new node to the right
        root->right = insert(root->right, data);
 
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == -2)
        {
            if (data > root->right->data)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        // insert the new node to the left
        root->left = insert(root->left, data);
 
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == 2)
        {
            if (data < root->left->data)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    // update the heights of the nodes
    root->ht = height(root);
    return root;
}
 
// deletes a node from the AVL tree
Node * delete(Node *root, int x)
{
    Node * temp = NULL;
 
    if (root == NULL)
    {
        return NULL;
    } 
 
    if (x > root->data)
    {
        root->right = delete(root->right, x);
        if (balance_factor(root) == 2)
        {
            if (balance_factor(root->left) >= 0)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    else if (x < root->data)
    {
        root->left = delete(root->left, x);
        if (balance_factor(root) == -2)
        {
            if (balance_factor(root->right) <= 0)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        { 
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
 
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            if (balance_factor(root) == 2)
            {
                if (balance_factor(root->left) >= 0)
                {
                    root = rotate_right(root);
                }
                else
                {
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        }
        else
        {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}
 
// search a node in the AVL tree
Node* search(Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
 
    if(root->data == key)
    {
        return root;
    }
 
    if(key > root->data)
    {
        search(root->right, key);
    }
    else
    {
        search(root->left, key);
    } 
}
 
// inorder traversal of the tree
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
 
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
<<<<<<< HEAD
 
=======
 
>>>>>>> 905b323f5ecee4465fcb28c1ebdcbdd7d0d1e198
