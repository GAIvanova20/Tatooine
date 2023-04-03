#pragma once

#include "levelFunctions.h"
#include "levelOne.h"

#include <string>

using namespace std;

// Class for elements containers
class elementsClass
{
private:
    string elementName;
    Rectangle elementContainer;
    Rectangle elementMolecules;

public:
    // Default constructor
    elementsClass();
    // Constructor for initializing all information needed
    elementsClass(string name, Rectangle elementRec, Rectangle molecules);

    // Displays element containers
    void drawElement(Texture2D elementsContainers, Rectangle elementsCollision, Vector2 centerElementsColl);
    // Display element molecules
    void drawMolecules(Texture2D elementsInsideContainers, Rectangle elementsCollision, Vector2 centerElementsInsideColl);
};