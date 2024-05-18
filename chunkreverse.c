//the first element is not getting printed, need to contact TAs for help

#include <stdio.h>
#include <stdlib.h>

struct nodeType {
    int val;
    struct nodeType *next;
};

//renaming structure for easy access
typedef struct nodeType Node;
int Createlist();
void Displaylist();
Node* chunkreverse(Node* head, int k);

Node *head;

int main(){
    //taking the user's input for length of linked list
    int N, k;
    printf("\nPlease enter the length of linked list: \n");
    scanf("%d", &N);

    Createlist(N);

    printf("\n The linked list is \n");
    Displaylist();
    
    printf("Enter integer for chunk:");
    scanf("%d", &k);
    chunkreverse(head, k);
    
    printf("\n The chunk reversed linked list is \n");
    Displaylist();
}

int Createlist (int N){

    //creating two temporary nodes
    Node *newNode, *temp;
    int val, x;
    head = (Node*) malloc(sizeof(Node));
    //temp = (Node*) malloc(sizeof(Node));
    //terminate if memory not allocated

    if (head == NULL){
        printf("There is an error (ehhhhhhh!)");
        exit (0);
    }

    //input first node from user
    printf("Enter the data for node 1:");
    scanf("%d", &val);

    head -> val = val; //link data field with value
    head -> next = NULL; //link to the address of the next item in the list

    //creating n-1 nodes and adding values to the list
    temp = head;
    for (x=2; x<=N; x++){
        newNode = (Node*)malloc(sizeof(Node));

        //If memory is not allocated for newNode
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", x);
        scanf("%d", &val);
        newNode->val = val; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}

void Displaylist()
{
    Node *temp;

    // Return if list is empty 
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->val); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}

Node* chunkreverse(Node* head, int k){

    if (head==NULL){
        return NULL;
    }
    //initializing the current for the head pointer, previous and next 
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count =0;
    
    //while current is not the last element, reverse the node
    while (curr != NULL && count < k){
        //store value of next element
        next = curr ->next;
        //make the next element, the previous
        curr->next = prev;

        //change previous to current
        prev = curr;
        //change current to the next
        curr = next;
        count++;
    }
    //Now, next is the pointer to (k+1)th node
    //Recursively call starting from current and make rest of the list as next of first node
    
    if (next !=  NULL){
        head->next = chunkreverse(next, k);
    }
 
    //return 
    return prev;
    
}