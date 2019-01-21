//
// Created by Igli milaqi on 20/01/2019.
//

#ifndef LUAASSIGNMENT_PLAYERINFO_H
#define LUAASSIGNMENT_PLAYERINFO_H

#include "../Engine/Entity.h"
#include "../Engine/TextComponent.h"
#include "Components/PlayerComponent.h"

class PlayerInfo : public Engine::Entity {

public:
    void Build() override;
    void Start() override;
    void Update(float timeStep) override;

    void SetPlayerComponent(PlayerComponent* p);

private:
    Engine::TextComponent* deckInfoText;
    PlayerComponent* m_playerComponent;
    Engine::Text* m_pressButtonText;

};


#endif //LUAASSIGNMENT_PLAYERINFO_H
