//
// Created by Igli milaqi on 24/12/2018.
//

#ifndef LUAASSIGNMENT_SPRITE_H
#define LUAASSIGNMENT_SPRITE_H


#include "Entity.h"
#include "SpriteRenderer.h"

namespace Engine {


    class Sprite : public Engine::Entity {

    public:
        void Build() override;
        SpriteRenderer* GetSpriteRenderer();


    private:
        SpriteRenderer* m_spriteRenderer;

    };
}

#endif //LUAASSIGNMENT_SPRITE_H
