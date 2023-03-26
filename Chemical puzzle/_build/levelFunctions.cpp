#include "levelFunctions.h"

void drawLevelBackground(Texture2D levelBackground)
{
	DrawTexture(levelBackground, 0, 0, RAYWHITE);
}

void drawGameElements(Texture2D container, Texture2D containerElementOne, Texture2D containerElementTwo)
{
	DrawTexture(container, 300, 300, RAYWHITE);
	DrawTexture(containerElementOne, 300, 800, RAYWHITE);
	DrawTexture(containerElementTwo, 600, 800, RAYWHITE);
}