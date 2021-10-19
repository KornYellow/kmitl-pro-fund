/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <cmath>
using namespace std;

int sumOfDivisor(int number) {

    int sum = 0;
    for(int i = 1; i <= number / 2; i++) {

        if(number % i == 0) sum += i;
    }

    return sum;
}

int main() {

    int result = 0;
    for(int i = 1; i < 10000; i++) {

        int sum = sumOfDivisor(i);
        if(i == sumOfDivisor(sum) && i != sum) result += i;
    }

    cout << result << endl;

    return 0;
}