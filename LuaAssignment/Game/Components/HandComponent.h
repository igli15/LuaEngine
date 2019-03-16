//
// Created by Igli milaqi on 29/12/2018.
//

#ifndef LUAASSIGNMENT_HANDCOMPONENT_H
#define LUAASSIGNMENT_HANDCOMPONENT_H


#include "../../Engine/Component.h"
#include <vector>
extern "C"
{
#include <lua.h>
}


class Card;
class HandSlot;

class HandComponent : public Engine::Component {

public:
    void Start() override;
    void AddSlots(float slotNumber,float startXPos,float cardWidth,float cardHeight);
    void AddCard(Card* card);
    void DecrementCardNumber();
    void DiscardRandomCard();
    void DecreaseCostOfACard(int amount);
    ~HandComponent() override;

    int GetCurrentCardNumber();
    unsigned int GetMaxCardCapacity();


    static void SetHandInstance(HandComponent* handComponent);
    static int luaDiscardRandomCard(lua_State* lua_state);
    static int luaDecreaseCostOfACard(lua_State *lua_state);

private:

    unsigned int m_maxCardCapacity = 7;
    int m_currentCardNumber = 0;
    std::vector<HandSlot*> m_cardSlots;
    HandSlot* FindEmptySlot();


    static HandComponent* handInstance;

};


#endif //LUAASSIGNMENT_HANDCOMPONENT_H
