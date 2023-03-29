#pragma once

#include "raylib.h"
#include "levelOne.h"
#include <string>

using namespace std;

void drawLevelBackground(Texture2D levelBackground);
void drawGameElements(Texture2D container, Texture2D elementsContainers, Texture2D elementsInsideContainers, Vector2 elementsPos, Vector2 containerPos, bool isElementReturned);

Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos);

bool checkMolecules(Vector2 elementsPos, Vector2 containerPos, bool isElementReturned);
