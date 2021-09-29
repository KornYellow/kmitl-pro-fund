#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

const int GAME_WIDTH = 80;
const int GAME_HEIGHT = 25;
char PLAYER[6] = "<=O=>";

enum TEXT_COLOR {
    BLACK, BLUE, GREEN, AQUA,
    RED, PURPLE, YELLOW, WHITE,
    GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_AQUA,
    LIGHT_RED, LIGHT_PURPLE, LIGHT_YELLOW, BRIGHT_WHITE
};

void setCursorVisible(bool is_visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lp_cursor;
    lp_cursor.bVisible = is_visible;
    lp_cursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lp_cursor);
}

void setCursorColor(int foreground, int background) {
    HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h_console, background * 16 + foreground);
}

void movePosition(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void drawText(int x, int y, int foreground, int background) {
    movePosition(x, y);
    setCursorColor(foreground, background);
}

void eraseText(int x, int y) {
    movePosition(x, y);
    setCursorColor(BLACK, BLACK);
}

int randomInt(int a) {

    return rand() % a;
}

int randomIntRange(int a, int b) {

    return rand() % (b + 1 - a) + a;
}

char getCharAtPosition(int x, int y) {
    HANDLE h_std = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x, y};
    DWORD num_read;
    if (!ReadConsoleOutputCharacter(h_std, (LPTSTR)buf, 1, c, (LPDWORD)&num_read)) {
        return '\0';
    }
    else {
        return buf[0];
    }
}

class Bullet {
public:
    int x = 0;
    int y = 0;
    bool is_out_of_bounds = true;
    bool shootBullet(int x, int y) {
        if (!this->is_out_of_bounds) return false;
        
        // Move Bullet To Player Location
        this->x = x + 2;
        this->y = y - 1;
        this->is_out_of_bounds = false;
        return true;
    }
    bool isBulletHitStar(int x, int y) {
        if (getCharAtPosition(x, y) == '*') {
            // Remove Bullet
            this->is_out_of_bounds = true;
            eraseText(this->x, this->y);
            printf(" ");

            // Beep
            Beep(700, 100);

            return true;
        }
        return false;
    }
    void updateBullet() {
        if (this->is_out_of_bounds) return;

        // Remove Last Text
        eraseText(this->x, this->y);
        printf(" ");

        // Draw New Text
        this->y--;
        drawText(this->x, this->y, YELLOW, BLACK);
        printf("^");
        
        // Out Of Bounds
        if (this->y <= 0) {
            this->is_out_of_bounds = true;
            eraseText(this->x, this->y);
            printf(" ");
        }
    }
};

class Star {
public:
    int x = -1;
    int y = -1;
    
    // Constructor
    Star() {
        this->randomNewPosition();
    }

    // Random Position
    void randomNewPosition() {
        // Remove Previous Text
        eraseText(this->x, this->y);
        printf(" ");
        
        // Random
        this->x = randomIntRange(10, 70);
        this->y = randomIntRange(2, 5);
    }

    // Update Star
    void updateStar() {
        // Draw New Text
        drawText(this->x, this->y, GREEN, BLACK);
        printf("*");
    }
};

int main() {

    // Random Seed
    srand(time(NULL));

    char input_c = ' ';

    // Score
    int score = 0;

    // Player
    int x = 20;
    int y = 20;

    int player_direction = 0;
    bool is_player_shoot = false;

    setCursorVisible(false);

    drawText(x, y, BLUE, BLACK);
    printf(PLAYER);

    // Bullets
    const int player_max_bullets = 5;
    Bullet bullets[player_max_bullets];

    // Stars
    const int max_stars = 20;
    Star stars[max_stars];

    do {

        // Checking User's Input
        if (_kbhit()) {

            input_c = _getch();

            if (input_c == 'a') player_direction = -1;
            if (input_c == 'd') player_direction = 1;
            if (input_c == 's') player_direction = 0;
            if (input_c == ' ') is_player_shoot = true;

            fflush(stdin);
        }

        // Move Until Player Hits The Bounds
        if (player_direction != 0) {

            // Out Of Bounds
            if (x + player_direction > GAME_WIDTH) player_direction = 0;
            if (x + player_direction < 0) player_direction = 0;

            // Remove Previous Text
            eraseText(x, y);
            printf("     ");

            // Draw New Text
            x += player_direction;
            drawText(x, y, BLUE, BLACK);
            printf(PLAYER);
        }

        // Player Perform Shoot Action
        if (is_player_shoot) {

            // Shoot If Possible
            for (int i = 0; i < player_max_bullets; i++) {
                
                if (bullets[i].shootBullet(x, y)) break;
            }

            is_player_shoot = false;
        }

        // Star Update
        for (int i = 0; i < max_stars; i++) {

            stars[i].updateStar();
        }

        // Bullet Update
        for (int i = 0; i < player_max_bullets; i++) {

            // Check if Bullet Hit Star
            if (bullets[i].isBulletHitStar(bullets[i].x, bullets[i].y - 1)) {

                // Increase Score
                score += 10;

                // Destroy Star
                for (int j = 0; j < max_stars; j++) {
                    if (bullets[i].x == stars[j].x && bullets[i].y - 1 == stars[j].y) {
                        stars[j].randomNewPosition();
                    }
                }
            }
            bullets[i].updateBullet();
        }
        
        // Score Update
        drawText(GAME_WIDTH, 2, WHITE, BLACK);
        printf("Score : %d", score);

        Sleep(100);

    } while (input_c != 'x');

    return 0;
}