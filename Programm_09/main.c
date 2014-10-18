// Copyright © 2013-2014 Martin Ueding <dev@martin-ueding.de>

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "numerov.h"
#include "rk4.h"

double dgl_y(double x, double *y, double *a) {
    //double y_ = y[0];
    double y_prime = y[2];
    //double w_alpha = y[1];
    //double w_alpha_prime = y[3];
    return y_prime;
}

double dgl_y_prime(double x, double *y, double *a) {
    double y_ = y[0];
    //double y_prime = y[2];
    double w_alpha = y[1];
    //double w_alpha_prime = y[3];
    return 2.* y_ /(1.+x)/(1.+x) * w_alpha;
}

double dgl_w_alpha(double x, double *y, double *a) {
    //double y_ = y[0];
    //double y_prime = y[2];
    //double w_alpha = y[1];
    double w_alpha_prime = y[3];
    return w_alpha_prime;
}

double dgl_w_alpha_prime(double x, double *y, double *a) {
    //double y_ = y[0];
    //double y_prime = y[2];
    //double w_alpha = y[1];
    //double w_alpha_prime = y[3];
    return 2. / (1.+x)/(1.+x);
}

void aufgabe1() {
    puts("# Aufgabe 1");
    double h = .01;
    double x;
    double alpha = 5.;
    double y[] = {1., 0., alpha, 1.};
    ode f[] = {dgl_y, dgl_w_alpha, dgl_y_prime, dgl_w_alpha_prime};
    int n = 4;
    struct state s;
    rk4_init_state(n, &s);
    FILE *fp = fopen("out/1.txt", "w");
    assert(fp);
    for (int iter_id = 0; iter_id < 100; iter_id++) {
        y[0] = 1.;
        y[1] = 0.;
        y[2] = alpha;
        y[3] = 1.;
        x = 0.;

        while (x <= 1.) {
            fprintf(fp, "%15g %15g %15g %15g %15g\n", x, y[0], y[1], y[2], y[3]);
            rk4(n, h, &x, y, f, NULL, &s);
        }

        alpha -= (y[0] - .5) / y[1];
    }
    fclose(fp);
}

void aufgabe2() {
    puts("# Aufgabe 2");
    int step_count = 1000;
    double h = .01;

    double s[step_count];
    double u[step_count];
    double r[step_count];

    double e_min;
    double e_max;
    double e;

    e_min = 0.;
    e_max = 1.;

    char *filenames[] = {
        "out/2f-gerade.txt", "out/2f-ungerade.txt",
        "out/2g-gerade.txt", "out/2g-ungerade.txt"
    };
    double u_start[4][2] = {
        {1, 1}, {0, h},
        {1, 1}, {0, h}
    };

    for (int even_odd = 0; even_odd < 4; even_odd++) {
        FILE *fp = fopen(filenames[even_odd], "w");
        assert(fp);
        for (e_max = 1.; e_max < 1000.; e_max += .5) {
            double a = e_min;
            double b = e_max;
            do {
                e = (a+b) / 2.;

                for (int step_id = 0; step_id < step_count; step_id++) {
                    double x = h * step_id;
                    if (even_odd < 2)
                        s[step_id] = 2. * (e - 0.5 *x*x);
                    else
                        s[step_id] = 2. * (e - 0.5 *x*x - 1.5 * x * x * x * x);
                    r[step_count] = 0.;
                }

                u[0] = u_start[even_odd][0];
                u[1] = u_start[even_odd][1];

                numerov(step_count, h, s, u, r);

                int decrement = 2;

                while (1) {
                    if (u[step_count -decrement] > 0) {
                        a = e;
                        break;
                    }
                    else if (u[step_count -decrement] < 0) {
                        b = e;
                        break;
                    }
                    else {
                        decrement++;
                    }
                    //printf("%d\n", decrement);
                }

                //printf("%20f %20g\n", e, u[step_count -decrement]);
            } while (fabs(a - b) >= 1e-9);

            if (e == e_min || e == e_max) {
                //printf("%15f Keine erfolgreiche Bisektion\n", e_max);
            }
            else {
                //printf("%15f %15f\n", e_max, e);
                fprintf(fp, "%f\n", e);
            }
        }
        fclose(fp);
    }
}

int main(int argc, char **argv) {
    aufgabe1();
    aufgabe2();

    return 0;
}
