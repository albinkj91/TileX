#include "Scene.h"

using namespace std;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

int main()
{
	Scene scene{WINDOW_WIDTH, WINDOW_HEIGHT};
	scene.run();
    return 0;
}
