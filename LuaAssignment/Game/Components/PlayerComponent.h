//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_PLAYERCOMPONENT_H
#define LUAASSIGNMENT_PLAYERCOMPONENT_H


#include "../../Engine/Component.h"

class Hand;
class Card;
class Deck;

class PlayerComponent : public Engine::Component {

private:

    Hand* m_hand;
    Deck* m_deck;

public:
    void Start() override;
    void Update(float timeStep) override;
    bool isHoldingCard = false;
    void AddCardToHand(Card* card);
    void DrawCard();
};


#endif //LUAASSIGNMENT_PLAYERCOMPONENT_H
