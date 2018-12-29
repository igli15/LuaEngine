//
// Created by Igli milaqi on 29/12/2018.
//

#ifndef LUAASSIGNMENT_DECKCOMPONENT_H
#define LUAASSIGNMENT_DECKCOMPONENT_H


#include <vector>
#include "../../Engine/Component.h"

class Card;
class CardTemplate;

class DeckComponent : public Engine::Component {


private:
    std::vector<CardTemplate*> m_cardTemplates;

public:

    void Start() override;
    void AddCardTemplate(CardTemplate* cardTemplate);
    void ShuffleDeck();
    Card* DrawCard();
};


#endif //LUAASSIGNMENT_DECKCOMPONENT_H
