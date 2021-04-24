#include <iostream>
#include <vector>
#include <chrono>
#include "GameObject.h"
#include "ComponentsManager.h"
#include "main.h"

int main()
{
    const int numObjects = 3500000;

    ComponentsManager compMgr = ComponentsManager(numObjects);
    std::vector<GameObject*> vecObjects = {};

    for (int i = 0; i < numObjects; i++)
    {
        GameObject* newObj = new GameObject();
        vecObjects.emplace_back(newObj);
        compMgr.CreateComponentsForId(newObj->GetId());
    }

    CacheUnfriendlyMethod(vecObjects);
    CacheFriendlyMethod(compMgr);

    for (int i = 0; i < vecObjects.size(); i++)
        delete vecObjects[i];
}

void CacheUnfriendlyMethod(std::vector<GameObject*>& vecObjects)
{
    //############## POINTER CHASE/CACHE UNFRIENDLY ##############
    std::cout << "Measuring non cache friendly (pointer chase) mode...\n";

    auto pointerChaseStart = std::chrono::steady_clock::now();

    for (int loops = 0; loops < 20; loops++)
        for (int i = 0; i < vecObjects.size(); i++)
            vecObjects[i]->Update();

    auto pointerChaseEnd = std::chrono::steady_clock::now();


    std::cout
        << "Elapsed time in milliseconds POINTER CHASE: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(pointerChaseEnd - pointerChaseStart).count() << " ms\n";
}

void CacheFriendlyMethod(ComponentsManager& compMgr)
{
    //############## LOCALITY/CACHE FRIENDLY ##############
    std::cout << "Measuring cache friendly (locality) mode...\n";

    auto cacheStart = std::chrono::steady_clock::now();

    for (int loops = 0; loops < 20; loops++)
        compMgr.Update();


    auto cacheEnd = std::chrono::steady_clock::now();

    std::cout
        << "Elapsed time in milliseconds CACHE: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(cacheEnd - cacheStart).count() << " ms\n";
}