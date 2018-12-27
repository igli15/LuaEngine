//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_CARDCOMPONENT_H
#define LUAASSIGNMENT_CARDCOMPONENT_H


#include "../../Engine/Component.h"
#include "../../Engine/SpriteRenderer.h"
#include "../../Game/HandSlot.h"

class CardComponent : public Engine::Component {

private:
    Engine::SpriteRenderer* m_spriteRenderer;
    HandSlot* m_slot;
    bool m_selected = false;

public:
    void Start() override;
    void Update(float timeStep) override;
    void SetHandSlot(HandSlot* slot);

};


#endif //LUAASSIGNMENT_CARDCOMPONENT_H
