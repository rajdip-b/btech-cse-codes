#include <stdio.h>

double f(double x, double y) {
    return (x + y + x * y);
}

double eulers_ode(double x0, double y0, double x, double h) {
    if (x0 == x){
        return y0;
    }else {
        y0 += h*f(x0, y0);
        x0 += h;
        printf("y = %lf, x = %lf\n", x0, y0);
        return eulers_ode(x0, y0, x, h);
    }
}

int main() {
    double x0, y0, x, h;
    scanf("%lf %lf %lf %lf", &x0, &y0, &x, &h);
    printf("Value of y at x = %lf is %lf\n", x, eulers_ode(x0, y0, x, h));
    return 0;
}