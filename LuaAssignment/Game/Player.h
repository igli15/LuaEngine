//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_PLAYER_H
#define LUAASSIGNMENT_PLAYER_H


#include "../Engine/Entity.h"
#include "Components/PlayerComponent.h"
#include "Hand.h"

class Player : public Engine::Entity {

public:
    void Build() override;
    void Start() override;

private:
    PlayerComponent* m_playerComponent;
};


#endif //LUAASSIGNMENT_PLAYER_H
