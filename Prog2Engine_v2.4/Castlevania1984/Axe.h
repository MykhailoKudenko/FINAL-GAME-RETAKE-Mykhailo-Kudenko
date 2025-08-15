#pragma once

#include "Projectile.h"

#include "Animation.h"


class Axe : public Projectile
{
public:
    Axe(const Vector2f& pos, const Vector2f& unitDirection);

    void Update(float elapsedSec) override;
    void Draw(bool IsDebug) const override;

    static void LoadTexture();
    static void FreeTexture();

private:

    Animation m_Animation;

    static Texture* s_AxeTexture;
    const static float s_AxeSpeed;
    float m_timeUntillGoingDown;
};

