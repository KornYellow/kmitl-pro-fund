/*
    Problem : จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นรูปผีเสื้อที่มีขนาดของปีกแต่ละข้างเท่ากับตัวเลขที่รับเข้ามา
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    cout << "Enter number : ";
    
    int n;
    cin >> n;

    n = (n * 2) - 1;
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            int anchor_point_1 = i;
            int anchor_point_2 = n - i - 1;
            if((i >= n/2 && j >= anchor_point_1) ||
               (i <= n/2 && j <= anchor_point_1) ||
               (i <= n/2 && j >= anchor_point_2) ||
               (i >= n/2 && j <= anchor_point_2)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }

    return 0;
}