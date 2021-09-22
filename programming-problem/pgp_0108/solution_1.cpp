/*
    Problem : รับค่าประโยคมา 1 ประโยคจากนั้นให้เช็คว่าแต่ละตัวมีอักษรซ้ำกันมากน้อยแค่ไหน
    Level : 3
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "Enter string to count : ";

    string text;
    getline(cin, text);

    int result[26];
    for(int i = 0; i < 26; i++) result[i] = 0;

    for(int i = 0; i < text.length(); i++) {

        result[toupper(text.at(i)) - 65]++;
    }

    for(int i = 0; i < 26; i++) cout << (char)(i + 65) << " : " << result[i] << endl;

    return 0;
}