//
// Created by Igli milaqi on 29/12/2018.
//

#ifndef LUAASSIGNMENT_HANDCOMPONENT_H
#define LUAASSIGNMENT_HANDCOMPONENT_H


#include "../../Engine/Component.h"
#include <vector>
#include <lua.h>

class Card;
class HandSlot;

class HandComponent : public Engine::Component {

public:
    void Start() override;
    void AddSlots(float slotNumber,float startXPos,float cardWidth,float cardHeight);
    void AddCard(Card* card);
    void DecrementCardNumber();
    void DiscardRandomCard();
    ~HandComponent() override;

    int GetCurrentCardNumber();
    unsigned int GetMaxCardCapacity();


private:
    unsigned int m_maxCardCapacity = 7;
    int m_currentCardNumber = 0;
    std::vector<HandSlot*> m_cardSlots;
    HandSlot* FindEmptySlot();

};


#endif //LUAASSIGNMENT_HANDCOMPONENT_H
