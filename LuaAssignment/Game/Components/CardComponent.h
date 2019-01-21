//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_CARDCOMPONENT_H
#define LUAASSIGNMENT_CARDCOMPONENT_H


#include "../../Engine/Component.h"
#include "../../Engine/SpriteRenderer.h"
#include "../../Game/HandSlot.h"
#include "PlayerComponent.h"
#include "../CardTemplate.h"

class CardComponent : public Engine::Component {

private:
    PlayerComponent* m_playerComponent;
    HandSlot* m_slot;
    bool m_selected = false;
    bool m_hovered = false;
    int m_damage;
    int m_cost;
    std::function<void()> m_ability;

public:
    void Start() override;
    void Update(float timeStep) override;
    void SetHandSlot(HandSlot* slot);
    void PlayCard();
    void SetPlayer(PlayerComponent* playerComponent);
    void SetDamage(int damage);
    void SetCost(int cost);
    void SetAbility(std::function<void()> ability);
    std::function<void()> GetAbility();
    int GetCost();
    int GetDamage();

    HandSlot* GetSlot();
};


#endif //LUAASSIGNMENT_CARDCOMPONENT_H
