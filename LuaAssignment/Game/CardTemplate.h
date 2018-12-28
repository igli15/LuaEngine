//
// Created by Igli milaqi on 28/12/2018.
//

#ifndef LUAASSIGNMENT_CARDTEMPLATE_H
#define LUAASSIGNMENT_CARDTEMPLATE_H


#include <string>
#include <functional>

class CardTemplate {

protected:
    std::string m_name;
    std::string m_description;
    std::string m_imagePath;
    float m_cost;
    float m_damage;
    std::function<void()> m_ability;

public:
    CardTemplate(const std::string& name,const std::string& description, const std::string& imagePath,
                float cost,float damage,const std::function<void()>& ability);

    std::string Name() const;
    std::string Description() const;
    std::string ImagePath() const;
    float Cost() const;
    float Damage() const;
    std::function<void()> Ability() const;
};


#endif //LUAASSIGNMENT_CARDTEMPLATE_H
