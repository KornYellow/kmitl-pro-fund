/*
จงเขียนโปรแกรมเพื่อหาค่า Body Mass Index จากค่าความสูงและน้ำหนัก ซึ่งมีสูตรการคำนวณดังนี้
BMI = Weight / Height^2
เมื่อ Weight มีหน่วยเป็นกิโลกรัม และ Height มีหน่วยเป็นเมตร (เกณฑ์การแบ่งน้ำหนักโดยใช้ BMI , ต่ำกว่า 18.5 น้ำหนักต่ำกว่าเกณฑ์ , 18.5 - 24.9 ปกติ , 25.0 - 29.9 สูงกว่ามาตรฐาน , ตั้งแต่ 30.0 ขึ้นไป อ้วนเกินไป ) (Level 1)
*/

#include <iostream>
using namespace std;

int main() {

    double bmi, weight, height;
    cout << "ใส่น้ำหนักและส่วนสูง : ";
    cin >> weight >> height;

    height = height/100;

    string result;
    bmi = weight/(height*height);
    if(bmi > 30) result = "อ้วนเกินไป";
    else if(bmi > 25) result = "สูงกว่ามาตรฐาน";
    else if(bmi > 18.5) result = "ปกติ";
    else result = "น้ำหนักต่ำกว่าเกณฑ์";

    cout << "คุณ" << result << endl;

    return 0;
}