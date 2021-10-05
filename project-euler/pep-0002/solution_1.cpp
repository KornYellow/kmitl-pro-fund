/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    int term_first = 1;
    int term_second = 2;

    int result = 0;
    while(term_second < 4000000) {

        if(term_second % 2 == 0) result += term_second;

        int temp = term_second;
        term_second = term_first + term_second;
        term_first = temp;
    }

    cout << result << endl;

    return 0;
}