/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNumber(unsigned long int number) {

    if(number == 1) return false;
    for(unsigned long int i = 2; i <= sqrt(number); i++) {

        if(number % i == 0) return false;
    }
    return true;
}

int main() {

    unsigned long int result = 0;
    unsigned long int number = 2;
    while(number <= 2000000) {
        if(isPrimeNumber(number)) {
            result += number;
            cout << number << endl;
        }
        number ++;
    }

    cout << result << endl; 

    return 0;
}