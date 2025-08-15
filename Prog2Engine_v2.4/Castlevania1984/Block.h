#pragma once
#include "Entity.h"



class Block : public Entity
{
	public:
		Block(const Vector2f& startPos, const Rectf& Hitbox);

		void Update(float elapsedSec) override;

		void Draw(bool IsDebug) const override;

		Rectf GetHitBox() const;

		~Block();

	private:

	Rectf m_Hitbox;
};

