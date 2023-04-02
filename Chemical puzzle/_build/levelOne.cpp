#include "levelOne.h"

void displayLevelOne()
{
    DrawText("Level One:", 50, 50, 40, DARKGRAY);
}

void drawLevelCompletionText()
{
    DrawText("Level Complete!", 750, 100, 55, DARKGRAY);
    DrawText("Na2S", 400, 450, 50, DARKGRAY);
    DrawText("Na", 920, 300, 50, RAYWHITE);
    DrawText("S", 1440, 300, 50, RAYWHITE);
    DrawText("Did you know?", 750, 550, 55, DARKGRAY);
    DrawText("In the home, Sodium sulfide is used in drain cleaners, household cleaners - ", 50, 700, 45, DARKGRAY);
    DrawText("for the oven, bathroom, hair straighteners, dishwasher soap, and car airbags.", 50, 750, 45, DARKGRAY);
    DrawText("Industrially, it is used in detergents, in cement and", 410, 820, 45, DARKGRAY);
    DrawText("as a precursor in the production of other chemicals.", 410, 870, 45, DARKGRAY);
    DrawText("Press ENTER to continue...", 700, 990, 45, DARKGRAY);
}

void displayLevelOneElements(Texture2D elementsContainers, Texture2D elementsInsideContainers, Rectangle elements, Rectangle elementsCollision, 
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Rectangle elementsInsideContainer, bool checkMolecules)
{
	elementsClass element[5];
    string elementsNames[5] = { "Na", "S", "Fe", "S", "Na2"};

    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
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

            drawLevelCompletionText();
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
    DrawText("->", 670, 250, 120, DARKGRAY);
    DrawText("+", 1150, 250, 120, DARKGRAY);
}