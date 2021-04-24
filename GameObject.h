#pragma once
#include <vector>
#include "Object.h"
#include "ComponentPhysicsDummy.h"
#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"

class GameObject : protected Object
{
    std::vector<Component*> m_vecComponents = {};
public:
    GameObject()
    {
        id = nextId;
        nextId++;
        m_vecComponents.emplace_back(new ComponentAIDummy(this));
        m_vecComponents.emplace_back(new ComponentPhysicsDummy(this));
        m_vecComponents.emplace_back(new ComponentCollisionDummy(this));
        m_vecComponents.emplace_back(new ComponentAIDummy(this));
        m_vecComponents.emplace_back(new ComponentPhysicsDummy(this));
        m_vecComponents.emplace_back(new ComponentCollisionDummy(this));
    };
    ~GameObject()
    {
        for (int i = 0; i < m_vecComponents.size(); i++)
            delete m_vecComponents[i];
    };

    void Update()
    {
        for (auto& comp : m_vecComponents)
            comp->Update();
    }

    int GetId() { return id; }
};
