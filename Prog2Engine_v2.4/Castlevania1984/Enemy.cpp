#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(const Vector2f& pos, float speed, const Rectf& hitbox)
    : m_Speed{ speed }, m_Hitbox{ hitbox }
{
    m_Pos = pos;
}

Enemy::~Enemy()
{
}


Rectf Enemy::GetHitbox() const
{ 
    return(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
}