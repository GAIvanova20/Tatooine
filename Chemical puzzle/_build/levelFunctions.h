#pragma once

#include "raylib.h"

void drawLevelBackground(Texture2D levelBackground);
void drawGameElements(Texture2D container, Texture2D elementsContainers, Vector2 elementsPos, Vector2 containerPos);

Vector2 dragAndDropElements(Vector2 mousePos, Vector2 elementsPos, Vector2 containerPos);