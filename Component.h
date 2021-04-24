#pragma once
#include "Object.h"

class Component
{
protected:
    Object* m_Parent = 0;
    double m_ElapsedDt = 0.0;
    int m_GameObjectId = 0;
    double dataValue = 0.0;
public:
    Component() {};
    ~Component() {};

    void SetGameObjectId(int id) { m_GameObjectId = id; }
    virtual void Update(double deltaTime = 0.0) = 0;
};
