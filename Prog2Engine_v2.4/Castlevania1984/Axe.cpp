
#include "pch.h"
#include "Axe.h"

Texture* Axe::s_AxeTexture = nullptr;
const float Axe::s_AxeSpeed = 100;

Axe::Axe(const Vector2f& pos, const Vector2f& unitDirection)
    : Projectile(pos, unitDirection, Rectf{ 0, 0, 20, 20 }, 5.f)
    , m_Animation(s_AxeTexture, 0, 4, 0.2)
{
    m_timeUntillGoingDown = 0.5;
}

void Axe::Update(float elapsedSec)
{
    if (m_timeUntillGoingDown > 0)
    {
        m_timeUntillGoingDown = m_timeUntillGoingDown - elapsedSec;

        m_Pos.y = m_Pos.y + s_AxeSpeed * elapsedSec;
    }
    else
    {
        m_Pos.y = m_Pos.y - s_AxeSpeed * elapsedSec;
    }


    m_Pos += m_Velocity * s_AxeSpeed * elapsedSec;

    

    m_CurrentLifetime += elapsedSec;

    if (m_CurrentLifetime > s_MaxLifetime)
    {
        m_IsActive = false;
    }
    m_Animation.Update(elapsedSec);
}
void Axe::Draw(bool IsDebug) const
{
    m_Animation.Draw(m_Pos, false);
    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }
}

void Axe::LoadTexture()
{
    if (!s_AxeTexture)
    {
        s_AxeTexture = new Texture("../../Resources/Reworked textures/Drops/Axe.png"); 
    }

}

void Axe::FreeTexture()
{
    delete s_AxeTexture;
    s_AxeTexture = nullptr;
}