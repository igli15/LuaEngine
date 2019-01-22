//
// Created by Igli milaqi on 24/12/2018.
//

#ifndef LUAASSIGNMENT_CARD_H
#define LUAASSIGNMENT_CARD_H


#include "../Engine/Entity.h"
#include "../Engine/Sprite.h"
#include "../Engine/Text.h"
#include "CardTemplate.h"
#include "Components/CardComponent.h"

class Card : public Engine::Entity {

protected:
    Engine::SpriteRenderer* m_spriteRenderer;
    Engine::Sprite* m_cardImage;
    Engine::Text* m_cardName;
    Engine::Text* m_cardDescription;
    Engine::Text* m_cardCost;
    CardComponent* m_cardComponent;

public:
    void Start() override;
    void Build() override;
    void ApplyTemplate(const CardTemplate& cardTemplate);
    void SetCardName(const std::string& name);
    void SetCardDescription(const std::string& description);
    void SetCardImage(const std::string& path);

    void SetCardCostText(const std::string& newCost);

};


#endif //LUAASSIGNMENT_CARD_H
