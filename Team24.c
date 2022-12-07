// Pritam Basu 2021A7PS2175H
// Saksham Attri 2021A7PS2950H

#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2) // comparator function that is used in the quick sort
{
    return (*(int *)p2 - *(int *)p1);
}

int main(int argc, char *argv[])
{
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL) // If error in opening the file, exit with code 1
    {
        printf("Error opening file\n");
        exit(1);
    }
    int n, e;
    fscanf(fptr, "%d %d", &n, &e); // extracting n and e from the file

    if (n <= 0 || e < 0)
    {
        printf("Invalid input\n");
        exit(1);
    }

    // initializing the elements of the 2D Adjacency Matrix to 0s
    int **adjacencyMatrix;
    adjacencyMatrix = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        *(adjacencyMatrix + i) = (int *)calloc(n, sizeof(int));
    int a, b;
    for (int i = 0; i < e; i++)
    {
        fscanf(fptr, "%d %d", &a, &b); // extracting the pairs from the file
        adjacencyMatrix[a - 1][b - 1]++;
        adjacencyMatrix[b - 1][a - 1]++;
    }

    int x = 0;
    int outs[n]; // stores the degree sequence
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += adjacencyMatrix[i][j];
        outs[x++] = sum;
    }

    qsort(outs, n, sizeof(int), comparator); // applying quick sort on the array

    for (int i = 0; i < n; i++) // printing the degree sequence in non-increasing order
        printf("%d ", outs[i]);
    printf("\n");
    fclose(fptr);

    return 0;
}
