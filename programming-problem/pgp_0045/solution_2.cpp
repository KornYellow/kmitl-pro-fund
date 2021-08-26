/*
    Problem : จงเขียนฟังก์ชั่น factorial
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter number : ";
    cin >> n;

    int result = 1;
    while(n > 0) {

        result *= n;
        n--;
    }
    cout << result << endl;

    return 0;
}