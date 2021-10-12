/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

unsigned long int produceChain(unsigned long int number) {

    if(number % 2 == 0) return number / 2;
    return (number * 3) + 1;
}

int countChain(unsigned long int number) {

    int chain_count = 1;
    while(number != 1) {

        number = produceChain(number);
        chain_count ++;
    }
    return chain_count;
}

int main() {

    int highest_chain = 0;
    int number_highest;

    for(int i = 13; i < 1000000; i++) {
        
        unsigned int count_chain = countChain(i);
        
        if(count_chain > highest_chain) {
            
            highest_chain = count_chain;
            number_highest = i;
        }
        
        cout << "Number : " << i << " Chains : " << count_chain << endl;
    }

    cout << number_highest << endl;

    return 0;
}