#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Game/Game.h"
#include "Game/TemplateGame.h"
#include "Rendering/Display/DisplayManager.h"
using namespace Game;
using namespace Rendering::Display;

static TemplateGame* TGame;

int main()
{
    TGame = new TemplateGame("Test Game");

    TGame->Run();
}