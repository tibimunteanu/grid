#pragma once

#include "Math.h"

class Entity
{
public:
    enum SPACE {local = 0, world = 1};


private:
    Vector2 mPos;
    float mRotation;
    Vector2 mScale;

    bool mActive;
    Entity* mParent;

public:
    Entity(Vector2 pos = VEC2_ZERO);
    ~Entity();

    void Pos(Vector2 pos);
    Vector2 Pos(SPACE space = world);

    void Rotation(float rotation);
    float Rotation(SPACE space = world);

    void Scale(Vector2 scale);
    Vector2 Scale(SPACE space = world);

    void Active(bool active);
    bool Active();

    void Parent(Entity* parent);
    Entity* Parent();

    void Translate(Vector2 offset);
    void Rotate(float amount);

    virtual void Update();
    virtual void Render();
};
