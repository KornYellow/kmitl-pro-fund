/*
    Problem : จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นรูปผีเสื้อที่มีขนาดของปีกแต่ละข้างเท่ากับตัวเลขที่รับเข้ามา
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout << "Enter number : ";
    
    int n;
    cin >> n;

    n--;
    for(int y = n; y >= -n; y--) {

        for(int x = n; x >= -n; x--) {

            if(x >= abs(y) || x <= -abs(y)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }

    return 0;
}