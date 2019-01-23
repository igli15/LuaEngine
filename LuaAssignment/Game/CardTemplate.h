//
// Created by Igli milaqi on 28/12/2018.
//

#ifndef LUAASSIGNMENT_CARDTEMPLATE_H
#define LUAASSIGNMENT_CARDTEMPLATE_H


#include <string>
#include <functional>
#include <SFML/Graphics/Texture.hpp>
#include "../Engine/LuaProgram.h"
#include "Components/DeckComponent.h"

class CardTemplate {

protected:
    std::string m_path = "";
    std::string m_name = "";
    std::string m_description = "";
    sf::Texture* m_image = nullptr;
    int m_cost = 0;
    int m_damage = 0;
    std::function<void()> m_ability;

    //Engine::LuaProgram* m_luaProgram;

public:
    CardTemplate();
    ~CardTemplate();

    CardTemplate(const CardTemplate &t);
    CardTemplate& operator = (const CardTemplate &t);

    std::string Name() const;
    std::string Description() const;
    sf::Texture* Image() const;
    int Cost() const;
    int Damage() const;
    std::function<void()> Ability() const;

    void SetPath(const std::string& p);
    void SetName(const std::string& n);
    void SetDescription(const std::string& d);
    void SetCost(int newCost);
    void SetDamage(int newDamage);
    void SetImage(sf::Texture* image);
    void SetAbility(std::function<void()> a);

    void AddCardTemplateToDeck();


    static int NewCardTemplate(lua_State* lua_state);

};


#endif //LUAASSIGNMENT_CARDTEMPLATE_H
