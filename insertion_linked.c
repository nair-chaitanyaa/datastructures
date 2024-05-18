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
void insertion();
void insert_node(Node* new);

Node *head;
Node *sorted;

int main(){
    //taking the user's input for length of linked list
    int N;
    printf("\nPlease enter the length of linked list: \n");
    scanf("%d", &N);

    Createlist(N);

    printf("\n The linked list is \n");
    Displaylist();

    //sort the linked list using selection sort with head as input
    insertion(head);

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

//function to add the sorted nodes into a new list
void insert_node(Node* new)
{
    //Special case for the head end
    if (sorted == NULL || sorted->val >= new->val) {
        new->next = sorted;
        sorted = new;
    }
    else {
        Node* current = sorted;
        //Locate the node before the point of insertion
        while (current->next != NULL && current->next->val < new->val) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}
  
// function to sort a singly linked list using insertion sort
void insertion()
{
  
    Node* temp = head;
  
    // Traverse and insert every node to sorted linked list
    while (temp != NULL) {
  
        //Store pointer next for next iteration
        Node* next = temp->next;
  
        //insert temp in sorted linked list
        insert_node(temp);

        temp = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
}