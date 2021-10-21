/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <string> result;

void permutation(string input, int index) {

    if(index == input.size()) {

        result.push_back(input);

        return;
    }

    for(int i = index; i < input.size(); i++) {

        swap(input[i], input[index]);
        permutation(input, index + 1);
        swap(input[i], input[index]);
    }

    return;
}

int main() {

    string input = "0123456789";
    permutation(input, 0);

    sort(result.begin(), result.end());
    cout << result.at(1000000 - 1) << endl;

    return 0;
}