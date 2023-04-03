#include "menu.h"
#include "levelOne.h"

// Displays game menu
void drawMenu(Texture2D menuBackground)
{
    // Displays menu background
    DrawTexture(menuBackground, 0, 0, RAYWHITE);

    // Displays menu text
    DrawText("Chemical Puzzle", 500, 400, 120, DARKGRAY);
    DrawText("Press ENTER to start or ESC to exit", 590, 510, 40, DARKGRAY);
    DrawText("Created by team Tatooine", 710, 550, 40, DARKGRAY);
}

// Switches between menu and game
bool switchToGame(Texture2D menuBackground, Texture2D levelBackground, Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers,
                    bool checkEnter, Vector2 elementsPos, Vector2 containerPos,bool isElementReturned)
{
    // If ENTER is pressed it switches to game
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

// Main function
void startGame()
{
    // Initialize Window
    InitWindow(1920, 1080, "Chemical Puzzle");

    // Sets FPS to 60
    SetTargetFPS(60);

    // Toogles fullscreen on game
    ToggleFullscreen();

    // Load all textures needed
    Texture2D menuBackground = LoadTexture("../resources/menuBackground.png");
    Texture2D levelBackground = LoadTexture("../resources/levelBackground.png");
    Texture2D container = LoadTexture("../resources/container.png");
    Texture2D elementsContainers = LoadTexture("../resources/elementsContainers.png");
    Texture2D elementsInsideContainers = LoadTexture("../resources/molecules.png");

    Vector2 mousePos = {-100, -100};
    Vector2 elementsPos = { 300, 800 };
    Vector2 containerPos = { 450, 300 };

    // Checks if ENTER is pressed once
    bool checkEnter = 0;
    // Checks if molecules are in the main container
    bool isElementReturned = 0;

    while (!WindowShouldClose())
    {
        // Tracks mouse cursor position
        mousePos = GetMousePosition();

        isElementReturned = checkMolecules(elementsPos, containerPos, isElementReturned);

        // Gets element position due to drag and drop function
        elementsPos = dragAndDropElements(mousePos, elementsPos, containerPos);

        BeginDrawing();

        // Default background if textures don't load
        ClearBackground(RAYWHITE);

        checkEnter = switchToGame(menuBackground, levelBackground, container, elementsContainers, elementsInsideContainers, checkEnter, elementsPos, containerPos, isElementReturned);

        EndDrawing();
    }

    // Unloads textures
    UnloadTexture(menuBackground); 
    UnloadTexture(levelBackground);
    UnloadTexture(container);
    UnloadTexture(elementsContainers);
    UnloadTexture(elementsInsideContainers);

    CloseWindow();
}