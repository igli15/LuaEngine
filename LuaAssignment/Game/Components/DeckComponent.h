//
// Created by Igli milaqi on 29/12/2018.
//

#ifndef LUAASSIGNMENT_DECKCOMPONENT_H
#define LUAASSIGNMENT_DECKCOMPONENT_H


#include <vector>
#include "../../Engine/Component.h"

class Card;
class CardTemplate;
class PlayerComponent;

class DeckComponent : public Engine::Component {


private:
    std::vector<CardTemplate*> m_cardTemplates;
    PlayerComponent* m_playerComponent;

public:

    void Start() override;
    void SetPlayer(PlayerComponent* p);
    void AddCardTemplate(CardTemplate* cardTemplate);
    void ShuffleDeck();

    int GetNumberOfCardsInDeck();

    Card* DrawCard();
};


#endif //LUAASSIGNMENT_DECKCOMPONENT_H
