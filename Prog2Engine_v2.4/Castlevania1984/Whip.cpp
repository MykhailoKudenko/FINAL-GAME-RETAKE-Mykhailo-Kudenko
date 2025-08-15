#include "pch.h"
#include "Whip.h"

Whip::Whip(const Vector2f& pos)
    : Projectile(pos, Vector2f{0, 0}, Rectf{0, 0, 50, 10}, 0.1f)
{

}

void Whip::Update(float elapsedSec)
{
    m_CurrentLifetime += elapsedSec;
    
    if (m_CurrentLifetime > s_MaxLifetime)
    {
        m_IsActive = false;
    }

}
void Whip::Draw(bool IsDebug) const
{
    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }
}