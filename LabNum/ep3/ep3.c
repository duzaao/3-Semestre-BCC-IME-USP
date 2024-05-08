#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Função para calcular o polinômio de Lagrange
double lagrangeInterpolation(double x, double* xData, double* yData, int dataSize) {
    double result = 0.0;

    for (int i = 0; i < dataSize; i++) {
        double term = yData[i];

        for (int j = 0; j < dataSize; j++) {
            if (j != i) {
                term *= (x - xData[j]) / (xData[i] - xData[j]);
            }
        }

        result += term;
    }

    return result;
}

// Função para calcular F(x) cos(θ(x)) usando a interpolação de Lagrange
double f(double x) {
    double xData[] = {0, 5, 10, 15, 20, 25, 30}; // Valores de x na Tabela 1
    double yData[] = {0.0, 1.5297, 9.5120, 8.7025, 2.8087, 1.0881, 0.3537}; // Valores de F(x) cos(θ(x)) interpolados

    int dataSize = sizeof(xData) / sizeof(xData[0]); // Tamanho dos dados interpolados

    return lagrangeInterpolation(x, xData, yData, dataSize);
}

// Função para aproximar a integral usando a regra do trapézio composto
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

// Função para aproximar a integral usando a regra de Simpson composto
double simpsonRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2.0 * f(x) : 4.0 * f(x);
    }

    return (h / 3.0) * sum;
}


double monteCarloIntegration_2_1(int n, double (*g)(double)) {
    int i;
    double sum = 0.0;
    
    // Inicializa a semente aleatória
    srand(time(NULL));
    
    for (i = 0; i < n; i++) {
        // Gera um número aleatório no intervalo [0, 1]
        double u = (double)rand() / RAND_MAX;
        
        // Calcula g(Ui) / n e adiciona ao somatório
        sum += g(u) / n;
    }
    
    return sum;
}
double monteCarloIntegration_2_2(int n, double (*g)(double, double)) {
    int i;
    double sum = 0.0;
    
    // Inicializa a semente aleatória
    srand(time(NULL));
    
    for (i = 0; i < n; i++) {
        // Gera dois números aleatórios no intervalo [-1, 1]
        double x = ((double)rand() / RAND_MAX) * 2 - 1;
        double y = ((double)rand() / RAND_MAX) * 2 - 1;
        
        // Calcula g(x, y) e adiciona ao somatório
        sum += 4*g(x, y) / n;
    }
    
    return sum;
}

double seno(double x){
    return sin(x);
}

double x3(double x){
    return 4*(4*x+3)*(4*x+3)*(4*x+3); 
}

double ex(double u){
    return exp(log(1 - u))/(1 - u); 
}


double circunf(double x, double y) {
    // Função g(x, y) que verifica se (x, y) está dentro da circunferência
    double distance = x * x + y * y;
    if (distance <= 1.0) return 1.0;
    else return 0.0;
}




int main() {
    int n;
    double integral;
    int n1;
    double trapResult;
    double simpsonResult;
    printf ("\n\n\n -------------------- PARTE 1 -------------------- \n\n\n");

    double a = 0.0; // Limite inferior de integração
    double b = 30.0; // Limite superior de integração
    printf("Entre com o valor de n (número de amostras): ");
    scanf("%d", &n1);


    trapResult = trapezoidalRule(a, b, n1);
    simpsonResult = simpsonRule(a, b, n1);

    printf("Resultado usando a regra do trapézio composto: %lf\n", trapResult);
    printf("Resultado usando a regra de Simpson composto: %lf\n", simpsonResult);

    printf ("\n\n\n -------------------- PARTE 2 --------------------\n\n\n");
    printf("Entre com o valor de n (número de amostras): ");
    scanf("%d", &n);
    
    // Integrando a função seno(x)
    integral = monteCarloIntegration_2_1(n, seno);
    printf("Integral de seno(x) no intervalo [0, 1]: %lf\n", integral);
    
    // Integrando a função x^3
    integral = monteCarloIntegration_2_1(n, x3);
    printf("Integral de x^3 no intervalo [3, 7]: %lf\n", integral);
    
    // Integrando a função e^x
    integral = monteCarloIntegration_2_1(n, ex);
    printf("Integral de e^-x no intervalo [0, inf]: %lf\n", integral);
    
    // Integrando a função circunf(x, y)
    integral = monteCarloIntegration_2_2(n, circunf);
    printf("Área da circunferência no primeiro quadrante: %lf\n\n", integral);

        printf ("\n -------------------------------------------------\n\n\n");
    
    return 0;
}



