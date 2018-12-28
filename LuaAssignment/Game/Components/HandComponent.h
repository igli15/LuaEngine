//
// Created by Igli milaqi on 29/12/2018.
//

#ifndef LUAASSIGNMENT_HANDCOMPONENT_H
#define LUAASSIGNMENT_HANDCOMPONENT_H


#include "../../Engine/Component.h"
#include <vector>

class Card;
class HandSlot;

class HandComponent : public Engine::Component {

public:
    void Start() override;
    void AddSlots(float slotNumber,float startXPos,float cardWidth,float cardHeight);
    void AddCard(Card* card);
    ~HandComponent() override;

private:
    unsigned int m_maxCardCapacity = 8;
    std::vector<HandSlot*> m_cardSlots;
    HandSlot* FindEmptySlot();

};


#endif //LUAASSIGNMENT_HANDCOMPONENT_H
