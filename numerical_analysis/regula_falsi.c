#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x*x-x-1;
}

double linear_interpolation(double a, double b) {
    return (a*f(b)-b*f(a))/(f(b)-f(a));
}

void regula_falsi(double a, double b, double e, int iterCount) {
    iterCount += 1;
    double c = linear_interpolation(a, b);
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);

    printf("%d\t%20lf\t%lf\t%lf\t%lf\n", iterCount, a, b, c, fc);
    if (fabs(fc) <= e){
        printf("Root lies at: %lf\n", c);
    } else if (f(b)*f(c) < 0){
        regula_falsi(c, b, e, iterCount);
    } else {
        regula_falsi(a, c, e, iterCount);
    }
}

int main() {
    double a, b, e;
    scanf("%lf %lf %lf", &a, &b, &e);
    printf("Iteration\tLower bound(a)\tUpper bound(b)\tMid point(c)\tf(c)\n");
    regula_falsi(a, b, e, 0);
    return 0;
}