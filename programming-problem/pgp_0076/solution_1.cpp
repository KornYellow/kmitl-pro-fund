/*
    Problem : บวกเมทริกซ์ 2 เมทริกซ์ มิติ m × n
    Level : 4
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
using namespace std;

int main() {

    int x, y;
    cin >> y >> x;
    
    int mat[x][y];
    for(int j = 0; j < y; j++) {
        for(int i = 0; i < x; i++) {
            cin >> mat[i][j];
        }
    }

    for(int j = 0; j < y; j++) {
        for(int i = 0; i < x; i++) {
            int temp;
            cin >> temp;
            mat[i][j] += temp;
        }
    }

    for(int j = 0; j < y; j++) {
        for(int i = 0; i < x; i++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

