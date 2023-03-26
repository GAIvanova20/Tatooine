#include "levelFunctions.h"

void drawLevelBackground(Texture2D levelBackground)
{
	DrawTexture(levelBackground, 0, 0, RAYWHITE);
}

void drawGameElements(Texture2D container, Texture2D elementsContainers, Vector2 elementsPos, Vector2 containerPos)
{
    Rectangle elements = { 0, 0, elementsContainers.width / 2, elementsContainers.height };
    Rectangle elementsCollision = { elementsPos.x, elementsPos.y, elementsContainers.width / 2, elementsContainers.height };
    Rectangle containerRec = { 0, 0, container.width, container.height };
    Rectangle containerCollision = { containerPos.x, containerPos.y, container.width, container.height };

    Vector2 centerElementsColl = { float(elementsContainers.width / 4), float(elementsContainers.height / 2) };
    Vector2 centerContainerColl = { float(container.width / 2), float(container.height / 2) };

	DrawTexturePro(container, containerRec, containerCollision, centerContainerColl, 0, RAYWHITE);
    DrawTexturePro(elementsContainers, elements, elementsCollision, centerElementsColl, 0, RAYWHITE);
}

Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos)
{
        if (CheckCollisionPointCircle(mousePos, elementsPos, 100))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                elementsPos = mousePos;
            }
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            if (CheckCollisionCircles(elementsPos, 100, containerPos, 100))
            {
                elementsPos = containerPos;
            }
        }

    return elementsPos;
}

