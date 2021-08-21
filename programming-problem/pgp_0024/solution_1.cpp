/*
    Problem : จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นสามเหลี่ยมที่มีด้านเท่ากับตัวเลขที่รับเข้ามา ดังตัวอย่าง
    Level : 2
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    int n;  
    cout << "Enter number : ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(i >= j) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }

    return 0;
}