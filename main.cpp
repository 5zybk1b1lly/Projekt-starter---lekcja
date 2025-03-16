#include <iostream>
#include "Poks.hpp"
#include "moves.hpp"
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include <queue>

using namespace std;


void draw_gui();

int main()
{

    const int screenWidth = 1400;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "GigantMony");



    SetTargetFPS(60);
    while (!WindowShouldClose())
    {


        BeginDrawing();
        ClearBackground(SKYBLUE);
        draw_gui();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void draw_gui()
{
    Rectangle menu {-2, 810, 900, 310};
    DrawRectangleLinesEx(menu, 4, BLACK);

    DrawText("Atack", 15, 850, 30, BLACK);
    DrawText("Defend", 15, 900, 30, BLACK);
    DrawText("Special Atack", 15, 950, 30, BLACK);

    Rectangle console {906, 810, 600, 310};
    DrawRectangleLinesEx(console, 4, BLACK);
}