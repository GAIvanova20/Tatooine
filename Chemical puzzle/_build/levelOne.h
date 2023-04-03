#pragma once

// Library for graphics
#include "raylib.h"
#include "levelFunctions.h"
#include "elementsClass.h"

// Displays which level the player is currently on
void displayLevelOne();
// Displays all game elements on screen
void displayLevelOneElements(Texture2D elementsContainers, Texture2D elementsInsideContainers, Rectangle elements, Rectangle elementsCollision,
    Vector2 centerElementsColl, Vector2 centerElementsInsideColl, Rectangle elementsInsideContainer, bool checkMolecules);
// Displays all containers on screen
void displayLevelOneContainers(Texture2D container, Rectangle containerRec, Rectangle containerCollision, Vector2 centerContainerColl);