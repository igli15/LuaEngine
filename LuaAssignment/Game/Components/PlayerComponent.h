//
// Created by Igli milaqi on 27/12/2018.
//

#ifndef LUAASSIGNMENT_PLAYERCOMPONENT_H
#define LUAASSIGNMENT_PLAYERCOMPONENT_H


#include "../../Engine/Component.h"
#include "EnemyComponent.h"

class Hand;
class Card;
class Deck;

class PlayerComponent : public Engine::Component {

private:

    Hand* m_hand;
    Deck* m_deck;
    EnemyComponent* m_enemyComponent;

    int m_currentMana = 0;
    int m_manaCapacity = 0;
    int m_maxMana = 10;

    bool m_isTurn;
    int m_health;

public:
    void Start() override;
    void Update(float timeStep) override;
    bool isHoldingCard = false;
    void AddCardToHand(Card* card);
    void OnTurnStart();
    void SetEnemyComponent(EnemyComponent* e);
    void EndTurn();
    void DrawCard();
    void DealDamage(int damage);
    void SetManaCount(int mana);
    void SpendMana(int amount);
    int GetCurrentManaCount();
    int GetManaCapacity();
    int GetMaxManaCount();
    int GetHealth();
    Hand* GetHand();
    Deck* GetDeck();
    EnemyComponent* GetEnemy();
};


#endif //LUAASSIGNMENT_PLAYERCOMPONENT_H
