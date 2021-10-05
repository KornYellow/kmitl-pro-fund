/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {
    
    unsigned long int natural_sum_squared = 0;
    unsigned long int natural_squared_sum = 0;
    for(int i = 0; i <= 100; i++) {
        natural_sum_squared += i;
        natural_squared_sum += i*i;
    }
    natural_sum_squared = natural_sum_squared * natural_sum_squared;

    cout << natural_sum_squared - natural_squared_sum << endl;
    
    return 0;
}