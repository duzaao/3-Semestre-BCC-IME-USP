#include <stdio.h>
#include <complex.h>
#include <math.h>

#define N 200
#define MAX_ITER 20
#define TOL 0.000001

double complex evalf(double complex z) {
    return cpow(z, 7.0) - 1.0;
}

double complex evalDf(double complex z) {
    return 7.0 * cpow(z, 6.0);

    
}


double complex newton(double complex z) {
    for (int iter = 0; iter < MAX_ITER; iter++) {
        z = z - evalf(z) / evalDf(z);
    }
    return z;
}




void newton_basins(double l, double u, int p) {
    double complex z, sol[7] = {1.0, cexp(2.0 * M_PI * I / 7.0), cexp(4.0 * M_PI * I / 7.0), cexp(6.0 * M_PI * I / 7.0), 
                         cexp(-2.0 * M_PI * I / 7.0), cexp(-4.0 * M_PI * I / 7.0), cexp(-6.0 * M_PI * I / 7.0)};
    double x[p], y[p];
    int C[p][p];

    FILE *fptr;

    // Cria a malha de pontos
    for (int i = 0; i < p; i++) {
        x[i] = l + (u - l) * i / (p - 1);
        y[i] = l + (u - l) * i / (p - 1);
    }

    // Executa o método de Newton em cada ponto da malha
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            z = x[i] + y[j] * I;

            for (int iter = 0; iter < MAX_ITER; iter++) {
                z = newton(z);
            }

            // Encontra a raiz mais próxima
            int index = 0;
            double min_distance = cabs(z - sol[0]);

            for (int k = 1; k < 7; k++) {
                double distance = cabs(z - sol[k]);

                if (distance < min_distance) {
                    index = k;
                    min_distance = distance;
                }
            }

            C[i][j] = index + 1;
        }
    }

    // Escreve os valores em um arquivo
    fptr = fopen("output.txt", "w");

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            fprintf(fptr, "%d ", C[i][j]);
        }

        fprintf(fptr, "\n");
    }

    fclose(fptr);

    // Plota o gráfico utilizando o Gnuplot
    FILE *gp = popen("gnuplot", "w");
    fprintf(gp, "set term pngcairo size 1200,800\n");
    fprintf(gp, "set output 'output.png'\n");
    fprintf(gp, "set view map\n");
    fprintf(gp, "plot 'output.txt' matrix with image\n");
    fclose(gp);
}

int main() {
    double l = -1.5;
    double u = 1.5;
    int p = 200;

    newton_basins(l, u, p);
    //printf("%lf", Pfixo(3.0));

    return 0;
}
