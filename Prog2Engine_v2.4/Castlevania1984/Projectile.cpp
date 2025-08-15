#include "pch.h"
#include "Projectile.h"





Projectile::Projectile(const Vector2f& pos, const Vector2f& velocity, const Rectf& hitbox, float LifeTime)
    : m_Velocity{ velocity }
    , m_Hitbox{ hitbox }
    , m_IsActive{ true }
    , m_CurrentLifetime{ 0.f }
    , s_MaxLifetime { LifeTime }
{
    m_Pos = pos;
}

Projectile::~Projectile()
{
    
}

bool Projectile::IsActive() const
{
    return m_IsActive;
}

Rectf Projectile::GetHitbox() const
{
    return(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));;
}