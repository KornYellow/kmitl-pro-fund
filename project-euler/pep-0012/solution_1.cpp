/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <cmath>
using namespace std;

int countFactor(int number) {

    int factor_count = 1;
    for(int i = 1; i < sqrt(number); i++) {

        if(number % i == 0) {

            if(number / i == i) factor_count ++;
            else factor_count += 2;
        }
    }
    return factor_count;
}

int main() {

    unsigned long int number = 1;
    int index = 2;
    while(true) {

        int factor = countFactor(number);
        cout << "Number : " << number << " Factor : " << factor << endl;
        if(factor > 500) {
            
            std::cout << number << std::endl;
            break;
        }      

        number += index;
        index ++;
    }

    return 0;
}