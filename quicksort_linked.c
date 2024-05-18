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
void quicksort(Node* first, Node* last);
Node* find_last(Node* head);
Node* partition (Node* first, Node* last);

Node *head;

void main() {
    //taking the user's input for length of linked list
    int N;
    printf("\nPlease enter the length of linked list: \n");
    scanf("%d", &N);

    Createlist(N);

    printf("\n The linked list is \n");
    Displaylist();

    //find the last node and store in variable last
    Node* last = find_last(head);
    //sorting using quicksort
    quicksort(head, last);

    //print linked list after this. 
    printf("\n The sorted linked list is \n");
    Displaylist();
}

int Createlist (int N) {

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

Node* find_last(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
 
//partition the linked list along the pivot element
Node* partition(Node* first, Node* last){
    //assume head is pivot
    Node* pivot = first;
    Node* front = first;
    int temp = 0;
    //only run the loop if the head is not null and is not the last element, a.k.a circular linked list
    while (front != NULL && front != last) {
        if (front->val < last->val) {
            pivot = first;
 
            // Swapping  node values
            temp = first->val;
            first->val = front->val;
            front->val = temp;

            //moving to next node
            first = first->next;
        }
 
        // moving to next node
        front = front->next;
    }
 
    //change last node to current node
    temp = first->val;
    first->val = last->val;
    last->val = temp;
    return pivot;
}
 
// devise quicksort for linked list
void quicksort(Node* first, Node* last)
{
    //check if circular list
    if (first == last) {
        return;
    }
    //creating new pivot pointer
    Node* pivot = partition(first, last);

    //recursively call quicksort if chunk is right hand side of the pivot element
    if (pivot != NULL && pivot->next != NULL) {
        quicksort(pivot->next, last);
    }

    //recusrively call quicksort if chunk is left hand side of the pivot element 
    if (pivot != NULL && first != pivot) {
        quicksort(first, pivot);
    }
}