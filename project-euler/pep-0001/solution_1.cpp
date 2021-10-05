/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    int result = 0;
    for(int i = 3; i < 1000; i++) {

        if(i % 3 == 0) result += i;
        else if(i % 5 == 0) result += i;
    }
    cout << result << endl;

    return 0;
}