/*
    Problem : จงเขียนโปรแกรมรับความยาวของด้านทั้ง 3 ของสามเหลี่ยมแล้วแสดงผลพื้นที่ของสามเหลี่ยมรูปนี้ในกรณีที่เป็นด้านของสามเหลี่ยม และจะแสดงค่าเป็น 0 ถ้าไม่เป็นด้านของสามเหลี่ยม
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <cmath>
using namespace std;

bool triangleCheck(double a, double b, double c) {

    if(a + b > c && a + c > b && b + c > a) return true;
    return false;
}

double calculateTriangleArea(double a, double b, double c) {

    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {

    double a, b, c;
    cout << "Enter triangle sides (a b c) : " << endl;
    cin >> a >> b >> c;

    if(triangleCheck(a, b, c)) {
        cout << "Triangle area : " << calculateTriangleArea(a, b, c) << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}