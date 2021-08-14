/*
จงเขียนการทำงานต่อไปนี้ในรูปแบบภาษาซี (Level 2)
c = 2a+b
c = a^5+a^4+2a^3+3a^2+4a+3
c = 2+3a
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double a, b;

    cout << "ใส่ค่าที่ต้องการคำนวณ" << endl;
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;

    double c1, c2, c3;
    c1 = (2 * a) + b;
    c2 = pow(a, 5) + pow(a, 4) + (2 * pow(a, 3)) + (3 * pow(a, 2)) + (4 * a) + 3;
    c3 = 2 + (3 * a);

    cout << "c = 2a + b : คำตอบ c = " << c1 << endl; 
    cout << "c = a^5 + a^4 + 2a^3 + 3a^2 + 4a + 3 : คำตอบ c = " << c2 << endl;
    cout << "c = 2 + 3a : คำตอบ c = " << c3 << endl;

    return 0;
}