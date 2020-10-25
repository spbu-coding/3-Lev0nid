#include <stdio.h>
#include <math.h>

#define EPS 1e-6
#define EPSf 1e-6f

void solve_system_with_float(float delta, float *x, float *y) {
    *y = (delta + 0.0001f) / 0.0001f;
    *x = 2 - *y;
}

void solve_system_with_float_incorrect(float delta, float *x, float *y) {
    *y = (delta + 2.0001f - 2.0f) / 0.0001f;
    *x = 2 - *y;
}

void solve_system_with_double(double delta, double *x, double *y) {
    *y = (0.0001 + delta) / 0.0001;
    *x = 2 - *y;
}

void solve_system_with_double_incorrect(double delta, double *x, double *y) {
    *y = (2.0001 - 2.0 + delta) / 0.0001;
    *x = 2 - *y;
}

double dist_d(double x, double y){
    return sqrt((x - 1) * (x - 1) + (y - 1) * (y - 1));
}

float dist_f(float x, float y) {
    return sqrtf((x - 1) * (x - 1) + (y - 1) * (y - 1));
}

void solve_with_doubles() {
    double x, y, delta = 0.0001, dist = 1;
    int step = 0;

    while(dist > EPS) {
        solve_system_with_double(delta, &x, &y);
        dist = dist_d(x, y);
        delta *= 0.5;
        step++;
        printf("delta = %.16lf\nx = %.16lf y = %.16f\ndist = %.16lf\n", delta, x, y, dist);
    }
    printf("%d steps\n", step);
}

void solve_with_floats() {
    float x, y, delta = 0.0001f, dist = 1;
    int step = 0;

    while(dist > EPSf) {
        solve_system_with_float(delta, &x, &y);
        dist = dist_f(x, y);
        delta *= 0.5f;
        step++;
        printf("delta = %.16lf\nx = %.16lf y = %.16lf\ndist = %.16lf\n", delta, x, y, dist);
    }
    printf("%d steps\n", step);
}

void solve_with_doubles_incorrect() {
    double x, y, delta = 0.0001, dist = 1;
    int step = 0;

    while(dist > EPS) {
        solve_system_with_double_incorrect(delta, &x, &y);
        dist = dist_d(x, y);
        delta *= 0.5;
        step++;
        printf("delta = %.16lf\nx = %.16lf y = %.16f\ndist = %.16lf\n", delta, x, y, dist);
    }
    printf("%d steps\n", step);
}

void solve_with_floats_incorrect() {
    float x, y, delta = 0.0001f, dist = 1;
    int step = 0;

    while(dist > EPSf && step < 50) {
        solve_system_with_float_incorrect(delta, &x, &y);
        dist = dist_f(x, y);
        delta *= 0.5f;
        step++;
        printf("delta = %.16lf\nx = %.16lf y = %.16lf\ndist = %.16lf\n", delta, x, y, dist);
    }
    printf("%d steps\n", step);
}

int main() {
    printf("CORRECT DOUBLES\n");
    solve_with_doubles();
    printf("CORRECT FLOATS\n");
    solve_with_floats();
    printf("INCORRECT DOUBLES\n");
    solve_with_doubles_incorrect();
    printf("INCORRECT FLOATS\n");
    solve_with_floats_incorrect();
    return 0;
}