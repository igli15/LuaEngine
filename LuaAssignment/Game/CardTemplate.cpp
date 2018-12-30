//
// Created by Igli milaqi on 28/12/2018.
//

#include "CardTemplate.h"

CardTemplate::CardTemplate(const std::string &name, const std::string &description, const std::string &imagePath,
                           int cost, int damage, const std::function<void()>& ability)
                           : m_name(name), m_description(description),m_imagePath(imagePath),m_cost(cost),m_damage(damage),m_ability(ability) {


}

std::string CardTemplate::Name() const {
    return m_name;
}

std::string CardTemplate::Description() const {
    return m_description;
}

std::string CardTemplate::ImagePath() const {
    return m_imagePath;
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
