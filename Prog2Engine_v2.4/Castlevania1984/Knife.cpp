#include "pch.h"
#include "Knife.h"

Texture* Knife::s_KnifeTexture = nullptr;
const float Knife::s_KnifeSpeed = 100;



Knife::Knife(const Vector2f& pos, const Vector2f& unitDirection)
    : Projectile(pos, unitDirection, Rectf{ 0, 0, 20, 10 }, 5.f)
{

}

void Knife::Update(float elapsedSec)
{
    m_Pos += m_Velocity * s_KnifeSpeed * elapsedSec;


    m_CurrentLifetime += elapsedSec;

    if (m_CurrentLifetime > s_MaxLifetime)
    {
        m_IsActive = false;
    }

}
void Knife::Draw(bool IsDebug) const
{
    if (m_Velocity.x > 0)
    {
        s_KnifeTexture->Draw(m_Pos);
    }
    else
    {
        glPushMatrix();


        float mirroredX = -GetHitbox().left - GetHitbox().width;
        float y = GetHitbox().bottom;

        glScalef(-1, 1, 1);
        s_KnifeTexture->Draw(Vector2f{ mirroredX, y });
        glPopMatrix();
    }
    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }
}

void Knife::LoadTexture()
{
    if (!s_KnifeTexture)
    {
        s_KnifeTexture = new Texture("../../Resources/Reworked textures/Drops/Knife.png"); 
    }

}

void Knife::FreeTexture()
{
    delete s_KnifeTexture;
    s_KnifeTexture = nullptr;
}