//
// Created by Igli milaqi on 14/10/2018.
//

#ifndef SMFLPROJECT_COLLIDER_H
#define SMFLPROJECT_COLLIDER_H


#include "Component.h"

namespace Engine
{
    class Rigidbody;

    class Collider : public Component {

    private:
        bool m_isTrigger = false;
        float m_width = 0;
        float m_height = 0;
        float m_x = 0;
        float m_y = 0;
        Rigidbody* m_rb;

    public:
        Collider();
        ~Collider() override;
        float Width() const;
        float Height();
        void SetWidth(float width);
        void SetHeight(float height);
        bool IsTrigger();
        void SetIsTrigger(bool isTrigger);
        void CheckForAllCollisions();
        void Start() override;
        void Update(float timeStep) override;
        float X() const;
        float Y() const;

    };
}


#endif //SMFLPROJECT_COLLIDER_H
