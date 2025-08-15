#pragma once
#include "Entity.h"

class Projectile : public Entity
{
public:
    Projectile(const Vector2f& pos, const Vector2f& velocity, const Rectf& hitbox, float LifeTime);
    virtual ~Projectile();

    virtual void Update(float elapsedSec) override = 0;
    virtual void Draw(bool IsDebug) const override = 0;

    bool IsActive() const;


    //disable copying week 06
    Projectile(const Projectile&) = delete;
    Projectile& operator=(const Projectile&) = delete;

    Rectf GetHitbox() const;

protected:
    const Vector2f m_Velocity;
    const Rectf m_Hitbox;
    bool m_IsActive;

    float m_CurrentLifetime;
    const float s_MaxLifetime;
};

