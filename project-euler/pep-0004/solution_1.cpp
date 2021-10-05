/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int isPalindrome(int number) {
    
    int n;
    int temp = number;    
    int reversed_number = 0;
    while(temp > 0) {
        
        n = temp % 10;
        reversed_number = (reversed_number * 10) + n;
        temp = temp / 10;
    }
    if(number == reversed_number) return true;
    return false;
}

int main() {

    int result = 0;
    for(int i = 1; i <= 999; i++) {

        for(int j = 1; j <= 999; j++) {

            if(isPalindrome(i * j) && i * j > result) result = i * j;
        }
    }

    cout << result << endl;
    
    return 0;
}