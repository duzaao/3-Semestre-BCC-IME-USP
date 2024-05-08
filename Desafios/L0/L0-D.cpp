#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;
    int tamanho = s.length();
    char pal[tamanho];
    memset(pal, 0, sizeof(pal));
    int alfabeto[26] = {0};

    for (int i = 0; i < tamanho; i++) {
        alfabeto[s[i] - 'A']++;
    }

    int impar = 0;
    int letraImpar = 0;
    for (int i = 0; i < 26; i++) {
        if (alfabeto[i] % 2 == 1) {
            impar++;
            letraImpar = i;
        }
    }

    if (impar > 1) {
        cout << "NO SOLUTION\n";
    } else {
        int j = 0;
        for (int i = 0; i < 26; i++) {
            while (alfabeto[i] >= 2) {
                pal[j++] = 'A' + i;
                pal[tamanho - j] = 'A' + i;
                alfabeto[i] -= 2; 
            }
        }
        if (impar == 1) {
            pal[tamanho/2] = 'A' + letraImpar;
        }
        
        for (int i = 0; i < tamanho; i++) {
            cout << pal[i];
        }
    }

    return 0;
}