#include "pch.h"
#include "Block.h"

Block::Block(const Vector2f& startPos, const Rectf& Hitbox)
{
	

	m_Pos = startPos;

	m_Hitbox = Hitbox;
}

void Block::Draw(bool IsDebug) const
{
	
	if (IsDebug)
	{
		utils::SetColor(Color4f(0, 1, 0, 1));
		utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
	}
	
}

void Block::Update(float)
{
	
}

Block::~Block()
{
	
}


Rectf Block::GetHitBox() const
{


	return(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
}