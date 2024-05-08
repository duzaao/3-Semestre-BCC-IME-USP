#include <iostream>
#include <cmath> // Biblioteca para usar a função abs (valor absoluto)

using namespace std;

int main() {
int n,i,j,tamanho,pos,x;
int menor = INT16_MAX, maior = 0;
double meio;
int pertoMeio=0;
double MaisPertoDoMeio=INT16_MAX;
cin >> n;

for (i = 0; i < n; i++) {
cin >> tamanho >> x;

meio = tamanho / 2.0;
MaisPertoDoMeio=INT16_MAX;
pertoMeio=0;
menor = INT16_MAX;
maior = 0;

for (j = 0; j < x; j++) {
  cin >> pos;
  if (pos > maior) maior = pos;
  if (pos < menor) menor = pos;

  if (pos>meio)
  {

      if((pos-meio)<MaisPertoDoMeio){
        MaisPertoDoMeio = pos - meio;
        pertoMeio = pos;
      }

  }

  else if((meio-pos)<MaisPertoDoMeio)
  {
      MaisPertoDoMeio = meio - pos;
      pertoMeio = pos;
  }

 
}
if(menor>(tamanho-maior)) menor = tamanho - maior;
if(pertoMeio>meio)
cout << endl << tamanho - pertoMeio << " " << tamanho - menor << endl;
else
cout << endl << pertoMeio << " " << tamanho - menor << endl;

}
return 0;
}