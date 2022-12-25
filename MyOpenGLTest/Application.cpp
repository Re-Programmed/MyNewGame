#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Game/Game.h"
#include "Game/TemplateGame.h"
#include "Rendering/Display/DisplayManager.h"
using namespace Game;
using namespace Rendering::Display;

int main()
{
    TemplateGame tg("Test Game");

    tg.Run();
}