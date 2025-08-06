//1. Print matrix in spiral form
#include <stdio.h>
#define MAX 100

void Spiral(int m, int n, int a[MAX][MAX]) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            printf("%d ", a[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", a[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }
}

int main() {
    int m, n;
    int a[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Spiral order:\n");
    Spiral(m, n, a);

    return 0;
}

//2.Rotate matrix by 90 degree

#include <stdio.h>
#define MAX 100

void rotate90(int n, int mat[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n - 1 - j];
            mat[i][n - 1 - j] = temp;
        }
}

void printMatrix(int n, int mat[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int n, mat[MAX][MAX];

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    rotate90(n, mat);

    printf("Matrix after 90 degree rotation:\n");
    printMatrix(n, mat);

    return 0;
}

//3.Sum of diagonals

#include <stdio.h>

#define MAX 100

int main() {
    int n, mat[MAX][MAX];
    int mainDiagonal = 0, secondaryDiagonal = 0;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 0; i < n; i++) {
        mainDiagonal += mat[i][i];
        secondaryDiagonal += mat[i][n - 1 - i];    
    }

    printf("Main diagonal sum = %d\n", mainDiagonal);
    printf("Secondary diagonal sum = %d\n", secondaryDiagonal);

    return 0;
}

// 4.Transpose of matrix
#include <stdio.h>
#define MAX 100

int main() {
    int mat[MAX][MAX], trans[MAX][MAX];
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans[j][i] = mat[i][j]; 
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }

    return 0;
}

// 5.Check if matrix is sparse
#include <stdio.h>

#define MAX 100

int isSparse(int rows, int cols, int mat[MAX][MAX]) {
    int zeroCount = 0;
    int total = rows * cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] == 0)
                zeroCount++;

    return (zeroCount > total / 2);
}

int main() {
    int mat[MAX][MAX];
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);

    if (isSparse(rows, cols, mat))
        printf("The matrix is sparse.\n");
    else
        printf("The matrix is not sparse.\n");

    return 0;
}

// 6.Add two polynomials
#include <stdio.h>

#define MAX 100

void addPolynomials(int poly1[], int poly2[], int result[], int n1, int n2) {
    int max = (n1 > n2) ? n1 : n2;

    for (int i = 0; i < max; i++) {
        int coeff1 = (i < n1) ? poly1[i] : 0;
        int coeff2 = (i < n2) ? poly2[i] : 0;
        result[i] = coeff1 + coeff2;
    }
}

void printPolynomial(int poly[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] == 0) continue;

        if (i != n - 1 && poly[i] > 0)
            printf(" + ");

        if (i == 0)
            printf("%d", poly[i]);
        else if (poly[i] == 1)
            printf("x^%d", i);
        else
            printf("%d*x^%d", poly[i], i);
    }
    printf("\n");
}

int main() {
    int poly1[MAX], poly2[MAX], result[MAX] = {0};
    int n1, n2, max;

    printf("Enter highest degree of first polynomial: ");
    scanf("%d", &n1);
    n1++;  

    printf("Enter coefficients of first polynomial (from x^0 to x^%d):\n", n1 - 1);
    for (int i = 0; i < n1; i++)
        scanf("%d", &poly1[i]);

    printf("Enter highest degree of second polynomial: ");
    scanf("%d", &n2);
    n2++;

    printf("Enter coefficients of second polynomial (from x^0 to x^%d):\n", n2 - 1);
    for (int i = 0; i < n2; i++)
        scanf("%d", &poly2[i]);

    max = (n1 > n2) ? n1 : n2;

    addPolynomials(poly1, poly2, result, n1, n2);

    printf("Resultant polynomial after addition:\n");
    printPolynomial(result, max);

    return 0;
}

// 7.Multiply two polynomials
#include <stdio.h>

int main() {
    int a[10], b[10], res[20] = {0};
    int n1, n2;

    printf("Degree of 1st poly: ");
    scanf("%d", &n1);
    printf("Coefficients of 1st poly:\n");
    for (int i = 0; i <= n1; i++) scanf("%d", &a[i]);

    printf("Degree of 2nd poly: ");
    scanf("%d", &n2);
    printf("Coefficients of 2nd poly:\n");
    for (int i = 0; i <= n2; i++) scanf("%d", &b[i]);

    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
            res[i + j] += a[i] * b[j];

    printf("Result: ");
    for (int i = n1 + n2; i >= 0; i--)
        if (res[i]) printf("%s%d*x^%d", (i != n1 + n2) ? " + " : "", res[i], i);
    printf("\n");

    return 0;
}

// 8.Dynamic array operations
#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size = 0, choice, val, pos;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &val);
                arr = realloc(arr, (size + 1) * sizeof(int));
                arr[size++] = val;
                break;

            case 2: 
                if (size == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= size) {
                    printf("Invalid position.\n");
                    break;
                }
                for (int i = pos; i < size - 1; i++)
                    arr[i] = arr[i + 1];
                size--;
                arr = realloc(arr, size * sizeof(int));
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                free(arr);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

// 9.Identity matrix check
#include <stdio.h>

#define MAX 100

int isIdentity(int mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0))
                return 0;
        }
    return 1;
}

int main() {
    int mat[MAX][MAX], n;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    if (isIdentity(mat, n))
        printf("The matrix is an identity matrix.\n");
    else
        printf("The matrix is NOT an identity matrix.\n");

    return 0;
}

// 10.Count zeros in matrix
#include <stdio.h>

#define MAX 100

int countZeros(int mat[MAX][MAX], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] == 0)
                count++;
    return count;
}

int main() {
    int mat[MAX][MAX];
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);

    int zeros = countZeros(mat, rows, cols);
    printf("Total number of zeros in the matrix: %d\n", zeros);

    return 0;
}

