//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_HANDSLOT_H
#define LUAASSIGNMENT_HANDSLOT_H


#include "../Engine/IVector.h"


 class Card;
class HandSlot {

public:
    HandSlot(const unsigned int& pIndex,const Engine::IVector& pPos);
    ~HandSlot();
    Engine::IVector* pos;
    unsigned int index;
    Card* currentCard = nullptr;
    bool IsEmpty();

};


#endif //LUAASSIGNMENT_HANDSLOT_H
