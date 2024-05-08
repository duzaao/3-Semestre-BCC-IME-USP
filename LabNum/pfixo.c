#include <stdio.h>
#include <complex.h>
#include <math.h>

#define N 200
#define MAX_ITER 20
#define TOL 0.000001

// função que retorna o valor absoluto de um número
double mod(double x){
    if(x<0)x*=-1;
    return x;
}

// função que aplica o método iterativo de ponto fixo para encontrar uma solução
double Pfixo(double x) {
    int i = 0;
    double y;
    int modo1 = 0, modo2 = 0; 

    // determina o modo de cálculo de acordo com o valor de x
    if(x<-0.2) modo2 = 1;
    else if(x<2){
        modo1 = 1;
    }

    // aplica o método iterativo de ponto fixo
    if(modo2){
        y = x - (exp(x) - 2 * pow(x,2.0))/(exp(x) - 4*x); 
    }
    else if(modo1){
        y = sqrt(exp(x)/2);
    }
    else {
        y = log(2*pow(x,2.0));
    }
        
    while(mod(y-x) > TOL && i < 200) {
        if(i) x = y;

        if(modo2){
            y = x - (exp(x) - 2 * pow(x,2.0))/(exp(x) - 4*x); 
        }
        else if(modo1){
            y = sqrt(exp(x)/2);
         }
        else {
            y = log(2*pow(x,2.0));
        }
        i++;
    }
    return y;
}

// função principal do programa
int main(){
    double num;
    int n;
    int i =0;
    scanf("%d",&n);

    // loop que lê n números do teclado e aplica o método iterativo de ponto fixo em cada um deles
    while(i<n){
        scanf("%lf", &num);
        printf("%lf\n", Pfixo(num));
        i++;
    }
    return 0;
}
