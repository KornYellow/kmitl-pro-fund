#include <stdio.h>
#include <windows.h>
#include <conio.h>

const int GAME_WIDTH = 80;
const int GAME_HEIGHT = 25;
char PLAYER[6] = "<=O=>";

void movePosition(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void drawShip(int x, int y) {
    movePosition(x, y);
    printf(PLAYER);
}
void eraseShip(int x, int y) {
    movePosition(x, y);
    printf("     ");
}
int main() {
    char input_c = ' ';
    int x = 20;
    int y = 20;
    drawShip(x, y);
    do {
        if (_kbhit()) {
            input_c = _getch();
            if (input_c == 'a') {
                if (x - 1 >= 0) {
                    eraseShip(x, y);
                    drawShip(--x, y);
                }
            }
            if (input_c == 'd') {
                if (x + 1 <= GAME_WIDTH) {
                    eraseShip(x, y);
                    drawShip(++x, y);
                }
            }
            if (input_c == 'w') { 
                if (y - 1 >= 0) {
                    eraseShip(x, y);
                    drawShip(x, --y);
                }
            }
            if (input_c == 's') { 
                if (y + 1 <= GAME_HEIGHT) {
                    eraseShip(x, y);
                    drawShip(x, ++y);
                }
            }
            fflush(stdin);
        }
        Sleep(100);
    } while (input_c != 'x');

    return 0;
}