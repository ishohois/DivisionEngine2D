#include "GameObject.h"
#include <vector>

class GameManager
{
private:
    std::vector<GameObject *> gameObjects;

protected:
public:
    void runGameLoop();
    void add(GameObject *gameObject);
};
