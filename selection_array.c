#include <stdio.h>

void selection (int A[], int n);
void swap (int *with, int *to);

int main (){
    //create an array using user input
    int n, i;
    printf("Enter the length of the array:");
    scanf ("%d", &n);

    //checking if n is a non-zero positive number
    if (n <= 0){
        printf("Error, please enter a non-zero positive number.");
    }
    int arr[n];
    //taking inputs into the array
    printf("Enter the elements:");
    for (i=0; i<n; i++){
        scanf ("%d", &arr[i]);
        }
    printf("\n The unsorted array is:\n");
        
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    
    selection(arr, n);
    
    printf("\n The sorted array is:\n");
        
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    }


//devise the selection sort algorithm 
void selection(int A[], int n){
    int i;
    for (i = 0; i < n-1; i++){
        int min = i;
        //check for the minimum element
        int j;
        for (j = i + 1; j < n; j++){
            if (A[j] < A[min]){
                min = j;
            }
            //if smallest element, swap with the first position
            }
            swap (&A[min], &A[i]);
    }
}

void swap(int *with, int *to){
    //swapping elements to place at the beginning of the list
    int current = *with; //temporary variable for the element to be swapped with
    *with = *to; //assigning the position of the element to be swapped with to the element to be swapped to
    *to = current; //reassigning the swapped element to the current or with elements
}
