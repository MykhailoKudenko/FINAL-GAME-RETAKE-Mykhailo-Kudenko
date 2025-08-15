#pragma once
#include "Enemy.h"



class Zombie : public Enemy
{

public:
    Zombie(const Vector2f& startPos);

    void Update(float elapsedSec) override final;
    void Draw(bool IsDebug) const override final;

    static void LoadTexture();
    static void FreeTexture();

private:

    Animation m_Animation;


    static Texture* s_ZombieTexture;
    const float m_WalkDistance;
    float m_DistanceTravelled;
    bool m_MovingRight;
    const float m_GravityAcceleration;
};

