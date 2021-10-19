/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector <string> name_list;

int main() {

    fstream filename;
    filename.open("names.txt", ios::in);
    
    char c;
    int string_pos = 0;
    string name;
    while(true) {

        filename >> c;
        if(filename.eof()) break;

        if(c == '\"') string_pos ++;
        if(c >= 'A' && c <= 'Z') {
            
            name.push_back(c);
        }
        if(string_pos == 2) {

            name_list.push_back(name.substr());
            name.clear();

            string_pos = 0;
        }
    }
    filename.close();

    sort(name_list.begin(), name_list.end());

    unsigned long int result = 0;
    for(int i = 0; i < name_list.size(); i++) {

        int sum = 0;
        for(int j = 0; j < name_list.at(i).size(); j++) {
            
            sum += name_list.at(i).at(j) - 'A' + 1;
        }

        result += sum * (i + 1);
    }

    cout << result << endl;

    return 0;
}