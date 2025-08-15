#pragma once

#include "Projectile.h"

class Knife : public Projectile
{
public:
    Knife(const Vector2f& pos, const Vector2f& unitDirection);

    void Update(float elapsedSec) override;
    void Draw(bool IsDebug) const override;

    static void LoadTexture();
    static void FreeTexture();

private:

    static Texture* s_KnifeTexture;
    const static float s_KnifeSpeed;
};

