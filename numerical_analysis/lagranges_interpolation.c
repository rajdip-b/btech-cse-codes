#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    double x;
    double y;
}data;

double lagrange_interpolation(double x, data *arr, int n) {
    double ans = 0.0;
    for (int i = 0; i<n; i++) {
        double mul = 1.0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                mul *= (x-arr[j].x)/(arr[i].x-arr[j].x);
            }
        }
        mul *= arr[i].y;
        ans += mul;
    }
    return ans;
}

int main() {
    int n;
    double x;
    scanf("%d", &n);
    data *arr = (data*) malloc(n*sizeof(data));
    scanf("%lf", &x);
    for (int i=0;i<n;i++){
        scanf("%lf", &arr[i].x);
        scanf("%lf", &arr[i].y);
    }
    printf("Value for x: %lf is %lf\n", x, lagrange_interpolation(x, arr, n));
    return 0;
}