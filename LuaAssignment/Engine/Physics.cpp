//
// Created by Igli milaqi on 14/10/2018.
//

#include "Physics.h"
#include "IVector.h"
#include "Collider.h"

bool Engine::Physics::CircleCircleCollision(const Collider& circle1, const Collider& circle2)
{
    float distance = IVector(circle1.X() - circle2.X(),circle1.Y() - circle2.Y()).GetLength();

    float radius1 = circle1.Width()/2;
    float radius2 = circle2.Width()/2;

    return distance < radius1 + radius2;

}
