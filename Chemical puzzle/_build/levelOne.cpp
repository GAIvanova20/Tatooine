#include "levelOne.h"

// Displays which level the player is currently on
void displayLevelOne()
{
    DrawText("Level One:", 50, 50, 40, DARKGRAY);
}

// Displays information about the product after the level is finished 
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

// Displays all game elements on screen
void displayLevelOneElements(Texture2D elementsContainers, Texture2D elementsInsideContainers, Rectangle elements, Rectangle elementsCollision, 
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Rectangle elementsInsideContainer, bool checkMolecules)
{
    // Creates an array of objects
	elementsClass element[5];
    // Every elements' name
    string elementsNames[5] = { "Na", "S", "Fe", "S", "Na2"};

    // Fills up element[5]
    for (int i = 0; i < 5; i++)
    {
        // Changes the color of the elements' containers
        if (i % 2 == 0)
        {
            // Green color
            elements.x = 0;
        }
        else
        {
            // Blue color
            elements.x = float(elementsContainers.width / 2);
        }
        element[i] = elementsClass(elementsNames[i], elements, elementsInsideContainer);
    }

    // Displays all elements
    for (int i = 0; i < 5; i++)
    {
        // Checks if one element is in a container
        if (checkMolecules)
        {
            // Displays elements containers
            element[i].drawElement(elementsContainers, elementsCollision, centerElementsColl);
            centerElementsColl.x -= 350;
        }
        else
        {
            // Displays molecules in the container and end level text
            element[i].drawMolecules(elementsInsideContainers, elementsCollision, centerElementsInsideColl);
            drawLevelCompletionText();
        }
    }
}

// Displays all containers on screen
void displayLevelOneContainers(Texture2D container, Rectangle containerRec, Rectangle containerCollision, Vector2 centerContainerColl)
{
    // Displays containers
    for (int i = 0; i < 3; i++)
    {
        DrawTexturePro(container, containerRec, containerCollision, centerContainerColl, 0, RAYWHITE);
        centerContainerColl.x -= 500;
    }

    // Displays chemical equation signs
    DrawText("->", 670, 250, 120, DARKGRAY);
    DrawText("+", 1150, 250, 120, DARKGRAY);
}