#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Window Console
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

// Star
const int star_count = 80;
COORD stars[star_count];

// Player
COORD player = {0, 0};

int getRandomInt(int a, int b)
{

    return rand() % (b + 1 - a) + a;
}

HANDLE window_handle;
COORD buffer_size = {SCREEN_WIDTH, SCREEN_HEIGHT};
SMALL_RECT window_size = {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1};
CHAR_INFO console_buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

int setConsole()
{

    window_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(window_handle, true, &window_size);
    SetConsoleScreenBufferSize(window_handle, buffer_size);

    return 0;
}

HANDLE handle;
DWORD fdw_mode;

int setMode()
{

    handle = GetStdHandle(STD_INPUT_HANDLE);
    fdw_mode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(handle, fdw_mode);

    return 0;
}

void clearBuffer()
{

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            console_buffer[x + SCREEN_WIDTH * y].Char.AsciiChar = ' ';
            console_buffer[x + SCREEN_WIDTH * y].Attributes = 0;
        }
    }
}

void fillDataToBuffer()
{

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            console_buffer[x + SCREEN_WIDTH * y].Char.AsciiChar = 'A';
            console_buffer[x + SCREEN_WIDTH * y].Attributes = 7;
        }
    }
}

void fillBufferToConsole()
{

    COORD character_pos = {0, 0};
    WriteConsoleOutputA(window_handle, console_buffer, buffer_size, character_pos, &window_size);
}

void initStar()
{

    for (int i = 0; i < star_count; i++)
    {

        stars[i].X = getRandomInt(0, SCREEN_WIDTH - 1);
        stars[i].Y = getRandomInt(0, SCREEN_HEIGHT - 1);
    }
}

void fillStarToBuffer()
{

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {

            for (int i = 0; i < star_count; i++)
            {
                if (stars[i].X == x && stars[i].Y == y)
                {
                    console_buffer[x + SCREEN_WIDTH * y].Char.AsciiChar = '*';
                    console_buffer[x + SCREEN_WIDTH * y].Attributes = 7;
                }
            }
        }
    }
}

void starFall()
{

    for (int i = 0; i < star_count; i++)
    {

        if (stars[i].Y >= SCREEN_HEIGHT - 1)
        {

            stars[i].X = rand() % SCREEN_WIDTH;
            stars[i].Y = 1;
        }
        else
        {

            stars[i].Y++;
        }
    }
}

void setPlayerPosition(int x, int y)
{

    player.X = x;
    player.Y = y;
}

void fillPlayerToBuffer()
{

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {

            if (player.X == x && player.Y == y)
            {

                console_buffer[x + SCREEN_WIDTH * y].Char.AsciiChar = '$';
            }
        }
    }
}

void setPlayerColor(int color)
{

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {

            if (player.X == x && player.Y == y)
            {

                console_buffer[x + SCREEN_WIDTH * y].Attributes = color;
            }
        }
    }
}

bool playerCollideStar()
{

    for (int i = 0; i < star_count; i++)
    {

        if (stars[i].X == player.X && stars[i].Y == player.Y)
        {

            stars[i].X = getRandomInt(0, SCREEN_WIDTH - 1);
            stars[i].Y = getRandomInt(0, SCREEN_HEIGHT - 1);

            return true;
        }
    }
    return false;
}

int main()
{

    DWORD num_events = 0;
    DWORD num_events_read = 0;

    srand(time(NULL));

    setConsole();
    setMode();

    int color = 7;
    int hp = 10;

    setPlayerPosition(10, 10);
    initStar();

    bool is_running = true;
    while (is_running)
    {

        clearBuffer();

        GetNumberOfConsoleInputEvents(handle, &num_events);
        if (num_events != 0)
        {

            INPUT_RECORD *event_buffer = new INPUT_RECORD[num_events];
            ReadConsoleInput(handle, event_buffer, num_events, &num_events_read);
            for (DWORD i = 0; i < num_events_read; i++)
            {

                if (event_buffer[i].EventType == KEY_EVENT &&
                    event_buffer[i].Event.KeyEvent.bKeyDown == true)
                {

                    if (event_buffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
                    {

                        is_running = false;
                    }
                    else if (event_buffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
                    {

                        color = getRandomInt(0, 255);
                    }
                }
                else if (event_buffer[i].EventType == MOUSE_EVENT)
                {

                    int mouse_x = event_buffer[i].Event.MouseEvent.dwMousePosition.X;
                    int mouse_y = event_buffer[i].Event.MouseEvent.dwMousePosition.Y;

                    if (event_buffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
                    {

                        color = getRandomInt(0, 255);
                    }
                    else if (event_buffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
                    {

                        setPlayerPosition(mouse_x, mouse_y);
                    }
                }
            }

            delete[] event_buffer;
        }

        if (hp <= 0)
        {

            is_running = false;
        }

        bool isPlayerCollideStar = playerCollideStar();
        if (isPlayerCollideStar)
            hp--;

        starFall();
        fillStarToBuffer();

        fillPlayerToBuffer();
        setPlayerColor(color);
        fillBufferToConsole();

        Sleep(100);
    }

    clearBuffer();
    fillBufferToConsole();

    return 0;
}