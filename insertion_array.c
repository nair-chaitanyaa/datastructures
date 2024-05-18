#include <stdio.h>

void insertion(int arr[], int n);

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
    
    insertion(arr, n);
    
    printf("\n The sorted array is:\n");
        
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    }

//devise alogorithm for insertion sort
void insertion(int arr[], int n) {
    //for every element, check if the next element is either greater or smaller
    for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    // Compare key with each element on the left of it until an element smaller than it is found.
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}


