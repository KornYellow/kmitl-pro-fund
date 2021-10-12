/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <string>
using namespace std;

string getText(int number) {

    string text = "";

    if(number >= 100 && number < 1000) {
        if(number >= 100 && number < 200) { text += "OneHundred"; number -= 100; }
        if(number >= 200 && number < 300) { text += "TwoHundred"; number -= 200; }
        if(number >= 300 && number < 400) { text += "ThreeHundred"; number -= 300; }
        if(number >= 400 && number < 500) { text += "FourHundred"; number -= 400; }
        if(number >= 500 && number < 600) { text += "FiveHundred"; number -= 500; }
        if(number >= 600 && number < 700) { text += "SixHundred"; number -= 600; }
        if(number >= 700 && number < 800) { text += "SevenHundred"; number -= 700; }
        if(number >= 800 && number < 900) { text += "EightHundred"; number -= 800; }
        if(number >= 900 && number < 1000) { text += "NineHundred"; number -= 900; }
        if(number > 0) text += "And";
    }

    switch(number) {
        case 10: text += "Ten"; return text;
        case 11: text += "Eleven"; return text;
        case 12: text += "Twelve"; return text;
        case 13: text += "Thirteen"; return text;
        case 14: text += "Fourteen"; return text;
        case 15: text += "Fifteen"; return text;
        case 16: text += "Sixteen"; return text;
        case 17: text += "Seventeen"; return text;
        case 18: text += "Eighteen"; return text;
        case 19: text += "Nineteen"; return text;
    }

    if(number >= 20 && number < 30) { text += "Twenty"; number -= 20; }
    if(number >= 30 && number < 40) { text += "Thirty"; number -= 30; }
    if(number >= 40 && number < 50) { text += "Forty"; number -= 40; }
    if(number >= 50 && number < 60) { text += "Fifty"; number -= 50; }
    if(number >= 60 && number < 70) { text += "Sixty"; number -= 60; }
    if(number >= 70 && number < 80) { text += "Seventy"; number -= 70; }
    if(number >= 80 && number < 90) { text += "Eighty"; number -= 80; }
    if(number >= 90 && number < 100) { text += "Ninety"; number -= 90; }

    switch(number) {
        case 1: text += "One"; break; // one
        case 2: text += "Two"; break; // two
        case 3: text += "Three"; break; // three
        case 4: text += "Four"; break; // four
        case 5: text += "Five"; break; // five
        case 6: text += "Six"; break; // six
        case 7: text += "Seven"; break; // seven
        case 8: text += "Eight"; break; // eight
        case 9: text += "Nine"; break; // nine
    }

    return text;
}

int main() {

    int count = 0;
    for(int i = 1; i < 1000; i++) {
        count += getText(i).size();
    }

    string thousand = "onethousand";
    count += thousand.size();
    
    cout << count << endl;

    return 0;
}