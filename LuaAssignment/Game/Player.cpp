//
// Created by Igli milaqi on 27/12/2018.
//

#include "Player.h"

void Player::Build()
{
    Entity::Build();
    SetTag("Player");
    m_playerComponent = AddComponent<PlayerComponent>();

}

void Player::Start()
{
    Entity::Start();
}


