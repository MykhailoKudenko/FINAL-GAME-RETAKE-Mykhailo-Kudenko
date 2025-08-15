#include "pch.h"
#include "FirePlace.h"

Texture* FirePlace::s_FirePlaceTexture = nullptr;

FirePlace::FirePlace(const Vector2f& pos, Drop::DropType droptype) : Chest(pos, droptype, Rectf{ 0, 0, 16, 32 }, Animation{ s_FirePlaceTexture, 0, 2, 0.2 })
{

}




void FirePlace::LoadTexture()
{
    if (!s_FirePlaceTexture)
    {
        s_FirePlaceTexture = new Texture("../../Resources/Reworked textures/Drops/FirePlace.png");
    }
}

void FirePlace::FreeTexture()
{
    delete s_FirePlaceTexture;
    s_FirePlaceTexture = nullptr;
}