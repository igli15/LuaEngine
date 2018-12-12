//
// Created by Igli milaqi on 09/10/2018.
//

#ifndef SMFLPROJECT_RIGIDBODY_H
#define SMFLPROJECT_RIGIDBODY_H


#include "Component.h"
#include "IVector.h"

namespace Engine {

    class Rigidbody : public Component {

    private:
        IVector* m_velocity;
        IVector* m_acceeration;
        float m_maxSpeed;
        float m_friction = 0;

    public:
        Rigidbody();
        void Start() override;
        void Update(float timeStep) override;
        void SetAcceleration(float x , float y);
        void SetVelocity(float x , float y);
        void SetMaxSpeed(float maxSpeed);
        IVector* GetAcceleration();
        IVector* GetVelocity();
        void SetFriction(float friction);
    };
}


#endif //SMFLPROJECT_RIGIDBODY_H
