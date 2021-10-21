/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sumOfDivisor(int number) {

    int number_sqrt = (int)sqrt(number);
    int sum = 1;

    if(number == 1) return 1;
    if(number == number_sqrt * number_sqrt) {

        sum += number_sqrt;
        number_sqrt --;
    }

    for(int i = 2; i <= number_sqrt; i++) {

        if(number % i == 0) {
            
            sum += i + (number / i);
        }
    }

    return sum;
}

int main() {

    const int limit = 28123;

    vector <int> abundant_numbers;
    for(int i = 2; i <= limit; i++) {

        if(sumOfDivisor(i) > i) {

            abundant_numbers.push_back(i);
        }
    }

    bool is_abundant[limit + 1];
    for(int i = 0; i < abundant_numbers.size(); i++) {

        for(int j = i; j < abundant_numbers.size(); j++) {

            if(abundant_numbers.at(i) + abundant_numbers.at(j) <= limit) {

                is_abundant[abundant_numbers.at(i) + abundant_numbers.at(j)] = true;
            }
        }
    }

    unsigned long int result = 0;

    for(int i = 0; i <= limit; i++) {

        if(!is_abundant[i]) {

            result += i;
        }
    }
    
    cout << result << endl;

    return 0;
}