/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <vector>
using namespace std;

int leastCommonMultiplier(vector <int> numbers) {

    int result = 1;

    int highest_number = 0;
    for(int i = 0; i < numbers.size(); i++) {

        if(numbers.at(i) > highest_number) highest_number = numbers.at(i);
    }

    int divisor = 2;
    while(divisor < highest_number) {

        bool is_divisible = false;
        for(int i = 0; i < numbers.size(); i++) {

            if(numbers.at(i) % divisor == 0) {
                numbers.at(i) /= divisor;
                is_divisible = true;
            }
        }

        if(is_divisible) result *= divisor;
        else divisor ++;
    }

    for(int i = 0; i < numbers.size(); i++) {

        result *= numbers.at(i);
    }
    
    return result;
}

int main() {

    vector <int> numbers;
    for(int i = 1; i <= 20; i++) numbers.push_back(i);

    cout << leastCommonMultiplier(numbers) << endl;

    return 0;
}