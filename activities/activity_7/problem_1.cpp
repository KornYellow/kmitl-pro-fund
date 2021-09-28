#include <iostream>
#include <fstream>
using namespace std;

int main() {

    int player_level[5];
    int player_score[5];
    for(int i = 0; i < 5; i++) {

        cout << "Player [" << i + 1 << "] Level : "; 
        cin >> player_level[i];
        cout << "Player [" << i + 1 << "] Score : ";
        cin >> player_score[i];
    }

    ofstream fout;
    fout.open("highscore.txt");

    while(fout) {
        for(int i = 0; i < 5; i++) {

            string temp = to_string(player_level[i]) + "," + to_string(player_score[i]);
            fout << temp << endl; 
        }   
        break;
    }
    
    fout.close();

    cout << "Players data saved."<< endl;
    
    return 0;
}