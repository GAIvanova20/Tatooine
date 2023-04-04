#include "levelTwo.h"

// Displays information about the product after the level is finished 
void drawLevelTwoCompletionText()
{
    DrawText("Level Complete!", 750, 100, 55, DARKGRAY);
    DrawText("Ca(OH)", 370, 450, 50, DARKGRAY);
    DrawText("2", 545, 470, 35, DARKGRAY);
    DrawText("2HCL", 890, 300, 50, RAYWHITE);
    DrawText("CaCl", 1390, 300, 50, RAYWHITE);
    DrawText("2", 1505, 315, 35, RAYWHITE);
    DrawText("Did you know?", 750, 550, 55, DARKGRAY);
    DrawText("As an astringent, calcium chloride is used in the canning of vegetables,", 120, 680, 45, DARKGRAY);
    DrawText("in the preparation of tofu, in the processing of caviar. It is commonly used as", 90, 730, 45, DARKGRAY);
    DrawText("an electrolyte in sports and other drinks, including bottled water. ", 120, 780, 45, DARKGRAY);
    DrawText("The extremely salty taste of calcium chloride is used", 410, 850, 45, DARKGRAY);
    DrawText("to flavor pickles while not increasing the sodium content of food.", 320, 900, 45, DARKGRAY);
    DrawText("Press ENTER to continue...", 700, 990, 45, DARKGRAY);
}

// Displays all game elements on screen
void displayLevelTwoElements(Texture2D elementsContainers, Texture2D elementsInsideContainers, Rectangle elements, Rectangle elementsCollision,
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Rectangle elementsInsideContainer, bool checkMolecules)
{
    // Creates an array of objects
    elementsClass element[6];
    // Every elements' name
    string elementsNames[6] = { "(OH)2", "Ca", "H", "Ca", "Na", "Cl"};

    // Fills up element[5]
    for (int i = 0; i < 6; i++)
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
    for (int i = 0; i < 6; i++)
    {
        // Checks if one element is in a container
        if (checkMolecules)
        {
            // Displays elements containers
            element[i].drawElement(elementsContainers, elementsCollision, centerElementsColl);
            centerElementsColl.x -= 250;
        }
        else
        {
            // Displays molecules in the container and end level text
            element[i].drawMolecules(elementsInsideContainers, elementsCollision, centerElementsInsideColl);
            drawLevelTwoCompletionText();
        }
    }
}

// Displays all containers on screen
void displayLevelTwoContainers(Texture2D container, Rectangle containerRec, Rectangle containerCollision, Vector2 centerContainerColl)
{
    // Displays containers
    for (int i = 0; i < 3; i++)
    {
        DrawTexturePro(container, containerRec, containerCollision, centerContainerColl, 0, RAYWHITE);
        centerContainerColl.x -= 500;
    }

    // Displays chemical equation signs and water
    DrawText("+", 670, 250, 120, DARKGRAY);
    DrawText("->", 1150, 250, 120, DARKGRAY);
    DrawText("+ 2H O", 1580, 280, 50, DARKGRAY);
    DrawText("2", 1695, 300, 35, DARKGRAY);
}

// Displays level two
void displayLevelTwo(Texture2D elementsContainers, Texture2D elementsInsideContainers, Texture2D container,
    Rectangle elements, Rectangle elementsCollision, Rectangle containerRec, Rectangle containerCollision, Rectangle elementsInsideContainer,
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Vector2 centerContainerColl, bool checkMolecules)
{
	DrawText("Level Two: Using the elements below, create CaCl", 50, 50, 40, DARKGRAY);
    DrawText("2", 1060, 70, 30, DARKGRAY);
    displayLevelTwoContainers(container, containerRec, containerCollision, centerContainerColl);
    displayLevelTwoElements(elementsContainers, elementsInsideContainers, elements, elementsCollision,
        centerElementsColl, centerElementsInsideColl, elementsInsideContainer, checkMolecules);
}