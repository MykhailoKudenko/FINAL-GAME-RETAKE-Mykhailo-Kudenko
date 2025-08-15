#include "pch.h"
#include "Chest.h"




Chest::Chest(const Vector2f& pos, Drop::DropType droptype, const Rectf& hitbox, const Animation& animation)
	:  m_droptype(droptype), m_Hitbox(hitbox), m_Animation(animation)
{
	m_Pos = pos;
}

Rectf Chest::GetHitbox() const
{
	return(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
}


void Chest::Update(float elapsedSec)
{
    m_Animation.Update(elapsedSec);

    
}

Drop::DropType Chest::GetType() const
{
    return(m_droptype);
}

void Chest::Draw(bool IsDebug) const
{
    m_Animation.Draw(m_Pos, false);

    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }

}


