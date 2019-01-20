//
// Created by Igli milaqi on 20/01/2019.
//

#ifndef LUAASSIGNMENT_ENEMYCOMPONENT_H
#define LUAASSIGNMENT_ENEMYCOMPONENT_H

#include "../../Engine/Component.h"

class PlayerComponent;

class EnemyComponent : public Engine::Component {

public:
    void Start() override ;
    void Update(float timeStep) override;
    void DealDamage(int damage);
    void SetPlayerComponent(PlayerComponent* p);
    int GetHealth();
    void OnTurnStart();

private:
    int m_health;

    bool m_IsTurn ;

    PlayerComponent* m_playerComponent;
};


#endif //LUAASSIGNMENT_ENEMYCOMPONENT_H
