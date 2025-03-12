#include "solver.h"
#include <math.h>

double discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

double root1(double a, double b, double d) {
    return (-b + sqrt(d)) / (2 * a);
}

double root2(double a, double b, double d) {
    return (-b - sqrt(d)) / (2 * a);
}