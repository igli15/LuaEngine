//
// Created by Igli milaqi on 28/12/2018.
//

#include "CardTemplate.h"
#include "Components/HandComponent.h"
#include "../Engine/Game.h"
#include "Components/PlayerComponent.h"

CardTemplate::CardTemplate()
{

    m_luaProgram = new Engine::LuaProgram("../LuaScripts/CardTest.lua");

    m_luaProgram->CallCurrentProgram();
    m_luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","discardCard",HandComponent::luaDiscardRandomCard);
    m_luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","drawCard",PlayerComponent::luaDrawCard);
    m_luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","freezeOpponent",PlayerComponent::luaFreezeOpponent);
    m_luaProgram->PushToTable<std::string, int(*)(lua_State *) > ("callbacks", "decreaseCostOfACard", HandComponent::luaDecreaseCostOfACard);

    m_name = m_luaProgram->GetValueFromTable<std::string,std::string>("card","name");

    m_path = m_luaProgram->GetValueFromTable<std::string,std::string>("card","filePath");

    m_image = Engine::Game::Instance()->GetResourceManager()->LoadTexture(m_path,m_name);

    m_description = m_luaProgram->GetValueFromTable<std::string,std::string>("card","description");
    m_damage = m_luaProgram->GetValueFromTable<std::string,int>("card","damage");
    m_cost = m_luaProgram->GetValueFromTable<std::string,int>("card","manaCost");

    m_ability = [this]()
    {
        m_luaProgram->GetGlobalFunction("ability",0,0);
        m_luaProgram->CallGlobalFunction("ability");
    };
}

std::string CardTemplate::Name() const {
    return m_name;
}

std::string CardTemplate::Description() const {
    return m_description;
}

int CardTemplate::Cost() const {
    return m_cost;
}

int CardTemplate::Damage() const {
    return m_damage;
}

std::function<void()> CardTemplate::Ability() const {
    return m_ability;
}

sf::Texture* CardTemplate::Image() const
{
    return m_image;
}
