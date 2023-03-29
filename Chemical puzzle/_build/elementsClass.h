#pragma once
#include "levelFunctions.h"

class elementsClass
{
private:
    string elementName;
    Rectangle elementContainer;
    Rectangle elementMolecules;

public:
    elementsClass(string name, Rectangle elementRec, Rectangle molecules)
    {
        elementName = name;
        elementContainer = elementRec;
        elementMolecules = molecules;
    }

    void displayElement()
    {

    }
};