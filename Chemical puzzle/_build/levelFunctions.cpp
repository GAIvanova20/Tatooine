#include "levelFunctions.h"

void drawLevelBackground(Texture2D levelBackground)
{
	DrawTexture(levelBackground, 0, 0, RAYWHITE);
}

bool checkMolecules(Vector2 elementsPos, Vector2 containerPos, bool isElementReturned)
{
    if (CheckCollisionCircles(elementsPos, 1, containerPos, 1) || IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && isElementReturned == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void drawGameElements(Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers, Vector2 elementsPos, Vector2 containerPos, bool isElementReturned)
{
    Rectangle elements = { 0, 0, float(elementsContainers.width / 2), float(elementsContainers.height) };
    Rectangle elementsCollision = { elementsPos.x, elementsPos.y, float(elementsContainers.width / 2), float(elementsContainers.height)};
    Rectangle elementsInsideContainer = { 0, 0, float(elementsInsideContainers.width / 2), float(elementsInsideContainers.height) };
    Rectangle containerRec = { 0, 0, float(container.width), float(container.height) };
    Rectangle containerCollision = { containerPos.x, containerPos.y, float(container.width), float(container.height) };

    Vector2 centerElementsColl = { float(elementsContainers.width / 4), float(elementsContainers.height / 2) };
    Vector2 centerElementsInsideColl = { float(elementsInsideContainers.width / 3) - 15, float(elementsInsideContainers.height / 3) + 30 };
    Vector2 centerContainerColl = { float(container.width / 2), float(container.height / 2) };

    displayLevelOne();
    displayLevelOneContainers(container, containerRec, containerCollision, centerContainerColl);
    displayLevelOneElements(elementsContainers, elementsInsideContainers, elements, elementsCollision, centerElementsColl,
        centerElementsInsideColl, elementsInsideContainer, checkMolecules(elementsPos, containerPos, isElementReturned));
}

Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos)
{
    if(CheckCollisionPointCircle(mousePos, elementsPos, 100))
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

