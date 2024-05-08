#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    int cont =0;
    int contF;

    while (t--) {
        int n, ok = 0;
        char c;

        cin >> n >> c;

        string s;
        cin >> s;
        s = s + s;

        contF = 0;
        cont=0;
        for(int i=0; (i< 2*n); i++){
            if(s[i]==c) ok = 1;
            if(s[i]!= 'g' && ok) cont++;
            else{
                if(contF<cont)contF = cont;
                cont = 0;
                ok=0;
            }

                
            
        }
        cout <<contF << endl;
    }
        
    return 0;
}
