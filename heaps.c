#include <stdio.h>

int size = 0;

void swap(int *with, int *to){
    //swapping elements to place at the beginning of the list
    int current = *with; //temporary variable for the element to be swapped with
    *with = *to; //assigning the position of the element to be swapped with to the element to be swapped to
    *to = current; //reassigning the swapped element to the current or with elements
}

void Heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap.\n");
  }
  else
  {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[max])
      max = l;
    if (r < size && array[r] > array[max])
      max = r;
    if (max != i)
    {
      swap(&array[i], &array[max]);
      Heapify(array, size, max);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      Heapify(array, size, i);
    }
  }
}
void extract_element(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    Heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);}
  printf("\n");
}

int main()
{
  int array[12];

  insert(array, 2);
  insert(array, 0);
  insert(array, 98);
  insert(array, 230);
  insert(array, 1);

  printf("Max-Heap array: ");
  printArray(array, size);

  extract_element(array, 2);

  printf("After extracting min: ");

  printArray(array, size);
<<<<<<< HEAD
}
=======
}
>>>>>>> 905b323f5ecee4465fcb28c1ebdcbdd7d0d1e198
