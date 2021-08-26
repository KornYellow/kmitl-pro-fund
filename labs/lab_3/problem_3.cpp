/*
    Problem : ให้เขียนการทํางานของโปรแกรมแสดงรูปผีเสื้อที่มีขนาดตามตัวเลขที่ป้อน
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    n --;
    for(int y = -n; y <= n; y++) {
        
        for(int x = -n; x <= n; x++) {

            if(x >= abs(y) || x <= -abs(y)) cout << "*  ";
            else cout << "   ";
        }
        cout << endl;
    } 

    return 0;
}