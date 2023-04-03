#include "elementsClass.h"

// Default constructor
elementsClass::elementsClass()
{
    elementName = "";
    elementContainer = {0, 0, 0, 0};
    elementMolecules = { 0, 0, 0, 0 };
}

// Constructor for initializing all information needed
elementsClass::elementsClass(string name, Rectangle elementRec, Rectangle molecules)
{
    elementName = name;
    elementContainer = elementRec;
    elementMolecules = molecules;
}

// Displays element containers
void elementsClass::drawElement(Texture2D elementsContainers, Rectangle elementsCollision, Vector2 centerElementsColl)
{
   DrawTexturePro(elementsContainers, elementContainer, elementsCollision, centerElementsColl, 0, RAYWHITE);
}

// Display element molecules
void elementsClass::drawMolecules(Texture2D elementsInsideContainers, Rectangle elementsCollision, Vector2 centerElementsInsideColl)
{
    DrawTexturePro(elementsInsideContainers, elementMolecules, elementsCollision, centerElementsInsideColl, 0, RAYWHITE);
}
