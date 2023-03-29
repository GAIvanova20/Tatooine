#pragma once

#include "levelFunctions.h"
#include "levelOne.h"

#include <string>

using namespace std;

class elementsClass
{
private:
    string elementName;
    Rectangle elementContainer;
    Rectangle elementMolecules;

public:
    elementsClass();
    elementsClass(string name, Rectangle elementRec, Rectangle molecules);

    void drawElement(Texture2D elementsContainers, Rectangle elementsCollision, Vector2 centerElementsColl);
    void drawMolecules(Texture2D elementsInsideContainers, Rectangle elementsCollision, Vector2 centerElementsInsideColl);
};