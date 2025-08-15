#pragma once
#include "Enemy.h"
#include <iostream>


class Bat : public Enemy
{
public:
    Bat(const Vector2f& startPos);

    void Update(float elapsedSec) override final;
    void Draw(bool IsDebug) const override final;

    static void LoadTexture();   
    static void FreeTexture();

private:

    Animation m_Animation;

    static Texture* s_BatTexture;
    const float m_FlyDistance;
    float m_DistanceTravelled;
    bool m_MovingRight;

    bool m_MovingUp = true;
    float m_dirCountDown;
};
