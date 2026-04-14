#include <iostream>
using namespace std;

bool isFibonacci(int n, int a = 0, int b = 1) {
    if (a == n) return true;      // gtanq ev durs ekanq
    if (a > n) return false;      // der chenq gtel sharunakum enq

    return isFibonacci(n, b, a + b); //rekusia kanchum enq ;
}

int factorial(int n) {
    if (n == 0) return 1;   //baza payman 
    return n * factorial(n - 1);  // recursia,func kanchy
}

int main(){
    cout<<isFibonacci(8)<<" ";
    cout<<factorial(5);
}