#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x*x-x-2;
}

void bisection(double a, double b, double e, int iterCount) {
    iterCount += 1;
    double c = (a+b)/2;
    double fc = f(c);

    printf("%d\t%20lf\t%lf\t%lf\t%lf\n", iterCount, a, b, c, fc);
    if (fabs(a-b) < e){
        printf("Root lies at: %lf\n", c);
    } else if (fc < 0){
        bisection(c, b, e, iterCount);
    } else {
        bisection(a, c, e, iterCount);
    }
}

int main() {
    double a, b, e;
    scanf("%lf %lf %lf", &a, &b, &e);
    printf("Iteration\tLower bound(a)\tUpper bound(b)\tMid point(c)\tf(c)\n");
    bisection(a, b, e, 0);
    return 0;
}