/*
    Level : 2
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

long int largestPrimeFactor(long int number) {

    long int divisor = 2;
    while(number > 1) {

        if(number % divisor == 0) number = number / divisor;
        else divisor ++;
    }
    return divisor;
}

int main() {

    cout << largestPrimeFactor(600851475143) << endl;
    
    return 0;
}