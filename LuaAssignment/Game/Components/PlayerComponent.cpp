//
// Created by Igli milaqi on 27/12/2018.
//

#include "PlayerComponent.h"
#include "../Hand.h"
#include "../Deck.h"
#include "../Card.h"
#include "CardComponent.h"
#include "DeckComponent.h"
#include "../../Engine/Scene.h"
#include "../../Engine/Game.h"
#include "CardComponent.h"

PlayerComponent* PlayerComponent::instance;

void PlayerComponent::Start()
{
    Component::Start();
    m_inputDelayClock = new sf::Clock();

    m_health = 30;

    m_hand = m_parent->parentScene->Instantiate<Hand>();
    m_deck = m_parent->parentScene->Instantiate<Deck>();

    m_parent->AddChild(m_hand);
    m_parent->AddChild(m_deck);

    m_deck->GetDeckComponent()->SetPlayer(this);

    for (int i = 0; i < 20; ++i) {
       // CardTemplate *t = new CardTemplate();
       // m_deck->GetDeckComponent()->AddCardTemplate(t);
    }



    SetInstance(this);
}

void PlayerComponent::Update(float timeStep)
{
    Component::Update(timeStep);

    if(m_health <= 0)
    {
        Engine::Text* t = m_parent->parentScene->Instantiate<Engine::Text>();
        t->SetText("You Lose");
        t->GetTextComponent()->SetCharacterSize(200);
        t->SetWorldPosition(Engine::Game::Instance()->Width()/2 - 500,Engine::Game::Instance()->Height()/2 - 200);
        m_parent->parentScene->DestroyEntity(m_parent);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_inputDelayClock->getElapsedTime().asSeconds() > 0.25f && m_enemyComponent!= nullptr)
    {
        EndTurn();
        m_inputDelayClock->restart();
    }

}


void PlayerComponent::AddCardToHand(Card *card)
{
    card->GetComponent<CardComponent>()->SetPlayer(this);
    m_hand->GetHandComponent()->AddCard(card);
}

void PlayerComponent::DrawCard()
{
    Card* c = m_deck->GetDeckComponent()->DrawCard();

    if(c != nullptr)
    AddCardToHand(c);
}

Hand *PlayerComponent::GetHand()
{
    return m_hand;
}

Deck *PlayerComponent::GetDeck()
{
    return  m_deck;
}

int PlayerComponent::GetHealth()
{
    return  m_health;
}

void PlayerComponent::DealDamage(int damage)
{
    m_health -= damage;
}

void PlayerComponent::SetEnemyComponent(EnemyComponent *e)
{
    m_enemyComponent = e;
}

void PlayerComponent::EndTurn()
{
    if(m_enemyComponent != nullptr && m_isTurn)
    {
        m_isTurn = false;
        m_enemyComponent->OnTurnStart();
    }
}

void PlayerComponent::OnTurnStart()
{
    if(m_freezeDuration != 0 ) m_freezeDuration -=1;
    if(m_freezeDuration <= 0 )
    {
        m_freezeDuration = 0;
        m_isFrozen = false;
    }


    m_isTurn = true;
    if(m_freezeDuration != 0)  m_isFrozen = true;

    DrawCard();

    if(m_manaCapacity >= m_maxMana)
    {
        m_manaCapacity = m_maxMana;
    }
    else m_manaCapacity +=1;

    m_currentMana = m_manaCapacity;

}

void PlayerComponent::SetManaCount(int mana)
{
    m_currentMana = mana;
}

int PlayerComponent::GetCurrentManaCount()
{
    return m_currentMana;
}

int PlayerComponent::GetMaxManaCount()
{
    return m_maxMana;
}

EnemyComponent *PlayerComponent::GetEnemy()
{
    return m_enemyComponent;
}

void PlayerComponent::SpendMana(int amount)
{
    m_currentMana -= amount;
}

int PlayerComponent::GetManaCapacity()
{
    return m_manaCapacity;
}

PlayerComponent::~PlayerComponent()
{
    delete m_inputDelayClock;
    m_inputDelayClock = nullptr;

    m_enemyComponent = nullptr;
}

void PlayerComponent::Freeze(int freezeDuration)
{
    m_freezeDuration = freezeDuration;
}

int PlayerComponent::GetFreezeDuration()
{
    return m_freezeDuration;
}

void PlayerComponent::PlayCard(CardComponent *c)
{
    if(!m_isFrozen && m_isTurn && m_enemyComponent != nullptr) {

        SpendMana(c->GetCost());
        m_enemyComponent->DealDamage(c->GetDamage());

        m_hand->GetHandComponent()->DecrementCardNumber();
        c->GetSlot()->EmptySlot();
        m_parent->parentScene->DestroyEntity(c->Parent());

        if (c->GetAbility() != nullptr)
        {
            c->GetAbility()();
            std::cout<<"CALLING ABILITY"<<std::endl;
        }
        else
        {
            std::cout<<"Ability is null"<<std::endl ;
        }
    }
}

void PlayerComponent::SetInstance(PlayerComponent* p)
{
    instance = p;
}

int PlayerComponent::luaDrawCard(lua_State *l)
{
    instance->DrawCard();
    return 0;
}

void PlayerComponent::FreezeOpponent()
{
    m_enemyComponent->Freeze();
}

int PlayerComponent::luaFreezeOpponent(lua_State *l)
{
    instance->FreezeOpponent();
    return 0;
}

void PlayerComponent::ClearEnemy()
{
    m_enemyComponent = nullptr;
}



