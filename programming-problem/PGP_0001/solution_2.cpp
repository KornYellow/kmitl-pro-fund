/*
    Problem : จงเขียนโปรแกรมเพื่อรับค่าตัวเลข 2 ตัว แล้วแสดงผลบวก ลบ คูณ หาร ของตัวเลขทั้งสองตัวนั้น โดยใช้ตัวแปรน้อยที่สุด
    Level : 1
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    double x[2];
    cout << "Enter x and y : ";
    cin >> x[0] >> x[1];

    cout << x[0] << " + " << x[1] << " = " << x[0] + x[1] << endl;
    cout << x[0] << " - " << x[1] << " = " << x[0] - x[1] << endl;
    cout << x[0] << " x " << x[1] << " = " << x[0] * x[1] << endl;
    cout << x[0] << " / " << x[1] << " = " << x[0] / x[1] << endl;

    return 0;
}