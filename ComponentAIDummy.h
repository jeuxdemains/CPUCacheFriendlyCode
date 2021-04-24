#pragma once
#include "Component.h"

class ComponentAIDummy : public Component
{

public:
    ComponentAIDummy(Object* parent) { m_Parent = parent; };
    ComponentAIDummy(int ObjectId) { m_GameObjectId = ObjectId; }
    ComponentAIDummy() {};
    ~ComponentAIDummy() {};

    void Update(double deltaTime = 0.0013) override
    {
        m_ElapsedDt += deltaTime;
        double arbVal = cos(m_ElapsedDt) * sqrt(m_ElapsedDt * deltaTime + m_ElapsedDt * deltaTime) / 2;
        arbVal += sin(arbVal) * cos(arbVal) * tan(arbVal);
    }
};