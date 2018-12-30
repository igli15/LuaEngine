//
// Created by Igli milaqi on 20/10/2018.
//

#include "TextComponent.h"
#include "Scene.h"
#include <SFML/Graphics.hpp>

void Engine::TextComponent::Start()
{
    Component::Start();
    m_parent->parentScene->m_textRenderVector.push_back(this);
    m_font = new sf::Font();
    m_font->loadFromFile("../Assets/DefaultFont.ttf");
    m_text = new sf::Text();
    m_text->setFont(*m_font);

    m_text->setString("This is Text");  //Default string
    m_width = m_text->getLocalBounds().width;
    m_height = m_text->getLocalBounds().height;

}

void Engine::TextComponent::SetText(const std::string &text)
{
    m_text->setString(text);

    m_width = m_text->getLocalBounds().width;
    m_height = m_text->getLocalBounds().height;

}

void Engine::TextComponent::SetFont(const sf::Font &font)
{
    *m_font = font;
    m_text->setFont(font);

    m_width = m_text->getLocalBounds().width;
    m_height = m_text->getLocalBounds().height;
}

void Engine::TextComponent::SetCharacterSize(int size)
{
    m_text->setCharacterSize(size);

    m_width = m_text->getLocalBounds().width;
    m_height = m_text->getLocalBounds().height;
}

void Engine::TextComponent::SetColor(const sf::Color &color)
{
    m_text->setFillColor(color);
}

void Engine::TextComponent::DrawText(sf::RenderWindow &window)
{
    sf::RenderStates textRenderStates(m_text->getTransform());

    textRenderStates.transform *= m_parent->getTransform();

    if(m_parent->GetParentEntity() != nullptr)
    {
        textRenderStates.transform *= m_parent->GetParentEntity()->getTransform();
    }

    window.draw(*m_text,textRenderStates);
}

Engine::TextComponent::~TextComponent()
{
    auto iterator = std::find(m_parent->parentScene->m_textRenderVector.begin(),
                              m_parent->parentScene->m_textRenderVector.end(),this);

    if(iterator != m_parent->parentScene->m_textRenderVector.end())
    {

        m_parent->parentScene->m_textRenderVector.erase(iterator);
    }

    delete m_text;
    delete m_font;
    m_text = nullptr;
    m_font = nullptr;
}

sf::Text *Engine::TextComponent::GetText()
{
    return m_text;
}

void Engine::TextComponent::SetOrigin(const float &x, const float &y)
{
    m_text->setOrigin(x,y);
}

float Engine::TextComponent::Width()
{
    return m_width;
}

float Engine::TextComponent::Height()
{
    return m_height;
}

