/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    unsigned long int answer;
    for(int a = 3; a < 999; a++) {
        
        for(int b = 4; b < 999; b++) {

            for(int c = 5; c < 999; c++) {
                
                if(a + b + c != 1000) continue;
                if((a * a) + (b * b) == (c * c)) answer = a * b * c;
            }
        }
    }
    cout << answer << endl;
    

    return 0;
}