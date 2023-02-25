#include<stdio.h>
#include<stdlib.h>

void swap (int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void heapify (int arr[], int n, int i){
	int largest=i;
	int  l=2*i+1;
	int r=2*i+2;
	
	if (l<n && arr[l]>arr[largest])
		largest=l;
	if (r<n && arr[r]>arr[largest])
		largest=r;
	if (largest!=i){
		swap (&arr[i], &arr[largest]);
		heapify (arr,n,largest);
	}
}

void heapsort (int arr[], int n){
	int  i;
	for (i=n/2-1; i>=0; i--)
		heapify(arr,n,i);
	
	for (i=n-1; i>=0; i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

void printarr(int arr[], int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d ",arr[n]);
	}
}

int main()
{
	int n,i;
	printf("Enter the size of array :");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements:");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	heapsort(arr,n);
	printf("Sorted Array is: ");
	printarr(arr,n);
	return 0;
}

