#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x+2*x-2;
}

double f_dash(double x) {
    return 2*x+2;
}

void newton_raphson(double x, double e, int iterCount) {
    if (fabs(f(x)) <= e) {
        printf("Root is: %lf\n", x);
    } else {
        double x1 = x - (f(x)/f_dash(x));
        printf("%d\t%20lf\t%lf\t%lf\n",iterCount, x, x1, f(x1));
        newton_raphson(x1, e, ++iterCount);
    }
}

int main() {
    double a, b, e;
    scanf("%lf %lf %lf", &a, &b, &e);
    printf("Iterations\t\tx0\tx\t\tf(x)\n\n");
    newton_raphson((a+b)/2, e, 1);
    return 0;
}