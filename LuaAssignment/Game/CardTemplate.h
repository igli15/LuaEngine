//
// Created by Igli milaqi on 28/12/2018.
//

#ifndef LUAASSIGNMENT_CARDTEMPLATE_H
#define LUAASSIGNMENT_CARDTEMPLATE_H


#include <string>
#include <functional>
#include <SFML/Graphics/Texture.hpp>
#include "../Engine/LuaProgram.h"

class CardTemplate {

protected:
    std::string m_path;
    std::string m_name;
    std::string m_description;
    sf::Texture* m_image;
    float m_cost;
    float m_damage;
    std::function<void()> m_ability;

    Engine::LuaProgram* m_luaProgram;

public:
    CardTemplate();

    std::string Name() const;
    std::string Description() const;
    sf::Texture* Image() const;
    int Cost() const;
    int Damage() const;
    std::function<void()> Ability() const;
};


#endif //LUAASSIGNMENT_CARDTEMPLATE_H
