//
// Created by Igli milaqi on 27/12/2018.
//

#include "HandSlot.h"
#include "Card.h"


bool HandSlot::IsEmpty()
{
    return currentCard == nullptr;
}

HandSlot::HandSlot(const unsigned int & pIndex,const Engine::IVector& pPos)
{
    pos = new Engine::IVector(0,0);
    index = pIndex;
    pos->x = pPos.x;
    pos->y = pPos.y;
}

HandSlot::~HandSlot()
{
    delete(pos);
    pos = nullptr;
    currentCard = nullptr;
}

