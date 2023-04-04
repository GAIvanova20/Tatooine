#pragma once

// Library for graphics
#include "raylib.h"
#include "levelFunctions.h"
#include "elementsClass.h"

// Displays level two
void displayLevelTwo(Texture2D elementsContainers, Texture2D elementsInsideContainers, Texture2D container,
    Rectangle elements, Rectangle elementsCollision, Rectangle containerRec, Rectangle containerCollision, Rectangle elementsInsideContainer,
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Vector2 centerContainerColl, bool checkMolecules);