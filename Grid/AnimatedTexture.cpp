#include "AnimatedTexture.h"

// public API
AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h,
                                 int frameCount, float animationSpeed, ANIM_DIR animationDirection)
    : Texture(filename, x, y, w, h)
{
    mStartX = x;
    mStartY = y;

    mFrameCount = frameCount;
    mAnimationSpeed = animationSpeed;
    mTimePerFrame = mAnimationSpeed / mFrameCount;
    mAnimationTimer = 0.0f;

    mAnimationDirection = animationDirection;

    mAnimationDone = false;

    mWrapMode = loop;
}

AnimatedTexture::~AnimatedTexture()
{
}


void AnimatedTexture::WrapMode(WRAP_MODE mode)
{
    mWrapMode = mode;
}

void AnimatedTexture::Update()
{
    if (!mAnimationDone)
    {
        mAnimationTimer += Timer::Instance()->DeltaTime();

        if (mAnimationTimer >= mAnimationSpeed)
        {
            if (mWrapMode == loop)
            {
                mAnimationTimer -= mAnimationSpeed;
            }
            else
            {
                mAnimationDone = true;
                mAnimationTimer = mAnimationSpeed - mTimePerFrame;
            }
        }

        if (mAnimationDirection == horizontal)
        {
            mClipRect.x = mStartX + (int)(mAnimationTimer / mTimePerFrame) * mWidth;
        }
        else
        {
            mClipRect.y = mStartY + (int)(mAnimationTimer / mTimePerFrame) * mHeight;
        }
    }
}
