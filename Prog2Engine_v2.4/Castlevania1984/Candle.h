#pragma once
#include "Chest.h"

class Candle : public Chest
{
public:
	Candle(const Vector2f& pos, Drop::DropType droptype);

	static void LoadTexture();
	static void FreeTexture();


private:
	static Texture* s_CandleTexture;
};
