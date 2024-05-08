#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

using ll = long long;


#include <iostream>

using namespace std;




int main(){

    int t;
    ll n;
    ll n2 , n5;
    ll cont;
    cin >> t;

    for(int i = 0 ; i< t; i++){

        cin >> n;
        cont=0;
        n2 = n5 = n;

        while(n>=5) {
            n /= 5;
            cont += n;
            
        }


        
cout << cont << endl;
    } 
    
    return 0;

}
