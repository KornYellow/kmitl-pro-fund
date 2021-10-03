/*
    Problem : จงเขียนโปรแกรมเพื่อรับ String 1 ชุดแล้วแสดงผลลัพธ์เป็นสามเหลี่ยมจาก string ที่รับเข้ามา
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <string>
using namespace std;

void printTriangleString(string input) {

    if(input.length() <= 0) return;
    cout << input << endl;
    printTriangleString(input.substr(0, input.length() - 1));
}

int main() {

    cout << "Enter String : ";

    string input;
    cin >> input;

    printTriangleString(input);
    
    return 0;
}