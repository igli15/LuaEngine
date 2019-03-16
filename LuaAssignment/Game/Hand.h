//
// Created by Igli milaqi on 25/12/2018.
//

#ifndef LUAASSIGNMENT_HAND_H
#define LUAASSIGNMENT_HAND_H


#include <vector>
#include "Card.h"
#include "../Engine/IVector.h"
#include "HandSlot.h"
#include "Components/HandComponent.h"

class Hand : public Engine::Entity {

private:
    float m_startX;
    float m_cardWidth;
    float m_cardHeight ;

    HandComponent* m_handComponent;
    unsigned int m_slotNumber;

public:
    Hand();
    void Build() override;
    HandComponent* GetHandComponent();

};


#endif //LUAASSIGNMENT_HAND_H
