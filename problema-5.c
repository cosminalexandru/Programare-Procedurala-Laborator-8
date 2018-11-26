#include <stdio.h>
#include <stdlib.h>


int main() {

    printf("Introduceti modul de alocare al vectorilor(1.malloc 2.realloc):");
    int optiune;
    scanf("%d", &optiune);
    switch (optiune) {
        case 1: {
            int n, pozitive = 0, negative = 0;
            printf("Introduceti numarul de elemente al vectorului:");
            scanf("%d", &n);
            int *v = (int *) malloc(n * sizeof(int));
            printf("Introduceti elementele vectorului:");
            for (int i = 0; i < n; i++) {
                scanf("%d", v + i);
                if (*(v + i) > 0)
                    pozitive++;
                else negative++;
            }

            int *numerePozitive = (int *) malloc(pozitive * sizeof(int));
            int *numereNegative = (int *) malloc(negative * sizeof(int));

            int pozIndex = 0, negIndex = 0;
            for (int i = 0; i < n; i++)
                if (*(v + i) > 0) {
                    *(numerePozitive + pozIndex) = *(v + i);
                    pozIndex++;
                } else {
                    *(numereNegative + negIndex) = *(v + i);
                    negIndex++;
                }

            printf("Vectorul de numere negative este:");
            for (int i = 0; i < negIndex; i++) {
                printf("%d ", *(numereNegative + i));
            }
            printf("\n");

            printf("Vectorul de numere pozitive este:");
            for (int i = 0; i < pozIndex; i++) {
                printf("%d ", *(numerePozitive + i));
            }
            printf(("\n"));
            free(v);
            free(numereNegative);
            free(numerePozitive);
            break;
        }

        case 2: {
            int n, pozitive = 0, negative = 0;
            printf("Introduceti numarul de elemente al vectorului:");
            scanf("%d", &n);
            int *v = (int *) malloc(n * sizeof(int));
            int *numerePozitive = (int *) malloc(sizeof(int));
            int *numereNegative = (int *) malloc(sizeof(int));
            printf("Introduceti elementele vectorului:");
            for (int i = 0; i < n; i++) {
                scanf("%d", v + i);
                if (*(v + i) > 0) {
                    numerePozitive[pozitive] = v[i];
                    pozitive++;
                    int *aux = realloc(numerePozitive, (pozitive + 1) * sizeof(int));
                    if (aux == NULL) {
                        printf("Nu se poate redimensiona!");
                    } else {
                        numerePozitive = aux;
                    }
                } else {
                    numereNegative[negative] = v[i];
                    negative++;
                    int *aux = realloc(numereNegative, (negative + 1) * sizeof(int));
                    if (aux == NULL) {
                        printf("Nu se poate redimensiona!");
                    } else {
                        numereNegative = aux;
                    }
                }
            }
            printf("Vectorul de numere negative este:");
            for (int i = 0; i < negative; i++) {
                printf("%d ", *(numereNegative + i));
            }
            printf("\n");

            printf("Vectorul de numere pozitive este:");
            for (int i = 0; i < pozitive; i++) {
                printf("%d ", *(numerePozitive + i));
            }
            printf(("\n"));

            free(v);
            free(numereNegative);
            free(numerePozitive);
            break;
        }

        default: {
            printf("Nu ati ales o optiune valida!");
        }
    }


    return 0;
}