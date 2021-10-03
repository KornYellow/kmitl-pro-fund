/*
    Problem : จงเขียนโปรแกรมเพื่อรับ String 1 ชุดแล้วแสดงผลลัพธ์เป็นสามเหลี่ยมจาก string ที่รับเข้ามา
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "Enter String : ";

    string input;
    cin >> input;
    
    for(int i = input.length(); i > 0; i--) {
        cout << input.substr(0, i) << endl;
    }

    return 0;
}