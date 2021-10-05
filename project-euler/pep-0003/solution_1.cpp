/*
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

long int largestPrimeFactor(long int number) {

    for(long int i = 2; i < number; i++) {

        if(number % i == 0) return largestPrimeFactor(number / i);
    }
    return number;
}

int main() {

    cout << largestPrimeFactor(600851475143) << endl;
    
    return 0;
}