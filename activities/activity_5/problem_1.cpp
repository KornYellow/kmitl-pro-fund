/*
    Problem : ให้นักศึกษา เขียนโปรแกรม รับ string 1 ชุด แล้ว แสดงผล string โดยถ้ามี ตัวอักษรติดกันซ้ำกัน ให้ตัดออกเหลือเพียง 1 ตัว
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <string>
using namespace std;

string cutAccessChar(string input) {

    char temp_char = '\0';
    string result;

    for(int i = 0; i < input.size(); i++) {

        if(input.at(i) != temp_char) {
            temp_char = input.at(i);
            result.push_back(temp_char);
        }
    }
    
    return result;
}

int main() {

    cout << "Enter string : ";

    string input;
    cin >> input;
    
    cout << "Cut string : " << cutAccessChar(input) << endl;

    return 0;
}