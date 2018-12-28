//
// Created by Igli milaqi on 28/12/2018.
//

#include "CardTemplate.h"

CardTemplate::CardTemplate(const std::string &name, const std::string &description, const std::string &imagePath,
                           float cost, float damage, const std::function<void()>& ability)
                           : m_name(name), m_description(description),m_imagePath(imagePath),m_cost(cost),m_damage(damage),m_ability(ability) {


}

std::string CardTemplate::Name()
{
    return m_name;
}

std::string CardTemplate::Description()
{
    return m_description;
}

std::string CardTemplate::ImagePath()
{
    return m_imagePath;
}

float CardTemplate::Cost()
{
    return m_cost;
}

float CardTemplate::Damage()
{
    return m_damage;
}

std::function<void()> CardTemplate::Ability()
{
    return m_ability;
}
