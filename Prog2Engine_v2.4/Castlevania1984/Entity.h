#pragma once
#include "utils.h"
#include "Texture.h"

class Entity
{
	public:

		virtual ~Entity() = default;

		virtual void Update(float elapsedSec) = 0;
		virtual void Draw(bool IsDebug) const = 0;

		Vector2f GetPos() const;

	protected:
		Vector2f m_Pos;

		
};

