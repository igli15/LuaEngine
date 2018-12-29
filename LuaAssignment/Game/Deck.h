//
// Created by Igli milaqi on 29/12/2018.
//

#ifndef LUAASSIGNMENT_DECK_H
#define LUAASSIGNMENT_DECK_H


#include "../Engine/Entity.h"
#include "Components/DeckComponent.h"

class Deck : public Engine::Entity {

public:
    void Build() override;
    DeckComponent* GetDeckComponent() const;

private:
    DeckComponent* m_deckComponent;

};


#endif //LUAASSIGNMENT_DECK_H
