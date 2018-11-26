#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int real;
    int imaginar;
} Complex;


double complexModulus(Complex *complex) {
    return sqrt(complex->real * complex->real + complex->imaginar * complex->imaginar);
}

int main() {
    int n;
    printf("Introduceti numarul:");
    scanf("%d", &n);
    Complex *complexNumbers = (Complex *) malloc(n * sizeof(Complex));
    for (int i = 0; i < n; i++) {
        printf("Introduceti partea reala si partea imaginara a numarului complex:");
        scanf("%d %d", &(complexNumbers + i)->real, &(complexNumbers + i)->imaginar);
    }

    for (int i = 0; i < n; i++) {
        printf("%d + %d*i \n", (complexNumbers + i)->real, (complexNumbers + i)->imaginar);
    }

    int maxIndex = 0;
    double maxModulus = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (complexModulus(complexNumbers + i) > maxModulus)
            maxIndex = i;
    }

    printf("Numarul cu cel mai mare modul este %d + %d*i", (complexNumbers + maxIndex)->real,
           (complexNumbers + maxIndex)->imaginar);

    return 0;
}