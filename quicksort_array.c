//this code is bugged, will rectify post office hours - showing segmentation fault (core dumped).

#include <stdio.h>

void swap (int *with, int *to);
int partition(int arr[], int min, int max);
void quicksort(int arr[], int min, int max);

int main (){
    int n, i;
    //create an array using user input

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
    
    quicksort(arr, 0, n-1);
    
    printf("\n The sorted array is:\n");
        
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    }

void swap(int *with, int *to){
    //swapping elements to place at the beginning of the list
    int current = *with; //temporary variable for the element to be swapped with
    *with = *to; //assigning the position of the element to be swapped with to the element to be swapped to
    *to = current; //reassigning the swapped element to the current or with elements
}

int partition(int arr[], int min, int max){
    //using the last element of the array as a pivot element
    int pivot = arr[max];

    //creating a pointer for the greater element
    int i = (min - 1);

    //traverse and compare each element to the pivot
    int j;
    for (j = min; j < max; j++){
        if (arr[j] <= pivot){
            //if the element arr[j] is smaller than pivot, then swap with the greater element with pointer i
            i++;
            
            //swap elements
            swap(&arr[i], &arr[j]);
        }
    }

    //swap pivot and greater element at i
    swap (&arr[i + 1], &arr[max]);

    //back to partition
    return (i+1);
}

//devise the quicksort algorithm 
void quicksort(int A[], int min, int max){
    //if min value is smaller then max, find pivot such that elements greater are on the right and smaller on the left
    if (min < max){
        int pivot = partition(A, min, max);

        //recursively execute on right side
        quicksort(A, pivot+1, max);

        //recursively execute on left side
        quicksort(A, min, pivot +1);
    }
}