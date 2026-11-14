#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_TERMS (MAX_ROWS * MAX_COLS + 1)

int main(void) {
    int matrix[MAX_ROWS][MAX_COLS];
    int triplets[MAX_TERMS][3];
    int rows;
    int cols;
    int terms = 1;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX_ROWS ||
        cols < 1 || cols > MAX_COLS) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter the matrix values row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid matrix value.\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplets[terms][0] = i;
                triplets[terms][1] = j;
                triplets[terms][2] = matrix[i][j];
                terms++;
            }
        }
    }

    triplets[0][0] = rows;
    triplets[0][1] = cols;
    triplets[0][2] = terms - 1;

    printf("\nRow  Column  Value\n");
    for (int i = 0; i < terms; i++) {
        printf("%d    %d       %d\n",
               triplets[i][0],
               triplets[i][1],
               triplets[i][2]);
    }

    return 0;
}
