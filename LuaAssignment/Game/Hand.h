//
// Created by Igli milaqi on 25/12/2018.
//

#ifndef LUAASSIGNMENT_HAND_H
#define LUAASSIGNMENT_HAND_H


#include <vector>
#include "Card.h"
#include "../Engine/IVector.h"
#include "HandSlot.h"

class Hand {

public:


    Hand(float startX, float cardWidth, float cardHeight);
    void AddCard(Card* card);
    ~Hand();

private:
    unsigned int m_maxCardCapacity = 8;
    unsigned int m_slotNumber = 5;
    std::vector<HandSlot*> m_cardSlots;
    HandSlot* FindEmptySlot();


};


#endif //LUAASSIGNMENT_HAND_H
