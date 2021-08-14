/*
    จงเขียนโปรแกรมรับชื่อ นามสกุล และรหัสนักศึกษาของนักศึกษา 3 คน แล้วนำมาจัดอยู่ในตารางโดยให้ชื่อและนามสกุลของนักศึกษาอยู่ชิดด้านซ้ายของตาราง ส่วนรหัสอยู่ชิดขวาของตารางดังรูป (Level 1)
    +-------------+------------+-------------+
    |   Thanunchai|    Threepak|    400400444|
    |Thanunchai   |Threepak    |	400400445|
    |Thanunchai   |    Threepak|	400400446|
    +-------------+------------+-------------+

    Max first_name = 13
    Max last_name = 12
    Max student_id = 13

    Thanunchai Threepak 400400444
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    string first_name[3], last_name[3], student_id[3];
    int first_name_count[3], last_name_count[3], student_id_count[3], space_count;

    for(int i = 0; i < 3; i++) {

        cout << "Student Number [" << i + 1 << "]" << endl;

        cout << "[" << i + 1 << "]First Name : ";
        cin >> first_name[i];
        cout << endl;

        cout << "[" << i + 1 << "]Last Name : ";
        cin >> last_name[i];
        cout << endl;

        cout << "[" << i + 1 << "]Student ID : ";
        cin >> student_id[i];
        cout << endl;
        
        first_name_count[i] = min((int)first_name[i].length(), 13);
        last_name_count[i] = min((int)last_name[i].length(), 12);
        student_id_count[i] = min((int)student_id[i].length(), 13);
    }

    cout << "+-------------+------------+-------------+" << endl;
    for(int i = 0; i < 3; i++) {

        cout << "|";
        if(i == 0) {

            space_count = 13 - first_name_count[i];
            for(int j = 0; j < space_count; j++) cout << " "; //Print Space
            for(int j = 0; j < first_name_count[i]; j++) cout << first_name[i].at(j); //Print First Name

            cout << "|";
            space_count = 12 - last_name_count[i];
            for(int j = 0; j < space_count; j++) cout << " "; //Print Space
            for(int j = 0; j < last_name_count[i]; j++) cout << last_name[i].at(j); //Print Last Name
        }
        else if(i == 1) {

            for(int j = 0; j < 13; j++) {

                if(j < first_name_count[i]) cout << first_name[i].at(j);
                else cout << " "; 
            }

            cout << "|";
            for(int j = 0; j < 12; j++) {

                if(j < last_name_count[i]) cout << last_name[i].at(j);
                else cout << " "; 
            }
        }
        else if(i == 2) {
            
            for(int j = 0; j < 13; j++) {

                if(j < first_name_count[i]) cout << first_name[i].at(j);
                else cout << " "; 
            }

            cout << "|";
            space_count = 12 - last_name_count[i];
            for(int j = 0; j < space_count; j++) cout << " "; //Print Space
            for(int j = 0; j < last_name_count[i]; j++) cout << last_name[i].at(j); //Print Last Name
        }

        cout << "|";
        space_count = 13 - student_id_count[i];
        for(int j = 0; j < space_count; j++) cout << " "; //Print Space
        for(int j = 0; j < student_id_count[i]; j++) cout << student_id[i].at(j); //Print Student ID
        
        cout << "|" << endl;
    }
    cout << "+-------------+------------+-------------+" << endl;

    return 0;
}