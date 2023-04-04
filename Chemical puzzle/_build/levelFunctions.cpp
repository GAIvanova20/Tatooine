#include "levelFunctions.h"

// Displays level background
void drawLevelBackground(Texture2D levelBackground)
{
	DrawTexture(levelBackground, 0, 0, RAYWHITE);
}

// Checks if the element's container position matches the main container
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
 
// Checks if the level is complete
bool checkLevelCompletion(bool checkLevelCompletion, Vector2 elementPos, Vector2 containerPos)
{
    // Checks if the task is done
    if ((elementPos.x == containerPos.x && elementPos.y == containerPos.y) || checkLevelCompletion == 1)
    {
        // Checks if player has pressed ENTER
        if (IsKeyPressed(KEY_ENTER) || checkLevelCompletion == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

// Displays game elements for current level
void drawGameElements(Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers, Vector2 elementsPos, Vector2 containerPos, bool isElementReturned, bool checkLevelCompletion)
{
    // Rectangles for all elements and their collisions
    Rectangle elements = { 0, 0, float(elementsContainers.width / 2), float(elementsContainers.height) };
    Rectangle elementsCollision = { elementsPos.x, elementsPos.y, float(elementsContainers.width / 2), float(elementsContainers.height)};
    Rectangle elementsInsideContainer = { 0, 0, float(elementsInsideContainers.width / 2), float(elementsInsideContainers.height) };
    Rectangle containerRec = { 0, 0, float(container.width), float(container.height) };
    Rectangle containerCollision = { containerPos.x, containerPos.y, float(container.width), float(container.height) };

    // Position on screen on all elements
    Vector2 centerElementsColl = { float(elementsContainers.width / 4), float(elementsContainers.height / 2) };
    Vector2 centerElementsInsideColl = { float(elementsInsideContainers.width / 3) - 15, float(elementsInsideContainers.height / 3) + 30 };
    Vector2 centerContainerColl = { float(container.width / 2), float(container.height / 2) };

    if (checkLevelCompletion == 0)
    {
        // Displays level one
        displayLevelOne(elementsContainers, elementsInsideContainers, container,
            elements, elementsCollision, containerRec, containerCollision, elementsInsideContainer,
            centerElementsColl, centerElementsInsideColl, centerContainerColl, checkMolecules(elementsPos, containerPos, isElementReturned));
    }
    else
    {
        // Displays level two
        displayLevelTwo(elementsContainers, elementsInsideContainers, container,
            elements, elementsCollision, containerRec, containerCollision, elementsInsideContainer,
            centerElementsColl, centerElementsInsideColl, centerContainerColl, checkMolecules(elementsPos, containerPos, isElementReturned));
    }
}

// Drag and drop function for game elements
Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos)
{
    // Checks if the player's mouse is on one of the element's container
    if (CheckCollisionPointCircle(mousePos, elementsPos, 100))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            elementsPos = mousePos;
        }
    }

    // Checks if both containers positions match
    if (CheckCollisionCircles(elementsPos, 100, containerPos, 100))
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            elementsPos = containerPos;
        }
    }

    // Re-arranges elements' position after a level is complete
    if(IsKeyReleased(KEY_ENTER))
    {
        elementsPos = {300, 800};
    }

    return elementsPos;
}

