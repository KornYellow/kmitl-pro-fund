/*
จงเขียนโปรแกรมเพื่อรับค่าตัวเลข 2 ตัว แล้วแสดงผลบวก ลบ คูณ หาร ของตัวเลขทั้งสองตัวนั้น โดยใช้ตัวแปรน้อยที่สุด (Level 1)
*/

#include <iostream>
using namespace std;

int main() {

    double x, y;
    cin >> x >> y;

    cout << "ผลบวก : " << x + y << endl;
    cout << "ผลลบ : " << x - y << endl;
    cout << "ผลคูณ : " << x * y << endl;
    cout << "ผลหาร : " << x / y << endl;

    return 0;
}