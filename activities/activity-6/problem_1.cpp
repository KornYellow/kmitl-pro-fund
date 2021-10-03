/*
    Problem : ให้นักศึกษาสร้างฟังก์ชั่น swap(int*, int*) ที่สามารถสลับค่าที่เก็บอยู่ในตัวแปร 2 ตัวได้ และเขียนโปรแกรมเพื่อทดสอบการทำงานของฟังก์ชั่น swap
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b) {

    int temp = *a;
    a = b;
    b = &temp;
}

int main() {

    cout << "Enter two numbers (A B) : ";

    int a, b;
    cin >> a >> b;

    swap(a, b);
    cout << "Two numbers has been swapped (B A) : " << a << " " << b;

    return 0;
}