#pragma once
#include "Component.h"

class ComponentPhysicsDummy : public Component
{

public:
    ComponentPhysicsDummy(Object* parent) { m_Parent = parent; };
    ComponentPhysicsDummy(int ObjectId) { m_GameObjectId = ObjectId; }
    ComponentPhysicsDummy() {};
    ~ComponentPhysicsDummy() {}; 

    void Update(double deltaTime = 0.0013) override
    {
        m_ElapsedDt += deltaTime;
        double arbVal = cos(m_ElapsedDt) * sqrt(m_ElapsedDt * deltaTime + m_ElapsedDt * deltaTime) / 2;
        arbVal += sin(arbVal) * cos(arbVal) * tan(arbVal);
    }
};
