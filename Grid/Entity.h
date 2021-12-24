#pragma once

#include "Math.h"

class Entity
{
public:
    enum SPACE {local = 0, world = 1};

private:
    Vector2 mPos;
    float mRotation;

    bool mActive;
    Entity* mParent;

public:
    Entity(float x = 0.0f, float y = 0.0f);
    ~Entity();

    void Pos(Vector2 pos);
    Vector2 Pos(SPACE space = world);

    void Rotation(float rotation);
    float Rotation(SPACE space = world);

    void Active(bool active);
    bool Active();

    void Parent(Entity* parent);
    Entity* Parent();

    virtual void Update();
    virtual void Render();
};
