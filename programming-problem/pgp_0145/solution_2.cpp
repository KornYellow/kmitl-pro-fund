/*
    Problem : ต้องการส่งรหัสบัตรATM แต่เพื่อความปลอดภัยจึงได้นำตัวเลขเหล่านั้นมาซ่อนไว้ในประโยคเช่น HE45L32LO458T6H359ISIS1BO589RNT34ODEVN80AJA ซึ่งตัวเลขที่ถูกซ่อนอยู่จะถูกนำมาบวกกันเป็น 45+32+458+6+359+1+589+34+80 = 1604 นั้นคือจะสามารถใช้รหัส 1604 ในการกดรหัสบัตร ATM ได้นั้นเอง โดยถ้าหากผลรวมที่ได้น้อยกว่า 4 หลักให้ทำการเติมเลข 0 ไปด้านหน้า
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int pow(int num, int times) {

    if(times == 0)return 1;
    int result = num;
    for(int i = 0; i < times - 1; i++) result *= num;
    return result;
}

bool isNumber(char c) {
    
    if(c >= '0' && c <= '9') return true;
    return false;
}

int main() {

    cout << "Enter code : ";

    string input;
    cin >> input;

    int number = 0;
    int digit = 0;
    for(int i = input.length() - 1; i >= 0; i--) {

        if(isNumber(input.at(i))) {
            number += (input.at(i) - 48) * pow(10, digit);
            digit++;
        }
        else {
            digit = 0;
        }
    }
    cout << setfill('0') << setw(4) << number << endl;

    return 0;
}