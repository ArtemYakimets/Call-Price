#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 100000000

double discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

double root1(double a, double b, double d) {
    return (-b + sqrt(d)) / (2 * a);
}

double root2(double a, double b, double d) {
    return (-b - sqrt(d)) / (2 * a);
}

int main() {
    clock_t start, end;
    double spent_time;

    int *a =  malloc(ARRAY_SIZE * sizeof(int));
    int *b =  malloc(ARRAY_SIZE * sizeof(int));
    int *c =  malloc(ARRAY_SIZE * sizeof(int));

    srand(12345);
    for (long i = 0; i < ARRAY_SIZE; ++i) {
        a[i] = rand();
        b[i] = rand();
        c[i] = rand();
    }

    start = clock();

    for (long i = 0; i < ARRAY_SIZE; ++i) {
        double d = discriminant(a[i], b[i], c[i]);
        if (d >= 0) {
            double x1 = root1(a[i], b[i], d);
            double x2 = root2(a[i], b[i], d);
            // printf("%d: x1 = %lf, x2 = %lf\n", i, x1, x2);
        }
    }

    end = clock();

    spent_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %.6f seconds\n", spent_time);

    free(a);
    free(b);
    free(c);

    return 0;
}
