/*
    Problem : ให้ P(x) คือผลรวมตัวเลขตั้งแต่ 1..(x-1) ที่หาร x ได้ลงตัว เช่น P(28) = 1+2+4+7+14 = 28 ให้
เขียนการทํางานในการหาตัวเลข 1-10,000 ว่ามีตัวเลขใดบ้างที่ให้ค่า P(x)=x
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

bool isSpecialNumber(int number) {

    int result = 0;
    for(int i = 1; i < number - 1; i++) {
        
        if(number % i == 0) result += i;
    }
    return (result == number);
}

int main() {

    cout << "Which number between 1 - 10,000 result in P(x) = x" << endl;
    for(int i = 1; i <= 10000; i++) {
        if(isSpecialNumber(i)) {
            cout << i << " ";
        }
    }

    return 0;
}