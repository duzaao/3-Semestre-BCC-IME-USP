#include <iostream>

using namespace std;
int fast_exp(int a, int e){
    if(e==0) return 1;
    int x = fast_exp(a,e/2); x = x*x%10;
    if(e%2 == 1) x= x*a;
    return x;
}
int main(){

    int n;
    cin >> n;
    cout << fast_exp(8,n)%10 << endl;
}

// gcd(a,b) * lcm (a,b) = a * b