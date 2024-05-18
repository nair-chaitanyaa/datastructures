//trying to convert an array into a linked list. However, this code contains bugs that need to be fixed. The time complexity in this code is very high. 

#include <stdio.h>
#include <stdlib.h>

int CreateList();
void Displaylist();

struct nodeType {
    int val;
    struct nodeType *next;
};

typedef struct nodeType Node;
Node *head;

int main (int N, int i){
    //taking input from the user and storing it as an array
    printf("Please enter length of the linked list:\n");
    scanf("%d", &N);
    if (N <= 0){
        printf("EHHHH, no list can be made!");
    }
    else{
        int A[N];

        printf("Please enter values for N elements:\n");

        for (i = 0; i < N; i++){
            scanf("%d", &A[i]);
        }

        printf("The array is:\n");
        for (i = 0; i < N; i++){
            printf("%d\n", A[i]);
        }

        CreateList(A[N], N);
        Displaylist();
    }
    
}

int CreateList (int A[], int N){

    //creating two temporary nodes
    Node *newNode, *temp;
    int x;
    head = (Node*) malloc(sizeof(Node));
    //temp = (Node*) malloc(sizeof(Node));
    //terminate if memory not allocated

    if (head == NULL){
        printf("There is an error (ehhhhhhh!)");
        exit (0);
    }

    head -> val = A[0]; //link data field with value
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

        newNode->val = A[x-1]; // Link data field of newNode
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