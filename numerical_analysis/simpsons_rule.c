#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return log(x);
}

double simpsons (double lb, double ub, int n) {
    double h = (ub-lb)/n;
    double sum = f(lb) + f(ub);
    for (int x = 1; x < n; x++) {
        if (x%2 == 0)
            sum += 2*f(lb+x*h);
        else
            sum += 4*f(lb+x*h);
    } 
    return h*sum/3;
}

int main() {
    double lb, ub;
    int n;
    // 4 5.2 6
    scanf("%lf %lf %d", &lb, &ub, &n);
    printf("Result: %lf\n", simpsons(lb, ub, n));
    return 0;
}