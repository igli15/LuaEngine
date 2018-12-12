//
// Created by Igli milaqi on 20/10/2018.
//

#ifndef SMFLPROJECT_TEXTCOMPONENT_H
#define SMFLPROJECT_TEXTCOMPONENT_H

#include "Component.h"
#include "Text.h"

namespace sf
{
    class RenderWindow;
    class Text;
    class Font;
}

namespace Engine
{
    class TextComponent : public Engine::Component {

    private:
        sf::Text* m_text;
        sf::Font* m_font;
        float m_width;
        float m_height;

    public:
        void Start() override;
        void SetText(const std::string& text);
        void SetFont(const sf::Font& font);
        void SetCharacterSize(int size);
        void SetColor(const sf::Color& color);
        void SetOrigin(const float& x, const float& y);
        void DrawText(sf::RenderWindow& window);
        sf::Text* GetText();
        float Width();
        float Height();
        ~TextComponent() override;

    };
}

#endif //SMFLPROJECT_TEXTCOMPONENT_H
