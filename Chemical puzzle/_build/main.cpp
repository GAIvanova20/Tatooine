#include "main.h"

int main()
{
    InitWindow(1920, 1080, "Chemical Puzzle");

    SetTargetFPS(60);

    ToggleFullscreen();

    Texture2D menuBackground = LoadTexture("./resources/menuBackground.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(menuBackground, 0, 0, RAYWHITE);
        
        DrawText("Chemical Puzzle", 500, 400, 120, DARKGRAY);
        DrawText("Press ENTER to start or ESC to exit", 590, 510, 40, DARKGRAY);
        DrawText("Created by team Tatooine", 710, 550, 40, DARKGRAY);

        EndDrawing();
    }
    UnloadTexture(menuBackground);

    CloseWindow();
}