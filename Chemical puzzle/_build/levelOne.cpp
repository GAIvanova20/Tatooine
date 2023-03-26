#include "levelOne.h"

/*void dragAndDropElements(Texture2D container, Texture2D elementsContainerOne, Texture2D elementsContainerTwo)
{
    Texture2D blueCircle = LoadTexture("resources/blue_circle.png");
    Texture2D yellowCircle = LoadTexture("resources/yellow_circle.png");
    Texture2D greenCircle = LoadTexture(elementsContainerOne);

    Vector2 blueCirclePos = { 100, 100 }; // Blue
    Vector2 yellowCirclePos = { 900, 100 }; // Yellow
    Vector2 greenCirclePos = { 600, 100 }; // Green
    Vector2 mousePos = { -100, -100 };

    bool draggedCircle = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();

        if (draggedCircle)
        {
            greenCirclePos = mousePos;

            if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                draggedCircle = false;

                if (CheckCollisionCircles(greenCirclePos, 50, blueCirclePos, 50))
                {
                    greenCirclePos = blueCirclePos;
                }
                else if (CheckCollisionCircles(greenCirclePos, 50, yellowCirclePos, 50))
                {
                    greenCirclePos = yellowCirclePos;
                }
            }
        }
        else
        {
            if (CheckCollisionPointCircle(mousePos, greenCirclePos, 50))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    draggedCircle = true;
                }
            }
        }

        BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawTexture(blueCircle, blueCirclePos.x - blueCircle.width / 2, blueCirclePos.y - blueCircle.height / 2, WHITE);
        DrawTexture(yellowCircle, yellowCirclePos.x - yellowCircle.width / 2, yellowCirclePos.y - yellowCircle.height / 2, WHITE);
        DrawTexture(greenCircle, greenCirclePos.x - greenCircle.width / 2, greenCirclePos.y - greenCircle.height / 2, WHITE);

        EndDrawing();
    }

    UnloadTexture(blueCircle);
    UnloadTexture(yellowCircle);
    UnloadTexture(greenCircle);
}
*/