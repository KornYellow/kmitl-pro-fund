/*
    Problem : บวกเมทริกซ์ 2 เมทริกซ์ มิติ m × n
    Level : 4
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int x, y;
    cin >> y >> x;

    vector <vector <int>> mat;
    for(int n = 0; n < 2; n++) {
        for(int j = 0; j < y; j++) {
            if(n == 0) mat.resize(y);
            for(int i = 0; i < x; i++) {
                if(n == 0) mat.at(j).resize(x);
                int temp;
                cin >> temp;
                mat.at(j).at(i) += temp;
            }
        }
    }

    for(int j = 0; j < y; j++) {
        for(int i = 0; i < x; i++) {
            cout << mat.at(j).at(i) << " ";
        }
        cout << endl;
    }

    return 0;
}