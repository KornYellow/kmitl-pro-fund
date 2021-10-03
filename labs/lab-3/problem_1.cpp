/*
    Problem : ให้เขียนการทํางานของการหาผลบวกของตัวเลขโดดที่ไม่ใช่ 0 ทุกตัวในตัวเลขที่ป้อน ไปเรื่อยๆ จนกว่าจะเป็นเลขหลักเดียวเช่นเมื่อป้อน input เป็น 123456 จะได้ผลลัพธ์คือ 123456 -> 21-> 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    string number;
    cin >> number;

    cout << number;
    while(number.size() > 1) {

        int number_added = 0;
        for(int i = 0; i < number.size(); i++) {

            number_added += (int)number.at(i) - 48;
        }
        number = to_string(number_added);
        cout << " -> " << number;
    }

    return 0;
}