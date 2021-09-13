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

bool isNumber(char c) {
    
    if(c >= '0' && c <= '9') return true;
    return false;
}

int main() {

    cout << "Enter code : ";

    string input;
    cin >> input;

    int result = 0;

    int pointer_1 = 0;
    int pointer_2 = 0;
    while(true) {
        
        if(pointer_1 < input.length() && isNumber(input[pointer_1])) {

            pointer_1 ++;

        } else {
            
            if(pointer_2 != pointer_1) {
                
                string number_string = input.substr(pointer_2, pointer_1 - pointer_2);
                result += stoi(number_string);
            }

            pointer_1 ++;
            pointer_2 = pointer_1;
        }

        if(pointer_1 > input.length()) break;
    }

    cout << setfill('0') << setw(4) << result << endl;

    return 0;
}