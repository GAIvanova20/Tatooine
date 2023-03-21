#include "menu.h"

void drawMenu(Texture2D menuBackground)
{
    DrawTexture(menuBackground, 0, 0, RAYWHITE);

    DrawText("Chemical Puzzle", 500, 400, 120, DARKGRAY);
    DrawText("Press ENTER to start or ESC to exit", 590, 510, 40, DARKGRAY);
    DrawText("Created by team Tatooine", 710, 550, 40, DARKGRAY);
}

void startGame()
{
    InitWindow(1920, 1080, "Chemical Puzzle");

    SetTargetFPS(60);

    ToggleFullscreen();

    Texture2D menuBackground = LoadTexture("../resources/menuBackground.png");
    Texture2D levelBackground = LoadTexture("../resources/levelBackground.png");
    Texture2D container = LoadTexture("../resources/container.png");
    Texture2D elementsContainers = LoadTexture("../resources/elementsContainers.png");


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //drawMenu(menuBackground);

        drawLevelBackground(levelBackground);
        drawGameElements(container, elementsContainers);

        EndDrawing();
    }
    UnloadTexture(menuBackground); 
    UnloadTexture(levelBackground);
    UnloadTexture(container);
    UnloadTexture(elementsContainers);

    CloseWindow();
}