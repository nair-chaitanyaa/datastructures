//showing segmentation fault - need to debug

#include <stdio.h>

void merge (int arr[], int a, int b, int c);
void mergesort(int arr[], int s, int e);

int main (){
    
    int arr[]={2, 23, 82, 55, 12, 9, 90}; 
    int i, n = sizeof(arr);
    printf("\n The unsorted array is:\n");
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    
    mergesort(arr, 0, n-1);
    
    printf("\n The sorted array is:\n");
        
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
        }
    }

//function that combines two subarrays together
void merge (int arr[], int a, int b, int c){
    int l = b - a + 1, l2= c - b;

    int X[l], Y[l2];

    for (int i=0; i<l; i++){
        X[i] = arr[a+i];
    }
    
    for (int j=0; j<l2; j++){
        Y[j] = arr[b+1+j];
    }

    int i=0, j=0, k=a;

    while (i<l && j <l2){
        if (X[i]<= Y [j]){
            arr[k] = X[i];
            i++;
        }
        else{
            arr[k]=Y[j];
            j++;
        }
        k++;
    }
}

//issue begins from here - need to debug
void mergesort(int arr[], int s, int e){
    if (s < e){
        //find midpoint
        int m = s + (e-1)/ 2 ;
        //call recursively
        mergesort(arr, 1, m);
        mergesort (arr, m, e);

        //once partitioned, sort and combine
        merge(arr, s, m, e);
    }
}
