#include "Entity.h"

Entity::Entity(float x, float y)
{
    mPos.x = x;
    mPos.y = y;

    mRotation = 0.0f;
    mActive = true;

    mParent = NULL;
}

Entity::~Entity()
{
    mParent = NULL;
}

void Entity::Pos(Vector2 pos)
{
    mPos = pos;
}

Vector2 Entity::Pos(SPACE space)
{
    if (space == local 
        || mParent == NULL)
    {
        return mPos;
    }

    return mParent->Pos(world) + Rotate(mPos, mParent->Rotation(local));
}

void Entity::Rotation(float r)
{
    mRotation = r;

    if (mRotation > 360.0f)
    {
        mRotation -= 360.0f;
    }
    if (mRotation < 0)
    {
        mRotation += 360.0f;
    }
}

float Entity::Rotation(SPACE space)
{
    if (space == local
        || mParent == NULL)
    {
        return mRotation;
    }

    return mParent->Rotation(world) + mRotation;
}

void Entity::Active(bool active)
{
    mActive = active;
}

bool Entity::Active()
{
    return mActive;
}

void Entity::Parent(Entity* parent)
{
    mPos = Pos(world) - parent->Pos(world);

    mParent = parent;
}

Entity* Entity::Parent()
{
    return mParent;
}

void Entity::Update()
{

}

void Entity::Render()
{

}
