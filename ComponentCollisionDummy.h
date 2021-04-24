#pragma once
#include "Component.h"

class ComponentCollisionDummy : public Component
{

public:
    ComponentCollisionDummy(Object* parent) { m_Parent = parent; };
    ComponentCollisionDummy(int ObjectId) { m_GameObjectId = ObjectId; }
    ComponentCollisionDummy() {};
    ~ComponentCollisionDummy() {};

    void Update(double deltaTime = 0.013) override
    {
        m_ElapsedDt += deltaTime;
        double arbVal = cos(m_ElapsedDt) * sqrt(m_ElapsedDt * deltaTime + m_ElapsedDt * deltaTime) / 2;
        arbVal += sin(arbVal) * cos(arbVal) * tan(arbVal);
    }
};
