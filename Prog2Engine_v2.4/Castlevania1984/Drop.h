#pragma once
#include "Enemy.h"

class Drop : public Entity
{
public:
    enum class DropType
    {
        HeartSmall,
        HeartBig,
        Knife,
        Axe
    };

    Drop(const Vector2f& pos, DropType type);
    ~Drop();

    DropType GetType() const;

    void Update(float elapsedSec) override final;
    void Draw(bool IsDebug) const override final;
    
    Rectf GetHitBox() const;

private:
    float const m_GravityAcceleration = -45;

    DropType m_DropType;

    Texture* m_Texture = nullptr;

    Rectf m_Hitbox;
};
