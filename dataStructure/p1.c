#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct sparsMatrix
{
    int row;
    int col;
    int value;
};

// function that sort our matrix
void insertionSort(struct sparsMatrix *arr, int n);
// function that made our random matrix
void randMatrix(int** arr, int rows, int columns);
// print function
int main() {
    int rows = 0, columns = 0;
    //get entry
    printf("please enter the number of rows: \n");
    scanf("%d", &rows);
    printf("please enter the number of columns: \n");
    scanf("%d", &columns);
    // creat row matrix
    int **matrix = calloc(rows, sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = calloc(columns, sizeof(int));
    }
    randMatrix(matrix, rows , columns);

    printf("our random matrix is: \n");
    int valueCounter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
            if(matrix[i][j] != 0)
                valueCounter++;
        }
        printf("\n");
    }
    // made spars Matrix
    struct sparsMatrix spars [valueCounter + 1];
    spars[0].col = columns;
    spars[0].row = rows;
    spars[0].value = valueCounter;
    //printf("%d\t%d\t%d\t%d", spars[0].col, spars[0].row, spars[0].value, valueCounter);
    int tempCunt = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            if(matrix[i][j] != 0)
            {
                spars[tempCunt+1].col = i+1;
                spars[tempCunt+1].row = j+1;
                spars[tempCunt+1].value = matrix[i][j];
                tempCunt++;
            }
        }
    }
    printf("col\trow\tvalue");
    for (int i = 0; i < tempCunt+1; i++)
    {
        printf("\n%d\t%d\t%d", spars[i].col, spars[i].row, spars[i].value);
    }
    // transpose and sort the spars matrix
    for(int i = 1; i < valueCounter + 1; i++)
    {
        int newRow;
        int newCol;
        newRow = spars[i].col;
        newCol = spars[i].row;
        spars[i].row = newRow;
        spars[i].col = newCol;
    }
    insertionSort(spars, valueCounter +1);
    printf("\ncol\trow\tvalue\t after transpose:");
    for (int i = 0; i < tempCunt+1; i++)
    {
        printf("\n%d\t%d\t%d", spars[i].col, spars[i].row, spars[i].value);
    }
    for (int i = 0; i < rows + 1; i++)
    {
        for (int j = 0; j < columns + 1; j++)
        {
            // free memory
            free (matrix[i][j]);
        }
    }
    free(matrix);
    return 0;
}

void insertionSort(struct sparsMatrix *arr, int n) {
    int i, j;
    struct sparsMatrix key;
    for (i = 2; i < n; i++) {
        key = arr[i];
        j = i - 1;

        do {
            if (arr[j].col > key.col) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        } while (j >= 1);

        arr[j + 1] = key;
    }
    return;
}

void randMatrix(int** arr, int rows, int columns)
{
    // create different random number
    srand(time(NULL));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // generate number between 0 - 1
            float random = (float)rand() / (RAND_MAX + 1);
            // if the random number is less than 0.1, the cell value is a random number between 1 and 100
            if (random < 0.1)
            {
                arr[i][j] = rand() % 100 +1;
            }  
        }
    }
}