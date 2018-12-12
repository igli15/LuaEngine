//
// Created by Igli milaqi on 08/10/2018.
//

#define PI 3.14159265f

#include "IVector.h"
#include <math.h>

Engine::IVector::IVector(float x, float y) : Vector2(x, y)
{

}

float Engine::IVector::Deg2Rad(float degree)
{
    return (degree * PI)/180;
}

float Engine::IVector::Rad2Deg(float rad)
{
    return (rad * 180)/PI;
}

Engine::IVector Engine::IVector::GetUnitVectorDegrees(float degrees)
{
    IVector Vec(0,0);
    Vec.x = cosf(Deg2Rad(degrees));
    Vec.y = sinf(Deg2Rad(degrees));
    return Vec;
}

Engine::IVector Engine::IVector::GetUnitVectorRad(float rad)
{
    IVector Vec(0,0);
    Vec.x = cosf(rad);
    Vec.y = sinf(rad);
    return Vec;
}

float Engine::IVector::GetLength()
{
    return sqrtf(powf(x,2) + powf(y,2));
}

float Engine::IVector::GetAngleRad()
{
    return atan2(y,x);
}

float Engine::IVector::GetAngleDegrees()
{
    return Rad2Deg(atan2f(y,x));
}

float Engine::IVector::Dot(const IVector& other)
{
    return x * other.x + y * other.y;
}

Engine::IVector Engine::IVector::Normalize()
{
    float length = GetLength();
    if(length == 0) return *this;

    x/= length;
    y/=length;

    return *this;
}

Engine::IVector Engine::IVector::MaxLength(float maxLength)
{
    if(GetLength() >= maxLength)
    {
        this->Normalize();
        *this *= maxLength;
    }

    return *this;
}

Engine::IVector Engine::IVector::Clone()
{
    return IVector(x,y);
}

Engine::IVector Engine::IVector::SetAngleDegrees(float degrees)
{
    float length = GetLength();
    x = length * cosf(Deg2Rad(degrees));
    y = length * sinf(Deg2Rad(degrees));
    return *this;
}

Engine::IVector Engine::IVector::SetAngleRadians(float rad)
{
    float length = GetLength();
    x = length * cosf(rad);
    y = length * sinf(rad);
    return *this;
}

Engine::IVector Engine::IVector::RotateDegrees(float degrees)
{
    float cos = cosf(Deg2Rad(degrees));
    float sin = sinf(Deg2Rad(degrees));

    x = (x * cos - (y * sin));
    y = (x * sin + (y * cos));

    return *this;
}

Engine::IVector Engine::IVector::RotateRad(float rad)
{
    float cos = cosf(rad);
    float sin = sinf(rad);
    x = (x * cos - (y * sin));
    y = (x * sin + (y * cos));

    return *this;
}

Engine::IVector Engine::IVector::RotateAroundPoint(float px, float py, float degrees)
{
    x -= px;
    y -= py;
    RotateDegrees(degrees);
    x += px;
    y += py;

    return *this;
}

Engine::IVector Engine::IVector::Normal()
{
    return this->Clone().RotateDegrees(90).Normalize();
}

Engine::IVector &Engine::IVector::operator=(const Engine::IVector & other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Engine::IVector &Engine::IVector::operator=(const sf::Vector2f & other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}





