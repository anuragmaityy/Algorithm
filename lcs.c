#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display(int **Mat, int m, int n)
{
	int i,j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d", Mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
	int i,j,k,l;
    char s1[20], s2[20];
    printf("Enter first string:");
    scanf("%s", s1);
    printf("Enter second string:");
    scanf("%s", s2);
    i = strlen(s1);
    j = strlen(s2);
    int **mat;
    mat = (int **)calloc(j + 1, sizeof(int *));
    for (i = 0; i < j + 1; i++)
        mat[i] = (int *)calloc(j + 1, sizeof(int));
    for (k = 0; k < i + 1; k++)
    {
        for (l = 0; l < j + 1; l++)
        {
            if (k == 0 || l == 0)
                mat[k][l] = 0;
            else if (k > 0 && l > 0 && s1[k - 1] == s2[l - 1])
                mat[k][l] = mat[k - 1][l - 1] + 1;
            else if (k > 0 && l > 0 && s1[k - 1] != s2[l - 1])
            {
                mat[k][l] = mat[k - 1][l];
                if (mat[k][l - 1] > mat[k][l])
                    mat[k][l] = mat[k][l - 1];
            }
        }
    }
    printf("The memoization matrix is:\n\n");
    display(mat, i + 1, j + 1);
    printf("\nThe longest subsequence is:%d\n", mat[i][j]);
    return 0;
}