//
// Created by Igli milaqi on 11/10/2018.
//

#ifndef SMFLPROJECT_SPRITERENDERER_H
#define SMFLPROJECT_SPRITERENDERER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Component.h"

namespace Engine
{
    class SpriteRenderer : public Engine::Component {

    private:
            sf::Sprite* m_sprite = nullptr;
            sf::Texture* m_texture = nullptr;
            void CreateSprite(const std::string& filename);
    public:
        SpriteRenderer();
        ~SpriteRenderer() override;
        void Start() override;
       void RenderSprite(sf::RenderWindow& window);
       sf::Sprite* ApplySprite(const std::string& filename);
       sf::Sprite* GetSprite();
    };
}

#endif //SMFLPROJECT_SPRITERENDERER_H
