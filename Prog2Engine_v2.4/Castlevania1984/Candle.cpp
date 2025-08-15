#include "pch.h"
#include "Candle.h"

Texture* Candle::s_CandleTexture = nullptr;

Candle::Candle(const Vector2f& pos, Drop::DropType droptype) : Chest(pos, droptype, Rectf{ 0, 0, 8, 16 }, Animation{ s_CandleTexture, 0, 2, 0.2 })
{

}




void Candle::LoadTexture()
{
    if (!s_CandleTexture)
    {
        s_CandleTexture = new Texture("../../Resources/Reworked textures/Drops/Candle.png");
    }
}

void Candle::FreeTexture()
{
    delete s_CandleTexture;
    s_CandleTexture = nullptr;
}