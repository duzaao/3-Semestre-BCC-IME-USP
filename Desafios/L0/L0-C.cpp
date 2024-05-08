#include <iostream>

using namespace std;

int res(int a){
    return(a%2);
}

int main() {
    int x;
    cin >> x;

    if(!res(x)) cout << "YES\n";
    else cout << "NO\n"; 
    
}