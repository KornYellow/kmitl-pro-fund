/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<unsigned long int>> samples(21, vector<unsigned long int> (21, 0));

int main() {

    for(int i = 0; i < samples.size(); i++) {

        for(int j = 0; j < samples.at(i).size(); j++) {

            if(i == 0 || j == 0) samples.at(i).at(j) = 1;
            else {

                samples.at(i).at(j) = samples.at(i - 1).at(j) + samples.at(i).at(j - 1);
            }
        }
    }

    cout << samples.at(20).at(20) << endl;

    return 0;
}