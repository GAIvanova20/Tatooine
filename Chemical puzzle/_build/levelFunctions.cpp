#include "levelFunctions.h"

void drawLevelBackground(Texture2D levelBackground)
{
	DrawTexture(levelBackground, 0, 0, RAYWHITE);
}

bool isElementDropped = false;
bool isElementDragged = false;
bool isElementReturned = false;

void drawGameElements(Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers, Texture2D elementsDropped, Vector2 elementsPos, Vector2 containerPos)
{
    Rectangle elements = { 0, 0, elementsContainers.width / 2, elementsContainers.height };
    Rectangle elementsCollision = { elementsPos.x, elementsPos.y, elementsContainers.width / 2, elementsContainers.height};
    Rectangle elementsInsideContainer = { 0, 0, elementsInsideContainers.width / 2, elementsInsideContainers.height };
    Rectangle containerRec = { 0, 0, float(container.width), float(container.height) };
    Rectangle containerCollision = { containerPos.x, containerPos.y, float(container.width), float(container.height) };

    Vector2 centerElementsColl = { float(elementsContainers.width / 4), float(elementsContainers.height / 2) };
    Vector2 centerElementsInsideColl = { float(elementsInsideContainers.width / 3) - 15, float(elementsInsideContainers.height / 3) + 30 };
    Vector2 centerContainerColl = { float(container.width / 2), float(container.height / 2) };

    DrawTexturePro(container, containerRec, containerCollision, centerContainerColl, 0, RAYWHITE);

    if (isElementDropped)
    {
        if (isElementReturned)
        {
            DrawTexturePro(elementsContainers, elements, elementsCollision, centerElementsColl, 0, RAYWHITE);
        }
        else
        {
            DrawTexturePro(elementsInsideContainers, elementsInsideContainer, elementsCollision, centerElementsInsideColl, 0, RAYWHITE);
        }
    }
    else
    {
        DrawTexturePro(elementsContainers, elements, elementsCollision, centerElementsColl, 0, RAYWHITE);
    }
}

Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos)
{
    if(CheckCollisionPointCircle(mousePos, elementsPos, 100))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            elementsPos = mousePos;
            isElementDragged = true;
            isElementReturned = false;
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionCircles(elementsPos, 100, containerPos, 100))
        {
            elementsPos = containerPos;
            isElementDropped = true;
            isElementDragged = false;
            isElementReturned = false;
        }
        else
        {
            isElementDropped = false;
            isElementDragged = false;
            isElementReturned = true;
        }
    }

    return elementsPos;
}

