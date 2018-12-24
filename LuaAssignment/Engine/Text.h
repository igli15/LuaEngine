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
    void Start() override;
    void ScaleEntityLocal(const float &scaleX, const float &scaleY) override;
    void SetLocalPosition(float x, float y) override;
    void SetText(const std::string& text);
    TextComponent* GetTextComponent();
    };

}

#endif //SMFLPROJECT_TEXT_H
