//
// Created by Igli milaqi on 28/12/2018.
//

#include "CardTemplate.h"

CardTemplate::CardTemplate(const std::string &name, const std::string &description, sf::Texture* image,
                           int cost, int damage, const std::function<void()>& ability)
                           : m_name(name), m_description(description),m_image(image),m_cost(cost),m_damage(damage),m_ability(ability) {


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
