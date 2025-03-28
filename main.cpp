#include <iostream>
#include "Poks.hpp"
#include "moves.hpp"
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include <queue>

using namespace std;


void draw_gui(int selected, deque<string> &console_output);
void update_output_queue(deque<string> &output, string line);

int main()
{
    const int screenWidth = 1400;
    const int screenHeight = 1000;
    int selected_idx{};
    deque<string> console_output(5);
    
    InitWindow(screenWidth, screenHeight, "GigantMony");
    //Poks(string name, int hp, int ad, int def, Element _el, const char *path)
    Poks player("Air", 20, 10, 5, Element::Air,"resources/air.png");
    Poks enemy("Earth", 20, 10, 5, Element::Earth, "resources/earth.png");
    



    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_UP))
        {
            selected_idx--;
            selected_idx = selected_idx < 0 ? 2 : selected_idx;
        }
        if (IsKeyPressed(KEY_DOWN))
        {
            selected_idx++;
            selected_idx = selected_idx > 2 ? 0 : selected_idx;
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            string text{};
            switch (selected_idx)
            {
            case 0:
 
                player.attack(enemy, text);
                update_output_queue(console_output, text);
 
                enemy.attack(player, text);
                update_output_queue(console_output, text);
                break;
            case 1:
                player.defend(text);
                update_output_queue(console_output, text);
 
                enemy.attack(player, text);
                update_output_queue(console_output, text);
                break;
            case 2:
                player.special(enemy, text);
                update_output_queue(console_output, text);
 
                enemy.attack(player, text);
                update_output_queue(console_output, text);
                break;
            default:
                break;
            }
        }


        BeginDrawing();
        ClearBackground(SKYBLUE);
        draw_gui(selected_idx, console_output);
        player.render(screenWidth / 2 - 520, screenHeight / 2 - 220);
        enemy.render(screenWidth / 2 + 150, screenHeight / 2 - 350);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void draw_gui(int selected, deque<string> &console_output)
{
    Rectangle menu {-2, 810, 900, 310};
    DrawRectangleLinesEx(menu, 4, BLACK);

    DrawText("Atack", 15, 850, 30, BLACK);
    DrawText("Defend", 15, 900, 30, BLACK);
    DrawText("Special Atack", 15, 950, 30, BLACK);

    Rectangle selection {10, 830 + selected * 50, 300, 60};
    DrawRectangleLinesEx(selection, 4, BLACK);

    Rectangle console {906, 810, 600, 310};
    DrawRectangleLinesEx(console, 4, BLACK);
    int offset = 0;
    for (auto line : console_output)
    {
        DrawText(line.c_str(), 920, 820 + offset, 20, BLACK);
        offset += 30;
    }
}
void update_output_queue(deque<string> &output, string line)
{
    output.push_back(line);
    if (output.size() > 5)
    {
        output.pop_front();
    }
}