//
// Created by Igli milaqi on 14/10/2018.
//

#ifndef SMFLPROJECT_PHYSICS_H
#define SMFLPROJECT_PHYSICS_H

#include <vector>
#include "Collider.h"

namespace Engine {

    class Physics {

    public:
        std::vector<Collider*> colliderVector;

        static bool CircleCircleCollision(const Collider& circle1,const Collider& circle2);

    };
}


#endif //SMFLPROJECT_PHYSICS_H
