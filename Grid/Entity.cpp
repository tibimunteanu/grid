#include "Entity.h"

// public API
Entity::Entity(Vector2 pos)
{
    mPos = pos;
    mRotation = 0.0f;
    mScale = VEC2_ONE;

    mParent = NULL;
    mActive = true;
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

    Vector2 parentPos = mParent->Pos(world);
    Vector2 parentScale = mParent->Scale(world);

    Vector2 rotPos = mPos * parentScale;
    rotPos = RotateVector(rotPos, mParent->Rotation(local));

    return parentPos + rotPos;
}


void Entity::Rotation(float r)
{
    mRotation = r;

    if (mRotation > 360.0f)
    {
        int mul = mRotation / 360.0f;
        mRotation -= 360.0f * mul;
    }
    if (mRotation < 0)
    {
        int mul = (mRotation / 360.0f) - 1;
        mRotation -= 360.0f * mul;
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


void Entity::Scale(Vector2 scale)
{
    mScale = scale;
}

Vector2 Entity::Scale(SPACE space)
{
    if (space == local
        || mParent == NULL)
    {
        return mScale;
    }

    return mParent->Scale(world) * mScale;
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
    if (parent == NULL)
    {
        mPos = Pos(world);
        mRotation = Rotation(world);
        mScale = Scale(world);
    }
    else
    {
        if (mParent != NULL)
        {
            Parent(NULL);
        }

        Vector2 parentPos = parent->Pos(world);
        Vector2 parentScale = parent->Scale(world);
        float parentRot = parent->Rotation(world);

        mPos = Pos(world) - parentPos;
        mPos = RotateVector(mPos, -parentRot);
        mPos /= parentScale;

        mRotation -= parentRot;

        mScale /= parentScale;
    }

    mParent = parent;
}

Entity* Entity::Parent()
{
    return mParent;
}


void Entity::Translate(Vector2 offset)
{
    mPos += offset;
}

void Entity::Rotate(float amount)
{
    mRotation += amount;
}


void Entity::Update()
{

}

void Entity::Render()
{

}
