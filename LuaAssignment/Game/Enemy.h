//
// Created by Igli milaqi on 20/01/2019.
//

#ifndef LUAASSIGNMENT_ENEMY_H
#define LUAASSIGNMENT_ENEMY_H

#include "../Engine/Entity.h"
#include "../Engine/SpriteRenderer.h"
#include "../Engine/Sprite.h"

class Enemy : public Engine::Entity {

public:

    void Build() override;
    void Start() override;

private:

    Engine::Sprite* m_enemyArtSprite;
    Engine::SpriteRenderer* m_spriteRenderer;


};


#endif //LUAASSIGNMENT_ENEMY_H
