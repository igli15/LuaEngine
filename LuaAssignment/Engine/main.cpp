
#include <iostream>
#include <map>
#include <string>

#include "Game.h"
#include "../Game/MainGame.h"

int main() {

    std::srand(time(NULL));

    MainGame* game = new MainGame();

    game->LoadResources(*(Engine::Game::GetResourceManager()));
    game->Build();
    game->Gameloop();

    return 0;

}

