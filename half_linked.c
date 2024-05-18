//this code prints the alternate elements in the linked list using hare and tortoise pointers

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
Node* halfit(Node *head);

Node *head;

int main(){
    //taking the user's input for length of linked list
    int N;
    printf("\nPlease enter the length of linked list: \n");
    scanf("%d", &N);

    Createlist(N);

    printf("\n The linked list is \n");
    Displaylist();
    
    printf("Half the linked list is:");
    halfit(head);


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


Node* halfit(Node *head){

    Node* tor;
    Node* hare;

    if (head == NULL){
        return (NULL);
    }

    tor = head;
    hare = head;

    while (tor != NULL && hare != NULL && hare->next != NULL){

        if (hare == tor){
            printf("Data= %d\n", tor -> val);
            tor = tor->next;
            hare = hare->next->next;
        }

        else{
            printf("Data= %d\n", hare -> val);
            tor = tor ->next;
            hare = hare -> next -> next;
        }
    }

}