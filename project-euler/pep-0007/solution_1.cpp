/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

bool isPrimeNumber(unsigned long int number) {

    for(unsigned long int i = 2; i < number; i++) {

        if(number % i == 0) return false;
    }
    return true;
}

int main() {

    int number = 2;
    int prime_number_at = 1;

    int prime_number;
    while(prime_number_at <= 10001) {

        if(isPrimeNumber(number)) {

            prime_number_at ++;
            prime_number = number;
        }
        number ++;
    }

    cout << prime_number << endl;

    return 0;
}