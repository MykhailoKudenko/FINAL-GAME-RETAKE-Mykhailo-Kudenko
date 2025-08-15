#pragma once
#include "Enemy.h"



class Dog : public Enemy
{

public:
    Dog(const Vector2f& startPos);

    void Update(float elapsedSec) override final;
    void Draw(bool IsDebug) const override final;

    static void LoadTexture();
    static void FreeTexture();

    void Activate();


private:

    Animation m_Animation;

    static Texture* s_DogTexture;
    const float m_WalkDistance;
    float m_DistanceTravelled;
    bool m_MovingRight;
    const float m_GravityAcceleration;
    bool m_isActive;
};


