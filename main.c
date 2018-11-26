#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
enum {
    PROBLEMA1 = 1,
    PROBLEMA2,
    PROBLEMA3,
};

/**
 *
 */
void verifyComputerConfiguration() {
    unsigned int i = 1;
    char *c = (char *) &i;
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
}

/**
 *
 * @param n
 */
void extractBytes(int n) {
    for (int i = 0; i < sizeof(n); i++) {
        unsigned char byte = *((unsigned char *) &n + i);
        printf("Octetul %d este %u \n", i, byte);
    }
}

/**
 *
 * @param a
 * @param n
 */
void readMatrix(int a[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%d", *(a + i) + j);
        }
    }
}

/**
 *
 * @param a
 * @param n
 */
void displayMatrix(int a[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
}

/**
 *
 * @param a
 * @param n
 */
void middleOfMatrix(int a[][10], int n) {
    if (n % 2 == 1) {
        printf("The middle element is %d \n", *(*(a + n / 2) + n / 2));
    } else printf("Doesn't have middle");
}

/**
 *
 * @param a
 * @param n
 */
void mainDiagonal(int a[][10], int n) {
    printf("The elements of the main diagonal are:");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(*(a + i) + i));
    }
    printf("\n");
}

/**
 *
 * @param a
 * @param n
 */
void secondaryDiagonal(int a[][10], int n) {
    printf("The elements of the secondary diagonal are:");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(*(a + i) + (n - i - 1)));
    }
    printf("\n");
}

/**
 *
 * @param a
 * @param n
 * @param i
 * @param j
 */
void swapMatrixLines(int a[][10], int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        int aux = *(*(a + i) + k);
        *(*(a + i) + k) = *(*(a + j) + k);
        *(*(a + j) + k) = aux;
    }
}

//int main() {
//    printf("Introduceti numarul problemei(1-7):");
//    int problemNumber;
//    scanf("%d", &problemNumber);
//    switch (problemNumber) {
//        case PROBLEMA1 : {
//            verifyComputerConfiguration();
//            break;
//        }
//        case PROBLEMA2: {
//            printf("Introduceti numarul:");
//            int n;
//            scanf("%d", &n);
//            extractBytes(n);
//            break;
//        }
//        case PROBLEMA3: {
//            int a[10][10];
//            int n;
//            printf("Introduceti n =");
//            scanf("%d", &n);
//            readMatrix(a, n);
//            displayMatrix(a, n);
//            middleOfMatrix(a, n);
//            mainDiagonal(a, n);
//            secondaryDiagonal(a, n);
//            int i, j;
//            printf("Insert line i and line j:");
//            scanf("%d %d", &i, &j);
//            swapMatrixLines(a, n, i, j);
//            displayMatrix(a, n);
//        }
//        default: {
//            printf("Something is wrong");
//        }
//    }
//    return 0;
//}