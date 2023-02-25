#include <stdio.h>
#include<stdlib.h>

void sort(int *arr,int n)
{
	int i,j,temp,k;
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (*(arr+j) > *(arr+j+1))
			{
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
	}
	
}

int binary(int *arr, int a, int b, int x)
{
    if (b >= a) {
        int m = a + (b - a) / 2;
        if (*(arr+m) == x)
            return m;
        if (*(arr+m) > x)
            return binary(arr, a, m-1, x);
        else
        	return binary(arr, m+1, b, x);
    }
    return -1;
}
 
int main()
{
	int *arr,n,i,x,k;
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
	sort(arr,n);
	printf("The sorted array is: ");
	for (k=0;k<n;k++)
	{
		printf("%d  ",*(arr+k));
	}
	printf("\n");
    int result = binary(arr, 0, n - 1, x);
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