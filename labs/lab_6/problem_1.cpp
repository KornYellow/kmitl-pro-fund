#include <stdio.h>

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

void drawShip(int x, int y) {
    movePosition(x, y);
    setCursorColor(GREEN, RED);
    printf(PLAYER);
}

void eraseShip(int x, int y) {  
    movePosition(x, y);
    setCursorColor(BLACK, BLACK);
    printf("     ");
}

class Bullet {
public:
    int x = 0;
    int y = 0;
    bool is_out_of_bounds = true;

    bool shootBullet(int x, int y) {
        // Check If Already Shot
        if (is_out_of_bounds == false) return false;

        // Perform Shot
        is_out_of_bounds = false;
        this->x = x;
        this->y = y;
        return true;
    }
    void updateBullet() {
        // Check Out Of Bounds
        if (y - 1 > 0) this->is_out_of_bounds = true;
        if (is_out_of_bounds == true) return;        

        // Erase Previous Text
        movePosition(this->x, this->y);
        printf(" ");

        this->y--;

        // Draw New One
        movePosition(this->x, this->y);
        printf("O");
    }
};

int main() {

    char input_c = ' ';
    
    int x = 20;
    int y = 20;

    int player_direction = 0;
    bool is_player_shoot = false;
    int can_player_shoot = true;

    const int player_max_bullets = 5;

    // Bullets
    Bullet bullets[player_max_bullets];

    setCursorVisible(false);
    setCursorColor(GREEN, RED);
    drawShip(x, y);

    do {

        // Checking User's Input
        if (_kbhit()) {
           
            input_c = _getch();
            
            if (input_c == 'a') player_direction = -1;
            if (input_c == 'd') player_direction = 1;
            if (input_c == 's') player_direction = 0;
            if (input_c == 'w') is_player_shoot = true;
            
            fflush(stdin);
        }

        // Move Until Player Hits The Bounds
        if (player_direction != 0) {

            // Out Of Bounds
            if (x + player_direction > GAME_WIDTH) player_direction = 0;
            if (x + player_direction < 0) player_direction = 0;

            // Remove Previous Text
            eraseShip(x, y);
            
            // Draw New Text
            x += player_direction;
            drawShip(x, y);
        }

        // Player Perform Shooting
        if (is_player_shoot) {

            // Shoot The Bullet If Possible
            bool is_success_shot = false;
            for (int i = 0; i < player_max_bullets; i++) {
                is_success_shot = bullets[i].shootBullet(x, y - 1);
                if (is_success_shot) break;
            }

            is_player_shoot = false;
        }

        //Update Bullets
        for (int i = 0; i < player_max_bullets; i++) {
            bullets[i].updateBullet();
        }

        Sleep(100);

    } while (input_c != 'x');

    return 0;
}