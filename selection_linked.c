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
Node* selection (Node* head);

Node *head;

int main(){
    //taking the user's input for length of linked list
    int N;
    printf("\nPlease enter the length of linked list: \n");
    scanf("%d", &N);

    Createlist(N);

    printf("\n The linked list is \n");
    Displaylist();

    //sort the linked list using selection sort with head as input
    selection(head);

    //print linked list after this. 
    printf("\n The sorted linked list is \n");
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

Node* selection (Node* head){
    //declaring temporary pointer for the head node in the linked list
    Node* temp = head;

    while (temp){
        //keeping track of min
        Node* min = temp;
        //assigning next element as r
        Node* r = temp->next;

        //till r has been reached, check if value of min > r, otherwise move to next element
        //change > to < for descending order
        while(r){
            if (min->val > r->val){
                min = r;
            }
            r = r->next;
        }

        //swap the elements' values
        int x = temp->val;
        temp->val = min->val;
        min->val = x;
        temp = temp->next;

    }
}