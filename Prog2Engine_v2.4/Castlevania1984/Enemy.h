#pragma once
#include "Entity.h"

#include "Animation.h"

class Enemy : public Entity
{
public:
    Enemy(const Vector2f& pos, float speed, const Rectf& hitbox);
    virtual ~Enemy();

    virtual void Update(float elapsedSec) override = 0;
    virtual void Draw(bool IsDebug) const override = 0;

    Rectf GetHitbox() const;

protected:
    const float m_Speed;
    const Rectf m_Hitbox;
};

