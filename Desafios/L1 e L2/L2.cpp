/*Soma acumulada*/

#include <iostream>

using namespace std;

void AcSum(int* vet, int tam, int x[]){


    for(int i = 0;i<tam;i++){

        if(!i) {x[i] = vet[i];} 
        else{
        x[i] = x[i-1] + vet[i]; 
        }

    }
}

int main(){

    int n,i,a,b;
    
    cin >> n;
    int vet[n];
    int sum[n];
    for(i=0;i<n;i++){
        cin >> vet[i];
    }

    AcSum(vet,n, sum);

    int x;
    cin >> x;
    for(i = 0; i<x;i++) {
        cin >> a >> b;
        if(a!=min(a,b)){
            int aux = a;
            a = b;
            b = aux;
            
        }
        if(a==b) cout << vet[b] << endl;
        else
            if(a!=0)
            cout << sum [b] - sum[a-1] << endl;
            else cout << sum[b]<< endl;
    }



}


