//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_PLAYERCOMPONENT_H
#define LUAASSIGNMENT_PLAYERCOMPONENT_H


#include "../../Engine/Component.h"
#include "../Hand.h"

class PlayerComponent : public Engine::Component {

private:

    Hand* m_hand;

public:
    void Start() override;
    void Update(float timeStep) override;
    bool isHoldingCard = false;
    void AddCardToHand(Card* card);
};


#endif //LUAASSIGNMENT_PLAYERCOMPONENT_H
