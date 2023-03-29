#pragma once

#include "raylib.h"
#include "levelFunctions.h"
#include "elementsClass.h"

void displayLevelOne();
void displayLevelOneElements(Texture2D elementsContainers, Texture2D elementsInsideContainers, Rectangle elements, Rectangle elementsCollision,
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Rectangle elementsInsideContainer, bool checkMolecules);
void displayLevelOneContainers(Texture2D container, Rectangle containerRec, Rectangle containerCollision, Vector2 centerContainerColl);