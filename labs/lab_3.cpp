#include <iostream>
using namespace std;

int main() {

    int n = 5;

    n = n - 1;
    for(int y = -n; y < n + 1; y++) {
        for(int x = -n; x < n + 1; x++) {
            
            int val_left = -abs(y);
            int val_right = abs(y);
            
            if(x <= val_left || x >= val_right) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}