#pragma once
#include "Entity.h"
#include "Drop.h"
#include "Animation.h"

class Chest : public Entity
{
public:
	Chest(const Vector2f& pos, Drop::DropType droptype, const Rectf& hitbox, const Animation& animation);

	Rectf GetHitbox() const;


	void Draw(bool IsDebug) const override final;
	void Update(float elapsedSec) override final;

	Drop::DropType GetType() const;

protected:

	Animation m_Animation;

	Drop::DropType m_droptype;
	
	const Rectf m_Hitbox;

	

};

