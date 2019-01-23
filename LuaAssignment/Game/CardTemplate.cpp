//
// Created by Igli milaqi on 28/12/2018.
//

#include "CardTemplate.h"
#include "Components/HandComponent.h"
#include "../Engine/Game.h"
#include "Components/PlayerComponent.h"
#include "../Engine/Entity.h"
#include "Deck.h"

CardTemplate::CardTemplate()
{

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

void CardTemplate::SetPath(const std::string &p)
{
    m_path = p;
}

void CardTemplate::SetName(const std::string &n)
{
    m_name = n;
}

void CardTemplate::SetDescription(const std::string &d)
{
    m_description =  d ;
}

void CardTemplate::SetCost(int newCost)
{
    m_cost = newCost;
}

void CardTemplate::SetDamage(int newDamage)
{
    m_damage = newDamage;
}

int CardTemplate::NewCardTemplate(lua_State *lua_state)
{
    std::string path,name,description;
    int cost,damage;
    CardTemplate* cardTemplate;

    //lua_call(lua_state,0,0);

    damage = luaL_checkinteger(lua_state,5);
    cost = luaL_checkinteger(lua_state,4);
    description = luaL_checkstring(lua_state,3);
    name = luaL_checkstring(lua_state,2);
    path = luaL_checkstring(lua_state,1);

    luaL_checktype(lua_state, 6, LUA_TFUNCTION);

    lua_pushvalue(lua_state,6);

    int m_refIndex = luaL_ref(lua_state,LUA_REGISTRYINDEX);

    auto ability = [m_refIndex,lua_state]()
    {
        lua_rawgeti(lua_state,LUA_REGISTRYINDEX,m_refIndex);
        lua_pcall(lua_state,0,0,0);
        luaL_unref(lua_state,LUA_REGISTRYINDEX,m_refIndex);

    };

    sf::Texture* image = Engine::Game::Instance()->GetResourceManager()->LoadTexture(path,name);

    size_t bytes = sizeof(CardTemplate);
    cardTemplate = new(lua_newuserdata(lua_state,bytes)) CardTemplate();

    cardTemplate->SetDamage(damage);
    cardTemplate->SetCost(cost);
    cardTemplate->SetDescription(description);

    cardTemplate->SetName(name);
    cardTemplate->SetPath(path);
    cardTemplate->SetImage(image);
    cardTemplate->AddCardTemplateToDeck();
    cardTemplate->SetAbility(ability);

    return 1;
}

void CardTemplate::SetImage(sf::Texture* image)
{
    m_image = image;
}

void CardTemplate::AddCardTemplateToDeck()
{
    PlayerComponent* p = Engine::Entity::FindEntityWithTag("Player")->GetComponent<PlayerComponent>();
    p->GetDeck()->GetDeckComponent()->AddCardTemplate(this);
}

void CardTemplate::SetAbility(std::function<void()> a)
{
    m_ability = a;
}

CardTemplate::~CardTemplate()
{
   delete m_image;
   m_image = nullptr;

   m_path = "";
}

CardTemplate::CardTemplate(const CardTemplate &t) {

}

CardTemplate &CardTemplate::operator=(const CardTemplate &t) {


}
