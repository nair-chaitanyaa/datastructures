#include<stdio.h>
#include<stdlib.h>
int bubblesort(int arr[], int n);
void swap(int *with, int *to); 

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
    
    bubblesort(arr, n);
    
    printf("\n The sorted array is:\n");
        
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    }

int bubblesort(int arr[], int n){
    int j, i;
    for (j = 0; j < n-1; j++){
        for (i = 0; i < n - j - 1; i++)
            if (arr[i] > arr[i + 1])
            //change > to < in condition to get descending order
                swap(&arr[i], &arr[i + 1]);
    }
}

void swap(int *with, int *to){
    //swapping elements to place at the beginning of the list
    int current = *with; //temporary variable for the element to be swapped with
    *with = *to; //assigning the position of the element to be swapped with to the element to be swapped to
    *to = current; //reassigning the swapped element to the current or with elements
}