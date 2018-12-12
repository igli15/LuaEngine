//
// Created by Igli milaqi on 08/10/2018.
//

#ifndef SMFLPROJECT_IVECTOR_H
#define SMFLPROJECT_IVECTOR_H

#include <SFML/System.hpp>


namespace Engine {

    class IVector : public  sf::Vector2f {

    public:
        static float Deg2Rad(float degree);
        static float Rad2Deg(float rad);
        static IVector GetUnitVectorDegrees(float degrees);
        static IVector GetUnitVectorRad(float rad);

        IVector(float x, float y);
        float GetLength();
        float GetAngleRad();
        float GetAngleDegrees();
        float Dot(const IVector& other);
        IVector Normalize();
        IVector MaxLength(float maxLength);
        IVector Clone();
        IVector SetAngleDegrees(float degrees);
        IVector SetAngleRadians(float rad);
        IVector RotateDegrees(float degrees);
        IVector RotateRad(float rad);
        IVector RotateAroundPoint(float px, float py,float degrees);
        IVector Normal();
        IVector& operator=(const IVector &);
        IVector& operator=(const sf::Vector2f &);
    };
}


#endif //SMFLPROJECT_IVECTOR_H
