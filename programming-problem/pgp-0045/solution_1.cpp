/*
    Problem : จงเขียนฟังก์ชั่น factorial
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int factorial(int number) {

    if(number == 1) return 1;
    return number * factorial(number - 1);
}

int main() {

    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << factorial(n) << endl;

    return 0;
}