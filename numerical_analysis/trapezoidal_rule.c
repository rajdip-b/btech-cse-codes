#include <stdio.h>
#include <stdlib.h>

double f(double x) {
    return 1/(1+x*x);
}

double trapeziodal (double lb, double ub, int n) {
    double h = (ub-lb)/n;
    double sum = f(lb) + f(ub);
    for (int x = 1; x < n; x++) {
        sum += 2*f(lb+x*h);
    } 
    return h*sum/2;
}

int main() {
    double lb, ub;
    int n;
    // 0 1 6
    scanf("%lf %lf %d", &lb, &ub, &n);
    printf("Result: %lf\n", trapeziodal(lb, ub, n));
    return 0;
}