//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_PLAYERCOMPONENT_H
#define LUAASSIGNMENT_PLAYERCOMPONENT_H


#include <SFML/System/Clock.hpp>
#include "../../Engine/Component.h"
#include "EnemyComponent.h"


class Hand;
class Card;
class Deck;
class CardComponent;

class PlayerComponent : public Engine::Component {

private:

    Hand* m_hand;
    Deck* m_deck;
    EnemyComponent* m_enemyComponent;

    int m_freezeDuration = 0;
    bool m_isFrozen = false;
    int m_currentMana = 0;
    int m_manaCapacity = 0;
    int m_maxMana = 10;

    bool m_isTurn;
    int m_health;

    sf::Clock* m_inputDelayClock;

public:
    ~PlayerComponent() override;
    void Start() override;
    void Update(float timeStep) override;
    bool isHoldingCard = false;
    void AddCardToHand(Card* card);
    void OnTurnStart();
    void SetEnemyComponent(EnemyComponent* e);
    void EndTurn();
    void Freeze(int amountOfTurns);
    void DrawCard();
    void DealDamage(int damage);
    void SetManaCount(int mana);
    void SpendMana(int amount);
    int GetCurrentManaCount();
    int GetManaCapacity();
    int GetMaxManaCount();
    int GetHealth();
    int GetFreezeDuration();
    void PlayCard(CardComponent* c);
    Hand* GetHand();
    Deck* GetDeck();
    EnemyComponent* GetEnemy();
};


#endif //LUAASSIGNMENT_PLAYERCOMPONENT_H
