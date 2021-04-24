#pragma once
#include <vector>


class Object
{
protected:
    static int nextId;
    int id = 0;
public:
    virtual void Update() = 0;
};

int Object::nextId = 0;