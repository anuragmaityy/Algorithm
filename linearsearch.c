#include <stdio.h>
 
int search(int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (*(arr+i) == x)
            return i;
    return -1;
}
 

int main()
{
    int *arr,n,i,x;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for (i=0;i<n;i++)
    {
    	scanf("%d",arr+i);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&x);
    int result = search(arr, n, x);
    if (result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }
    return 0;
}