//
// Created by Igli milaqi on 20/01/2019.
//

#ifndef LUAASSIGNMENT_ENEMY_H
#define LUAASSIGNMENT_ENEMY_H

#include "../Engine/Entity.h"
#include "../Engine/SpriteRenderer.h"
#include "../Engine/Sprite.h"
#include "../Engine/Text.h"
#include "Components/EnemyComponent.h"

class Enemy : public Engine::Entity {

public:

    void Build() override;
    void Start() override;
    void Update(float timeStep) override;

private:

    Engine::Text* m_healthText;
    EnemyComponent* m_enemyComponent;
    Engine::Sprite* m_enemyArtSprite;
    Engine::SpriteRenderer* m_spriteRenderer;


};


#endif //LUAASSIGNMENT_ENEMY_H
