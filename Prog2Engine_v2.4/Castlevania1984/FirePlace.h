#pragma once
#include "Chest.h"

class FirePlace : public Chest
{
public:
	FirePlace(const Vector2f& pos, Drop::DropType droptype);

	static void LoadTexture();
	static void FreeTexture();


private:
	static Texture* s_FirePlaceTexture;
};

