//
// Created by Igli milaqi on 20/01/2019.
//

#ifndef LUAASSIGNMENT_ENEMYCOMPONENT_H
#define LUAASSIGNMENT_ENEMYCOMPONENT_H

#include "../../Engine/Component.h"

#include <iostream>
#include <vector>


class PlayerComponent;

class EnemyComponent : public Engine::Component {

public:
    void Start() override ;
    void Update(float timeStep) override;
    void DealDamage(int damage);
    void SetPlayerComponent(PlayerComponent* p);
    int GetHealth();
    void PickRandomAbility();

    void FreezePlayer();

    void DamagePlayer();
    void DiscardPlayerCard();

    void OnTurnStart();
    void EndTurn();

private:
    int m_health;

    bool m_IsTurn ;

    PlayerComponent* m_playerComponent;

    std::vector<std::function<void()>> m_abilities;

};


#endif //LUAASSIGNMENT_ENEMYCOMPONENT_H
