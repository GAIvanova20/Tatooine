#include "levelFunctions.h"

void drawLevelBackground(Texture2D levelBackground)
{
	DrawTexture(levelBackground, 0, 0, RAYWHITE);
}

void drawGameElements(Texture2D container, Texture2D containerElements)
{
	DrawTexture(container, 300, 300, RAYWHITE);
	DrawTexture(containerElements, 300, 800, RAYWHITE);
}