#include "menu.h"
#include "levelOne.h"

void drawMenu(Texture2D menuBackground)
{
    DrawTexture(menuBackground, 0, 0, RAYWHITE);

    DrawText("Chemical Puzzle", 500, 400, 120, DARKGRAY);
    DrawText("Press ENTER to start or ESC to exit", 590, 510, 40, DARKGRAY);
    DrawText("Created by team Tatooine", 710, 550, 40, DARKGRAY);
}

bool switchToGame(Texture2D menuBackground, Texture2D levelBackground, Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers,
                    bool checkEnter, Vector2 elementsPos, Vector2 containerPos,bool isElementReturned)
{
    if (IsKeyPressed(KEY_ENTER) || checkEnter == 1)
    {
        drawLevelBackground(levelBackground);
        drawGameElements(container, elementsContainers, elementsInsideContainers, elementsPos, containerPos, isElementReturned);
        return 1;
    }
    else
    {
        drawMenu(menuBackground);
        return 0;
    }
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
    Texture2D elementsInsideContainers = LoadTexture("../resources/molecules.png");

    Vector2 mousePos = {-100, -100};
    Vector2 elementsPos = { 300, 800 };
    Vector2 containerPos = { 450, 300 };

    bool checkEnter = 0;
    bool isElementReturned = 0;

    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();

        isElementReturned = checkMolecules(elementsPos, containerPos, isElementReturned);

        elementsPos = dragAndDropElements(mousePos, elementsPos, containerPos);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        checkEnter = switchToGame(menuBackground, levelBackground, container, elementsContainers, elementsInsideContainers, checkEnter, elementsPos, containerPos, isElementReturned);

        EndDrawing();
    }

    UnloadTexture(menuBackground); 
    UnloadTexture(levelBackground);
    UnloadTexture(container);
    UnloadTexture(elementsContainers);
    UnloadTexture(elementsInsideContainers);

    CloseWindow();
}