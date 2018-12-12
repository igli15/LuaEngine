//
// Created by Igli milaqi on 20/10/2018.
//

#ifndef SMFLPROJECT_TEXT_H
#define SMFLPROJECT_TEXT_H

#include "Entity.h"

namespace Engine {

    class TextComponent;

class Text : public Engine::Entity {

private:
    TextComponent* m_textComponent;

public:
    Text();
    void Build() override;
    void ScaleEntity(const float& scaleX,const float & scaleY) override;
    void SetPosition(float x,float y) override;

    };

}

#endif //SMFLPROJECT_TEXT_H
