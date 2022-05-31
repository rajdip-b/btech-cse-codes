#include <stdio.h>

double f(double x, double y) {
    return((x - y)/2);
}

double rk_method(double x0, double y0, double x, double h) {
    int n = (int)((x-x0)/h);

    while (n--) {
        double k1 = h*f(x0, y0);
        double k2 = h*f((x0+(0.5*h)), (y0+(0.5*k1)));
        double k3 = h*f((x0+(0.5*h)), (y0+(0.5*k2)));
        double k4 = h*f(x0+h, y0+k3);
        y0 += (double)(1.0/6.0)*(k1+2*k2+2*k3+k4);
        x0 += h;
    }
    return y0;
}

int main() {
    double x0, y0, x, h;
    scanf("%lf %lf %lf %lf", &x0, &y0, &x, &h);
    printf("Value of y at x = %lf is %lf\n", x, rk_method(x0, y0, x, h));
    return 0;
}