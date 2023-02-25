// Selection sort in C

#include <stdio.h>

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
	int step;
  for (step = 0; step < size - 1; step++) {
    int min_idx = step;
    int i;
    for (i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }
	int n=0;
    // put min at the correct position
    swap(&array[min_idx], &array[step]);
    n++;
    printf("No. of swaps: ", n);
  }
}

// function to print an array
void printArray(int array[], int size) {
	int i;
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int size,i;
  printf("NO. of ele:");
  scanf("%d",&size);
  int data[size];
  printf("Elements: ");
  for (i=0;i<size;i++){
  	scanf("%d",&data[size]);
  }
  selectionSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}

