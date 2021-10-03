/*
    Problem : ตรวจว่าเป็นเลขจำนวนเฉพาะหรือไม่
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

bool isPrime(int number) {

    if(number == 1) return false;
    for(int i = number/2; i > 1; i--) {
        if(number % i == 0) return false;
    }
    return true;
}

int main() {

    cout << "Enter number : ";

    int number;
    cin >> number;

    if(isPrime(number)) cout << number << " is a prime number." << endl;
    else cout << number << " is not a prime number." << endl;

    return 0;
}