#include "levelOne.h"

void displayLevelOne()
{
    DrawText("Level One:", 50, 50, 40, DARKGRAY);
}

void displayLevelOneElements(Texture2D elementsContainers, Texture2D elementsInsideContainers, Rectangle elements, Rectangle elementsCollision, 
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Rectangle elementsInsideContainer, bool checkMolecules)
{
	elementsClass element[5];
    string elementsNames[5] = { "Na", "S", "Fe", "S", "Na2"};

    for (int i = 0; i < 5; i++)
    {
        if(i % 2 == 0)
        {
            elements.x = 0;
        }
        else
        {
            elements.x = float(elementsContainers.width / 2);
        }
        element[i] = elementsClass(elementsNames[i], elements, elementsInsideContainer);
    }

    for (int i = 0; i < 5; i++)
    {
        if (checkMolecules)
        {
            element[i].drawElement(elementsContainers, elementsCollision, centerElementsColl);
            centerElementsColl.x -= 350;
        }
        else
        {
            element[i].drawMolecules(elementsInsideContainers, elementsCollision, centerElementsInsideColl);
        }
    }
}

void displayLevelOneContainers(Texture2D container, Rectangle containerRec, Rectangle containerCollision, Vector2 centerContainerColl)
{
    for (int i = 0; i < 3; i++)
    {
        DrawTexturePro(container, containerRec, containerCollision, centerContainerColl, 0, RAYWHITE);
        centerContainerColl.x -= 500;
    }
    DrawText("+", 670, 250, 120, DARKGRAY);
    DrawText("->", 1150, 250, 120, DARKGRAY);
}