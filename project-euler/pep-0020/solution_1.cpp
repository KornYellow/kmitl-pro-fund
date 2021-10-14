/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <vector>
using namespace std;

vector <int> number(401, 0);

int main() {

    number.at(398) = 1;

    int fact = 99;
    while(fact) {

        int carry = 0;
        for(int j = number.size() - 1; j >= 0; j--) {

            number.at(j) *= fact;

            number.at(j) += carry;
            carry = 0;
            
            while(number.at(j) > 9) {

                number.at(j) -= 10;
                carry += 1;
            }
        }
        
        fact--;
    }

    unsigned int result = 0;
    for(int i = 0; i < number.size(); i++) {

        result += number.at(i);
    }
    cout << result << endl;

    return 0;
}