#pragma once

// Library for graphics
#include "raylib.h"
#include "levelOne.h"
#include "levelTwo.h"
#include <string>

using namespace std;

// Displays level background
void drawLevelBackground(Texture2D levelBackground);
// Displays game elements for current level
void drawGameElements(Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers, Vector2 elementsPos, Vector2 containerPos, bool isElementReturned, bool checkLevelCompletion);

// Drag and drop function for game elements
Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos);

// Checks if the element's container position matches the main container
bool checkMolecules(Vector2 elementsPos, Vector2 containerPos, bool isElementReturned);
// Checks if the level is complete
bool checkLevelCompletion(bool checkLevelCompletion, Vector2 elementPos, Vector2 containerPos);
